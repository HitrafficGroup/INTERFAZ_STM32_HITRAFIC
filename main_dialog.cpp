#include "mainwindow.h"
#include "main_dialog.h"
#include "ui_main_dialog.h"
#include "ui_mainwindow.h"
#include <QPainter>

#define admin_test   0    //0调试，1发布

main_dialog::main_dialog(QWidget *parent):QDialog(parent), ui(new Ui::main_dialog)
{
    ui->setupUi(this);
    ui->tab_Par->setCurrentIndex(0);
    SignalStateTableShow();
    ChannelTableShow();
    PhaseTableShow();
    PatternTableShow();
    SplitTableShow();
    SequenceTableShow();
    ActionTableShow();
    PlanTableShow();
    ScheduleTableShow();
    OverlapTableShow();
    VehdetTableShow();
    PeddetTableShow();
    PeddetStateTableShow();
    PreemptTableShow();
    OnLineTableShow();
    datainit();

    //改变绿信比表号，重新读取表数据
    connect(ui->comboBox_SplitNumber, SIGNAL(currentIndexChanged(int)),this,SLOT(tableSplitShowData(int)));
    connect(ui->comboBox_sequenceNumber, SIGNAL(currentIndexChanged(int)),this,SLOT(tableSequenceShowData(int)));
    connect(ui->comboBox_dayPlanNumber, SIGNAL(currentIndexChanged(int)),this,SLOT(tablePlanShowData(int)));

    channel_dlg = new channel_dialog();//新建通道编辑对话框
    connect(channel_dlg, SIGNAL(ChannelDataSend(Channel)),this,SLOT(ChannelDataReceive(Channel)));//通道编辑对话框发送 通道数据信号 连接到
    connect(this, SIGNAL(ChannelDataSet(Channel)),channel_dlg, SLOT(ChannelDataInit(Channel)));
    connect(ui->tableChannel,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditChannel()));

    phase_dlg = new phase_dialog();
    connect(phase_dlg, SIGNAL(PhaseDataSend(Phase)),this,SLOT(PhaseDataReceive(Phase)));
    connect(this, SIGNAL(PhaseDataSet(Phase)),phase_dlg, SLOT(PhaseDataInit(Phase)));
    connect(ui->tablePhase,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditPhase()));

    pattern_dlg = new pattern_dialog();
    connect(pattern_dlg, SIGNAL(PatternDataSend(PatternType)),this,SLOT(PatternDataReceive(PatternType)));
    connect(this, SIGNAL(PatternDataSet(PatternType)),pattern_dlg, SLOT(PatternDataInit(PatternType)));
    connect(ui->tablePattern,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditPattern()));

    split_dlg = new split_dialog();
    connect(split_dlg, SIGNAL(SplitDataSend(Split)),this,SLOT(SplitDataReceive(Split)));
    connect(this, SIGNAL(SplitDataSet(Split)),split_dlg, SLOT(SplitDataInit(Split)));
    connect(ui->tableSplit,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditSplit()));

    sequence_dlg = new sequence_dialog();
    connect(sequence_dlg, SIGNAL(SequenceDataSend(SequenceType)),this,SLOT(SequenceDataReceive(SequenceType)));
    connect(this, SIGNAL(SequenceDataSet(SequenceType)),sequence_dlg, SLOT(SequenceDataInit(SequenceType)));
    connect(ui->tableSequence,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditSequence()));

    plan_dlg = new plan_dialog();
    connect(plan_dlg, SIGNAL(PlanDataSend(Plan)),this,SLOT(PlanDataReceive(Plan)));
    connect(this, SIGNAL(PlanDataSet(Plan)),plan_dlg, SLOT(PlanDataInit(Plan)));
    connect(ui->tablePlan,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditPlan()));

    action_dlg = new action_dialog();
    connect(action_dlg, SIGNAL(ActionDataSend(ActionType)),this,SLOT(ActionDataReceive(ActionType)));
    connect(this, SIGNAL(ActionDataSet(ActionType)),action_dlg, SLOT(ActionDataInit(ActionType)));
    connect(ui->tableAction,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditAction()));

    schedule_dlg = new schedule_dialog();
    connect(schedule_dlg, SIGNAL(ScheduleDataSend(Schedule)),this,SLOT(ScheduleDataReceive(Schedule)));
    connect(this, SIGNAL(ScheduleDataSet(Schedule)),schedule_dlg, SLOT(ScheduleDataInit(Schedule)));
    connect(ui->tableSchedule,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditSchedule()));

    overlap_dlg = new overlap_dialog();
    connect(overlap_dlg, SIGNAL(OverlapDataSend(OverlapType)),this,SLOT(OverlapDataReceive(OverlapType)));
    connect(this, SIGNAL(OverlapDataSet(OverlapType)),overlap_dlg, SLOT(OverlapDataInit(OverlapType)));
    connect(ui->tableOverlap,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditOverlap()));

    peddet_dlg = new peddet_dialog();
    connect(peddet_dlg, SIGNAL(PeddetDataSend(Peddet)),this,SLOT(PeddetDataReceive(Peddet)));
    connect(this, SIGNAL(PeddetDataSet(Peddet)),peddet_dlg, SLOT(PeddetDataInit(Peddet)));
    connect(ui->tablePeddet,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditPeddet()));

    vehdet_dlg = new vehdet_dialog();
    connect(vehdet_dlg, SIGNAL(VehdetDataSend(Vehdet)),this,SLOT(VehdetDataReceive(Vehdet)));
    connect(this, SIGNAL(VehdetDataSet(Vehdet)),vehdet_dlg, SLOT(VehdetDataInit(Vehdet)));
    connect(ui->tableVehdet,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(SendEditVehdet()));

    connect(ui->radioButton_yellowflash,SIGNAL(pressed()),this,SLOT(manual_unselect()));
    connect(ui->radioButton_allred,SIGNAL(pressed()),this,SLOT(manual_unselect()));
    connect(ui->radioButton_lampoff,SIGNAL(pressed()),this,SLOT(manual_unselect()));
    connect(ui->radioButton_nextphase,SIGNAL(pressed()),this,SLOT(manual_unselect()));
    connect(ui->radioButton_resident,SIGNAL(pressed()),this,SLOT(manual_unselect()));
    connect(ui->radioButton_auto,SIGNAL(pressed()),this,SLOT(manual_unselect()));


    on_pushButton_OpenSocket_clicked();
    timerConnect = new QTimer(this);
    connect(timerConnect, SIGNAL(timeout()), this, SLOT(ReadParProcess()));
    //ui->splitter_OP->hide();
    ui->lineEdit_DeviceNumber->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));//只能数字输入

#if admin_test
    ui->groupBox_test->hide();
    //ui->tab_preempt->hide();
    //ui->tab_vehicleDetector->hide();
    //ui->tab_pedestrianDetector->hide();
    //ui->tab_Par->tabBar()->hide();
    ui->tab_Par->removeTab(17); //删除n之后,后一个页面序号为n
    ui->tab_Par->removeTab(15);
    ui->tab_Par->removeTab(13);
    ui->tab_Par->removeTab(11);
#endif
}

main_dialog::~main_dialog()
{
    delete ui;
    db.close();
}

void main_dialog::closeEvent(QCloseEvent *e)
{
    e->accept();
}

void main_dialog::datainit(void)
{
    AscPort = 161;
    OnLineCount = 0;
    areaNum = 0x01;
    inteNumL = 0x01;
    inteNumH = 0x00;
    ReadState = 0;

    for(quint16 row = 1; row <= SplitMax; row++)
    {
        ui->comboBox_SplitNumber->addItem(tr("%1").arg(row));
    }
    ui->comboBox_SplitNumber->setCurrentIndex(0);

    for(quint16 row = 1; row <= SequenceMax; row++)
    {
        ui->comboBox_sequenceNumber->addItem(tr("%1").arg(row));
    }
    ui->comboBox_sequenceNumber->setCurrentIndex(0);

    for(quint16 row = 1; row <= PlanMax; row++)
    {
        ui->comboBox_dayPlanNumber->addItem(tr("%1").arg(row));
    }
    ui->comboBox_dayPlanNumber->setCurrentIndex(0);
    ui->pushButtonConnect->setEnabled(false);

    channelControlTypeStrList<<tr("")<<tr("其他相位")<<tr("机动车相位")<<tr("行人相位")<<tr("跟随相位")<<tr("闪灯")<<tr("常绿")<<tr("常红");//tr()
    channelFlashStrList<<tr("黄灯")<<tr("红灯")<<tr("交替");
    channelDimStrList<<tr("绿灯辉度")<<tr("黄灯辉度")<<tr("红灯辉度")<<tr("交替辉度");
    channelPositionStrList<<tr("其他")<<tr("东")<<tr("南")<<tr("西")<<tr("北")<<tr("东北")<<tr("东南")<<tr("西南")<<tr("西北");
    channelDirectionStrList<<tr("其他")<<tr("左转")<<tr("直行")<<tr("右转")<<tr("行人")<<tr("掉头")<<tr("非机动");
    SplitModeStrList<<tr("其他")<<tr("无")<<tr("最小车辆响应")<<tr("最大车辆响应")<<tr("行人响应")<<tr("最大车辆/行人响应")<<tr("忽略相位");
    WeekList<<tr("星期日")<<tr("星期一")<<tr("星期二")<<tr("星期三")<<tr("星期四")<<tr("星期五")<<tr("星期六");
    OverlapTypeList<<tr("其他")<<tr("常规")<<tr("黄绿停止");

    //CoordCorrectionList<<"其他"<<"驻留"<<"平滑过渡"<<"仅增加";
    //CoordMaximumList<<"其他"<<"最大1"<<"最大2"<<"最大约束";
    //CoordForceList<<"其他"<<"浮动"<<"固定";

    ChannelStatus.Reds = 0;
    ChannelStatus.Yellows = 0;
    ChannelStatus.Greens = 0;
    //tableSignalStateShowData();//wcx
}

void main_dialog::OpenDatabase(QString newtsc)
{
    ParName = newtsc;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(ParName);//D:/QtDir/TSC96/build-TSC96-Desktop_Qt_5_3_MinGW_32bit/tsc.db
    //db.setHostName("127.0.0.1");
    //db.setUserName("root");
    //db.setPassword("sino");
    if (!db.open())
    {
        qDebug() << tr("Connect to %1 error: ").arg(ParName) << db.lastError().text();
    }
    else
    {
        qDebug() << tr("Connect to MySql success").arg(ParName);
    }
    //数据读取
    UnitInit();
    ScheduleTabInit();
    PlanTabInit();
    ActionTabInit();
    PatternTabInit();
    SequenceTabInit();
    SplitTabInit();
    PhaseTabInit();
    ChannelTabInit();
    OverlapTabInit();
    PeddetDataInit();
    //数据显示
    tableScheduleShowData();
    tablePlanShowData(0);
    tableActionShowData();
    tablePatternShowData();
    tableSequenceShowData(0);
    tableSplitShowData(0);
    tablePhaseShowData();
    tableChannelShowData();
    tableOverlapShowData();
    tablePeddetShowData();
    tableVehdetShowData();
}

void main_dialog::SaveDatabase(void)
{
    for(quint8 row = 0; row < ChannelTab.Maximum; row++)
    {
        QSqlQuery sql_query;//"update 数据表 set 字段1=值1,字段2=值2 …… 字段n=值n where 条件表达式"
        /*
        QString update_sql = tr("update channelEntry set channelControlSource = :source, channelControlType = :type, channelFlash = :flash, channelDim = :dim, channePosition = :position, channelDirection = :direction, channelCountdownID = :id where channelNumber = :num");
        sql_query.prepare(update_sql);
        sql_query.bindValue(":source", ChannelTab.channel[row].ControlSource);
        sql_query.bindValue(":type", ChannelTab.channel[row].ControlType);
        sql_query.bindValue(":flash", ChannelTab.channel[row].Flash);
        sql_query.bindValue(":dim", ChannelTab.channel[row].Dim);
        sql_query.bindValue(":position", ChannelTab.channel[row].Position);
        sql_query.bindValue(":direction", ChannelTab.channel[row].Direction);
        sql_query.bindValue(":id", ChannelTab.channel[row].CountdownID);
        sql_query.bindValue(":num", ChannelTab.channel[row].Num);
        */
        QString str = tr("update channelEntry set channelControlSource = ?,channelControlType = ?,channelFlash = ?,channelDim = ?,channePosition = ?,channelDirection = ?,channelCountdownID = ? where channelNumber = ?");
        sql_query.prepare(str);
        sql_query.addBindValue(ChannelTab.channel[row].ControlSource);
        sql_query.addBindValue(ChannelTab.channel[row].ControlType);
        sql_query.addBindValue(ChannelTab.channel[row].Flash);
        sql_query.addBindValue(ChannelTab.channel[row].Dim);
        sql_query.addBindValue(ChannelTab.channel[row].Position);
        sql_query.addBindValue(ChannelTab.channel[row].Direction);
        sql_query.addBindValue(ChannelTab.channel[row].CountdownID,QSql::Binary);
        sql_query.addBindValue(ChannelTab.channel[row].Num);

        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        //else
        //{
        //    qDebug()<<tr("updated!");
        //}
    }
}

/********************************************************************************************/
//参数表格的构建
void main_dialog::SignalStateTableShow(void)
{
    SignalStateModel = new QStandardItemModel(4, 16);
    QStringList SignalStateTableHeaderStr;
    SignalStateTableHeaderStr <<tr("驱动板1")<<tr("红")<<tr("黄")<<tr("绿")
                              <<tr("驱动板2")<<tr("红")<<tr("黄")<<tr("绿")
                              <<tr("驱动板3")<<tr("红")<<tr("黄")<<tr("绿")
                              <<tr("驱动板4")<<tr("红")<<tr("黄")<<tr("绿");

    for(quint8 i = 0; i<16; i++) SignalStateModel->setHeaderData(i, Qt::Horizontal, SignalStateTableHeaderStr.at(i));

    ui->tableView_StateMonitor->setModel(SignalStateModel);

    ui->tableView_StateMonitor->setSelectionBehavior(QAbstractItemView::SelectRows);  //行选
    ui->tableView_StateMonitor->setSelectionMode(QAbstractItemView::SingleSelection); //只选中一行
    ui->tableView_StateMonitor->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tableView_StateMonitor->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
    ui->tableView_StateMonitor->resizeColumnsToContents();
    ui->tableView_StateMonitor->horizontalHeader()->setStretchLastSection(true);      //铺满控件
    ui->tableView_StateMonitor->horizontalHeader()->setHighlightSections(false);
    ui->tableView_StateMonitor->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p

    ui->tableView_StateMonitor->setAlternatingRowColors(true);      //设置隔行自动变色
    ui->tableView_StateMonitor->verticalHeader()->hide();           //隐藏左边那列

    //ItemDelegate *itemDelegate = new ItemDelegate;
    ui->tableView_StateMonitor->setItemDelegate(new ItemDelegate());

    //readOnlyDelegate *readonly = new readOnlyDelegate;
    //ui->tableView_StateMonitor->setItemDelegate(readonly);
}

void main_dialog::ScheduleTableShow(void)
{
    ScheduleModel=new QStandardItemModel(ScheduleMax, 3);
    ScheduleModel->setHeaderData(0, Qt::Horizontal, tr("调度计划号"));
    ScheduleModel->setHeaderData(1, Qt::Horizontal, tr("时段表"));
    ScheduleModel->setHeaderData(2, Qt::Horizontal, tr("计划时间"));
    ui->tableSchedule->setModel(ScheduleModel);

    ui->tableSchedule->setColumnWidth(0,120);
    ui->tableSchedule->setColumnWidth(1,60);
    ui->tableSchedule->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tableSchedule->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tableSchedule->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tableSchedule->horizontalHeader()->setHighlightSections(false);
    ui->tableSchedule->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tableSchedule->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tableSchedule->verticalHeader()->hide();//隐藏左边那列
}
void main_dialog::PlanTableShow(void)
{
    PlanModel=new QStandardItemModel(PeriodMax, 4);
    PlanModel->setHeaderData(0, Qt::Horizontal, tr("时段号"));
    PlanModel->setHeaderData(1, Qt::Horizontal, tr("时段"));
    PlanModel->setHeaderData(2, Qt::Horizontal, tr("动作"));
    PlanModel->setHeaderData(3, Qt::Horizontal, tr(""));
    ui->tablePlan->setModel(PlanModel);

    ui->tablePlan->setColumnWidth(0,80);
    ui->tablePlan->setColumnWidth(1,120);
    ui->tablePlan->setColumnWidth(2,80);
    ui->tablePlan->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tablePlan->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tablePlan->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tablePlan->horizontalHeader()->setHighlightSections(false);
    ui->tablePlan->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tablePlan->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tablePlan->verticalHeader()->hide();//隐藏左边那列
}

void main_dialog::ActionTableShow(void)
{
    ActionModel=new QStandardItemModel(ActionMax, 15);
    ActionModel->setHeaderData(0, Qt::Horizontal, tr("动作号"));
    ActionModel->setHeaderData(1, Qt::Horizontal, tr("方案"));
    ActionModel->setHeaderData(2, Qt::Horizontal, tr("辅助1"));
    ActionModel->setHeaderData(3, Qt::Horizontal, tr("辅助2"));
    ActionModel->setHeaderData(4, Qt::Horizontal, tr("辅助3"));
    ActionModel->setHeaderData(5, Qt::Horizontal, tr("辉度"));
    for(quint8 col=1;col<=8;col++)
    {
        ActionModel->setHeaderData(col+5, Qt::Horizontal, tr("特殊%1").arg(col));
    }
    ActionModel->setHeaderData(14, Qt::Horizontal, tr(""));
    ui->tableAction->setModel(ActionModel);

    ui->tableAction->setColumnWidth(0,60);
    ui->tableAction->setColumnWidth(1,120);
    for(quint8 col=2; col<=13; col++)
        ui->tableAction->setColumnWidth(col,40);

    ui->tableAction->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tableAction->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tableAction->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tableAction->horizontalHeader()->setHighlightSections(false);
    ui->tableAction->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tableAction->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tableAction->verticalHeader()->hide();//隐藏左边那列

    connect(ui->tableAction,SIGNAL(clicked(QModelIndex)), this, SLOT(tableActionSelectChange()));
}

void main_dialog::PatternTableShow(void)
{
    PatternModel = new QStandardItemModel(PatternMax, 7);
    PatternModel->setHeaderData(0, Qt::Horizontal, tr("方案"));
    PatternModel->setHeaderData(1, Qt::Horizontal, tr("周期长"));
    PatternModel->setHeaderData(2, Qt::Horizontal, tr("相位差"));
    PatternModel->setHeaderData(3, Qt::Horizontal, tr("绿信比表"));
    PatternModel->setHeaderData(4, Qt::Horizontal, tr("相序表"));
    PatternModel->setHeaderData(5, Qt::Horizontal, tr("工作模式"));
    PatternModel->setHeaderData(6, Qt::Horizontal, tr(""));
    ui->tablePattern->setModel(PatternModel);

    ui->tablePattern->setColumnWidth(0,60);
    ui->tablePattern->setColumnWidth(1,80);
    ui->tablePattern->setColumnWidth(2,60);
    ui->tablePattern->setColumnWidth(3,60);
    ui->tablePattern->setColumnWidth(4,60);
    ui->tablePattern->setColumnWidth(5,240);
    ui->tablePattern->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tablePattern->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tablePattern->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tablePattern->horizontalHeader()->setHighlightSections(false);
    ui->tablePattern->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p

    ui->tablePattern->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tablePattern->verticalHeader()->hide();//隐藏左边那列

    connect(ui->tablePattern,SIGNAL(clicked(QModelIndex)), this, SLOT(tablePatternSelectChange()));
}
void main_dialog::SplitTableShow(void)
{
    SplitModel = new QStandardItemModel(PhaseMax, 7);
    SplitModel->setHeaderData(0, Qt::Horizontal, tr("相位"));
    SplitModel->setHeaderData(1, Qt::Horizontal, tr("绿信比"));
    SplitModel->setHeaderData(2, Qt::Horizontal, tr("模式"));
    SplitModel->setHeaderData(3, Qt::Horizontal, tr("作为协调相位"));
    SplitModel->setHeaderData(4, Qt::Horizontal, tr("作为关键相位"));
    SplitModel->setHeaderData(5, Qt::Horizontal, tr("作为固定相位"));
    SplitModel->setHeaderData(6, Qt::Horizontal, tr(""));
    ui->tableSplit->setModel(SplitModel);

    ui->tableSplit->setColumnWidth(0,80);
    ui->tableSplit->setColumnWidth(1,80);
    ui->tableSplit->setColumnWidth(2,160);
    ui->tableSplit->setColumnWidth(3,120);
    ui->tableSplit->setColumnWidth(4,120);
    ui->tableSplit->setColumnWidth(5,120);
    ui->tableSplit->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tableSplit->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tableSplit->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tableSplit->horizontalHeader()->setHighlightSections(false);
    ui->tableSplit->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tableSplit->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tableSplit->verticalHeader()->hide();//隐藏左边那列
    ui->tableSplit->setShowGrid(true);
}
void main_dialog::SequenceTableShow(void)
{
    SequenceModel=new QStandardItemModel(4, 18);
    SequenceModel->setHeaderData(0, Qt::Horizontal, tr("环号"));
    for(quint8 col=1;col<=16;col++)
    {
        SequenceModel->setHeaderData(col, Qt::Horizontal, tr("%1").arg(col));
    }
    SequenceModel->setHeaderData(17, Qt::Horizontal, tr(""));
    ui->tableSequence->setModel(SequenceModel);

    ui->tableSequence->setColumnWidth(0,80);
    for(quint8 col=1;col<=16;col++)
    {
        ui->tableSequence->setColumnWidth(col,40);
    }
    ui->tableSequence->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tableSequence->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    //ui->tableSequence->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tableSequence->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tableSequence->horizontalHeader()->setHighlightSections(false);
    ui->tableSequence->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tableSequence->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tableSequence->verticalHeader()->hide();//隐藏左边那列
    ui->tableSequence->setShowGrid(true);
}
void main_dialog::PhaseTableShow(void)
{
    QStringList PhaseTabHeaderStrList;
    PhaseTabHeaderStrList<<tr("相位号")<<tr("行人放行")<<tr("行人清空")<<tr("最小绿")<<tr("单位延长绿")
                         <<tr("最大绿1")<<tr("最大绿2")<<tr("机动黄灯")<<tr("全红时间")<<tr("红灯保护")
                         <<tr("增加初始值")<<tr("增加初始值计算")<<tr("递减前时间")<<tr("递减前车辆数")<<tr("递减时间")
                         <<tr("单位递减率")<<tr("最小间隔")<<tr("动态最大限制")<<tr("动态步长")<<tr("初始状态")
                         <<tr("环")<<tr("机动清空")<<tr("相位选项")<<tr("并发")<<tr("");

    PhaseModel = new QStandardItemModel(32, PhaseTabHeaderStrList.size());

    for(quint8 col=0;col<PhaseTabHeaderStrList.size();col++)
    {
        PhaseModel->setHeaderData(col, Qt::Horizontal, PhaseTabHeaderStrList.at(col));
    }
    ui->tablePhase->setModel(PhaseModel);

    for(quint8 col=10;col<=20;col++)
    {
        ui->tablePhase->hideColumn(col);
    }
    for(quint8 col=22;col<=23;col++)
    {
        ui->tablePhase->hideColumn(col);
    }

    ui->tablePhase->setSelectionBehavior(QAbstractItemView::SelectRows);  //行选
    ui->tablePhase->setSelectionMode(QAbstractItemView::SingleSelection); //只选中一行
    ui->tablePhase->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tablePhase->horizontalHeader()->setStretchLastSection(true);      //铺满控件
    ui->tablePhase->horizontalHeader()->setHighlightSections(false);
    ui->tablePhase->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p

    ui->tablePhase->setAlternatingRowColors(true);                        //设置隔行自动变色
    ui->tablePhase->verticalHeader()->hide();                             //隐藏左边那列

    connect(ui->tablePhase,SIGNAL(clicked(QModelIndex)), this, SLOT(tablePhaseSelectChange(QModelIndex)));
}
void main_dialog::ChannelTableShow(void)
{
    ChannelModel = new QStandardItemModel(32, 9);
    ChannelModel->setHeaderData(0, Qt::Horizontal, tr("通道号"));
    ChannelModel->setHeaderData(1, Qt::Horizontal, tr("控制源"));
    ChannelModel->setHeaderData(2, Qt::Horizontal, tr("控制源类型"));
    ChannelModel->setHeaderData(3, Qt::Horizontal, tr("闪光模式"));
    ChannelModel->setHeaderData(4, Qt::Horizontal, tr("辉度模式"));
    ChannelModel->setHeaderData(5, Qt::Horizontal, tr("方位"));
    ChannelModel->setHeaderData(6, Qt::Horizontal, tr("方向"));
    ChannelModel->setHeaderData(7, Qt::Horizontal, tr("倒计时地址"));
    ChannelModel->setHeaderData(8, Qt::Horizontal, tr(""));
    ui->tableChannel->setModel(ChannelModel);

    ui->tableChannel->setSelectionBehavior(QAbstractItemView::SelectRows);  //行选
    ui->tableChannel->setSelectionMode(QAbstractItemView::SingleSelection); //只选中一行
    //ui->tableChannel->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    //ui->tableChannel->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
    ui->tableChannel->resizeColumnsToContents();
    ui->tableChannel->horizontalHeader()->setStretchLastSection(true);      //铺满控件
    ui->tableChannel->horizontalHeader()->setHighlightSections(false);
    ui->tableChannel->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p

    ui->tableChannel->setAlternatingRowColors(true);                        //设置隔行自动变色
    ui->tableChannel->verticalHeader()->hide();                             //隐藏左边那列
}

void main_dialog::OverlapTableShow(void)
{
    OverlapModel=new QStandardItemModel(OverlapMax, 7);
    OverlapModel->setHeaderData(0, Qt::Horizontal, tr("跟随号"));
    OverlapModel->setHeaderData(1, Qt::Horizontal, tr("类型"));
    OverlapModel->setHeaderData(2, Qt::Horizontal, tr("绿灯"));
    OverlapModel->setHeaderData(3, Qt::Horizontal, tr("黄灯"));
    OverlapModel->setHeaderData(4, Qt::Horizontal, tr("红灯"));
    OverlapModel->setHeaderData(5, Qt::Horizontal, tr("母相位"));
    OverlapModel->setHeaderData(6, Qt::Horizontal, tr("修正相位"));
    ui->tableOverlap->setModel(OverlapModel);

    ui->tableOverlap->setColumnWidth(0,80);
    ui->tableOverlap->setColumnWidth(1,60);
    ui->tableOverlap->setColumnWidth(2,60);
    ui->tableOverlap->setColumnWidth(3,60);
    ui->tableOverlap->setColumnWidth(4,60);
    ui->tableOverlap->setColumnWidth(5,240);
    ui->tableOverlap->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tableOverlap->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tableOverlap->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tableOverlap->horizontalHeader()->setHighlightSections(false);
    ui->tableOverlap->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tableOverlap->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tableOverlap->verticalHeader()->hide();//隐藏左边那列
    OverlapTab.Maximum = OverlapMax;
}
void main_dialog::VehdetTableShow(void)
{
    VehdetModel=new QStandardItemModel(VehdetMax, 10);
    VehdetModel->setHeaderData(0, Qt::Horizontal, tr("检测器编号"));
    VehdetModel->setHeaderData(1, Qt::Horizontal, tr("请求相位"));
    VehdetModel->setHeaderData(2, Qt::Horizontal, tr("开关相位"));
    VehdetModel->setHeaderData(3, Qt::Horizontal, tr("流量"));
    VehdetModel->setHeaderData(4, Qt::Horizontal, tr("占有率"));
    VehdetModel->setHeaderData(5, Qt::Horizontal, tr("延长绿"));
    VehdetModel->setHeaderData(6, Qt::Horizontal, tr("战略检测器"));
    VehdetModel->setHeaderData(7, Qt::Horizontal, tr("排队"));
    VehdetModel->setHeaderData(8, Qt::Horizontal, tr("请求"));
    VehdetModel->setHeaderData(9, Qt::Horizontal, tr(""));
    ui->tableVehdet->setModel(VehdetModel);

    ui->tableVehdet->setColumnWidth(0,100);
    ui->tableVehdet->setColumnWidth(1,80);
    ui->tableVehdet->setColumnWidth(2,80);
    ui->tableVehdet->setColumnWidth(3,40);
    ui->tableVehdet->setColumnWidth(4,60);
    ui->tableVehdet->setColumnWidth(5,60);
    ui->tableVehdet->setColumnWidth(6,100);
    ui->tableVehdet->setColumnWidth(7,40);
    ui->tableVehdet->setColumnWidth(8,40);

    ui->tableVehdet->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tableVehdet->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    //ui->tableVehdet->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tableVehdet->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tableVehdet->horizontalHeader()->setHighlightSections(false);
    ui->tableVehdet->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tableVehdet->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tableVehdet->verticalHeader()->hide();//隐藏左边那列
}
void main_dialog::PeddetTableShow(void)
{
    PeddetModel=new QStandardItemModel(PeddetMax, 6);
    PeddetModel->setHeaderData(0, Qt::Horizontal, tr("检测器编号"));
    PeddetModel->setHeaderData(1, Qt::Horizontal, tr("请求相位"));
    PeddetModel->setHeaderData(2, Qt::Horizontal, tr("无响应时间"));
    PeddetModel->setHeaderData(3, Qt::Horizontal, tr("最大持续响应时间"));
    PeddetModel->setHeaderData(4, Qt::Horizontal, tr("感应数/分钟"));
    PeddetModel->setHeaderData(5, Qt::Horizontal, tr(""));
    ui->tablePeddet->setModel(PeddetModel);

    ui->tablePeddet->setColumnWidth(0,120);
    ui->tablePeddet->setColumnWidth(1,80);
    ui->tablePeddet->setColumnWidth(2,120);
    ui->tablePeddet->setColumnWidth(3,160);
    ui->tablePeddet->setColumnWidth(4,120);

    ui->tablePeddet->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tablePeddet->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tablePeddet->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tablePeddet->horizontalHeader()->setHighlightSections(false);
    ui->tablePeddet->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tablePeddet->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tablePeddet->verticalHeader()->hide();//隐藏左边那列
}

void main_dialog::PeddetStateTableShow(void)
{
    PeddetStateModel = new QStandardItemModel(5, 9);

    PeddetStateModel->setHeaderData(0, Qt::Horizontal, tr("说明"));
    for(quint8 i = 1; i<=8; i++) PeddetStateModel->setHeaderData(i, Qt::Horizontal, tr("%1").arg(i));

    ui->tablePeddetState->setModel(PeddetStateModel);
    ui->tablePeddetState->setSelectionBehavior(QAbstractItemView::SelectRows);  //行选
    ui->tablePeddetState->setSelectionMode(QAbstractItemView::SingleSelection); //只选中一行
    ui->tablePeddetState->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    //ui->tablePeddetState->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分行
    ui->tablePeddetState->resizeColumnsToContents();
    ui->tablePeddetState->horizontalHeader()->setStretchLastSection(true);      //铺满控件
    ui->tablePeddetState->horizontalHeader()->setHighlightSections(false);
    ui->tablePeddetState->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p

    ui->tablePeddetState->setAlternatingRowColors(true);      //设置隔行自动变色
    ui->tablePeddetState->verticalHeader()->hide();           //隐藏左边那列
    ui->tablePeddetState->setItemDelegate(new ItemDelegate());
}

void main_dialog::PreemptTableShow(void)
{
    PreemptModel=new QStandardItemModel(32, 5);
    PreemptModel->setHeaderData(0, Qt::Horizontal, tr("优先号"));
    PreemptModel->setHeaderData(1, Qt::Horizontal, tr("延迟"));
    PreemptModel->setHeaderData(2, Qt::Horizontal, tr("持续时间"));
    PreemptModel->setHeaderData(3, Qt::Horizontal, tr("最小绿灯"));
    PreemptModel->setHeaderData(4, Qt::Horizontal, tr(""));
    ui->tablePreempt->setModel(PreemptModel);

    ui->tablePreempt->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tablePreempt->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tablePreempt->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//均分列
    ui->tablePreempt->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tablePreempt->horizontalHeader()->setHighlightSections(false);
    ui->tablePreempt->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tablePreempt->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tablePreempt->verticalHeader()->hide();//隐藏左边那列
}

void main_dialog::OnLineTableShow(void)
{
    OnLineModel=new QStandardItemModel(100, 6);
    OnLineModel->setHeaderData(0, Qt::Horizontal, tr("Version"));
    OnLineModel->setHeaderData(1, Qt::Horizontal, tr("Dispositivo No."));
    OnLineModel->setHeaderData(2, Qt::Horizontal, tr("IP"));
    OnLineModel->setHeaderData(3, Qt::Horizontal, tr("Puerto"));
    OnLineModel->setHeaderData(4, Qt::Horizontal, tr("Salida"));
    OnLineModel->setHeaderData(5, Qt::Horizontal, tr(""));
    ui->tableViewOnline->setModel(OnLineModel);
    ui->tableViewOnline->setSelectionBehavior(QAbstractItemView::SelectRows);//行选
    ui->tableViewOnline->setSelectionMode(QAbstractItemView::SingleSelection);//只选中一行
    ui->tableViewOnline->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(224,224,224);font:11p 'Calibri';color: black;};");//11pt 11p
    ui->tableViewOnline->horizontalHeader()->setStretchLastSection(true);//铺满控件
    ui->tableViewOnline->horizontalHeader()->setHighlightSections(false);
    ui->tableViewOnline->setAlternatingRowColors(true);//设置隔行自动变色
    ui->tableViewOnline->verticalHeader()->hide();//隐藏左边那列
    ui->tableViewOnline->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->tableViewOnline,SIGNAL(clicked(QModelIndex)), this, SLOT(tableViewOnlineSelectChange()));
}

/********************************************************************************************/
//1、所有数据从数据库读取到缓存；
//2、从缓存调取显示；
//3、修改数据到缓存；
//4、点击保存再写入数据库；

/********************************************************************************************/
//从数据库读取到缓存
void main_dialog::UnitInit(void)
{
    QSqlQuery sql_query;
    memset(&Unit, 0x00, sizeof(Unit));

    if(!sql_query.exec(tr("SELECT * FROM unitTable")))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        if(sql_query.first())
        {
            Unit.StartupFlash = sql_query.value(0).toInt();
            Unit.StartupAllRed = sql_query.value(1).toInt();
            Unit.AutomaticPedClear = sql_query.value(2).toInt();
            Unit.RedRevert = sql_query.value(3).toInt();
            Unit.BackupTime = sql_query.value(4).toInt();
            Unit.FlowCycle = sql_query.value(5).toInt();
            Unit.FlashStatus = sql_query.value(6).toInt();
            Unit.Status = sql_query.value(7).toInt();
            ui->spinBox_StartupFlash->setValue(Unit.StartupFlash);
            ui->spinBox_StartupAllRed->setValue(Unit.StartupAllRed);
            ui->spinBox_RedRevert->setValue(Unit.RedRevert);
            ui->spinBox_BackupTime->setValue(Unit.BackupTime);
            ui->spinBox_FlowCycle->setValue(Unit.FlowCycle);
            if(Unit.AutomaticPedClear == 2)
                ui->checkBox_automaticPedClear->setChecked(true);
            else
                ui->checkBox_automaticPedClear->setChecked(false);
        }
    }
}
void main_dialog::ScheduleTabInit(void)
{
    quint8 ScheduleIndex, ScheduleNum;
    QSqlQuery sql_query;

    memset(&ScheduleTab.Maximum, 0x00, sizeof(ScheduleTab));
    ScheduleTab.Maximum = ScheduleMax;

    if(!sql_query.exec(tr("SELECT * FROM timeBaseScheduleTable")))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        ScheduleIndex = 0;
        while(sql_query.next()) //sql_query.first()
        {
            ScheduleNum = sql_query.value(0).toInt();
            if(ScheduleNum > 0)
            {
                ScheduleTab.schedule[ScheduleIndex].Number = sql_query.value(0).toInt();
                ScheduleTab.schedule[ScheduleIndex].Month = sql_query.value(1).toInt();
                ScheduleTab.schedule[ScheduleIndex].Day = sql_query.value(2).toInt();
                ScheduleTab.schedule[ScheduleIndex].Date = sql_query.value(3).toInt();
                ScheduleTab.schedule[ScheduleIndex].DayPlan = sql_query.value(4).toInt();
                if(++ScheduleIndex >= ScheduleTab.Maximum)break;
            }
            else break;
        }
    }
}
void main_dialog::PlanTabInit(void)
{
    quint8 PlanNum;
    quint8 PlanIndex;
    QSqlQuery sql_query;

    memset(&PlanTab.Maximum, 0x00, sizeof(PlanTab));
    PlanTab.Maximum = PlanMax;

    for(PlanIndex = 0; PlanIndex < PlanTab.Maximum; PlanIndex++)
    {
        PlanNum = PlanIndex + 1;
        if(!sql_query.exec(tr("SELECT * FROM PlanTable where Num = %1").arg(PlanNum)))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            quint16 row = 0;
            while(sql_query.next())
            {
                PlanTab.Plan[PlanIndex].Period[row].EventNum = sql_query.value(1).toInt();
                PlanTab.Plan[PlanIndex].Period[row].Time.Hour = sql_query.value(2).toInt();
                PlanTab.Plan[PlanIndex].Period[row].Time.Minute = sql_query.value(3).toInt();
                PlanTab.Plan[PlanIndex].Period[row].ActionNum = sql_query.value(4).toInt();
                if(++row >= PeriodMax) break;
            }
            if(row > 0)PlanTab.Plan[PlanIndex].Num = PlanNum;
            else PlanTab.Plan[PlanIndex].Num = 0;
        }
    }
}
void main_dialog::ActionTabInit(void)
{
    quint8 ActionIndex, ActionNum;
    QSqlQuery sql_query;
    memset(&ActionTab.Maximum, 0x00, sizeof(ActionTab));
    ActionTab.Maximum = ActionMax;

    if(!sql_query.exec(tr("SELECT * FROM ActionTable")))
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        ActionIndex = 0;
        while(sql_query.next())
        {
            ActionNum = sql_query.value(0).toInt();
            if(ActionNum > 0)
            {
                ActionTab.Action[ActionIndex].Num = ActionNum;
                ActionTab.Action[ActionIndex].PatternNum = sql_query.value(1).toInt();
                ActionTab.Action[ActionIndex].Auxillary = sql_query.value(2).toInt();
                ActionTab.Action[ActionIndex].Special = sql_query.value(3).toInt();
            }
            if(++ActionIndex >= ActionTab.Maximum)break;
        }
    }
}
void main_dialog::PatternTabInit(void)
{
    quint8 PatternIndex = 0;
    QSqlQuery sql_query;
    memset(&PatternTab, 0x00, sizeof(PatternTab));
    PatternTab.Maximum = PatternMax;

    for(quint8 PatternNum = 1; PatternNum <= PatternTab.Maximum; PatternNum++)
    {
        if(!sql_query.exec(tr("SELECT * FROM patternTable where patternNumber = %1").arg(PatternNum)))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            if(sql_query.first())
            {
                PatternTab.Pattern[PatternIndex].Number = sql_query.value(0).toInt();
                PatternTab.Pattern[PatternIndex].CycleTime = sql_query.value(1).toInt();
                PatternTab.Pattern[PatternIndex].OffsetTime = sql_query.value(2).toInt();
                PatternTab.Pattern[PatternIndex].SplitNumber = sql_query.value(3).toInt();
                PatternTab.Pattern[PatternIndex].SequenceNumber = sql_query.value(4).toInt();
                PatternTab.Pattern[PatternIndex].WorkMode = sql_query.value(5).toInt();
                if(++PatternIndex >= PatternMax)break;
            }
        }
    }
}
void main_dialog::SplitTabInit(void)
{
    QSqlQuery sql_query;
    quint8 SplitNum;
    quint8 SplitIndex;

    memset(&SplitTab.Maximum, 0x00, sizeof(SplitTab));
    SplitTab.Maximum = SplitMax;
    for(SplitIndex = 0; SplitIndex < SplitTab.Maximum; SplitIndex++)
    {
        SplitNum = SplitIndex + 1;
        if(!sql_query.exec(tr("SELECT * FROM splitTable where splitNumber = %1").arg(SplitNum)))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            quint16 row = 0;
            while(sql_query.next())
            {
                SplitTab.Split[SplitIndex].Phase[row].Phase = sql_query.value(1).toInt();
                SplitTab.Split[SplitIndex].Phase[row].Time = sql_query.value(2).toInt();
                SplitTab.Split[SplitIndex].Phase[row].Mode = sql_query.value(3).toInt();
                SplitTab.Split[SplitIndex].Phase[row].Coord = sql_query.value(4).toInt();
                row++;
                if(row >= PhaseMax) break;
            }
            if(row>0)SplitTab.Split[SplitIndex].Num = SplitNum;
            else SplitTab.Split[SplitIndex].Num = 0;
        }
    }
}
void main_dialog::SequenceTabInit(void)
{
    quint8 SeqNum;
    quint8 SeqIndex;
    QSqlQuery sql_query;

    memset(&SeqTab.Maximum, 0x00, sizeof(SeqTab));
    SeqTab.Maximum = SequenceMax;
    for(SeqIndex = 0; SeqIndex < SeqTab.Maximum; SeqIndex++)
    {
        SeqNum = SeqIndex + 1;
        if(!sql_query.exec(tr("SELECT * FROM sequenceTable where sequenceNumber = %1").arg(SeqNum)))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            quint16 row = 0;
            while(sql_query.next())
            {
                quint8 ring = sql_query.value(1).toInt();
                SeqTab.Seq[SeqIndex].Ring[row].RingNum = ring;
                for(quint8 i = 0; i < PhaseMax; i++)
                {
                    SeqTab.Seq[SeqIndex].Ring[row].Phase[i] = sql_query.value(i+2).toInt();
                }
                row++;
                if(row >= RingMax) break;
            }
            if(row>0)SeqTab.Seq[SeqIndex].Num = SeqNum;
            else SeqTab.Seq[SeqIndex].Num = 0;
        }
    }
}
void main_dialog::PhaseTabInit(void)
{
    quint8 PhaseIndex, PhaseNum;
    QSqlQuery sql_query;

    memset(&PhaseTab.Maximum, 0x00, sizeof(PhaseTab));
    PhaseTab.Maximum = PhaseMax;
    for(PhaseIndex = 0; PhaseIndex < PhaseTab.Maximum; PhaseIndex++)
    {
        PhaseNum = PhaseIndex + 1;
        if(!sql_query.exec(tr("SELECT * FROM phaseTable where phaseNumber = %1").arg(PhaseNum)))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            if(sql_query.first())//sql_query.next()
            {
                PhaseTab.phase[PhaseIndex].Number = sql_query.value(0).toInt();
                PhaseTab.phase[PhaseIndex].Walk = sql_query.value(1).toInt();
                PhaseTab.phase[PhaseIndex].PedestrianClear = sql_query.value(2).toInt();
                PhaseTab.phase[PhaseIndex].MinimumGreen = sql_query.value(3).toInt();
                PhaseTab.phase[PhaseIndex].Passage = sql_query.value(4).toInt();

                PhaseTab.phase[PhaseIndex].Maximum1 = sql_query.value(5).toInt();
                PhaseTab.phase[PhaseIndex].Maximum2 = sql_query.value(6).toInt();
                PhaseTab.phase[PhaseIndex].YellowChange = sql_query.value(7).toInt();
                PhaseTab.phase[PhaseIndex].RedClear = sql_query.value(8).toInt();
                PhaseTab.phase[PhaseIndex].RedRevert = sql_query.value(9).toInt();

                PhaseTab.phase[PhaseIndex].AddedInitial = sql_query.value(10).toInt();
                PhaseTab.phase[PhaseIndex].MaximumInitial = sql_query.value(11).toInt();
                PhaseTab.phase[PhaseIndex].TimeBeforeReduction = sql_query.value(12).toInt();
                PhaseTab.phase[PhaseIndex].CarsBeforeReduction = sql_query.value(13).toInt();
                PhaseTab.phase[PhaseIndex].TimeToReduce = sql_query.value(14).toInt();

                PhaseTab.phase[PhaseIndex].ReduceBy = sql_query.value(15).toInt();
                PhaseTab.phase[PhaseIndex].MinimumGap = sql_query.value(16).toInt();
                PhaseTab.phase[PhaseIndex].DynamicMaxLimit = sql_query.value(17).toInt();
                PhaseTab.phase[PhaseIndex].DynamicMaxStep = sql_query.value(18).toInt();
                PhaseTab.phase[PhaseIndex].Startup = sql_query.value(19).toInt();

                PhaseTab.phase[PhaseIndex].Ring = sql_query.value(20).toInt();
                PhaseTab.phase[PhaseIndex].VehicleClear = sql_query.value(21).toInt();
                PhaseTab.phase[PhaseIndex].Options = sql_query.value(22).toInt();
                PhaseTab.phase[PhaseIndex].Concurrency = sql_query.value(23).toInt();
            }
        }
    }
}
void main_dialog::ChannelTabInit(void)
{
    quint8 ChannelIndex, ChannelNum;
    QSqlQuery sql_query;

    memset(&ChannelTab.Maximum, 0x00, sizeof(ChannelTab));
    ChannelTab.Maximum = ChannelMax;
    for(ChannelIndex = 0; ChannelIndex < ChannelTab.Maximum; ChannelIndex++)
    {
        ChannelNum = ChannelIndex + 1;
        if(!sql_query.exec(tr("SELECT * FROM channelEntry where channelNumber = %1").arg(ChannelNum)))
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            if(sql_query.first())
            {
                ChannelTab.channel[ChannelIndex].Num = sql_query.value(0).toInt();
                ChannelTab.channel[ChannelIndex].ControlSource = sql_query.value(1).toInt();
                ChannelTab.channel[ChannelIndex].ControlType = sql_query.value(2).toInt();
                ChannelTab.channel[ChannelIndex].Flash = sql_query.value(3).toInt();
                ChannelTab.channel[ChannelIndex].Dim = sql_query.value(4).toInt();
                ChannelTab.channel[ChannelIndex].Position = sql_query.value(5).toInt();
                ChannelTab.channel[ChannelIndex].Direction = sql_query.value(6).toInt();
                ChannelTab.channel[ChannelIndex].CountdownID = sql_query.value(7).toInt();
            }
        }
    }
}

void main_dialog::OverlapTabInit(void)
{
    memset(&OverlapTab.Maximum, 0x00, sizeof(OverlapTab));
    OverlapTab.Maximum = OverlapMax;
}

/********************************************************************************************/
//数据参数在表格中显示

     /*
void main_dialog::tableSignalStateShowData(void)
{


    QPainter painter;

    static int startAngle = 45 * 16; // 开始角度是 45 度
    static int spanAngle = 130 * 16; // 覆盖角度为 130 度
    static QRectF boundingRect(0, 0, 150, 150); // 包围矩形


    painter.translate(30, 30);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(boundingRect); // 绘制包围矩形
    painter.setBrush(Qt::lightGray);
    painter.drawArc(boundingRect, startAngle, spanAngle); // 画弧



        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        static int startAngle = 45 * 16; // 开始角度是 45 度
        static int spanAngle = 130 * 16; // 覆盖角度为 130 度
        static QRectF boundingRect(0, 0, 150, 150); // 包围矩形

        painter.translate(30, 30);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(boundingRect); // 绘制包围矩形
        painter.setBrush(Qt::lightGray);
        painter.drawArc(boundingRect, startAngle, spanAngle); // 画弧

        painter.translate(180, 0);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(boundingRect); // 绘制包围矩形
        painter.setBrush(Qt::lightGray);
        painter.drawChord(boundingRect, startAngle, spanAngle); // 画弦

        painter.translate(180, 0);
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(boundingRect); // 绘制包围矩形
        painter.setBrush(Qt::lightGray);
        painter.drawPie(boundingRect, startAngle, spanAngle); // 画饼图



    QString path = QString(":/SRC/calendar.png");

    //QPixmap px;
    //px.load(path);
    //ui->label->setPixmap(px);

    QImage im;
    im.load(path);
    QPixmap px = QPixmap::fromImage(im);
    //show
    ui->label->setPixmap(px);



    QLabel *label = new QLabel(this);
    label->setText("hello");
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(label);
    ui->groupBox_5->setLayout(vbox);



    QString path = QDir::currentPath() + "/SRC/calendar.png";
    QImage im;
    im.load(path);
    QPixmap px = QPixmap::fromImage(im);

    QLabel *label0 = new QLabel(this);
    //label0->setPixmap(px);

    //QPainter painter(label);
    //painter.setPen(Qt::blue);
    //painter.drawEllipse(30,15,50,65);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(label0);
    ui->groupBox_5->setLayout(vbox);

    //ui->pushButtonConnect->setStyleSheet("background-color: rgb(80, 250, 70);");
    label0->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
    label0->setStyleSheet("color:red;");

    QString red = "red";

    SignalStateModel->setData(SignalStateModel->index(0, 0), QVariant(1));
    SignalStateModel->item(0,0)->setTextAlignment(Qt::AlignCenter);//
    SignalStateModel->setData(SignalStateModel->index(0, 1), QVariant(red));//px
    SignalStateModel->item(0,1)->setTextAlignment(Qt::AlignCenter);
    SignalStateModel->item(0,1)->setForeground(QBrush(QColor(255, 0, 0)));
    //SignalStateModel->item(0,1)->setIcon(QIcon(path));
}
*/

void main_dialog::tableSignalStateShowData(void)
{
    quint16 i, board, row, col;
    quint32 temp = 0x1;

    int Width = ui->tableView_StateMonitor->columnWidth(0)/2;
    int Height = ui->tableView_StateMonitor->rowHeight(0)/2;
    int radius = Height;
    if(Width < Height)radius = Width;
    // cx cy : 设置圆的中心原点(center)
    // radius: 设置圆半径
    // fx fy : 设置焦点focus,也就是颜色的起始位置
    QRadialGradient gradient_G(Width, Height, radius, Width, Height);
    gradient_G.setColorAt(0.80, Qt::green);
    gradient_G.setColorAt(0.85, Qt::black);
    gradient_G.setColorAt(0.90, Qt::white);

    QRadialGradient gradient_Y(Width, Height, radius, Width, Height);
    gradient_Y.setColorAt(0.80, Qt::yellow);
    gradient_Y.setColorAt(0.85, Qt::black);
    gradient_Y.setColorAt(0.90, Qt::white);

    QRadialGradient gradient_R(Width, Height, radius, Width, Height);
    gradient_R.setColorAt(0.80, Qt::red);
    gradient_R.setColorAt(0.85, Qt::black);
    gradient_R.setColorAt(0.90, Qt::white);

    QRadialGradient gradient_B(Width, Height, radius, Width, Height);
    gradient_B.setColorAt(0.8, QColor::fromRgb(240,240,240));
    gradient_B.setColorAt(1.0, Qt::white);

    gre = QBrush( gradient_G );
    yel = QBrush( gradient_Y );
    red = QBrush( gradient_R );
    gra = QBrush( gradient_B );

    //gre = QBrush(QColor(0x20, 0xf0, 0x20));
    //yel = QBrush(QColor(0xf0, 0xf0, 0x20));
    //red = QBrush(QColor(0xf0, 0x20, 0x20));
    //gra = QBrush(QColor(Qt::lightGray));

    //QString redstr = "红";
    //QString yellowstr = "黄";
    //QString greenstr = "绿";

    for(i = 0; i < 16; i++)
    {
        //0 - 1 2 3   4 - 5 6 7     8 - 9 10 11     12 - 13 14 15
        board = i/4;
        row = (i%4);
        col = (board*4);

        SignalStateModel->setData(SignalStateModel->index(row, col), QVariant(i+1));
        SignalStateModel->item(row,col)->setTextAlignment(Qt::AlignCenter);

        SignalStateModel->setData(SignalStateModel->index(row, col+1), QVariant(""));
        SignalStateModel->setData(SignalStateModel->index(row, col+2), QVariant(""));
        SignalStateModel->setData(SignalStateModel->index(row, col+3), QVariant(""));

        //SignalStateModel->item(row,col+1)->setTextAlignment(Qt::AlignCenter);
        //SignalStateModel->item(row,col+2)->setTextAlignment(Qt::AlignCenter);
        //SignalStateModel->item(row,col+3)->setTextAlignment(Qt::AlignCenter);

        if(ChannelStatus.Reds & temp)
        {
            //SignalStateModel->item(row,col+1)->setForeground(red);
            SignalStateModel->item(row,col+1)->setBackground(red);
        }
        else
        {
            //SignalStateModel->item(row,col+1)->setForeground(gra);
            SignalStateModel->item(row,col+1)->setBackground(gra);
        }

        if(ChannelStatus.Yellows & temp)
        {
            //SignalStateModel->item(row,col+2)->setForeground(yel);
            SignalStateModel->item(row,col+2)->setBackground(yel);
        }
        else
        {
            //SignalStateModel->item(row,col+2)->setForeground(gra);
            SignalStateModel->item(row,col+2)->setBackground(gra);
        }

        if(ChannelStatus.Greens & temp)
        {
            //SignalStateModel->item(row,col+3)->setForeground(gre);
            SignalStateModel->item(row,col+3)->setBackground(gre);
        }
        else
        {
            //SignalStateModel->item(row,col+3)->setForeground(gra);
            SignalStateModel->item(row,col+3)->setBackground(gra);
        }
        temp <<= 0x1;
    }
    //ui->tableView_StateMonitor->selectedIndexes();
}

void main_dialog::tableScheduleShowData(void)
{
    quint8 indexRow = ui->tableSchedule->currentIndex().row();
    for(quint8 row = 0; row < ScheduleTab.Maximum; row++)
    {
        if(ScheduleTab.schedule[row].Number > 0)
        {
            ScheduleModel->setData(ScheduleModel->index(row, 0), QVariant(ScheduleTab.schedule[row].Number));
            ScheduleModel->setData(ScheduleModel->index(row, 1), QVariant(ScheduleTab.schedule[row].DayPlan));
            ScheduleModel->item(row,0)->setTextAlignment(Qt::AlignCenter);
            ScheduleModel->item(row,1)->setTextAlignment(Qt::AlignCenter);

            qint8 n;
            quint32 temp;
            QString PlanStr = tr("");
            if(ScheduleTab.schedule[row].Month & 0x1FFE)
            {
                n = -1;
                temp = 0x0002;
                PlanStr += tr(" 月份");
                for(quint8 i = 1; i <= 12; i++)
                {
                    if(ScheduleTab.schedule[row].Month & temp)
                    {
                        if(n==-1)
                        {
                            PlanStr += tr(":%1").arg(i);
                            n = i;
                        }
                        else if(n==0)
                        {
                            PlanStr += tr(",%1").arg(i);
                            n = i;
                        }
                        else
                        {
                            if(i == 12)PlanStr += tr("-%1").arg(i);
                        }
                    }
                    else
                    {
                        if(n > 0)
                        {
                            if(i-1 > n)
                                PlanStr += tr("-%1").arg(i-1);
                            n = 0;
                        }
                    }
                    temp <<= 1;
                }
            }
            if(ScheduleTab.schedule[row].Date & 0xFFFFFFFE)
            {
                n = -1;
                temp = 0x0002;
                PlanStr += tr("    日期");
                for(quint8 i = 1; i <= 31; i++)
                {
                    if(ScheduleTab.schedule[row].Date & temp)
                    {
                        if(n==-1)
                        {
                            PlanStr += tr(":%1").arg(i);
                            n = i;
                        }
                        else if(n==0)
                        {
                            PlanStr += tr(",%1").arg(i);
                            n = i;
                        }
                        else
                        {
                            if(i == 31)PlanStr += tr("-%1").arg(i);
                        }
                    }
                    else
                    {
                        if(n > 0)
                        {
                            if(i-1 > n)
                                PlanStr += tr("-%1").arg(i-1);
                            n = 0;
                        }
                    }
                    temp <<= 1;
                }
            }
            if(ScheduleTab.schedule[row].Day & 0xFE)
            {
                n = -1;
                temp = 0x0002;
                PlanStr += tr("    星期");
                for(quint8 i = 1; i <= 7; i++)
                {
                    if(ScheduleTab.schedule[row].Day & temp)
                    {
                        if(n==-1)
                        {
                            if(i == 1)
                            {
                                PlanStr += tr(":日");
                                n = i;
                            }
                            else
                            {
                                PlanStr += tr(":%1").arg(i-1);
                                n = i;
                            }
                        }
                        else if(n==0)
                        {
                            PlanStr += tr(",%1").arg(i-1);
                            n = i;
                        }
                        else
                        {
                            if(i == 7)PlanStr += tr("-%1").arg(i-1);
                        }
                    }
                    else
                    {
                        if(n > 0)
                        {
                            if(i-1 > n)
                                PlanStr += tr("-%1").arg(i-2);
                            n = 0;
                        }
                    }
                    temp <<= 1;
                }
            }
            ScheduleModel->setData(ScheduleModel->index(row, 2), QVariant(PlanStr));
        }
        else
        {
            ScheduleModel->removeRow(row);
            ScheduleModel->insertRow(row);
        }
    }
    ui->tableSchedule->scrollToTop();
    ui->tableSchedule->selectRow(indexRow);
}
void main_dialog::tablePlanShowData(int PlanIndex)
{
    qDebug()<<tr("PlanIndex = %1").arg(PlanIndex);
    quint8 indexRow = ui->tablePlan->currentIndex().row();

    for(quint8 row = 0; row < PeriodMax; row++)
    {
        if(PlanTab.Plan[PlanIndex].Period[row].EventNum > 0 && PlanTab.Plan[PlanIndex].Period[row].ActionNum > 0)
        {
            PlanModel->removeRow(row);
            PlanModel->insertRow(row);
            quint8 PeriodNum = PlanTab.Plan[PlanIndex].Period[row].EventNum;
            quint8 Hour = PlanTab.Plan[PlanIndex].Period[row].Time.Hour;
            quint8 Minute = PlanTab.Plan[PlanIndex].Period[row].Time.Minute;
            quint8 ActionNum = PlanTab.Plan[PlanIndex].Period[row].ActionNum;
            QString timeStr = tr("%1:%2").arg(Hour).arg(Minute);
            PlanModel->setData(PlanModel->index(row, 0), QVariant(PeriodNum));
            PlanModel->setData(PlanModel->index(row, 1), QVariant(timeStr));
            PlanModel->setData(PlanModel->index(row, 2), QVariant(ActionNum));
        }
        else
        {
            PlanModel->removeRow(row);
            PlanModel->insertRow(row);
        }
    }
    ui->tablePlan->scrollToTop();
    ui->tablePlan->selectRow(indexRow);
}
void main_dialog::tableActionShowData(void)
{
    quint8 row = 0;
    QString str = "√";
    quint8 indexRow = ui->tableAction->currentIndex().row();

    while(ActionTab.Action[row].Num > 0)
    {
        ActionModel->removeRow(row);
        ActionModel->insertRow(row);
        ActionModel->setData(ActionModel->index(row, 0), QVariant(ActionTab.Action[row].Num));
        ActionModel->setData(ActionModel->index(row, 1), QVariant(ActionTab.Action[row].PatternNum));
        ActionModel->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ActionModel->item(row,1)->setTextAlignment(Qt::AlignCenter);

        quint8 temp = 0x01;
        for(quint8 col=2; col<6; col++)
        {
            if(ActionTab.Action[row].Auxillary & temp)
            {
                ActionModel->setData(ActionModel->index(row, col), QVariant(str));
                ActionModel->item(row,col)->setTextAlignment(Qt::AlignCenter);
            }
            temp <<= 1;
        }
        temp = 0x01;
        for(quint8 col=6; col<14; col++)
        {
            if(ActionTab.Action[row].Special & temp)
            {
                ActionModel->setData(ActionModel->index(row, col), QVariant(str));
                ActionModel->item(row,col)->setTextAlignment(Qt::AlignCenter);
            }
            temp <<= 1;
        }
        if(++row >= ActionTab.Maximum)break;
    }
    for(quint8 ro = row; ro < ActionTab.Maximum; ro++)
    {
        ActionModel->removeRow(ro);
        ActionModel->insertRow(ro);
    }
    ui->tableAction->scrollToTop();
    ui->tableAction->selectRow(indexRow);
}

void main_dialog::tableVehdetShowData(void)
{
    quint8 row = 0, ro = 0;

    //显示所有已设定的参数
    for(row = 0; row < VehdetMax; row++)
    {
        if(VehdetTab.vehdet[row].Num > 0)
        {
            VehdetModel->removeRow(ro);
            VehdetModel->insertRow(ro);
            VehdetModel->setData(VehdetModel->index(ro, 0), QVariant(VehdetTab.vehdet[row].Num));
            VehdetModel->setData(VehdetModel->index(ro, 1), QVariant(VehdetTab.vehdet[row].CallPhase));
            VehdetModel->setData(VehdetModel->index(ro, 2), QVariant(VehdetTab.vehdet[row].SwitchPhase));
            VehdetModel->setData(VehdetModel->index(ro, 3), QVariant(VehdetTab.vehdet[row].Options&VDO_recordFlow?"√":""));
            VehdetModel->setData(VehdetModel->index(ro, 4), QVariant(VehdetTab.vehdet[row].Options&VDO_recordOccupancy?"√":""));
            VehdetModel->setData(VehdetModel->index(ro, 5), QVariant(VehdetTab.vehdet[row].Options&VDO_extend?"√":""));
            VehdetModel->setData(VehdetModel->index(ro, 6), QVariant(VehdetTab.vehdet[row].Options&VDO_strategy?"√":""));
            VehdetModel->setData(VehdetModel->index(ro, 7), QVariant(VehdetTab.vehdet[row].Options&VDO_queue?"√":""));
            VehdetModel->setData(VehdetModel->index(ro, 8), QVariant(VehdetTab.vehdet[row].Options&VDO_require?"√":""));

            for(int col = 0; col <= 8; col++)
                VehdetModel->item(ro,col)->setTextAlignment(Qt::AlignCenter);
            /*
            VehdetModel->item(ro,0)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,1)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,2)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,3)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,4)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,5)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,6)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,7)->setTextAlignment(Qt::AlignCenter);
            VehdetModel->item(ro,8)->setTextAlignment(Qt::AlignCenter);
            */

            ro++;
        }
    }
    //表格清空补全
    for( ; ro < VehdetMax; ro++)
    {
        VehdetModel->removeRow(ro);
        VehdetModel->insertRow(ro);
    }

    ui->tableVehdet->scrollToTop();
}

void main_dialog::tablePeddetShowData(void)
{
    quint8 row = 0, ro = 0;

    //显示所有已设定的参数
    for(row = 0; row < PeddetMax; row++)
    {
        if(PeddetTab.peddet[row].Num > 0)
        {
            PeddetModel->removeRow(ro);
            PeddetModel->insertRow(ro);
            PeddetModel->setData(PeddetModel->index(ro, 0), QVariant(PeddetTab.peddet[row].Num));
            PeddetModel->setData(PeddetModel->index(ro, 1), QVariant(PeddetTab.peddet[row].CallPhase));
            PeddetModel->setData(PeddetModel->index(ro, 2), QVariant(PeddetTab.peddet[row].NoActivity));
            PeddetModel->setData(PeddetModel->index(ro, 3), QVariant(PeddetTab.peddet[row].MaxPresence));
            PeddetModel->setData(PeddetModel->index(ro, 4), QVariant(PeddetTab.peddet[row].ErraticCounts));

            PeddetModel->item(ro,0)->setTextAlignment(Qt::AlignCenter);
            PeddetModel->item(ro,1)->setTextAlignment(Qt::AlignCenter);
            PeddetModel->item(ro,2)->setTextAlignment(Qt::AlignCenter);
            PeddetModel->item(ro,3)->setTextAlignment(Qt::AlignCenter);
            PeddetModel->item(ro,4)->setTextAlignment(Qt::AlignCenter);
            ro++;
        }
    }
    //表格清空补全
    for( ; ro < PeddetMax; ro++)
    {
        PeddetModel->removeRow(ro);
        PeddetModel->insertRow(ro);
    }

    ui->tablePeddet->scrollToTop();
}

void main_dialog::tablePeddetStateShowData(void)
{
    quint8 col;
    qDebug() << "eddetStateShowData";
    PeddetStateModel->setData(PeddetStateModel->index(0, 0), QVariant(tr("状态")));
    PeddetStateModel->setData(PeddetStateModel->index(1, 0), QVariant(tr("无响应")));
    PeddetStateModel->setData(PeddetStateModel->index(2, 0), QVariant(tr("有效持续")));
    PeddetStateModel->setData(PeddetStateModel->index(3, 0), QVariant(tr("次/分钟")));
    PeddetStateModel->setData(PeddetStateModel->index(4, 0), QVariant(tr("警报")));
    for(col = 0; col < PeddetMax; col++)
    {
        PeddetStateModel->setData(PeddetStateModel->index(0, col+1), QVariant(PeddetStateTab.peddet[col].Valid));
        PeddetStateModel->setData(PeddetStateModel->index(1, col+1), QVariant(PeddetStateTab.peddet[col].NoActivity));
        PeddetStateModel->setData(PeddetStateModel->index(2, col+1), QVariant(PeddetStateTab.peddet[col].Presence));
        PeddetStateModel->setData(PeddetStateModel->index(3, col+1), QVariant(PeddetStateTab.peddet[col].ErraticCounts));
        PeddetStateModel->setData(PeddetStateModel->index(4, col+1), QVariant(QString::number(PeddetStateTab.peddet[col].Alarms,16).toUpper()));
    }

    ui->tablePeddetState->scrollToTop();
}

void main_dialog::tableOverlapShowData(void)
{
    quint8 row = 0;
    quint8 indexRow = ui->tableOverlap->currentIndex().row();

    while(OverlapTab.Overlap[row].Num > 0)
    {
        OverlapModel->removeRow(row);
        OverlapModel->insertRow(row);
        OverlapModel->setData(OverlapModel->index(row, 0), QVariant(OverlapTab.Overlap[row].Num));
        OverlapModel->setData(OverlapModel->index(row, 1), QVariant(OverlapTypeList.at(OverlapTab.Overlap[row].Type-1)));
        OverlapModel->setData(OverlapModel->index(row, 2), QVariant(OverlapTab.Overlap[row].TrailGreen));
        OverlapModel->setData(OverlapModel->index(row, 3), QVariant(OverlapTab.Overlap[row].TrailYellow));
        OverlapModel->setData(OverlapModel->index(row, 4), QVariant(OverlapTab.Overlap[row].TrailRed));

        OverlapModel->item(row,0)->setTextAlignment(Qt::AlignCenter);
        OverlapModel->item(row,1)->setTextAlignment(Qt::AlignCenter);
        OverlapModel->item(row,2)->setTextAlignment(Qt::AlignCenter);
        OverlapModel->item(row,3)->setTextAlignment(Qt::AlignCenter);
        OverlapModel->item(row,4)->setTextAlignment(Qt::AlignCenter);

        QString IncludePhaseStr, ModifierPhaseStr;
        quint16 temp = 0x0001;
        for(quint8 i = 1; i <= 16; i++)
        {
            if(OverlapTab.Overlap[row].IncludedPhases & temp) IncludePhaseStr += tr("%1,").arg(i);
            if(OverlapTab.Overlap[row].ModifierPhases & temp) ModifierPhaseStr += tr("%1,").arg(i);
            temp <<= 1;
        }
        OverlapModel->setData(OverlapModel->index(row, 5), QVariant(IncludePhaseStr));
        OverlapModel->setData(OverlapModel->index(row, 6), QVariant(ModifierPhaseStr));

        if(++row >= OverlapTab.Maximum) break;
    }
    for(quint8 ro = row; ro < OverlapTab.Maximum; ro++)
    {
        OverlapModel->removeRow(ro);
        OverlapModel->insertRow(ro);
    }
    ui->tableOverlap->scrollToTop();
    ui->tableOverlap->selectRow(indexRow);
}

QString main_dialog::WorkModeStr(quint8 mode)
{
    QString Str;

    if(mode == FixedTime)Str = tr("定周期");
    else if(mode == LineCtrl)Str = tr("绿波控制");
    else if(mode == VehicleSense)Str = tr("感应控制");
    else if(mode == Flashing)Str = tr("闪光模式");
    else if(mode == AllRed)Str = tr("全红模式");
    else if(mode == LampOff)Str = tr("关灯模式");
    return Str;
}

void main_dialog::tablePatternShowData(void)
{
    quint8 indexRow = ui->tablePattern->currentIndex().row();
    for(quint8 row = 0; row < PatternTab.Maximum; row++)
    {
        if(PatternTab.Pattern[row].Number > 0)
        {
            qDebug()<<"PatternTab.Pattern[row].Number = " << PatternTab.Pattern[row].Number;
            PatternModel->setData(PatternModel->index(row, 0), QVariant(PatternTab.Pattern[row].Number));
            PatternModel->setData(PatternModel->index(row, 1), QVariant(PatternTab.Pattern[row].CycleTime));
            PatternModel->setData(PatternModel->index(row, 2), QVariant(PatternTab.Pattern[row].OffsetTime));
            PatternModel->setData(PatternModel->index(row, 3), QVariant(PatternTab.Pattern[row].SplitNumber));
            PatternModel->setData(PatternModel->index(row, 4), QVariant(PatternTab.Pattern[row].SequenceNumber));
            PatternModel->setData(PatternModel->index(row, 5), QVariant(WorkModeStr(PatternTab.Pattern[row].WorkMode)));

            PatternModel->item(row,0)->setTextAlignment(Qt::AlignCenter);
            PatternModel->item(row,1)->setTextAlignment(Qt::AlignCenter);
            PatternModel->item(row,2)->setTextAlignment(Qt::AlignCenter);
            PatternModel->item(row,3)->setTextAlignment(Qt::AlignCenter);
            PatternModel->item(row,4)->setTextAlignment(Qt::AlignCenter);
            //PatternModel->item(row,5)->setTextAlignment(Qt::AlignLeft);
        }
        else
        {
            PatternModel->removeRow(row);
            PatternModel->insertRow(row);
        }
    }
    ui->tablePattern->scrollToTop();
    ui->tablePattern->selectRow(indexRow);
}
void main_dialog::tableSplitShowData(int SplitIndex)
{
    qDebug()<<tr("SplitIndex = %1").arg(SplitIndex);
    quint8 indexRow = ui->tableSplit->currentIndex().row();

    for(quint8 row = 0; row < PhaseMax; row++)
    {
        if(SplitTab.Split[SplitIndex].Phase[row].Phase > 0)
        {
            int SplitMode;
            QString str1 = "√";
            SplitModel->removeRow(row);
            SplitModel->insertRow(row);

            SplitModel->setData(SplitModel->index(row, 0), QVariant(SplitTab.Split[SplitIndex].Phase[row].Phase));
            SplitModel->setData(SplitModel->index(row, 1), QVariant(SplitTab.Split[SplitIndex].Phase[row].Time));
            SplitMode = SplitTab.Split[SplitIndex].Phase[row].Mode-1;
            if(SplitMode >=0 && SplitMode < SplitModeStrList.count())
            {
                SplitModel->setData(SplitModel->index(row, 2), QVariant(SplitModeStrList.at(SplitMode)));
                SplitModel->item(row,2)->setTextAlignment(Qt::AlignCenter);
            }

            if(SplitTab.Split[SplitIndex].Phase[row].Coord & 0x01)
            {
                SplitModel->setData(SplitModel->index(row, 3), QVariant(str1));
                SplitModel->item(row,3)->setTextAlignment(Qt::AlignCenter);
            }
            if(SplitTab.Split[SplitIndex].Phase[row].Coord & 0x02)
            {
                SplitModel->setData(SplitModel->index(row, 4), QVariant(str1));
                SplitModel->item(row,4)->setTextAlignment(Qt::AlignCenter);
            }
            if(SplitTab.Split[SplitIndex].Phase[row].Coord & 0x04)
            {
                SplitModel->setData(SplitModel->index(row, 5), QVariant(str1));
                SplitModel->item(row,5)->setTextAlignment(Qt::AlignCenter);
            }
            SplitModel->item(row,0)->setTextAlignment(Qt::AlignCenter);
            SplitModel->item(row,1)->setTextAlignment(Qt::AlignCenter);
        }
        else
        {
            SplitModel->removeRow(row);
            SplitModel->insertRow(row);
        }
    }
    ui->tableSplit->scrollToTop();
    ui->tableSplit->selectRow(indexRow);
}
void main_dialog::tableSequenceShowData(int SequenceIndex)
{
    qDebug()<<tr("SequenceIndex = %1").arg(SequenceIndex);
    if(SeqTab.Seq[SequenceIndex].Num > 0)//相序表号不为空
    {
        for(quint8 ring = 0; ring < RingMax; ring++)
        {
            SequenceModel->removeRow(ring);
            SequenceModel->insertRow(ring);
            quint8 RingNum = SeqTab.Seq[SequenceIndex].Ring[ring].RingNum;
            if(RingNum)
            {
                SequenceModel->setData(SequenceModel->index(ring, 0), QVariant(RingNum));
                SequenceModel->item(ring, 0)->setTextAlignment(Qt::AlignCenter);
                for(quint8 i = 0; i < PhaseMax; i++)
                {
                    quint8 PhaseNum = SeqTab.Seq[SequenceIndex].Ring[ring].Phase[i];
                    if(PhaseNum > 0)
                    {
                        SequenceModel->setData(SequenceModel->index(ring, i + 1), QVariant(PhaseNum));
                        SequenceModel->item(ring, i + 1)->setTextAlignment(Qt::AlignCenter);
                    }
                }
            }
        }
    }
    else
    {
        for(quint8 ring = 0; ring < RingMax; ring++)
        {
            SequenceModel->removeRow(ring);
            SequenceModel->insertRow(ring);
        }
    }
}
void main_dialog::tablePhaseShowData(void)
{
    QModelIndex index = ui->tablePhase->currentIndex();
    for(quint8 PhaseIndex = 0; PhaseIndex < PhaseTab.Maximum; PhaseIndex++)
    {
        if(PhaseTab.phase[PhaseIndex].Number > 0)
        {
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 0), QVariant(PhaseTab.phase[PhaseIndex].Number));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 1), QVariant(PhaseTab.phase[PhaseIndex].Walk));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 2), QVariant(PhaseTab.phase[PhaseIndex].PedestrianClear));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 3), QVariant(PhaseTab.phase[PhaseIndex].MinimumGreen));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 4), QVariant(PhaseTab.phase[PhaseIndex].Passage));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 5), QVariant(PhaseTab.phase[PhaseIndex].Maximum1));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 6), QVariant(PhaseTab.phase[PhaseIndex].Maximum2));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 7), QVariant(PhaseTab.phase[PhaseIndex].YellowChange));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 8), QVariant(PhaseTab.phase[PhaseIndex].RedClear));
            PhaseModel->setData(PhaseModel->index(PhaseIndex, 9), QVariant(PhaseTab.phase[PhaseIndex].RedRevert));

            PhaseModel->setData(PhaseModel->index(PhaseIndex,10),QVariant(PhaseTab.phase[PhaseIndex].AddedInitial));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,11),QVariant(PhaseTab.phase[PhaseIndex].MaximumInitial));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,12),QVariant(PhaseTab.phase[PhaseIndex].TimeBeforeReduction));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,13),QVariant(PhaseTab.phase[PhaseIndex].CarsBeforeReduction));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,14),QVariant(PhaseTab.phase[PhaseIndex].TimeToReduce));

            PhaseModel->setData(PhaseModel->index(PhaseIndex,15),QVariant(PhaseTab.phase[PhaseIndex].ReduceBy));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,16),QVariant(PhaseTab.phase[PhaseIndex].MinimumGap));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,17),QVariant(PhaseTab.phase[PhaseIndex].DynamicMaxLimit));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,18),QVariant(PhaseTab.phase[PhaseIndex].DynamicMaxStep));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,19),QVariant(PhaseTab.phase[PhaseIndex].Startup));

            PhaseModel->setData(PhaseModel->index(PhaseIndex,20),QVariant(PhaseTab.phase[PhaseIndex].Ring));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,21),QVariant(PhaseTab.phase[PhaseIndex].VehicleClear));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,22),QVariant(PhaseTab.phase[PhaseIndex].Options));
            PhaseModel->setData(PhaseModel->index(PhaseIndex,23),QVariant(PhaseTab.phase[PhaseIndex].Concurrency));
            for(quint8 row = 0; row< 24; row++)
                PhaseModel->item(PhaseIndex,row)->setTextAlignment(Qt::AlignCenter);
        }
        else
        {
            PhaseModel->removeRow(PhaseIndex);
            PhaseModel->insertRow(PhaseIndex);
        }
    }
    ui->tablePhase->setCurrentIndex(index);
}
void main_dialog::tableChannelShowData(void)
{
    quint8 temp_var;
    quint8 channel_data;
    QString channeldataStr;

    for(quint8 row = 0; row < ChannelTab.Maximum; row++)
    {
        ChannelModel->setData(ChannelModel->index(row, 0), QVariant(ChannelTab.channel[row].Num));
        ChannelModel->item(row,0)->setTextAlignment(Qt::AlignCenter);

        ChannelModel->setData(ChannelModel->index(row, 1), QVariant(ChannelTab.channel[row].ControlSource));
        ChannelModel->item(row,1)->setTextAlignment(Qt::AlignCenter);

        channel_data = ChannelTab.channel[row].ControlType;
        if(channel_data < channelControlTypeStrList.size())
            channeldataStr = channelControlTypeStrList.at(channel_data);
        ChannelModel->setData(ChannelModel->index(row, 2), QVariant(channeldataStr));
        ChannelModel->item(row,2)->setTextAlignment(Qt::AlignCenter);

        channel_data = ChannelTab.channel[row].Flash;
        temp_var = 0x02;
        for(quint8 i=0;i<3;i++)
        {
            if(channel_data & temp_var)
                channeldataStr = channelFlashStrList.at(i);
            temp_var <<= 0x01;
        }
        ChannelModel->setData(ChannelModel->index(row, 3), QVariant(channeldataStr));
        ChannelModel->item(row,3)->setTextAlignment(Qt::AlignCenter);

        channel_data = ChannelTab.channel[row].Dim;
        temp_var = 0x01;
        for(quint8 i=0;i<4;i++)
        {
            if(channel_data & temp_var)
                channeldataStr = channelDimStrList.at(i);
            temp_var <<= 0x01;
        }
        ChannelModel->setData(ChannelModel->index(row, 4), QVariant(channeldataStr));
        ChannelModel->item(row,4)->setTextAlignment(Qt::AlignCenter);

        channel_data = ChannelTab.channel[row].Position;
        if(channel_data<channelPositionStrList.size())
            channeldataStr = channelPositionStrList.at(channel_data);
        ChannelModel->setData(ChannelModel->index(row, 5), QVariant(channeldataStr));
        ChannelModel->item(row,5)->setTextAlignment(Qt::AlignCenter);

        channel_data = ChannelTab.channel[row].Direction;
        if(channel_data<channelDirectionStrList.size())
            channeldataStr = channelDirectionStrList.at(channel_data);
        ChannelModel->setData(ChannelModel->index(row, 6), QVariant(channeldataStr));
        ChannelModel->item(row,6)->setTextAlignment(Qt::AlignCenter);

        channel_data = ChannelTab.channel[row].CountdownID;
        if(channel_data & 0x80)
        {
            channeldataStr = tr("启用%1").arg(channel_data & 0x7f);
        }
        else
        {
            channeldataStr = tr("未启用");
        }
        ChannelModel->setData(ChannelModel->index(row, 7), QVariant(channeldataStr));
        ChannelModel->item(row,7)->setTextAlignment(Qt::AlignCenter);
    }
}
/********************************************************************************************/
void main_dialog::VehdetDataInit(void)
{
    memset(&VehdetTab.vehdet[0].Num, 0x00, sizeof(VehdetTab));
}
void main_dialog::PeddetDataInit(void)
{
    memset(&PeddetTab.Maximum, 0x00, sizeof(PeddetTab));
    PeddetTab.Maximum = PeddetMax;
    memset(&PeddetStateTab.peddet[0].Valid, 0x00, sizeof(PeddetStateTab));
    PeddetStateTab.Maximum = PeddetMax;
}
void main_dialog::PreemptDataInit(void)
{

}

/********************************************************************************************/
//发送设置的参数数据到对话框当中
void main_dialog::SendEditSchedule(void)
{
    qDebug()<<"SendEdit_Schedule";
    int selectRow = ui->tableSchedule->currentIndex().row();
    emit ScheduleDataSet(ScheduleTab.schedule[selectRow]);

    schedule_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    schedule_dlg->setFixedSize(469,466);
    schedule_dlg->setModal(true);//设置当前窗口为模态对话框
    schedule_dlg->show();
}
void main_dialog::SendEditPlan(void)
{
    qDebug()<<"SendEdit_Plan";
    int PlanIndex = ui->comboBox_dayPlanNumber->currentIndex();
    int selectRow = ui->tablePlan->currentIndex().row();
    emit PlanDataSet(PlanTab.Plan[PlanIndex].Period[selectRow]);

    plan_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    plan_dlg->setFixedSize(250,180);
    plan_dlg->setModal(true);//设置当前窗口为模态对话框
    plan_dlg->show();
}
void main_dialog::SendEditAction(void)
{
    qDebug()<<"SendEdit_Action";
    int selectRow = ui->tableAction->currentIndex().row();
    emit ActionDataSet(ActionTab.Action[selectRow]);

    action_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    action_dlg->setFixedSize(430,340);
    action_dlg->setModal(true);//设置当前窗口为模态对话框
    action_dlg->show();
}
void main_dialog::SendEditPattern(void)
{
    qDebug()<<"Send Pattern";
    quint8 selectRow = ui->tablePattern->currentIndex().row();
    emit PatternDataSet(PatternTab.Pattern[selectRow]);

    pattern_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    pattern_dlg->setFixedSize(330,240);
    pattern_dlg->setModal(true);//设置当前窗口为模态对话框
    pattern_dlg->show();//
}

void main_dialog::SendEditSplit(void)
{
    qDebug()<<"Send Split";
    int SplitNum = ui->comboBox_SplitNumber->currentIndex();
    int selectRow = ui->tableSplit->currentIndex().row();
    emit SplitDataSet(SplitTab.Split[SplitNum].Phase[selectRow]);

    split_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    split_dlg->setFixedSize(460,240);
    split_dlg->setModal(true);//设置当前窗口为模态对话框
    split_dlg->show();
}

void main_dialog::SendEditSequence(void)
{
    qDebug()<<"Send Sequence";
    int SequenceNum = ui->comboBox_sequenceNumber->currentIndex();
    int selectRow = ui->tableSequence->currentIndex().row();
    emit SequenceDataSet(SeqTab.Seq[SequenceNum].Ring[selectRow]);

    sequence_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    sequence_dlg->setFixedSize(237,400);
    sequence_dlg->setModal(true);//设置当前窗口为模态对话框
    sequence_dlg->show();
}

void main_dialog::SendEditPhase(void)
{
    qDebug()<<"Send Phase";

    quint8 selectRow = ui->tablePhase->currentIndex().row();

    Phase phase = PhaseTab.phase[selectRow];
    if(phase.Number == 0)
    {
        for(quint8 row = 0; row < PhaseTab.Maximum - 1; row++)
        {
            if(PhaseTab.phase[row+1].Number == 0 || PhaseTab.phase[row+1].Number > PhaseTab.phase[row].Number + 1)
            {
                phase.Number = PhaseTab.phase[row].Number + 1;
                break;
            }
        }
    }
    emit PhaseDataSet(phase);

    phase_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    phase_dlg->setFixedSize(800,680);
    phase_dlg->setModal(true);//设置当前窗口为模态对话框
    phase_dlg->show();
}

void main_dialog::SendEditChannel(void)
{
    qDebug()<<"Send Channel";
    quint8 selectRow = ui->tableChannel->currentIndex().row();
    if(selectRow >= ChannelMax) selectRow = 0;

    emit ChannelDataSet(ChannelTab.channel[selectRow]);
    channel_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    channel_dlg->setFixedSize(430,500);
    channel_dlg->setModal(true);//设置当前窗口为模态对话框
    channel_dlg->show();
    //channel_dlg->activateWindow();
    //channel_dlg->raise();
}

void main_dialog::manual_unselect(void)
{
    qDebug()<<"not appoint pressed()";
    ui->checkBox_east->setChecked(false);
    ui->checkBox_south->setChecked(false);
    ui->checkBox_north->setChecked(false);
    ui->checkBox_west->setChecked(false);

    ui->checkBox_left->setChecked(false);
    ui->checkBox_straight->setChecked(false);
    ui->checkBox_right->setChecked(false);
    ui->checkBox_pedestrian->setChecked(false);
}

void main_dialog::SendEditOverlap(void)
{
    qDebug()<<"Send Overlap";
    quint8 selectRow = ui->tableOverlap->currentIndex().row();
    emit OverlapDataSet(OverlapTab.Overlap[selectRow]);

    overlap_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    overlap_dlg->setFixedSize(400,380);
    overlap_dlg->setModal(true);//设置当前窗口为模态对话框
    overlap_dlg->show();
}

void main_dialog::on_pushButton_VehdetDelete_clicked()
{
    quint8 selectRow = ui->tableVehdet->currentIndex().row();
    bool ok;
    quint8 selectVehdet = VehdetModel->data(VehdetModel->index(selectRow,0)).toInt(&ok);
    if(ok == true)
    {
        qDebug() << "selectVehdet" << selectVehdet;
        memset(&VehdetTab.vehdet[selectVehdet-1],0,sizeof(Vehdet));

        tableVehdetShowData();
        ui->tableVehdet->selectRow(selectRow);
    }
}

void main_dialog::on_pushButton_PeddetDelete_clicked()
{
    quint8 selectRow = ui->tablePeddet->currentIndex().row();
    bool ok;
    quint8 selectPeddet = PeddetModel->data(PeddetModel->index(selectRow,0)).toInt(&ok);
    if(ok == true)
    {
        qDebug() << "selectPeddet" << selectPeddet;
        memset(&PeddetTab.peddet[selectPeddet-1],0,sizeof(Peddet));

        tablePeddetShowData();
        ui->tablePeddet->selectRow(selectRow);
    }
}

void main_dialog::SendEditPeddet(void)
{
    qDebug()<<"Send Peddet";
    quint8 selectRow = ui->tablePeddet->currentIndex().row();
    bool ok;
    quint8 selectPeddet = PeddetModel->data(PeddetModel->index(selectRow,0)).toInt(&ok);
    if(ok == true)
    {
        qDebug() << "selectPeddet" << selectPeddet;
        emit PeddetDataSet(PeddetTab.peddet[selectPeddet-1]);
    }
    else
    {
        qDebug() << "selectRow" << selectRow;
        Peddet peddet;
        quint8 i = 0;
        for(i = 0; i <= 31; i++)
        {
            if(PeddetTab.peddet[i].Num == 0)
            {
                break;
            }
        }
        peddet = PeddetTab.peddet[i];
        peddet.Num = i+1;

        emit PeddetDataSet(peddet);
    }
    peddet_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    peddet_dlg->setFixedSize(460,220);
    peddet_dlg->setModal(true);//设置当前窗口为模态对话框
    peddet_dlg->show();
}

void main_dialog::SendEditVehdet(void)
{
    qDebug()<<"Send Vehdet";
    quint8 selectRow = ui->tableVehdet->currentIndex().row();
    bool ok;
    quint8 selectVehdet = VehdetModel->data(VehdetModel->index(selectRow,0)).toInt(&ok);
    if(ok == true)
    {
        qDebug() << "selectPeddet" << selectVehdet;
        emit VehdetDataSet(VehdetTab.vehdet[selectVehdet-1]);
    }
    else
    {
        qDebug() << "selectRow" << selectRow;
        Vehdet vehdet;
        quint8 i = 0;
        for(i = 0; i <= 31; i++)
        {
            if(VehdetTab.vehdet[i].Num == 0)
            {
                break;
            }
        }
        vehdet = VehdetTab.vehdet[i];
        vehdet.Num = i+1;
        emit VehdetDataSet(vehdet);
    }
    vehdet_dlg->setWindowFlags(windowFlags()&~(Qt::CustomizeWindowHint|Qt::WindowContextHelpButtonHint | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint));
    vehdet_dlg->setFixedSize(460,460);
    vehdet_dlg->setModal(true);//设置当前窗口为模态对话框
    vehdet_dlg->show();
}
/*************************************************************************/
//接收参数的槽函数
void main_dialog::ScheduleDataReceive(Schedule schedule)
{
    qDebug()<<"Receive Schedule";
    if(schedule.Number == 0)return;
    for(quint8 row = 0; row < ScheduleTab.Maximum; row++)
    {
        quint8 ScheduleNum = ScheduleTab.schedule[row].Number;
        //列表中已有该调度计划就重新赋值该调度计划
        if(ScheduleNum == schedule.Number)
        {
            ScheduleTab.schedule[row] = schedule;
            ui->tableSchedule->selectRow(row);
            break;
        }
        //动作表中无该调度计划,就重新排序，插入新的调度计划
        else if(ScheduleNum == 0)
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    if(schedule.Number > ScheduleTab.schedule[i-1].Number)
                    {
                        ScheduleTab.schedule[i] = schedule;
                        ui->tableSchedule->selectRow(i);
                        break;
                    }
                    else
                    {
                        ScheduleTab.schedule[i] = ScheduleTab.schedule[i-1];
                    }
                }
                else
                {
                    ScheduleTab.schedule[i] = schedule;
                    ui->tableSchedule->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    tableScheduleShowData();
}
void main_dialog::PlanDataReceive(Plan plan)
{
    quint8 PlanIndex = ui->comboBox_dayPlanNumber->currentIndex();
    quint8 selectRow = ui->tablePlan->currentIndex().row();
    quint16 setMinute = plan.Time.Hour*60 + plan.Time.Minute;
    qDebug()<<"Receive Plan";
    //判断plan EventNum是否为0，不为零就删除之后再插入，为0就直接插入！！！
    if(plan.EventNum != 0)
    {
        quint8 n;
        for(n = selectRow; n < PeriodMax - 1; n++)
        {
            if(PlanTab.Plan[PlanIndex].Period[n+1].EventNum > 0)
            {
                PlanTab.Plan[PlanIndex].Period[n] = PlanTab.Plan[PlanIndex].Period[n+1];
                PlanTab.Plan[PlanIndex].Period[n].EventNum = n+1;
            }
            else break;
        }
        memset(&PlanTab.Plan[PlanIndex].Period[n],0,sizeof(Plan));
    }

    for(quint8 row = 0; row < PeriodMax; row++)
    {
        quint16 planMinute = PlanTab.Plan[PlanIndex].Period[row].Time.Hour*60 + PlanTab.Plan[PlanIndex].Period[row].Time.Minute;
        //列表中已有该时段就重新赋值该时段
        if(PlanTab.Plan[PlanIndex].Period[row].EventNum > 0)
        {
            if(setMinute == planMinute)
            {
                PlanTab.Plan[PlanIndex].Period[row] = plan;
                PlanTab.Plan[PlanIndex].Period[row].EventNum = row+1;
                PlanTab.Plan[PlanIndex].Num = PlanIndex + 1;
                ui->tablePlan->selectRow(row);
                break;
            }
        }
        //时段表中无该时段,就重新排序，插入新的时段
        else
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    planMinute = PlanTab.Plan[PlanIndex].Period[i-1].Time.Hour*60 + PlanTab.Plan[PlanIndex].Period[i-1].Time.Minute;
                    if(setMinute > planMinute)
                    {
                        PlanTab.Plan[PlanIndex].Period[i] = plan;
                        PlanTab.Plan[PlanIndex].Period[i].EventNum = i+1;
                        PlanTab.Plan[PlanIndex].Num = PlanIndex + 1;
                        ui->tablePlan->selectRow(i);
                        break;
                    }
                    else
                    {
                        PlanTab.Plan[PlanIndex].Period[i] = PlanTab.Plan[PlanIndex].Period[i-1];
                        PlanTab.Plan[PlanIndex].Period[i].EventNum = i+1;
                    }
                }
                else
                {
                    PlanTab.Plan[PlanIndex].Period[i] = plan;
                    PlanTab.Plan[PlanIndex].Period[i].EventNum = i+1;
                    PlanTab.Plan[PlanIndex].Num = PlanIndex + 1;
                    ui->tablePlan->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    tablePlanShowData(PlanIndex);
}

void main_dialog::ActionDataReceive(ActionType action)
{
    qDebug()<<"Receive Action";
    if(action.Num == 0)return;
    for(quint8 row = 0; row < ActionTab.Maximum; row++)
    {
        quint8 ActionNum = ActionTab.Action[row].Num;
        //列表中已有该动作就重新赋值该动作
        if(ActionNum == action.Num)
        {
            ActionTab.Action[row] = action;
            ui->tableAction->selectRow(row);
            break;
        }
        //动作表中无该动作,就重新排序，插入新的动作
        else if(ActionNum == 0)
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    if(action.Num > ActionTab.Action[i-1].Num)
                    {
                        ActionTab.Action[i] = action;
                        ui->tableAction->selectRow(i);
                        break;
                    }
                    else
                    {
                        ActionTab.Action[i] = ActionTab.Action[i-1];
                    }
                }
                else
                {
                    ActionTab.Action[i] = action;
                    ui->tableAction->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    tableActionShowData();
}

void main_dialog::CalcPatternCycleTime(void)
{
    for(quint8 x = 0; x < PatternMax; x++)
    {
        if(PatternTab.Pattern[x].Number > 0)
        {
            quint16 CycleTimeMax = 0;
            quint16 CycleTime[4] = {0};
            quint8 SequenceNum = PatternTab.Pattern[x].SequenceNumber;
            quint8 SplitNum = PatternTab.Pattern[x].SplitNumber;

            for(quint8 r = 0; r < RingMax; r++)
            {
                for(quint8 n = 0; n < PhaseMax; n++)
                {
                    quint8 PhaseNum = SeqTab.Seq[SequenceNum - 1].Ring[r].Phase[n];
                    if(PhaseNum > 0)
                    {
                        for(quint8 i = 0; i < PhaseMax; i++)
                        {
                            if(PhaseNum == SplitTab.Split[SplitNum-1].Phase[i].Phase)
                            {
                                quint8 SplitTime = SplitTab.Split[SplitNum-1].Phase[i].Time;
                                CycleTime[r] += SplitTime;
                                break;
                            }
                        }
                    }
                    else
                        break;
                }
                if(CycleTime[r] > CycleTimeMax)
                    CycleTimeMax = CycleTime[r];
            }
            PatternTab.Pattern[x].CycleTime = CycleTimeMax;
        }
    }
}

void main_dialog::PatternDataReceive(PatternType pattern)
{
    qDebug()<<"Receive Pattern";
    for(quint8 row = 0; row < PatternTab.Maximum; row++)
    {
        quint8 PatternNum = PatternTab.Pattern[row].Number;
        //列表中已有该方案就重新赋值该方案
        if(PatternNum == pattern.Number)
        {
            qDebug()<<"重新赋值该方案";
            PatternTab.Pattern[row] = pattern;
            ui->tablePattern->selectRow(row);
            break;
        }
        //方案表中无该方案,就重新排序，插入新的方案
        else if(PatternNum == 0)
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    if(pattern.Number > PatternTab.Pattern[i-1].Number)
                    {
                        qDebug()<<"插入新的方案";
                        PatternTab.Pattern[i] = pattern;
                        ui->tablePattern->selectRow(i);
                        break;
                    }
                    else
                    {
                        qDebug()<<"下移方案";
                        PatternTab.Pattern[i] = PatternTab.Pattern[i-1];
                    }
                }
                else
                {
                    qDebug()<<"表第一项插入新的方案";
                    PatternTab.Pattern[i] = pattern;
                    ui->tablePattern->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    //重新计算方案的周期时间
    CalcPatternCycleTime();
    tablePatternShowData();
}
void main_dialog::SplitDataReceive(Split split)
{
    qDebug()<<"Receive Split";
    if(split.Phase == 0)return;
    quint8 SplitIndex = ui->comboBox_SplitNumber->currentIndex();

    SplitTab.Split[SplitIndex].Num = SplitIndex+1;
    for(quint8 row = 0; row < PhaseMax; row++)
    {
        quint8 PhaseNum = SplitTab.Split[SplitIndex].Phase[row].Phase;
        //绿信比表中已有该相位就重新赋值该相位
        if(PhaseNum == split.Phase)
        {
            SplitTab.Split[SplitIndex].Phase[row] = split;
            ui->tableSplit->selectRow(row);
            break;
        }
        //绿信比中无该绿信比,就重新排序，插入新的绿信比
        else if(PhaseNum == 0)
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    if(split.Phase > SplitTab.Split[SplitIndex].Phase[i-1].Phase)
                    {
                        SplitTab.Split[SplitIndex].Phase[i] = split;
                        ui->tableSplit->selectRow(i);
                        break;
                    }
                    else
                        SplitTab.Split[SplitIndex].Phase[i] = SplitTab.Split[SplitIndex].Phase[i-1];
                }
                else
                {
                    SplitTab.Split[SplitIndex].Phase[i] = split;
                    ui->tableSplit->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    //重新计算方案的周期时间
    CalcPatternCycleTime();
    tableSplitShowData(SplitIndex);
    tablePatternShowData();
}
void main_dialog::SequenceDataReceive(SequenceType sequence)
{
    qDebug()<<"Receive Sequence";
    quint8 SeqIndex = ui->comboBox_sequenceNumber->currentIndex();
    for(quint8 row = 0; row < RingMax; row++)
    {
        if(SeqTab.Seq[SeqIndex].Ring[row].RingNum == sequence.RingNum)
        {
            SeqTab.Seq[SeqIndex].Num = SeqIndex+1;
            bool ringEmpty = true;
            for(quint8 n = 0; n<16; n++)
            {
                if(sequence.Phase[n] > 0)ringEmpty = false;
            }
            if(ringEmpty == true)
            {
                sequence.RingNum = 0;
                qDebug()<<"ringEmpty";
            }
            SeqTab.Seq[SeqIndex].Ring[row] = sequence;
            break;
        }
        else if(SeqTab.Seq[SeqIndex].Ring[row].RingNum == 0)
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    if(sequence.RingNum > SeqTab.Seq[SeqIndex].Ring[i-1].RingNum)
                    {
                        SeqTab.Seq[SeqIndex].Num = SeqIndex+1;
                        bool ringEmpty = true;
                        for(quint8 n = 0; n<16; n++)
                        {
                            if(sequence.Phase[n] > 0)ringEmpty = false;
                        }
                        if(ringEmpty == true)
                        {
                            sequence.RingNum = 0;
                            qDebug()<<"ringEmpty";
                        }
                        SeqTab.Seq[SeqIndex].Ring[i] = sequence;
                        ui->tableSequence->selectRow(i);
                        break;
                    }
                    else
                    {
                        SeqTab.Seq[SeqIndex].Ring[i] = SeqTab.Seq[SeqIndex].Ring[i-1];
                    }
                }
                else
                {
                    SeqTab.Seq[SeqIndex].Num = SeqIndex+1;
                    bool ringEmpty = true;
                    for(quint8 n = 0; n<16; n++)
                    {
                        if(sequence.Phase[n] > 0)ringEmpty = false;
                    }
                    if(ringEmpty == true)
                    {
                        sequence.RingNum = 0;
                        qDebug()<<"ringEmpty";
                    }
                    SeqTab.Seq[SeqIndex].Ring[i] = sequence;
                    ui->tableSequence->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    //重新计算方案的周期时间
    CalcPatternCycleTime();
    tableSequenceShowData(SeqIndex);
    tablePatternShowData();
}
void main_dialog::PhaseDataReceive(Phase phase)
{
    qDebug()<<"Receive Phase";
    if(phase.Number == 0)return;
    for(quint8 row = 0; row < PhaseTab.Maximum; row++)
    {
        quint8 phaseNum = PhaseTab.phase[row].Number;
        //列表中已有该相位就重新赋值该相位
        if(phaseNum == phase.Number)
        {
            PhaseTab.phase[row] = phase;
            ui->tablePhase->selectRow(row);
            break;
        }
        //动作表中无该动作,就重新排序，插入新的动作
        else if(phaseNum == 0)
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    if(phase.Number > PhaseTab.phase[i-1].Number)
                    {
                        PhaseTab.phase[i] = phase;
                        ui->tablePhase->selectRow(i);
                        break;
                    }
                    else
                    {
                        PhaseTab.phase[i] = PhaseTab.phase[i-1];
                    }
                }
                else
                {
                    PhaseTab.phase[i] = phase;
                    ui->tablePhase->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    tablePhaseShowData();
}
void main_dialog::ChannelDataReceive(Channel channel)
{
    quint8 ChannelIndex = channel.Num - 1;

    ChannelTab.channel[ChannelIndex] = channel;
    //memcpy(&ChannelTab.channel[ChannelIndex], &channel, sizeof(Channel));
    //tableChannelShowData();

    quint8 tableRow,temp_var;
    tableRow = channel.Num-1;
    QString channelControlTypeStr, channelFlashStr, channelDimStr,channePositionStr, channelDirectionStr, channelCountdownIDStr;

    channelControlTypeStr = channelControlTypeStrList.at(channel.ControlType);
    temp_var = 0x02;
    for(quint8 i=0;i<3;i++)
    {
        if(channel.Flash & temp_var)
            channelFlashStr = channelFlashStrList.at(i);
        temp_var <<= 0x01;
    }
    temp_var = 0x01;
    for(quint8 i=0;i<4;i++)
    {
        if(channel.Dim & temp_var)
            channelDimStr = channelDimStrList.at(i);
        temp_var <<= 0x01;
    }

    channePositionStr = channelPositionStrList.at(channel.Position);
    channelDirectionStr = channelDirectionStrList.at(channel.Direction);

    if(channel.CountdownID & 0x80)
    {
        channelCountdownIDStr = tr("启用%1").arg(channel.CountdownID & 0x7f);
    }
    else
    {
        channelCountdownIDStr = tr("未启用");
    }

    ChannelModel->setData(ChannelModel->index(tableRow,0),QVariant(channel.Num));
    ChannelModel->setData(ChannelModel->index(tableRow,1),QVariant(channel.ControlSource));
    ChannelModel->setData(ChannelModel->index(tableRow,2),QVariant(channelControlTypeStr));
    ChannelModel->setData(ChannelModel->index(tableRow,3),QVariant(channelFlashStr));
    ChannelModel->setData(ChannelModel->index(tableRow,4),QVariant(channelDimStr));
    ChannelModel->setData(ChannelModel->index(tableRow,5),QVariant(channePositionStr));
    ChannelModel->setData(ChannelModel->index(tableRow,6),QVariant(channelDirectionStr));
    ChannelModel->setData(ChannelModel->index(tableRow,7),QVariant(channelCountdownIDStr));
}

void main_dialog::PeddetDataReceive(Peddet peddet)
{
    qDebug() << "Receive Peddet";
    if(peddet.Num == 0)return;
    quint8 selectRow = ui->tablePeddet->currentIndex().row();
    PeddetTab.peddet[peddet.Num - 1] = peddet;

    tablePeddetShowData();
    ui->tablePeddet->selectRow(selectRow);
}

void main_dialog::VehdetDataReceive(Vehdet vehdet)
{
    qDebug() << "Receive Vehdet";
    if(vehdet.Num == 0)return;
    quint8 selectRow = ui->tableVehdet->currentIndex().row();
    VehdetTab.vehdet[vehdet.Num - 1] = vehdet;

    tableVehdetShowData();
    ui->tableVehdet->selectRow(selectRow);
}

void main_dialog::OverlapDataReceive(OverlapType Overlap)
{
    qDebug() << "Receive Overlap";
    if(Overlap.Num == 0)return;
    for(quint8 row = 0; row < OverlapTab.Maximum; row++)
    {
        quint8 OverlapNum = OverlapTab.Overlap[row].Num;
        //列表中已有该Overlap就重新赋值该Overlap
        if(OverlapNum == Overlap.Num)
        {
            OverlapTab.Overlap[row] = Overlap;
            ui->tableOverlap->selectRow(row);
            break;
        }
        //列表中无该Overlap,就重新排序，插入新的Overlap
        else if(OverlapNum == 0)
        {
            for(qint8 i = row; i >= 0; i--)
            {
                if(i > 0)
                {
                    if(Overlap.Num > OverlapTab.Overlap[i-1].Num)
                    {
                        OverlapTab.Overlap[i] = Overlap;
                        ui->tableOverlap->selectRow(i);
                        break;
                    }
                    else
                    {
                        OverlapTab.Overlap[i] = OverlapTab.Overlap[i-1];
                    }
                }
                else
                {
                    OverlapTab.Overlap[i] = Overlap;
                    ui->tableOverlap->selectRow(i);
                    break;
                }
            }
            break;
        }
    }
    tableOverlapShowData();
}

void main_dialog::on_pushButton_OverlapDelete_clicked()
{
    quint8 Row = ui->tableOverlap->currentIndex().row();
    quint8 row;
    for(row = Row; row < OverlapTab.Maximum - 1; row++)
    {
        if(OverlapTab.Overlap[row+1].Num > 0)
        {
            OverlapTab.Overlap[row] = OverlapTab.Overlap[row+1];
        }
        else break;
    }
    memset(&OverlapTab.Overlap[row],0,sizeof(OverlapType));
    ui->tableOverlap->selectRow(Row);
    tableOverlapShowData();
}

void main_dialog::on_pushButton_OverlapCopy_clicked()
{
    quint8 selectRow = ui->tableOverlap->currentIndex().row();
    OverlapType overlap =  OverlapTab.Overlap[selectRow];
    //计算复制到的最小的空动作号
    quint8 overlapNum = 0;
    for(quint8 row = 0; row < OverlapTab.Maximum - 1; row++)
    {
        if(OverlapTab.Overlap[row+1].Num == 0 || OverlapTab.Overlap[row+1].Num > OverlapTab.Overlap[row].Num + 1)
        {
            overlapNum = OverlapTab.Overlap[row].Num + 1;
            break;
        }
    }

    bool isOK;
    overlap.Num = QInputDialog::getInt(this, tr("跟随相位%1复制").arg(overlap.Num),tr("复制到："), overlapNum, 1, OverlapTab.Maximum, 1,&isOK, windowFlags()&~(Qt::WindowContextHelpButtonHint));
    if(isOK)
    {
        OverlapDataReceive(overlap);
    }
}

/*************************************************************************/
void main_dialog::on_pushButton_PeriodDelete_clicked()
{
    quint8 PlanIndex = ui->comboBox_dayPlanNumber->currentIndex();
    quint8 selectRow = ui->tablePlan->currentIndex().row();
    if(PlanTab.Plan[PlanIndex].Period[selectRow].EventNum > 0)
    {
        quint8 n;
        for(n = selectRow; n < PeriodMax - 1; n++)
        {
            if(PlanTab.Plan[PlanIndex].Period[n+1].EventNum > 0)
            {
                PlanTab.Plan[PlanIndex].Period[n] = PlanTab.Plan[PlanIndex].Period[n+1];
                PlanTab.Plan[PlanIndex].Period[n].EventNum = n+1;
            }
            else break;
        }
        memset(&PlanTab.Plan[PlanIndex].Period[n],0,sizeof(Plan));
    }
    tablePlanShowData(PlanIndex);
}
void main_dialog::on_pushButton_ScheduleDelete_clicked()
{
    quint8 Row = ui->tableSchedule->currentIndex().row();
    quint8 row;
    for(row = Row; row < ScheduleTab.Maximum - 1; row++)
    {
        if(ScheduleTab.schedule[row+1].Number > 0)
        {
            ScheduleTab.schedule[row] = ScheduleTab.schedule[row+1];
        }
        else break;
    }
    memset(&ScheduleTab.schedule[row],0,sizeof(Schedule));
    ui->tableSchedule->selectRow(Row);
    tableScheduleShowData();
}

void main_dialog::on_pushButton_ActionDelete_clicked()
{
    quint8 Row = ui->tableAction->currentIndex().row();
    quint8 row;
    for(row = Row; row < ActionTab.Maximum - 1; row++)
    {
        if(ActionTab.Action[row+1].Num > 0)
        {
            ActionTab.Action[row] = ActionTab.Action[row+1];
        }
        else break;
    }
    memset(&ActionTab.Action[row],0,sizeof(ActionType));
    ui->tableAction->selectRow(Row);
    tableActionShowData();
}

void main_dialog::tableActionSelectChange(void)
{
    quint8 selectRow = ui->tableAction->currentIndex().row();
    if(ActionModel->data(ActionModel->index(selectRow,0)).isNull())
    {
        ui->pushButton_ActionCopy->setEnabled(false);
        ui->pushButton_ActionDelete->setEnabled(false);
    }
    else
    {
        ui->pushButton_ActionCopy->setEnabled(true);
        ui->pushButton_ActionDelete->setEnabled(true);
    }
}

/*************************************************************************/
void main_dialog::on_pushButton_SplitDelRow_clicked()
{
    quint8 SplitIndex = ui->comboBox_SplitNumber->currentIndex();
    quint8 row = ui->tableSplit->currentIndex().row();
    quint8 i = 0;
    for(i = row; i < PhaseMax-1; i++)
    {
        quint8 Phase1 = SplitTab.Split[SplitIndex].Phase[i+1].Phase;
        if(Phase1 > 0)
            memcpy(&SplitTab.Split[SplitIndex].Phase[i].Phase, &SplitTab.Split[SplitIndex].Phase[i+1].Phase, 4);
        else break;
    }
    memset(&SplitTab.Split[SplitIndex].Phase[i],0,sizeof(Split));
    CalcPatternCycleTime();
    tableSplitShowData(SplitIndex);
    tablePatternShowData();
}
void main_dialog::on_pbPhase_delete_clicked()
{
    quint8 selectRow = ui->tablePhase->currentIndex().row();

    quint8 i = 0;
    for(i = selectRow; i < PhaseMax-1; i++)
    {
        quint8 PhaseNum = PhaseTab.phase[i].Number;
        if(PhaseNum > 0)
            memcpy(&PhaseTab.phase[i], &PhaseTab.phase[i+1], sizeof(Phase));
        else break;
    }
    memset(&PhaseTab.phase[i],0x00,sizeof(Phase));

    tablePhaseShowData();
}

void main_dialog::tablePatternSelectChange(void)
{
    quint8 selectRow = ui->tablePattern->currentIndex().row();
    if(PatternModel->data(PatternModel->index(selectRow,0)).isNull())
    {
        ui->pbPattern_copy->setEnabled(false);
        ui->pbPattern_delete->setEnabled(false);
    }
    else
    {
        ui->pbPattern_copy->setEnabled(true);
        ui->pbPattern_delete->setEnabled(true);
    }
}
void main_dialog::tablePhaseSelectChange(QModelIndex index)
{
    quint8 selectRow = index.row();
    if(PhaseModel->data(PhaseModel->index(selectRow,0)).isNull())
    {
        ui->pbPhase_copy->setEnabled(false);
        ui->pbPhase_delete->setEnabled(false);
    }
    else
    {
        ui->pbPhase_copy->setEnabled(true);
        ui->pbPhase_delete->setEnabled(true);
    }
}

void main_dialog::on_pbPattern_delete_clicked()
{
    quint8 row;
    quint8 selectRow = ui->tablePattern->currentIndex().row();

    for(row = selectRow; row < PatternTab.Maximum - 1; row++)
    {
        if(PatternTab.Pattern[row+1].Number > 0)
        {
            PatternTab.Pattern[row] = PatternTab.Pattern[row+1];
        }
        else break;
    }
    memset(&PatternTab.Pattern[row],0,sizeof(PatternType));
    ui->tablePattern->selectRow(selectRow);
    tablePatternShowData();
}

void main_dialog::on_pushButton_ActionCopy_clicked()
{
    quint8 selectRow = ui->tableAction->currentIndex().row();
    ActionType action =  ActionTab.Action[selectRow];
    //计算复制到的最小的空动作号
    quint8 actionNum = 0;
    for(quint8 row = 0; row < ActionTab.Maximum - 1; row++)
    {
        if(ActionTab.Action[row+1].Num == 0 || ActionTab.Action[row+1].Num > ActionTab.Action[row].Num + 1)
        {
            actionNum = ActionTab.Action[row].Num + 1;
            break;
        }
    }

    bool isOK;
    action.Num = QInputDialog::getInt(this, tr("动作%1复制").arg(action.Num),tr("复制到方案："), actionNum, 1, ActionTab.Maximum, 1,&isOK, windowFlags()&~(Qt::WindowContextHelpButtonHint));
    if(isOK)
    {
        ActionDataReceive(action);
    }
}

void main_dialog::on_pbPattern_copy_clicked()
{
    quint8 selectRow = ui->tablePattern->currentIndex().row();
    PatternType pattern =  PatternTab.Pattern[selectRow];

    quint8 patternNum = 0;
    for(quint8 row = 0; row < PatternTab.Maximum - 1; row++)
    {
        if(PatternTab.Pattern[row+1].Number == 0 || PatternTab.Pattern[row+1].Number > PatternTab.Pattern[row].Number + 1)
        {
            patternNum = PatternTab.Pattern[row].Number + 1;
            break;
        }
    }

    //static int getInt(QWidget *parent, const QString &title, const QString &label, int value = 0,
    //                  int minValue = -2147483647, int maxValue = 2147483647,
    //                  int step = 1, bool *ok = 0, Qt::WindowFlags flags = 0);
    bool isOK;
    pattern.Number = QInputDialog::getInt(this, tr("方案%1复制").arg(pattern.Number),tr("复制到方案："), patternNum, 1, PatternTab.Maximum, 1,&isOK, windowFlags()&~(Qt::WindowContextHelpButtonHint));

    if(isOK)
    {
        PatternDataReceive(pattern);
    }
}

void main_dialog::on_pbPhase_copy_clicked()
{
    quint8 selectRow = ui->tablePhase->currentIndex().row();
    Phase phase =  PhaseTab.phase[selectRow];

    quint8 phaseNum = 0;
    for(quint8 row = 0; row < PhaseTab.Maximum - 1; row++)
    {
        if(PhaseTab.phase[row+1].Number == 0 || PhaseTab.phase[row+1].Number > PhaseTab.phase[row].Number + 1)
        {
            phaseNum = PhaseTab.phase[row].Number + 1;
            break;
        }
    }

    bool isOK;
    phase.Number = QInputDialog::getInt(this, tr("相位%1复制").arg(phase.Number),tr("复制到相位："), phaseNum, 1, PhaseTab.Maximum, 1,&isOK);

    if(isOK)
    {
        PhaseDataReceive(phase);
    }
}


void main_dialog::on_pushButton_Save_clicked()
{
    SaveDatabase();
}

/*************************************************************************/
void main_dialog::on_pushButton_OpenSocket_clicked()
{
    if(ui->pushButton_OpenSocket->text()==tr("打开端口"))
    {
        udpSocket = new QUdpSocket(this);
        quint16 Port = 13536;

        while(udpSocket->bind(QHostAddress::AnyIPv4, Port)==false) Port++;

        udpcon = connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
        netOpenFlag = true;

        ui->pushButton_OpenSocket->setText(tr("关闭端口"));
        ui->pushButton_OpenSocket->setStyleSheet("background-color: rgb(80, 250, 70);");
        ui->label_LocalPort->setText(tr("Local Port:%1").arg(Port));
    }
    else if(ui->pushButton_OpenSocket->text()==tr("关闭端口"))
    {
        udpSocket->close();
        disconnect(udpcon);
        delete udpSocket;
        netOpenFlag = false;
        ui->pushButton_OpenSocket->setText(tr("打开端口"));
        ui->pushButton_OpenSocket->setStyleSheet("background-color: rgb(250, 100, 100);");
    }
}

void main_dialog::WorkState(quint8* rx_var)
{
    ui->label_Schedule->setText(tr("%1").arg(rx_var[0]));
    ui->label_plan->setText(tr("%1").arg(rx_var[1]));
    ui->label_action->setText(tr("%1").arg(rx_var[2]));

    ui->label_pattern->setText(tr("%1").arg(rx_var[3]));
    ui->label_seq->setText(tr("%1").arg(rx_var[4]));
    ui->label_split->setText(tr("%1").arg(rx_var[5]));

    if(rx_var[6] == FixedTime)
        ui->label_WorkMode->setText(tr("定周期"));
    else if(rx_var[6] == LineCtrl)
        ui->label_WorkMode->setText(tr("绿波模式"));
    else if(rx_var[6] == VehicleSense)
        ui->label_WorkMode->setText(tr("感应模式"));
    else if(rx_var[6] == Flashing)
        ui->label_WorkMode->setText(tr("黄闪模式"));
    else if(rx_var[6] == AllRed)
        ui->label_WorkMode->setText(tr("全红模式"));
    else if(rx_var[6] == LampOff)
        ui->label_WorkMode->setText(tr("关灯模式"));
    else if(rx_var[6] == ManualAppoint)
        ui->label_WorkMode->setText(tr("指定放行模式"));
    else if(rx_var[6] == ManualStep)
        ui->label_WorkMode->setText(tr("步进"));
    else if(rx_var[6] == ManualFlashing)
        ui->label_WorkMode->setText(tr("黄闪"));
    else if(rx_var[6] == ManualAllRead)
        ui->label_WorkMode->setText(tr("全红"));
    else if(rx_var[6] == ManualLampOff)
        ui->label_WorkMode->setText(tr("关灯"));
    else ui->label_WorkMode->setText(tr("其他模式"));

    if(rx_var[7] == WMR_Normal)
    {
        ui->label_Reason->setText(tr("正常"));
        ui->label_Detail->setText(tr("正常"));
    }
    else if(rx_var[7] == WMR_LocalManual)
    {
        ui->label_Reason->setText(tr("本地手动"));
        //ui->label_Detail->setText(tr("正常"));
        ui->label_Detail->setText(tr("剩余时间%1").arg(rx_var[8]|(rx_var[9]<<8)));
    }
    else if(rx_var[7] == WMR_RemoteManual)
    {
        ui->label_Reason->setText(tr("远程手动"));
        //ui->label_Detail->setText(tr("正常"));
        ui->label_Detail->setText(tr("剩余时间%1").arg(rx_var[8]|(rx_var[9]<<8)));
    }
    else if(rx_var[7] == WMR_RemoteGuard)
    {
        ui->label_Reason->setText(tr("移动警卫控制"));
        //ui->label_Detail->setText(tr("正常"));
        ui->label_Detail->setText(tr("剩余时间%1").arg(rx_var[8]|(rx_var[9]<<8)));
    }
    else if(rx_var[7] == WMR_RedGreenConflict)
    {
        QString StrDetail = tr("灯组");
        quint16 data = rx_var[8]|(rx_var[9]<<8);
        quint16 temp = 0x0001;
        for(quint8 i = 0; i<16; i++)
        {
            if(temp & data)
            {
                StrDetail += tr("%1").arg(i+1);break;
            }
            temp <<= 1;
        }
        StrDetail += tr("红绿同亮冲突");
        ui->label_Reason->setText(tr("红绿同亮冲突"));
        ui->label_Detail->setText(StrDetail);
    }
    else if(rx_var[7] == WMR_GreenConflict)
    {
        QString StrDetail = tr("相位");
        quint16 data = rx_var[8]|(rx_var[9]<<8);
        quint16 temp = 0x0001;
        for(quint8 i = 0; i<16; i++)
        {
            if(temp & data)
            {
                StrDetail += tr("%1").arg(i+1);break;
            }
            temp <<= 1;
        }
        StrDetail += tr("绿冲突");
        ui->label_Reason->setText(tr("绿冲突"));
        ui->label_Detail->setText(StrDetail);
    }
    else if(rx_var[7] == WMR_RedFailed)
    {
        QString StrDetail = tr("灯组");
        quint16 data = rx_var[8]|(rx_var[9]<<8);
        quint16 temp = 0x0001;
        for(quint8 i = 0; i<16; i++)
        {
            if(temp & data)
            {
                StrDetail += tr("%1").arg(i+1);break;
            }
            temp <<= 1;
        }
        StrDetail += tr("红灯失效");
        ui->label_Reason->setText(tr("红灯失效"));
        ui->label_Detail->setText(StrDetail);
    }
    else
    {
        ui->label_Reason->setText(tr("其他"));//还需详尽处理
        ui->label_Detail->setText(tr(""));
    }
    quint8 i = 10;
    //4个环的数据
    ui->label_phaseRing1->setText(tr("%1").arg(rx_var[i++]));
    ui->label_splitTimeRing1->setText(tr("%1").arg(rx_var[i++]));
    ui->label_remainTimeRing1->setText(tr("%1").arg(rx_var[i++]));

    ui->label_phaseRing2->setText(tr("%1").arg(rx_var[i++]));
    ui->label_splitTimeRing2->setText(tr("%1").arg(rx_var[i++]));
    ui->label_remainTimeRing2->setText(tr("%1").arg(rx_var[i++]));

    ui->label_phaseRing3->setText(tr("%1").arg(rx_var[i++]));
    ui->label_splitTimeRing3->setText(tr("%1").arg(rx_var[i++]));
    ui->label_remainTimeRing3->setText(tr("%1").arg(rx_var[i++]));

    ui->label_phaseRing4->setText(tr("%1").arg(rx_var[i++]));
    ui->label_splitTimeRing4->setText(tr("%1").arg(rx_var[i++]));
    ui->label_remainTimeRing4->setText(tr("%1").arg(rx_var[i++]));


    ChannelStatus.Reds = (rx_var[22]<<24)|(rx_var[23]<<16)|(rx_var[24]<<8)|rx_var[25];
    ChannelStatus.Yellows = (rx_var[26]<<24)|(rx_var[27]<<16)|(rx_var[28]<<8)|rx_var[29];
    ChannelStatus.Greens = (rx_var[30]<<24)|(rx_var[31]<<16)|(rx_var[32]<<8)|rx_var[33];
    tableSignalStateShowData();

    quint32 Reg1sCount = rx_var[34]|rx_var[35]<<8|rx_var[36]<<16|rx_var[37]<<24;
    ui->label_Reg1sCount->setText(tr("%1天%2小时%3分钟%4秒").arg(Reg1sCount/86400).arg(Reg1sCount%86400/3600).arg(Reg1sCount%3600/60).arg(Reg1sCount%60));
    DoorStateShow(rx_var[38], false);
}

void main_dialog::readPendingDatagrams()
{
    quint8 array[2048];
    QHostAddress sender;
    quint16 senderPort;
    quint16 size = udpSocket->bytesAvailable();

    if(size == 0)return;
    udpSocket->readDatagram((char *)array, size, &sender, &senderPort); //读取数据

    QString statusMsg;
    quint8 msgerror = Frame_right;
    quint16 dataEndPoint;
    quint8 CheckSumReceive,CheckSumCalc = 0;
    GBMSG_TYPE *gbmsg;
    gbmsg = (GBMSG_TYPE *)array;

    //判断数据帧结构
    if(gbmsg->Head != frame_head || gbmsg->Version != frame_ver || gbmsg->Sendid != ID_TSC || \
       gbmsg->Reciveid != ID_PC || array[size-1] != frame_tail)
    {
        msgerror = Frame_wrong;
        return;
    }

    //计算校验和
    if(array[size-3] == 0xDB && array[size-2] == 0xDC)
    {
        dataEndPoint = size-4;
        CheckSumReceive = 0xC0;
        for(quint16 i=1;i<=dataEndPoint;i++)
        {
            CheckSumCalc += array[i];
        }
    }
    else if(array[size-3] == 0xDB && array[size-2] == 0xDD)
    {
        dataEndPoint = size-4;
        CheckSumReceive = 0xDB;
        for(quint16 i=1;i<=dataEndPoint;i++)
        {
            CheckSumCalc += array[i];
        }
    }
    else
    {
        dataEndPoint = size-3;
        CheckSumReceive = array[size-2];
        for(quint16 i=1;i<=dataEndPoint;i++)
        {
            CheckSumCalc += array[i];
        }
    }
    //判断检验和是否正确
    if(CheckSumCalc != CheckSumReceive)
    {
        msgerror = CheckSum_failed;
        return;
    }
    //转义字符的还原操作
    quint16 rx_num = 0;
    for(quint16 num = 11; num <= dataEndPoint;)
    {
        if(array[num] == 0xDB && array[num+1] == 0xDC)
        {
            rx_var[rx_num++] = 0xC0;
            num += 2;
        }
        else if(array[num] == 0xDB && array[num+1] == 0xDD)
        {
            rx_var[rx_num++] = 0xDB;
            num += 2;
        }
        else
        {
            rx_var[rx_num++] = array[num];
            num ++;
        }
    }
    //判断具体指令
    if(gbmsg->DataLinkCode == DL_BasicInfo)
    {
        if(gbmsg->ObjectCode == O_CurrentTime)//时间操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询时间应答
            {
                //查询时间成功，显示时间
                if(rx_num == 7)
                {
                    quint8 second = rx_var[0]/16*10 + rx_var[0]%16;//second
                    quint8 minute = rx_var[1]/16*10 + rx_var[1]%16;//minute
                    quint8 hour = rx_var[2]/16*10 + rx_var[2]%16;//hour
                    quint8 week = rx_var[3];//week
                    quint8 date = rx_var[4]/16*10 + rx_var[4]%16;//date
                    quint8 month = rx_var[5]/16*10 + rx_var[5]%16;//month
                    quint16 year = 2000 + rx_var[6]/16*10 + rx_var[6]%16;//year

                    QString DateTimeString;
                    QDate Date(year,month,date);
                    QTime Time(hour,minute,second);

                    DateTimeString = Date.toString("yyyy-MM-dd ") + Time.toString("hh:mm:ss ") + WeekList.at(week);
                    ui->label_time->setText(DateTimeString);
                    ReadFalg |= TimePar;
                    statusMsg = tr("读取时间成功");
                    qDebug()<<tr("read Time success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置时间应答
            {
                WriteFalg |= TimePar;
                statusMsg = tr("设置时间成功");
                qDebug()<<tr("set Time success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_WorkState)
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询状态应答
            {
                statusMsg = tr("读取状态成功");
                qDebug()<<tr("read WorkState success");
            }
            else if(gbmsg->OperationType == OT_InitiativeReport)//查询状态应答
            {
                statusMsg = tr("状态上报成功");
                //qDebug()<<tr("WorkState Report success");
            }
            //查询状态成功
            if(rx_num == 39)
            {
                WorkState(rx_var);
            }
        }
        else if(gbmsg->ObjectCode == O_DeviceInfo)
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询设备信息应答
            {
                quint16 StrLen = 0;
                quint16 temp[64];
                for(quint16 i=0;i<128;)
                {
                    if(rx_var[i] != 0x00 || rx_var[i+1] != 0x00)
                    {
                        temp[StrLen++] = (rx_var[i]<<8)|rx_var[i+1];
                        i += 2;
                    }
                    else break;
                }

                QString manufacturerInfoStr;
                manufacturerInfoStr.resize(StrLen);
                for(quint16 i=0; i<StrLen; i++)
                {
                    manufacturerInfoStr[i] = QChar(temp[i]);
                }
                ui->lineEdit_ManufacturerInfo->setText(manufacturerInfoStr);

                memcpy(deviceInfoBuf, &rx_var[128], 48);
                QByteArray deviceversion;
                deviceversion.resize(4);

                for(quint8 i=0;i<4;i++)
                {
                    deviceversion[i] = rx_var[128+i];
                }
                deviceversion = deviceversion.toHex();
                ui->label_DeviceVersion->setText(deviceversion);

                QByteArray deviceNumber;
                deviceNumber.resize(16);
                for(quint8 i=0;i<16;i++)
                {
                    deviceNumber[i] = rx_var[132+i];
                }
                deviceNumber = deviceNumber.toHex();
                quint8 StrNum = deviceNumber.count();
                while(StrNum > 0)
                {
                    if(deviceNumber.at(0) == '0')
                        deviceNumber.remove(0,1);
                    else break;
                    StrNum = deviceNumber.count();
                }

                ui->lineEdit_DeviceNumber->setText(deviceNumber);

                QByteArray productionDate;
                productionDate.resize(6);
                for(quint8 i=0;i<6;i++)
                {
                    productionDate[i] = rx_var[148+i];
                }
                productionDate = productionDate.toHex();
                ui->label_ProductionDate->setText(productionDate);

                QByteArray configurationDate;
                configurationDate.resize(6);
                for(quint8 i=0;i<6;i++)
                {
                    configurationDate[i] = rx_var[154+i];
                }
                configurationDate = configurationDate.toHex();
                ui->label_ConfigurationDate->setText(configurationDate);

                ReadFalg |= DevicePar;
                statusMsg = tr("读取设备信息成功");
                qDebug()<<tr("read DeviceInfo success");
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置时间应答
            {
                //WriteFalg |= TimePar;
                statusMsg = tr("设置设备信息成功");
                qDebug()<<tr("set DeviceInfo success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_BasicInfo)
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询设备信息应答
            {
                quint16 StrLen = 0;
                quint16 temp[64];
                for(quint16 i=0;i<128;)
                {
                    if(rx_var[i] != 0x00 || rx_var[i+1] != 0x00)
                    {
                        temp[StrLen++] = (rx_var[i]<<8)|rx_var[i+1];
                        i += 2;
                    }
                    else break;
                }

                QString InterInfoStr;
                InterInfoStr.resize(StrLen);
                for(quint16 i=0; i<StrLen; i++)
                {
                    InterInfoStr[i] = QChar(temp[i]);
                }
                ui->lineEdit_IntersectionInfo->setText(InterInfoStr);

                ui->lineEdit_IP->setText(tr("%1.%2.%3.%4").arg(rx_var[128]).arg(rx_var[129]).arg(rx_var[130]).arg(rx_var[131]));
                ui->lineEdit_Mask->setText(tr("%1.%2.%3.%4").arg(rx_var[132]).arg(rx_var[133]).arg(rx_var[134]).arg(rx_var[135]));
                ui->lineEdit_Gateway->setText(tr("%1.%2.%3.%4").arg(rx_var[136]).arg(rx_var[137]).arg(rx_var[138]).arg(rx_var[139]));

                for(int i=0;i<6;i++) mac[i] = rx_var[142+i];
                QByteArray mac_addr;
                mac_addr.resize(6);
                mac_addr[0] = rx_var[142];
                mac_addr[1] = rx_var[143];
                mac_addr[2] = rx_var[144];
                mac_addr[3] = rx_var[145];
                mac_addr[4] = rx_var[146];
                mac_addr[5] = rx_var[147];
                mac_addr = mac_addr.toHex();
                mac_addr.insert(10,":");
                mac_addr.insert(8,":");
                mac_addr.insert(6,":");
                mac_addr.insert(4,":");
                mac_addr.insert(2,":");
                ui->label_MAC->setText(mac_addr);

                ui->lineEdit_ServerIP->setText(tr("%1.%2.%3.%4").arg(rx_var[148]).arg(rx_var[149]).arg(rx_var[150]).arg(rx_var[151]));
                ui->lineEdit_ServerPort->setText(tr("%1").arg((rx_var[152]<<8)|rx_var[153]));

                double TimeZone = ((rx_var[156]<<16)|(rx_var[157]<<8)|rx_var[158])/3600.0;
                qDebug() << TimeZone << rx_var[156] << rx_var[157] << rx_var[158];
                if(rx_var[155]==0) TimeZone = TimeZone*(-1);
                ui->spinBox_TimeZone->setValue(TimeZone);

                quint32 TscNum = (rx_var[159]<<24)|(rx_var[160]<<16)|(rx_var[161]<<8)|rx_var[162];
                ui->spinBox_TscNumber->setValue(TscNum);
                qDebug()<<TscNum<<rx_var[159]<<rx_var[160]<<rx_var[161]<<rx_var[162];

                ReadFalg |= BasicPar;
                statusMsg = tr("读取基础信息成功");
                qDebug()<<tr("read BasicInfo success");
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置时间应答
            {
                //WriteFalg |= TimePar;
                statusMsg = tr("设置基础信息成功");
                qDebug()<<tr("set BasicInfo success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else
        {
            msgerror = Unsupport_OB;
        }
    }
    else if(gbmsg->DataLinkCode == DL_Com)
    {
        if(gbmsg->ObjectCode == O_Call && gbmsg->OperationType == OT_QueryAnswer)//搜索操作
        {
            QByteArray string;
            string.resize(4);
            for(quint8 i=0;i<4;i++) string[i] = rx_var[i];
            string = string.toHex();
            OnLineModel->setData(OnLineModel->index(OnLineCount,0),QVariant(string));//VerStr

            string.resize(2);
            for(quint8 i=0;i<2;i++) string[i] = rx_var[5 + i];
            string = string.toHex();
            OnLineModel->setData(OnLineModel->index(OnLineCount,1),QVariant(string));

            QString senderIPStr = sender.toString();
            QString senderPortStr = tr("%1").arg(senderPort);
            OnLineModel->setData(OnLineModel->index(OnLineCount,2),QVariant(senderIPStr));
            OnLineModel->setData(OnLineModel->index(OnLineCount,3),QVariant(senderPortStr));
            OnLineModel->setData(OnLineModel->index(OnLineCount,4),QVariant(tr("%1").arg(rx_var[4])));
            OnLineCount++;
            ui->tableViewOnline->scrollToTop();
            statusMsg = tr("搜索成功");
            qDebug()<<tr("search success");
        }
    }
    else if(gbmsg->DataLinkCode == DL_CharacPar)
    {
        if(gbmsg->ObjectCode == O_Schedule)//调度计划表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 ScheduleSize = 9;
                if(ScheduleTab.Maximum == rx_var[0] && rx_num == ScheduleSize * ScheduleTab.Maximum + 1)
                {
                    for(quint16 i = 0; i < ScheduleTab.Maximum; i++)
                    {
                        quint16 readpoint = ScheduleSize * i + 1;
                        ScheduleTab.schedule[i].Number = rx_var[readpoint];
                        ScheduleTab.schedule[i].Month = rx_var[readpoint+1] | (rx_var[readpoint+2]<<8);
                        ScheduleTab.schedule[i].Day = rx_var[readpoint+3];
                        ScheduleTab.schedule[i].Date =  (quint32)rx_var[readpoint+4] | \
                                                       ((quint32)rx_var[readpoint+5]<<8) | \
                                                       ((quint32)rx_var[readpoint+6]<<16) | \
                                                       ((quint32)rx_var[readpoint+7]<<24);
                        ScheduleTab.schedule[i].DayPlan = rx_var[readpoint+8];
                    }
                    ReadFalg |= SchedulePar;
                    tableScheduleShowData();
                    statusMsg = tr("读取调度计划成功");
                    qDebug()<<tr("read Schedule success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= SchedulePar;
                statusMsg = "设置调度计划成功";
                qDebug()<<tr("set Schedule success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Plan)//时段表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 PlanSize = 73;
                if(PlanTab.Maximum == rx_var[0] && rx_num == (PlanSize * PlanTab.Maximum + 1))
                {
                    quint16 readpoint = 1;
                    for(quint16 i = 0; i < PlanTab.Maximum; i++)
                    {
                        PlanTab.Plan[i].Num = rx_var[readpoint++];
                        for(quint16 j = 0; j < PeriodMax; j++)
                        {
                            PlanTab.Plan[i].Period[j].Time.Hour = rx_var[readpoint++];
                            PlanTab.Plan[i].Period[j].Time.Minute = rx_var[readpoint++];
                            PlanTab.Plan[i].Period[j].ActionNum = rx_var[readpoint++];
                            if(PlanTab.Plan[i].Period[j].ActionNum > 0)
                                PlanTab.Plan[i].Period[j].EventNum = j+1;
                            else
                                PlanTab.Plan[i].Period[j].EventNum = 0;
                        }
                    }
                    ReadFalg |= PlanPar;
                    tablePlanShowData(ui->comboBox_dayPlanNumber->currentIndex());
                    statusMsg = tr("读取时段表成功");
                    qDebug()<<tr("read Plan success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= PlanPar;
                statusMsg = tr("设置时段表成功");
                qDebug()<<tr("set Plan success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Action)//动作表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 ActionSize = 4;
                if(ActionTab.Maximum == rx_var[0] && rx_num == ActionSize * ActionTab.Maximum + 1)
                {
                    quint16 readpoint = 1;
                    for(quint16 i = 0; i < ActionTab.Maximum; i++)
                    {
                        ActionTab.Action[i].Num = rx_var[readpoint++];
                        ActionTab.Action[i].PatternNum = rx_var[readpoint++];
                        ActionTab.Action[i].Auxillary = rx_var[readpoint++];
                        ActionTab.Action[i].Special = rx_var[readpoint++];
                    }
                    ReadFalg |= ActionPar;
                    tableActionShowData();
                    statusMsg = tr("读取动作表成功");
                    qDebug()<<tr("read Action success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= ActionPar;
                statusMsg = tr("设置动作表成功");
                qDebug()<<tr("set Action success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Pattern)//方案表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 PatternSize = 7;
                if(PatternTab.Maximum == rx_var[0] && rx_num == PatternSize * PatternTab.Maximum + 1)
                {
                    for(quint16 i = 0; i < PatternTab.Maximum; i++)
                    {
                        quint16 readpoint = PatternSize * i + 1;
                        PatternTab.Pattern[i].Number = rx_var[readpoint];
                        if(PatternTab.Pattern[i].Number > 0) qDebug()<<"received PatternTab.Pattern[i].Number" <<PatternTab.Pattern[i].Number;
                        PatternTab.Pattern[i].CycleTime = rx_var[readpoint+1]|(rx_var[readpoint+2]<<8);
                        PatternTab.Pattern[i].OffsetTime = rx_var[readpoint+3];
                        PatternTab.Pattern[i].SplitNumber = rx_var[readpoint+4];
                        PatternTab.Pattern[i].SequenceNumber = rx_var[readpoint+5];
                        PatternTab.Pattern[i].WorkMode = rx_var[readpoint+6];
                    }
                    ReadFalg |= PatternPar;
                    CalcPatternCycleTime();
                    tablePatternShowData();
                    statusMsg = tr("读取方案表成功");
                    qDebug()<<tr("read Pattern success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= PatternPar;
                statusMsg = tr("设置方案表成功");
                qDebug()<<tr("set Pattern success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Split)//绿信比操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 SplitSize = PhaseMax * 4 + 1;
                if(SplitTab.Maximum == rx_var[0] && rx_num == SplitSize * SplitTab.Maximum + 1)
                {
                    quint16 readpoint = 1;
                    for(quint16 i = 0; i < SplitTab.Maximum; i++)
                    {
                        SplitTab.Split[i].Num = rx_var[readpoint++];
                        for(quint16 j = 0; j < PhaseMax; j++)
                        {
                            SplitTab.Split[i].Phase[j].Phase = rx_var[readpoint++];
                            SplitTab.Split[i].Phase[j].Time = rx_var[readpoint++];
                            SplitTab.Split[i].Phase[j].Mode = rx_var[readpoint++];
                            SplitTab.Split[i].Phase[j].Coord = rx_var[readpoint++];
                        }
                    }
                    ReadFalg |= SplitPar;
                    tableSplitShowData(ui->comboBox_SplitNumber->currentIndex());
                    CalcPatternCycleTime();
                    tablePatternShowData();
                    statusMsg = tr("读取绿信比成功");
                    qDebug()<<tr("read Split success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= SplitPar;
                statusMsg = tr("设置绿信比成功");
                qDebug()<<tr("set Split success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Sequence)//相序表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 SequenceSize = (PhaseMax + 1) * RingMax + 1;
                if(SeqTab.Maximum == rx_var[0] && rx_num == SequenceSize * SeqTab.Maximum + 1)
                {
                    quint16 readpoint = 1;
                    for(quint16 i = 0; i < SeqTab.Maximum; i++)
                    {
                        SeqTab.Seq[i].Num = rx_var[readpoint++];
                        for(quint16 j = 0; j < RingMax; j++)
                        {
                            SeqTab.Seq[i].Ring[j].RingNum = rx_var[readpoint++];
                            for(quint16 p = 0; p < PhaseMax; p++)
                                SeqTab.Seq[i].Ring[j].Phase[p] = rx_var[readpoint++];
                        }
                    }
                    ReadFalg |= SequencePar;
                    tableSequenceShowData(ui->comboBox_sequenceNumber->currentIndex());
                    CalcPatternCycleTime();
                    tablePatternShowData();
                    statusMsg = tr("读取相序表成功");
                    qDebug()<<tr("read Sequence success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= SequencePar;
                statusMsg = tr("设置相序表成功");
                qDebug()<<tr("set Sequence success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Phase)//相位表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 PhaseSize = 32;
                if(PhaseTab.Maximum == rx_var[0] && rx_num == PhaseSize * PhaseTab.Maximum + 1)
                {
                    for(quint16 i = 0; i < PhaseTab.Maximum; i++)
                    {
                        quint16 readpoint = PhaseSize * i + 1;
                        PhaseTab.phase[i].Number = rx_var[readpoint];
                        PhaseTab.phase[i].Walk = rx_var[readpoint+1];
                        PhaseTab.phase[i].PedestrianClear = rx_var[readpoint+2];
                        PhaseTab.phase[i].MinimumGreen = rx_var[readpoint+3];
                        PhaseTab.phase[i].Passage = rx_var[readpoint+4];

                        PhaseTab.phase[i].Maximum1 = rx_var[readpoint+5];
                        PhaseTab.phase[i].Maximum2 = rx_var[readpoint+6];
                        PhaseTab.phase[i].YellowChange = rx_var[readpoint+7];
                        PhaseTab.phase[i].RedClear = rx_var[readpoint+8];
                        PhaseTab.phase[i].RedRevert = rx_var[readpoint+9];

                        PhaseTab.phase[i].AddedInitial = rx_var[readpoint+10];
                        PhaseTab.phase[i].MaximumInitial = rx_var[readpoint+11];
                        PhaseTab.phase[i].TimeBeforeReduction = rx_var[readpoint+12];
                        PhaseTab.phase[i].CarsBeforeReduction = rx_var[readpoint+13];
                        PhaseTab.phase[i].TimeToReduce = rx_var[readpoint+14];

                        PhaseTab.phase[i].ReduceBy = rx_var[readpoint+15];
                        PhaseTab.phase[i].MinimumGap = rx_var[readpoint+16];
                        PhaseTab.phase[i].DynamicMaxLimit = rx_var[readpoint+17];
                        PhaseTab.phase[i].DynamicMaxStep = rx_var[readpoint+18];
                        PhaseTab.phase[i].Startup = rx_var[readpoint+19];

                        PhaseTab.phase[i].Ring = rx_var[readpoint+20];
                        PhaseTab.phase[i].VehicleClear = rx_var[readpoint+21];
                        PhaseTab.phase[i].Options = rx_var[readpoint+22]|(rx_var[readpoint+23]<<8);

                        PhaseTab.phase[i].Concurrency =  (quint32)rx_var[readpoint+24]|\
                                                        ((quint32)rx_var[readpoint+25]<<8)|\
                                                        ((quint32)rx_var[readpoint+26]<<16)|\
                                                        ((quint32)rx_var[readpoint+27]<<24);
                        PhaseTab.phase[i].ReleasePhase = (quint32)rx_var[readpoint+28]|\
                                                        ((quint32)rx_var[readpoint+29]<<8)|\
                                                        ((quint32)rx_var[readpoint+30]<<16)|\
                                                        ((quint32)rx_var[readpoint+31]<<24);
                    }
                    ReadFalg |= PhasePar;
                    tablePhaseShowData();
                    statusMsg = tr("读取相位表成功");
                    qDebug()<<tr("read Phase success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= PhasePar;
                statusMsg = tr("设置相位表成功");
                qDebug()<<tr("set Phase success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Channel)//通道表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 ChannelSize = 8;
                if(ChannelTab.Maximum == rx_var[0] && rx_num == ChannelSize * ChannelTab.Maximum + 1)
                {
                    quint16 readpoint = 1;
                    for(quint16 i = 0; i < ChannelTab.Maximum; i++)
                    {
                        ChannelTab.channel[i].Num = rx_var[readpoint++];
                        ChannelTab.channel[i].ControlSource = rx_var[readpoint++];
                        ChannelTab.channel[i].ControlType = rx_var[readpoint++];
                        ChannelTab.channel[i].Flash = rx_var[readpoint++];
                        ChannelTab.channel[i].Dim = rx_var[readpoint++];
                        ChannelTab.channel[i].Position = rx_var[readpoint++];
                        ChannelTab.channel[i].Direction = rx_var[readpoint++];
                        ChannelTab.channel[i].CountdownID = rx_var[readpoint++];
                    }
                    ReadFalg |= ChannelPar;
                    tableChannelShowData();
                    statusMsg = tr("读取通道表成功");
                    qDebug()<<tr("read Channel success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= ChannelPar;
                statusMsg = tr("设置通道表成功");
                qDebug()<<tr("set Channel success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Unit)//单元参数操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                if(rx_num == 12)
                {
                    Unit.StartupFlash = rx_var[0];
                    Unit.StartupAllRed = rx_var[1];
                    Unit.AutomaticPedClear = rx_var[2];
                    Unit.RedRevert = rx_var[3];
                    Unit.BackupTime = rx_var[4]|(rx_var[5]<<8);
                    Unit.FlowCycle = rx_var[6];
                    Unit.FlashStatus = rx_var[7];
                    Unit.Status = rx_var[8];
                    Unit.GreenConflictDetectFlag = rx_var[9];
                    Unit.RedGreenConflictDetectFlag = rx_var[10];
                    Unit.RedFailedDetectFlag = rx_var[11];

                    ui->spinBox_StartupFlash->setValue(Unit.StartupFlash);
                    ui->spinBox_StartupAllRed->setValue(Unit.StartupAllRed);
                    ui->spinBox_RedRevert->setValue(Unit.RedRevert);
                    ui->spinBox_BackupTime->setValue(Unit.BackupTime);
                    ui->spinBox_FlowCycle->setValue(Unit.FlowCycle);
                    if(Unit.AutomaticPedClear == 2)
                        ui->checkBox_automaticPedClear->setChecked(true);
                    else
                        ui->checkBox_automaticPedClear->setChecked(false);

                    if(Unit.GreenConflictDetectFlag) ui->checkBox_GreenConflict->setChecked(true);
                    else ui->checkBox_GreenConflict->setChecked(false);

                    if(Unit.RedGreenConflictDetectFlag) ui->checkBox_RedGreenConflict->setChecked(true);
                    else ui->checkBox_RedGreenConflict->setChecked(false);

                    if(Unit.RedFailedDetectFlag) ui->checkBox_RedFailed->setChecked(true);
                    else ui->checkBox_RedFailed->setChecked(false);

                    ReadFalg |= UnitPar;
                    statusMsg = tr("读取单元参数成功");
                    qDebug()<<tr("read Unit success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= UnitPar;
                statusMsg = tr("设置单元参数成功");
                qDebug()<<tr("set Unit success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Coord)//协调操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                if(rx_num == 4)
                {
                    Coord.OperationalMode = rx_var[0];
                    Coord.CorrectionMode = rx_var[1];
                    Coord.MaximumMode = rx_var[2];
                    Coord.ForceMode = rx_var[3];

                    if(Coord.OperationalMode == CoordAutomatic)
                    {
                        ui->comboBox_coordOperationalMode->setCurrentIndex(0);
                    }
                    else if(Coord.OperationalMode == CoordManualFree)
                    {
                        ui->comboBox_coordOperationalMode->setCurrentIndex(2);
                    }
                    else if(Coord.OperationalMode == CoordManualFlash)
                    {
                        ui->comboBox_coordOperationalMode->setCurrentIndex(3);
                    }
                    else
                    {
                        ui->comboBox_coordOperationalMode->setCurrentIndex(1);
                        ui->spinBox_coordManualPattern->setValue(Coord.OperationalMode);
                    }
                    ui->comboBox_coordCorrectionMode->setCurrentIndex(Coord.CorrectionMode-1);
                    ui->comboBox_coordMaximumMode->setCurrentIndex(Coord.MaximumMode-1);
                    ui->comboBox_coordForceMode->setCurrentIndex(Coord.ForceMode-1);
                    ReadFalg |= CoordPar;
                    statusMsg = tr("读取协调表成功");
                    qDebug()<<tr("read Coord success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= CoordPar;
                statusMsg = tr("设置协调表成功");
                qDebug()<<tr("set Coord success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Overlap)//跟随相位表操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 tempL,tempH;
                quint8 OverlapSize = 10;
                if(OverlapTab.Maximum == rx_var[0] && rx_num == OverlapSize * OverlapTab.Maximum + 1)
                {
                    quint16 readpoint = 1;
                    for(quint16 i = 0; i < OverlapTab.Maximum; i++)
                    {
                        OverlapTab.Overlap[i].Num = rx_var[readpoint++];
                        OverlapTab.Overlap[i].Type = rx_var[readpoint++];
                        tempL = rx_var[readpoint++];
                        tempH = rx_var[readpoint++];
                        OverlapTab.Overlap[i].IncludedPhases = tempL |(tempH<<8);
                        tempL = rx_var[readpoint++];
                        tempH = rx_var[readpoint++];
                        OverlapTab.Overlap[i].ModifierPhases = tempL |(tempH<<8);

                        OverlapTab.Overlap[i].TrailGreen = rx_var[readpoint++];
                        OverlapTab.Overlap[i].TrailClear = rx_var[readpoint++];
                        OverlapTab.Overlap[i].TrailYellow = rx_var[readpoint++];
                        OverlapTab.Overlap[i].TrailRed = rx_var[readpoint++];
                    }
                    ReadFalg |= OverlapPar;
                    tableOverlapShowData();
                    statusMsg = tr("读取跟随相位表成功");
                    qDebug()<<tr("read Overlap success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= OverlapPar;
                statusMsg = tr("设置跟随相位表成功");
                qDebug()<<tr("set Overlap success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else
        {
            msgerror = Unsupport_OB;
        }
    }
    else if(gbmsg->DataLinkCode == DL_Intervention)
    {
        if(gbmsg->ObjectCode == O_Peddet)//操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 PeddetSize = 6;
                if(PeddetTab.Maximum == rx_var[0] && rx_num == PeddetSize * PeddetTab.Maximum + 1)
                {
                    quint16 readpoint = 1;
                    for(quint16 i = 0; i < PeddetTab.Maximum; i++)
                    {
                        PeddetTab.peddet[i].Num = rx_var[readpoint++];
                        PeddetTab.peddet[i].CallPhase = rx_var[readpoint++];
                        PeddetTab.peddet[i].NoActivity = rx_var[readpoint++];
                        PeddetTab.peddet[i].MaxPresence = rx_var[readpoint++];
                        PeddetTab.peddet[i].ErraticCounts = rx_var[readpoint++];
                        PeddetTab.peddet[i].Alarms = rx_var[readpoint++];
                    }
                    ReadFalg |= PeddetPar;
                    tablePeddetShowData();
                    ui->tablePeddet->selectRow(0);
                    statusMsg = tr("读取行人检测器表成功");
                    qDebug()<<tr("read Peddet success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= PeddetPar;
                statusMsg = tr("设置行人检测器表成功");
                qDebug()<<tr("set Peddet success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Vehdet)//操作
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                if(VehdetMax == rx_var[0] && rx_num == sizeof(VehdetTab) + 1)
                {
                    memcpy(&VehdetTab.vehdet[0].Num, &rx_var[1], sizeof(VehdetTab));

                    ReadFalg |= VehdetPar;
                    tableVehdetShowData();
                    ui->tableVehdet->selectRow(0);
                    statusMsg = tr("读取车辆检测器表成功");
                    qDebug()<<tr("read Vehdet success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                WriteFalg |= VehdetPar;
                statusMsg = tr("设置车辆检测器表成功");
                qDebug()<<tr("set Vehdet success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_PeddetState)
        {
            if(gbmsg->OperationType == OT_QueryAnswer)//查询应答
            {
                //查询成功
                quint8 PeddetStateSize = sizeof(PeddetState);
                qDebug()<<tr("PeddetStateSize = ")<<PeddetStateSize;
                if(PeddetStateTab.Maximum == rx_var[0] && rx_num == PeddetStateSize * PeddetStateTab.Maximum + 1)//
                {
                    int readpoint = 1;
                    quint16 data = 0;
                    for(quint16 i = 0; i < PeddetStateTab.Maximum; i++)
                    {
                        PeddetStateTab.peddet[i].Valid = rx_var[readpoint++];
                        PeddetStateTab.peddet[i].Alarms = rx_var[readpoint++];
                        data = rx_var[readpoint]|(rx_var[readpoint+1] << 8); readpoint += 2;
                        PeddetStateTab.peddet[i].NoActivity = data;
                        data = rx_var[readpoint]|(rx_var[readpoint+1] << 8); readpoint += 2;
                        PeddetStateTab.peddet[i].Presence = data;
                        data = rx_var[readpoint]|(rx_var[readpoint+1] << 8); readpoint += 2;
                        PeddetStateTab.peddet[i].ErraticCounts = data;
                    }
                    tablePeddetStateShowData();
                    ui->tablePeddetState->selectRow(0);
                    statusMsg = tr("读取行人检测器状态表成功");
                    qDebug()<<tr("read PeddetState success");
                }
            }
            else if(gbmsg->OperationType == OT_SetAnswer)//设置应答
            {
                statusMsg = tr("清空行人检测器状态表成功");
                qDebug()<<tr("set PeddetState success");
            }
            else//不支持的操作类型
                msgerror = Unsupport_OT;
        }
        else if(gbmsg->ObjectCode == O_Alarm)
        {
            if(gbmsg->OperationType == OT_InitiativeReport)//查询应答
            {
                if(rx_var[0] == TypeAlarm_Environment)
                {
                    if(rx_var[1] == DoorState)
                    {
                        DoorStateShow(rx_var[2], true);
                    }
                }
            }
        }
        else if(gbmsg->ObjectCode == O_RemoteControl)
        {
            if(rx_var[0] == ClearError)
            {
                statusMsg = tr("手动清除故障成功");
            }
            else if(rx_var[0] == Manual_auto)
            {
                statusMsg = tr("恢复自动成功");
            }
            else if(rx_var[0] == Manual_start)
            {
                statusMsg = tr("手动执行成功");
            }
        }
    }
    else
        msgerror = Unsupport_DL;

    if(msgerror != Frame_right)
    {
        switch(msgerror)
        {
            case Frame_wrong: statusMsg = tr("数据协议错误");break;
            case CheckSum_failed: statusMsg = tr("数据校验错误");break;
            case Unsupport_OT: statusMsg = tr("不支持的操作类型");break;
            case Unsupport_DL: statusMsg = tr("不支持的数据链路码");break;
            case Unsupport_OB: statusMsg = tr("不支持的操作对象");break;
            case DataError: statusMsg = tr("数据错误");break;
        }
    }

    if(!statusMsg.isEmpty()) emit(setMainStatusBar(statusMsg));
}


void main_dialog::DoorStateShow(bool stateflag, bool statusflag)
{
    QString statusMsg;
    if(stateflag)
    {
        ui->label_Door->setText(tr("门已开启"));
        ui->label_Door->setStyleSheet("background-color: rgb(250, 100, 100);");
        statusMsg = tr("状态报警：门已开启！");
    }
    else
    {
        ui->label_Door->setText(tr("门已关闭"));
        ui->label_Door->setStyleSheet("background-color: rgb(80, 250, 70);");
        statusMsg = tr("状态报警：门已关闭！");
    }
    if(statusflag)emit(setMainStatusBar(statusMsg));
}

void main_dialog::on_pushButtonSearch_clicked()
{
    if(netOpenFlag == false) return;
    quint8 gbtx[32];
    gbtx[0] = frame_head;
    gbtx[1] = frame_ver;
    gbtx[2] = ID_PC;
    gbtx[3] = ID_TSC;
    gbtx[4] = DL_Com;
    gbtx[5] = areaNum;
    gbtx[6] = inteNumL;
    gbtx[7] = inteNumH;
    gbtx[8] = OT_Query;
    gbtx[9] = O_Call;
    gbtx[10] = Reserve_Data;
    qDebug()<<gbtx[0];
    qDebug()<<gbtx[1];
    qDebug()<<gbtx[2];
    qDebug()<<gbtx[3];
    qDebug()<<gbtx[4];
    qDebug()<<gbtx[5];
    qDebug()<<gbtx[6];
    qDebug()<<gbtx[7];
    qDebug()<<gbtx[8];
    qDebug()<<gbtx[9];


    quint8 CheckSumCalc = 0;
    for(quint8 i = 1; i<=10; i++)
    {
        CheckSumCalc += gbtx[i];
    }
    quint8 num = 11;
    if(CheckSumCalc == 0xC0)
    {
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDC;
    }else if(CheckSumCalc == 0xDB){
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDD;
    }else{
        gbtx[num++]= CheckSumCalc;
    }
    gbtx[num++]= frame_tail;

    QString ipstr = tr("255.255.255.255");

    AscPort = 161;
    QByteArray msg(QByteArray::fromRawData((const char *)gbtx, num));
    qDebug() << gbtx;
    udpSocket->writeDatagram(msg, QHostAddress(ipstr), AscPort);
    for(quint8 i = 0; i < OnLineCount; i++)
    {
        OnLineModel->removeRow(i);
        OnLineModel->insertRow(i);
    }
    OnLineCount = 0;

    qDebug()<<tr("Search ASC");
}

void main_dialog::on_pushButton_BasicInfoRead_clicked()
{
    ReadData(O_BasicInfo);
}

void main_dialog::on_pushButton_DeviceInfoRead_clicked()
{
    ReadData(O_DeviceInfo);
}

void main_dialog::on_pushButton_TimeRead_clicked()
{
    ReadData(O_CurrentTime);
}

void main_dialog::on_pbPhase_read_clicked()
{
    ReadData(O_Phase);
}

void main_dialog::on_pushButton_sequenceRead_clicked()
{
    ReadData(O_Sequence);
}

void main_dialog::on_pushButton_SplitRead_clicked()
{
    ReadData(O_Split);
}

void main_dialog::on_pbPattern_read_clicked()
{
    ReadData(O_Pattern);
}

void main_dialog::on_pushButton_PeriodRead_clicked()
{
    ReadData(O_Plan);
}

void main_dialog::on_pushButton_ScheduleRead_clicked()
{
    ReadData(O_Schedule);
}

void main_dialog::on_pushButton_OverlapRead_clicked()
{
    ReadData(O_Overlap);
}

void main_dialog::on_pushButton_PeddetRead_clicked()
{
    ReadData(O_Peddet);
}

void main_dialog::on_pushButton_VehdetRead_clicked()
{
    ReadData(O_Vehdet);
}

void main_dialog::on_pushButton_PeddetState_clicked()
{
    ReadData(O_PeddetState);
}

void main_dialog::on_pushButton_UnitRead_clicked()
{
    ReadData(O_Unit);
}

void main_dialog::on_pushButton_ChannelRead_clicked()
{
    ReadData(O_Channel);
}

void main_dialog::on_pushButton_ActionRead_clicked()
{
    ReadData(O_Action);
}

void main_dialog::on_pushButton_CoordRead_clicked()
{
    ReadData(O_Coord);
}

void main_dialog::on_pushButton_StateMonitoring_clicked()
{
    ReadData(O_WorkState);
}

void main_dialog::on_pushButton_ClearError_clicked()//清除故障
{
    SetData(O_RemoteControl);
}

void main_dialog::ReadData(quint8 Object_id)
{
    if(netOpenFlag == false) return;
    QString statusMsg = "读取";
    gbtx[0] = frame_head;
    gbtx[1] = frame_ver;
    gbtx[2] = ID_PC;
    gbtx[3] = ID_TSC;
    gbtx[5] = areaNum;
    gbtx[6] = inteNumL;
    gbtx[7] = inteNumH;
    gbtx[10] = Reserve_Data;

    if(Object_id == O_CurrentTime)//读取时间
    {
        gbtx[4] = DL_BasicInfo;
        gbtx[8] = OT_Query;
        gbtx[9] = O_CurrentTime;
        statusMsg += "hora de la señal";
        qDebug()<<tr("read time");
    }
    else if(Object_id == O_Schedule)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Schedule;
        statusMsg += "调度计划表";
        qDebug()<<tr("read Schedule");
    }
    else if(Object_id == O_Plan)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Plan;
        statusMsg += "时段表";
        qDebug()<<tr("read Plan");
    }
    else if(Object_id == O_Action)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Action;
        statusMsg += "动作表";
        qDebug()<<tr("read Action");
    }
    else if(Object_id == O_Pattern)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Pattern;
        statusMsg += "方案表";
        qDebug()<<tr("read Pattern");
    }
    else if(Object_id == O_Split)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Split;
        statusMsg += "绿信比";
        qDebug()<<tr("read Split");
    }
    else if(Object_id == O_Sequence)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Sequence;
        statusMsg += "相序表";
        qDebug()<<tr("read Sequence");
    }
    else if(Object_id == O_Phase)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Phase;
        statusMsg += "相位表";
        qDebug()<<tr("read Phase");
    }
    else if(Object_id == O_Channel)//读取通道表
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Channel;
        statusMsg += "通道表";
        qDebug()<<tr("read Channel");
    }
    else if(Object_id == O_Unit)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Unit;
        statusMsg += "单元参数";
        qDebug()<<tr("read Unit");
    }
    else if(Object_id == O_Coord)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Coord;
        statusMsg += "协调参数";
        qDebug()<<tr("read Coord");
    }
    else if(Object_id == O_Overlap)
    {
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Overlap;
        statusMsg += "跟随相位表";
        qDebug()<<tr("read Overlap");
    }
    else if(Object_id == O_Peddet)
    {
        gbtx[4] = DL_Intervention;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Peddet;
        statusMsg += "行人检测器表";
        qDebug()<<tr("read Peddet");
    }
    else if(Object_id == O_Vehdet)
    {
        gbtx[4] = DL_Intervention;
        gbtx[8] = OT_Query;
        gbtx[9] = O_Vehdet;
        statusMsg += "车辆检测器表";
        qDebug()<<tr("read Vehdet");
    }
    else if(Object_id == O_PeddetState)
    {
        gbtx[4] = DL_Intervention;
        gbtx[8] = OT_Query;
        gbtx[9] = O_PeddetState;
        statusMsg += "行人检测器状态表";
        qDebug()<<tr("read PeddetState");
    }
    else if(Object_id == O_DeviceInfo)
    {
        gbtx[4] = DL_BasicInfo;
        gbtx[8] = OT_Query;
        gbtx[9] = O_DeviceInfo;
        statusMsg += "设备信息";
        qDebug()<<tr("read DeviceInfo");
    }
    else if(Object_id == O_BasicInfo)
    {
        gbtx[4] = DL_BasicInfo;
        gbtx[8] = OT_Query;
        gbtx[9] = O_BasicInfo;
        statusMsg += "基础信息";
        qDebug()<<tr("read BasicInfo");
        qDebug()<<gbtx;
    }
    else if(Object_id == O_WorkState)
    {
        gbtx[4] = DL_BasicInfo;
        gbtx[8] = OT_Query;
        gbtx[9] = O_WorkState;

        if(ui->checkBox_AutoReportSignal->isChecked())
            gbtx[10] = 0x02;
        else
            gbtx[10] = Reserve_Data;
        statusMsg += "状态信息";
        qDebug()<<tr("read WorkState");
    }

    quint8 CheckSumCalc = 0;
    for(quint8 i = 1; i<=10; i++)
    {
        CheckSumCalc += gbtx[i];
    }
    quint8 num = 11;
    if(CheckSumCalc == 0xC0)
    {
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDC;
    }else if(CheckSumCalc == 0xDB){
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDD;
    }else{
        gbtx[num++]= CheckSumCalc;
    }
    gbtx[num++]= frame_tail;

    //AscPort = 5000;
    //AscIpStr = ui->lineEdit_ipStr->text();
    QByteArray msg(QByteArray::fromRawData((const char *)gbtx, num));
    udpSocket->writeDatagram(msg, QHostAddress(AscIpStr), AscPort);
    emit setMainStatusBar(statusMsg);
}

//国标规定数据长度大于1个字节，先发送低字节，再发送高字节
void main_dialog::on_pushButton_Read_clicked()
{
    if(ui->comboBox_OP->currentText() == tr("信号机时间"))//读取时间
    {
        ReadData(O_CurrentTime);
    }
    else if(ui->comboBox_OP->currentText() == tr("调度计划表"))
    {
        ReadData(O_Schedule);
    }
    else if(ui->comboBox_OP->currentText() == tr("时段表"))
    {
        ReadData(O_Plan);
    }
    else if(ui->comboBox_OP->currentText() == tr("动作表"))
    {
        ReadData(O_Action);
    }
    else if(ui->comboBox_OP->currentText() == tr("方案表"))
    {
        ReadData(O_Pattern);
    }
    else if(ui->comboBox_OP->currentText() == tr("绿信比"))
    {
        ReadData(O_Split);
    }
    else if(ui->comboBox_OP->currentText() == tr("相序表"))
    {
        ReadData(O_Sequence);
    }
    else if(ui->comboBox_OP->currentText() == tr("相位表"))
    {
        ReadData(O_Phase);
    }
    else if(ui->comboBox_OP->currentText() == tr("通道表"))//读取通道表
    {
        ReadData(O_Channel);
    }
    else if(ui->comboBox_OP->currentText() == tr("单元参数"))
    {
        ReadData(O_Unit);
    }
    else if(ui->comboBox_OP->currentText() == tr("协调参数"))
    {
        ReadData(O_Coord);
    }
    else if(ui->comboBox_OP->currentText() == tr("跟随相位表"))
    {
        ReadData(O_Overlap);
    }
    else if(ui->comboBox_OP->currentText() == tr("设备信息"))
    {
        ReadData(O_DeviceInfo);
    }
    else if(ui->comboBox_OP->currentText() == tr("基础信息"))
    {
        ReadData(O_BasicInfo);
    }
    else if(ui->comboBox_OP->currentText() == tr("行人检测器"))
    {
        ReadData(O_Peddet);
    }
}

void main_dialog::on_pushButton_TimeSet_clicked()
{
    SetData(O_CurrentTime);
}

void main_dialog::on_pbPhase_set_clicked()
{
    SetData(O_Phase);
}

void main_dialog::on_pushButton_sequenceSet_clicked()
{
    SetData(O_Sequence);
}

void main_dialog::on_pushButton_SplitSet_clicked()
{
    SetData(O_Split);
}

void main_dialog::on_pbPattern_set_clicked()
{
    SetData(O_Pattern);
}

void main_dialog::on_pushButton_ActionSet_clicked()
{
    SetData(O_Action);
}

void main_dialog::on_pushButton_PeriodSet_clicked()
{
    SetData(O_Plan);
}

void main_dialog::on_pushButton_ScheduleSet_clicked()
{
    SetData(O_Schedule);
}

void main_dialog::on_pushButton_OverlapSet_clicked()
{
    SetData(O_Overlap);
}

void main_dialog::on_pushButton_PeddetSet_clicked()
{
    SetData(O_Peddet);
}

void main_dialog::on_pushButton_VehdetSet_clicked()
{
    SetData(O_Vehdet);
}

void main_dialog::on_pushButton_ChannelSet_clicked()
{
    SetData(O_Channel);
}

void main_dialog::on_pushButton_BasicInfoSet_clicked()
{
    SetData(O_BasicInfo);
}

void main_dialog::on_pushButton_DeviceInfoSet_clicked()
{
    QString str = ui->label_DeviceVersion->text() + \
                  ui->label_ProductionDate->text() + \
                  ui->label_ConfigurationDate->text();
    if(str.isEmpty())
    {
        str = tr("基础信息不全！");
        emit setMainStatusBar(str);
    }
    else SetData(O_DeviceInfo);
}

void main_dialog::on_pushButton_UnitSet_clicked()
{
    SetData(O_Unit);
}

void formatString(QString &org, int n=2, const QChar &ch=QChar(' '))
{
    int size = org.size();
    int space = qRound(size*1.0/n+0.5)-1;
    if(space <= 0)return;
    for(int i=0,pos=n;i<space;++i,pos+=(n+1))
    {
        org.insert(pos,ch);
    }
}

void main_dialog::on_pushButton_manual_clicked()
{
    if(netOpenFlag == false) return;
    QString statusMsg = tr("手动控制");
    quint16 num = 0;
    quint16 temp_num = 0;
    qDebug()<<tr("manual clicked");
    gbtx[0] = frame_head;
    gbtx[1] = frame_ver;
    gbtx[2] = ID_PC;
    gbtx[3] = ID_TSC;
    gbtx[4] = DL_Intervention;
    gbtx[5] = areaNum;
    gbtx[6] = inteNumL;
    gbtx[7] = inteNumH;
    gbtx[8] = OT_Set;
    gbtx[9] = O_RemoteControl;
    gbtx[10] = Reserve_Data;

    if(ui->radioButton_auto->isChecked())//恢复自控
    {
        temp_var[0] = Manual_auto;
        temp_var[1] = Manual_NONE;
        temp_var[2] = MANUAL_POS_Other;
        temp_var[3] = MANUAL_DIR_Other;
    }
    else if(ui->radioButton_resident->isChecked())//驻留等待
    {
        temp_var[0] = Manual_start;
        temp_var[1] = Manual_appoint;
        temp_var[2] = MANUAL_POS_Other;
        temp_var[3] = MANUAL_DIR_Other;
    }
    else if(ui->radioButton_appoint->isChecked())//指定放行
    {
        temp_var[0] = Manual_start;
        temp_var[1] = Manual_appoint;
        temp_var[2] = MANUAL_POS_Other;
        temp_var[3] = MANUAL_DIR_Other;
        if(ui->checkBox_east->isChecked())  temp_var[2] |= MANUAL_POS_East;
        if(ui->checkBox_south->isChecked()) temp_var[2] |= MANUAL_POS_South;
        if(ui->checkBox_north->isChecked()) temp_var[2] |= MANUAL_POS_North;
        if(ui->checkBox_west->isChecked())  temp_var[2] |= MANUAL_POS_West;

        if(ui->checkBox_left->isChecked())      temp_var[3] |= MANUAL_DIR_Left;
        if(ui->checkBox_straight->isChecked())  temp_var[3] |= MANUAL_DIR_Straight;
        if(ui->checkBox_right->isChecked())     temp_var[3] |= MANUAL_DIR_Right;
        if(ui->checkBox_pedestrian->isChecked())temp_var[3] |= MANUAL_DIR_Pedestrian;
    }
    else//
    {
        temp_var[0] = Manual_start;
        if(ui->radioButton_yellowflash->isChecked())
            temp_var[1] = Manual_yellowflash;
        else if(ui->radioButton_allred->isChecked())
            temp_var[1] = Manual_allred;
        else if(ui->radioButton_lampoff->isChecked())
            temp_var[1] = Manual_lampoff;
        else if(ui->radioButton_nextphase->isChecked())
            temp_var[1] = Manual_nextphase;
        else return;
        temp_var[2] = MANUAL_POS_Other;
        temp_var[3] = MANUAL_DIR_Other;
    }

    int time = ui->spinBox_AutoTime->value();
    temp_var[4] = time&0xff;
    temp_var[5] = (time>>8)&0xff;

    num = 11;
    temp_num = 6;

    //转义字符的实施
    for(quint16 n = 0; n < temp_num; n++)
    {
        if(temp_var[n] == 0xC0)
        {
            gbtx[num++] = 0xDB;
            gbtx[num++] = 0xDC;
        }
        else if(temp_var[n] == 0xDB)
        {
            gbtx[num++] = 0xDB;
            gbtx[num++] = 0xDD;
        }
        else
            gbtx[num++] = temp_var[n];
    }

    quint8 CheckSumCalc = 0;
    for(quint16 i = 1; i < num; i++)
    {
        CheckSumCalc += gbtx[i];
    }

    if(CheckSumCalc == 0xC0)
    {
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDC;
    }else if(CheckSumCalc == 0xDB){
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDD;
    }else{
        gbtx[num++]= CheckSumCalc;
    }
    gbtx[num++]= frame_tail;

    //AscPort = 5000;
    //AscIpStr = ui->lineEdit_ipStr->text();
    QByteArray msg(QByteArray::fromRawData((const char *)gbtx, num));
    udpSocket->writeDatagram(msg, QHostAddress(AscIpStr), AscPort);
    emit setMainStatusBar(statusMsg);
}


void main_dialog::SetData(quint8 Object_id)
{
    if(netOpenFlag == false) return;
    QString statusMsg = "设置";
    quint16 temp_num = 0;
    gbtx[0] = frame_head;
    gbtx[1] = frame_ver;
    gbtx[2] = ID_PC;
    gbtx[3] = ID_TSC;

    gbtx[5] = areaNum;
    gbtx[6] = inteNumL;
    gbtx[7] = inteNumH;
    gbtx[10] = Reserve_Data;
    quint16 num = 0;
    if(Object_id == O_CurrentTime)//设置时间
    {
        statusMsg += tr("信号机时间");
        qDebug()<<tr("set Time");
        gbtx[4] = DL_BasicInfo;
        gbtx[8] = OT_Set;
        gbtx[9] = O_CurrentTime;

        bool ok;
        quint8 datatime[7];
        datatime[0] = QDateTime::currentDateTime().toString("ss").toInt(&ok,16);
        datatime[1] = QDateTime::currentDateTime().toString("mm").toInt(&ok,16);
        datatime[2] = QDateTime::currentDateTime().toString("hh").toInt(&ok,16);
        datatime[4] = QDateTime::currentDateTime().toString("dd").toInt(&ok,16);
        datatime[5] = QDateTime::currentDateTime().toString("MM").toInt(&ok,16);
        datatime[6] = QDateTime::currentDateTime().toString("yy").toInt(&ok,16);
        datatime[3] = WeekList.indexOf(QDateTime::currentDateTime().toString("dddd"));
        if(datatime[3] > 6)
        {
            quint16 y,m,d,a,b,c;
            y = ((datatime[6]>>4)&0x0f)*10+(datatime[6]&0x0f);
            m = ((datatime[5]>>4)&0x0f)*10+(datatime[5]&0x0f);
            d = ((datatime[4]>>4)&0x0f)*10+(datatime[4]&0x0f);
            if(m<3)
            {
                m=m+12;
                y=y-1;
            }
            a=y/4;
            b=(m+1)*13/5;
            c=y+a+b+d-1;
            c=c%7;
            datatime[3] = c;
        }
        gbtx[11] = datatime[0];
        gbtx[12] = datatime[1];
        gbtx[13] = datatime[2];
        gbtx[14] = datatime[3];
        gbtx[15] = datatime[4];
        gbtx[16] = datatime[5];
        gbtx[17] = datatime[6];
        qDebug() << gbtx[14];

        num = 18;
        temp_num = 0;
    }
    else if(Object_id == O_Schedule)//设置
    {
        statusMsg += tr("调度计划表");
        qDebug()<<tr("set Schedule");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Schedule;
        gbtx[11] = ScheduleTab.Maximum;
        num = 12;
        temp_num = 0;
        for(quint16 i = 0; i < ScheduleTab.Maximum; i++)
        {
            temp_var[temp_num++] = ScheduleTab.schedule[i].Number;
            temp_var[temp_num++] =(ScheduleTab.schedule[i].Month & 0xff);
            temp_var[temp_num++] =(ScheduleTab.schedule[i].Month >> 8);
            temp_var[temp_num++] = ScheduleTab.schedule[i].Day;
            temp_var[temp_num++] =(ScheduleTab.schedule[i].Date & 0xff);
            temp_var[temp_num++] =(ScheduleTab.schedule[i].Date >> 8);
            temp_var[temp_num++] =(ScheduleTab.schedule[i].Date >> 16);
            temp_var[temp_num++] =(ScheduleTab.schedule[i].Date >> 24);
            temp_var[temp_num++] = ScheduleTab.schedule[i].DayPlan;
        }
    }
    else if(Object_id == O_Plan)//设置
    {
        statusMsg += tr("时段表");
        qDebug()<<tr("set Plan");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Plan;
        gbtx[11] = PlanTab.Maximum;
        num = 12;
        temp_num = 0;
        for(quint16 i = 0; i < PlanTab.Maximum; i++)
        {
            PlanTab.Plan[i].Num = i + 1;
            temp_var[temp_num++] = PlanTab.Plan[i].Num;
            for(quint16 j = 0; j < PeriodMax; j++)
            {
                temp_var[temp_num++] = PlanTab.Plan[i].Period[j].Time.Hour;
                temp_var[temp_num++] = PlanTab.Plan[i].Period[j].Time.Minute;
                temp_var[temp_num++] = PlanTab.Plan[i].Period[j].ActionNum;
            }
        }
    }
    else if(Object_id == O_Action)//设置
    {
        statusMsg += tr("动作表");
        qDebug()<<tr("set Action");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Action;
        gbtx[11] = ActionTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < ActionTab.Maximum; i++)
        {
            temp_var[temp_num++] = ActionTab.Action[i].Num;
            temp_var[temp_num++] = ActionTab.Action[i].PatternNum;
            temp_var[temp_num++] = ActionTab.Action[i].Auxillary;
            temp_var[temp_num++] = ActionTab.Action[i].Special;
        }
    }
    else if(Object_id == O_Pattern)//设置
    {
        statusMsg += tr("方案表");
        qDebug()<<tr("set Pattern");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Pattern;
        gbtx[11] = PatternTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < PatternTab.Maximum; i++)
        {
            temp_var[temp_num++] = PatternTab.Pattern[i].Number;
            temp_var[temp_num++] =(PatternTab.Pattern[i].CycleTime & 0xff);
            temp_var[temp_num++] =(PatternTab.Pattern[i].CycleTime >> 8);
            temp_var[temp_num++] = PatternTab.Pattern[i].OffsetTime;
            temp_var[temp_num++] = PatternTab.Pattern[i].SplitNumber;
            temp_var[temp_num++] = PatternTab.Pattern[i].SequenceNumber;
            temp_var[temp_num++] = PatternTab.Pattern[i].WorkMode;
        }
    }
    else if(Object_id == O_Split)//设置
    {
        statusMsg += tr("绿信比");
        qDebug()<<tr("set Split");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Split;
        gbtx[11] = SplitTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < SplitTab.Maximum; i++)
        {
            temp_var[temp_num++] = SplitTab.Split[i].Num;
            for(quint16 j = 0; j < PhaseMax; j++)
            {
                temp_var[temp_num++] = SplitTab.Split[i].Phase[j].Phase;
                temp_var[temp_num++] = SplitTab.Split[i].Phase[j].Time;
                temp_var[temp_num++] = SplitTab.Split[i].Phase[j].Mode;
                temp_var[temp_num++] = SplitTab.Split[i].Phase[j].Coord;
            }
        }
    }
    else if(Object_id == O_Sequence)//设置
    {
        statusMsg += tr("相序表");
        qDebug()<<tr("set Sequence");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Sequence;
        gbtx[11] = SeqTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < SeqTab.Maximum; i++)
        {
            temp_var[temp_num++] = SeqTab.Seq[i].Num;
            for(quint16 j = 0; j < RingMax; j++)
            {
                temp_var[temp_num++] = SeqTab.Seq[i].Ring[j].RingNum;
                for(quint16 p = 0; p < PhaseMax; p++)
                    temp_var[temp_num++] = SeqTab.Seq[i].Ring[j].Phase[p];
            }
        }
    }
    else if(Object_id == O_Phase)//设置
    {
        statusMsg += tr("相位表");
        qDebug()<<tr("set Phase");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Phase;
        gbtx[11] = PhaseTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < PhaseTab.Maximum; i++)
        {
            temp_var[temp_num++] = PhaseTab.phase[i].Number;
            temp_var[temp_num++] = PhaseTab.phase[i].Walk;
            temp_var[temp_num++] = PhaseTab.phase[i].PedestrianClear;
            temp_var[temp_num++] = PhaseTab.phase[i].MinimumGreen;
            temp_var[temp_num++] = PhaseTab.phase[i].Passage;

            temp_var[temp_num++] = PhaseTab.phase[i].Maximum1;
            temp_var[temp_num++] = PhaseTab.phase[i].Maximum2;
            temp_var[temp_num++] = PhaseTab.phase[i].YellowChange;
            temp_var[temp_num++] = PhaseTab.phase[i].RedClear;
            temp_var[temp_num++] = PhaseTab.phase[i].RedRevert;

            temp_var[temp_num++] = PhaseTab.phase[i].AddedInitial;
            temp_var[temp_num++] = PhaseTab.phase[i].MaximumInitial;
            temp_var[temp_num++] = PhaseTab.phase[i].TimeBeforeReduction;
            temp_var[temp_num++] = PhaseTab.phase[i].CarsBeforeReduction;
            temp_var[temp_num++] = PhaseTab.phase[i].TimeToReduce;

            temp_var[temp_num++] = PhaseTab.phase[i].ReduceBy;
            temp_var[temp_num++] = PhaseTab.phase[i].MinimumGap;
            temp_var[temp_num++] = PhaseTab.phase[i].DynamicMaxLimit;
            temp_var[temp_num++] = PhaseTab.phase[i].DynamicMaxStep;
            temp_var[temp_num++] = PhaseTab.phase[i].Startup;

            temp_var[temp_num++] = PhaseTab.phase[i].Ring;
            temp_var[temp_num++] = PhaseTab.phase[i].VehicleClear;
            temp_var[temp_num++] = PhaseTab.phase[i].Options & 0xff;
            temp_var[temp_num++] = PhaseTab.phase[i].Options >> 8;

            temp_var[temp_num++] = PhaseTab.phase[i].Concurrency & 0xff;
            temp_var[temp_num++] = PhaseTab.phase[i].Concurrency >> 8;
            temp_var[temp_num++] = PhaseTab.phase[i].Concurrency >> 16;
            temp_var[temp_num++] = PhaseTab.phase[i].Concurrency >> 24;

            temp_var[temp_num++] = PhaseTab.phase[i].ReleasePhase & 0xff;
            temp_var[temp_num++] = PhaseTab.phase[i].ReleasePhase >> 8;
            temp_var[temp_num++] = PhaseTab.phase[i].ReleasePhase >> 16;
            temp_var[temp_num++] = PhaseTab.phase[i].ReleasePhase >> 24;
        }
    }
    else if(Object_id == O_Channel)//设置通道
    {
        statusMsg += tr("通道表");
        qDebug()<<tr("set Channel");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Channel;
        gbtx[11] = ChannelTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < ChannelTab.Maximum; i++)
        {
            temp_var[temp_num++] = ChannelTab.channel[i].Num;
            temp_var[temp_num++] = ChannelTab.channel[i].ControlSource;
            temp_var[temp_num++] = ChannelTab.channel[i].ControlType;
            temp_var[temp_num++] = ChannelTab.channel[i].Flash;
            temp_var[temp_num++] = ChannelTab.channel[i].Dim;
            temp_var[temp_num++] = ChannelTab.channel[i].Position;
            temp_var[temp_num++] = ChannelTab.channel[i].Direction;
            temp_var[temp_num++] = ChannelTab.channel[i].CountdownID;
        }
    }
    else if(Object_id == O_Unit)//设置单元参数
    {
        statusMsg += tr("单元参数");
        qDebug()<<tr("set Unit");

        Unit.StartupFlash = ui->spinBox_StartupFlash->value();
        Unit.StartupAllRed = ui->spinBox_StartupAllRed->value();
        Unit.RedRevert = ui->spinBox_RedRevert->value();
        Unit.BackupTime = ui->spinBox_BackupTime->value();
        Unit.FlowCycle = ui->spinBox_FlowCycle->value();
        Unit.FlashStatus = 0;
        Unit.Status = 0;
        if(ui->checkBox_automaticPedClear->isChecked())
            Unit.AutomaticPedClear = 2;
        else
            Unit.AutomaticPedClear = 1;

        if(ui->checkBox_GreenConflict->isChecked())
            Unit.GreenConflictDetectFlag = 1;
        else Unit.GreenConflictDetectFlag = 0;

        if(ui->checkBox_RedGreenConflict->isChecked())
            Unit.RedGreenConflictDetectFlag = 1;
        else Unit.RedGreenConflictDetectFlag = 0;

        if(ui->checkBox_RedFailed->isChecked())
            Unit.RedFailedDetectFlag = 1;
        else Unit.RedFailedDetectFlag = 0;

        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Unit;

        num = 11;
        temp_num = 0;
        temp_var[temp_num++] = Unit.StartupFlash;
        temp_var[temp_num++] = Unit.StartupAllRed;
        temp_var[temp_num++] = Unit.AutomaticPedClear;
        temp_var[temp_num++] = Unit.RedRevert;
        temp_var[temp_num++] = Unit.BackupTime & 0xff;
        temp_var[temp_num++] = Unit.BackupTime >> 8;
        temp_var[temp_num++] = Unit.FlowCycle;
        temp_var[temp_num++] = Unit.FlashStatus;
        temp_var[temp_num++] = Unit.Status;
        temp_var[temp_num++] = Unit.GreenConflictDetectFlag;
        temp_var[temp_num++] = Unit.RedGreenConflictDetectFlag;
        temp_var[temp_num++] = Unit.RedFailedDetectFlag;
    }
    else if(Object_id == O_Coord)//设置协调参数
    {
        statusMsg += tr("协调参数");
        qDebug()<<tr("set Coord");

        if(ui->comboBox_coordOperationalMode->currentIndex()==0)
            Coord.OperationalMode = CoordAutomatic;
        else if(ui->comboBox_coordOperationalMode->currentIndex()==1)
            Coord.OperationalMode = ui->spinBox_coordManualPattern->value();
        else if(ui->comboBox_coordOperationalMode->currentIndex()==2)
            Coord.OperationalMode = CoordManualFree;
        else if(ui->comboBox_coordOperationalMode->currentIndex()==3)
            Coord.OperationalMode = CoordManualFlash;

        Coord.CorrectionMode = ui->comboBox_coordCorrectionMode->currentIndex()+1;
        Coord.MaximumMode = ui->comboBox_coordMaximumMode->currentIndex()+1;
        Coord.ForceMode = ui->comboBox_coordForceMode->currentIndex()+1;

        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Coord;

        num = 11;
        temp_num = 0;
        temp_var[temp_num++] = Coord.OperationalMode;
        temp_var[temp_num++] = Coord.CorrectionMode;
        temp_var[temp_num++] = Coord.MaximumMode;
        temp_var[temp_num++] = Coord.ForceMode;
    }
    else if(Object_id == O_Overlap)//设置跟随相位表
    {
        statusMsg += tr("跟随相位表");
        qDebug()<<tr("set Overlap");
        gbtx[4] = DL_CharacPar;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Overlap;
        gbtx[11] = OverlapTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < OverlapTab.Maximum; i++)
        {
            temp_var[temp_num++] = OverlapTab.Overlap[i].Num;
            temp_var[temp_num++] = OverlapTab.Overlap[i].Type;
            temp_var[temp_num++] = OverlapTab.Overlap[i].IncludedPhases & 0xff;
            temp_var[temp_num++] =(OverlapTab.Overlap[i].IncludedPhases>>8);
            temp_var[temp_num++] = OverlapTab.Overlap[i].ModifierPhases & 0xff;
            temp_var[temp_num++] =(OverlapTab.Overlap[i].ModifierPhases>>8);
            temp_var[temp_num++] = OverlapTab.Overlap[i].TrailGreen;
            temp_var[temp_num++] = OverlapTab.Overlap[i].TrailClear;
            temp_var[temp_num++] = OverlapTab.Overlap[i].TrailYellow;
            temp_var[temp_num++] = OverlapTab.Overlap[i].TrailRed;
        }
    }
    else if(Object_id == O_Peddet)//行人检测器表
    {
        statusMsg += tr("行人检测器表");
        qDebug()<<tr("set Peddet");
        gbtx[4] = DL_Intervention;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Peddet;
        gbtx[11] = PeddetTab.Maximum;
        num = 12;

        temp_num = 0;
        for(quint16 i = 0; i < PeddetTab.Maximum; i++)
        {
            temp_var[temp_num++] = PeddetTab.peddet[i].Num;
            temp_var[temp_num++] = PeddetTab.peddet[i].CallPhase;
            temp_var[temp_num++] = PeddetTab.peddet[i].NoActivity;
            temp_var[temp_num++] = PeddetTab.peddet[i].MaxPresence;
            temp_var[temp_num++] = PeddetTab.peddet[i].ErraticCounts;
            temp_var[temp_num++] = PeddetTab.peddet[i].Alarms;
        }
    }
    else if(Object_id == O_Vehdet)//车辆检测器表
    {
        statusMsg += tr("车辆检测器表");
        qDebug()<<tr("set Vehdet");
        gbtx[4] = DL_Intervention;
        gbtx[8] = OT_Set;
        gbtx[9] = O_Vehdet;
        gbtx[11] = VehdetMax;
        num = 12;

        temp_num = sizeof(VehdetTab);
        qDebug()<<tr("sizeof Vehdet = ")<<temp_num;
        memcpy(temp_var, &VehdetTab.vehdet[0].Num, temp_num);
    }
    else if(Object_id == O_BasicInfo)//设置基础信息
    {
        statusMsg += tr("基础信息表");
        qDebug()<<tr("set BasicInfo");
        gbtx[4] = DL_BasicInfo;
        gbtx[8] = OT_Set;
        gbtx[9] = O_BasicInfo;
        num = 11;
        temp_num = 0;

        //路口名称转换为字节数据流
        QString IntersectionInfoStr = ui->lineEdit_IntersectionInfo->text();
        quint8 StrNum = IntersectionInfoStr.count();

        memset(temp_var,0,128);
        if(StrNum > 0)
        {
            quint16 data;
            for(int i=0; i<StrNum; i++)
            {
                data = IntersectionInfoStr.at(i).unicode();
                temp_var[temp_num++] = data>>8;
                temp_var[temp_num++] = data&0xff;
                if(i >= 63)break;
            }
        }
        temp_num = 128;

        //用于IP数据校验的正则表达式
        QRegExp rx("^([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]).([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]).([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5]).([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])$");

        //IP地址获取
        if(rx.exactMatch(ui->lineEdit_IP->text()))
        {
            QString String = ui->lineEdit_IP->text();
            quint8 length = String.length();
            quint8 i, n = 0;
            quint8 point[3] = {0x00};

            for(i = 0; i < length; i++)
            {
                if(String.at(i)=='.')
                {
                    if(n < 3) point[n] = i;
                    n++;
                }
            }

            quint8 ipd[4];
            if(point[0] == 1)
                ipd[0] = String.at(0).toLatin1()-0x30;
            else if(point[0] == 2)
                ipd[0] = (String.at(0).toLatin1()-0x30)*10+(String.at(1).toLatin1()-0x30);
            else if(point[0] == 3)
                ipd[0] = (String.at(0).toLatin1()-0x30)*100 + (String.at(1).toLatin1()-0x30)*10+(String.at(2).toLatin1()-0x30);
            else ipd[0] = 192;

            if((point[1]-point[0]) == 2)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30);
            else if((point[1]-point[0]) == 3)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*10 + (String.at(point[0]+2).toLatin1()-0x30);
            else if((point[1]-point[0]) == 4)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*100 + (String.at(point[0]+2).toLatin1()-0x30)*10 + (String.at(point[0]+3).toLatin1()-0x30);
            else ipd[1] = 192;

            if((point[2]-point[1]) == 2)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30);
            else if((point[2]-point[1]) == 3)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*10 + (String.at(point[1]+2).toLatin1()-0x30);
            else if((point[2]-point[1]) == 4)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*100 + (String.at(point[1]+2).toLatin1()-0x30)*10 + (String.at(point[1]+3).toLatin1()-0x30);
            else ipd[2] = 1;

            if((length-point[2]) == 2)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30);
            else if((length-point[2]) == 3)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*10 + (String.at(point[2]+2).toLatin1()-0x30);
            else if((length-point[2]) == 4)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*100 + (String.at(point[2]+2).toLatin1()-0x30)*10 + (String.at(point[2]+3).toLatin1()-0x30);
            else ipd[3] = 1;

            for(int i=0; i<4; i++) temp_var[temp_num++] = ipd[i];
        }
        else
        {
            statusMsg = tr("新的ip地址数据错误！");
            emit setMainStatusBar(statusMsg);
            return;
        }

        //子网掩码
        if(rx.exactMatch(ui->lineEdit_Mask->text()))
        {
            QString String = ui->lineEdit_Mask->text();
            quint8 length = String.length();
            quint8 i, n = 0;
            quint8 point[3] = {0x00};

            for(i = 0; i < length; i++)
            {
                if(String.at(i)=='.')
                {
                    if(n < 3) point[n] = i;
                    n++;
                }
            }

            quint8 ipd[4];
            if(point[0] == 1)
                ipd[0] = String.at(0).toLatin1()-0x30;
            else if(point[0] == 2)
                ipd[0] = (String.at(0).toLatin1()-0x30)*10+(String.at(1).toLatin1()-0x30);
            else if(point[0] == 3)
                ipd[0] = (String.at(0).toLatin1()-0x30)*100 + (String.at(1).toLatin1()-0x30)*10+(String.at(2).toLatin1()-0x30);
            else ipd[0] = 192;

            if((point[1]-point[0]) == 2)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30);
            else if((point[1]-point[0]) == 3)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*10 + (String.at(point[0]+2).toLatin1()-0x30);
            else if((point[1]-point[0]) == 4)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*100 + (String.at(point[0]+2).toLatin1()-0x30)*10 + (String.at(point[0]+3).toLatin1()-0x30);
            else ipd[1] = 192;

            if((point[2]-point[1]) == 2)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30);
            else if((point[2]-point[1]) == 3)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*10 + (String.at(point[1]+2).toLatin1()-0x30);
            else if((point[2]-point[1]) == 4)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*100 + (String.at(point[1]+2).toLatin1()-0x30)*10 + (String.at(point[1]+3).toLatin1()-0x30);
            else ipd[2] = 1;

            if((length-point[2]) == 2)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30);
            else if((length-point[2]) == 3)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*10 + (String.at(point[2]+2).toLatin1()-0x30);
            else if((length-point[2]) == 4)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*100 + (String.at(point[2]+2).toLatin1()-0x30)*10 + (String.at(point[2]+3).toLatin1()-0x30);
            else ipd[3] = 1;

            for(int i=0; i<4; i++) temp_var[temp_num++] = ipd[i];
        }
        else
        {
            statusMsg = tr("新的子网掩码数据错误！");
            emit setMainStatusBar(statusMsg);
            return;
        }

        //网关
        if(rx.exactMatch(ui->lineEdit_Gateway->text()))
        {
            QString String = ui->lineEdit_Gateway->text();
            quint8 length = String.length();
            quint8 i, n = 0;
            quint8 point[3] = {0x00};

            for(i = 0; i < length; i++)
            {
                if(String.at(i)=='.')
                {
                    if(n < 3) point[n] = i;
                    n++;
                }
            }

            quint8 ipd[4];
            if(point[0] == 1)
                ipd[0] = String.at(0).toLatin1()-0x30;
            else if(point[0] == 2)
                ipd[0] = (String.at(0).toLatin1()-0x30)*10+(String.at(1).toLatin1()-0x30);
            else if(point[0] == 3)
                ipd[0] = (String.at(0).toLatin1()-0x30)*100 + (String.at(1).toLatin1()-0x30)*10+(String.at(2).toLatin1()-0x30);
            else ipd[0] = 192;

            if((point[1]-point[0]) == 2)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30);
            else if((point[1]-point[0]) == 3)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*10 + (String.at(point[0]+2).toLatin1()-0x30);
            else if((point[1]-point[0]) == 4)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*100 + (String.at(point[0]+2).toLatin1()-0x30)*10 + (String.at(point[0]+3).toLatin1()-0x30);
            else ipd[1] = 192;

            if((point[2]-point[1]) == 2)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30);
            else if((point[2]-point[1]) == 3)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*10 + (String.at(point[1]+2).toLatin1()-0x30);
            else if((point[2]-point[1]) == 4)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*100 + (String.at(point[1]+2).toLatin1()-0x30)*10 + (String.at(point[1]+3).toLatin1()-0x30);
            else ipd[2] = 1;

            if((length-point[2]) == 2)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30);
            else if((length-point[2]) == 3)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*10 + (String.at(point[2]+2).toLatin1()-0x30);
            else if((length-point[2]) == 4)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*100 + (String.at(point[2]+2).toLatin1()-0x30)*10 + (String.at(point[2]+3).toLatin1()-0x30);
            else ipd[3] = 1;

            for(int i=0; i<4; i++) temp_var[temp_num++] = ipd[i];
        }
        else
        {
            statusMsg = tr("新的网关地址数据错误！");
            emit setMainStatusBar(statusMsg);
            return;
        }

        //信号机端口号
        temp_var[temp_num++] = 0x00;
        temp_var[temp_num++] = 161;

        for(int i=0; i<6; i++) temp_var[temp_num++] = mac[i];//MAC地址

        //服务器地址
        if(rx.exactMatch(ui->lineEdit_ServerIP->text()))
        {
            QString String = ui->lineEdit_ServerIP->text();
            quint8 length = String.length();
            quint8 i, n = 0;
            quint8 point[3] = {0x00};

            for(i = 0; i < length; i++)
            {
                if(String.at(i)=='.')
                {
                    if(n < 3) point[n] = i;
                    n++;
                }
            }

            quint8 ipd[4];
            if(point[0] == 1)
                ipd[0] = String.at(0).toLatin1()-0x30;
            else if(point[0] == 2)
                ipd[0] = (String.at(0).toLatin1()-0x30)*10+(String.at(1).toLatin1()-0x30);
            else if(point[0] == 3)
                ipd[0] = (String.at(0).toLatin1()-0x30)*100 + (String.at(1).toLatin1()-0x30)*10+(String.at(2).toLatin1()-0x30);
            else ipd[0] = 192;

            if((point[1]-point[0]) == 2)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30);
            else if((point[1]-point[0]) == 3)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*10 + (String.at(point[0]+2).toLatin1()-0x30);
            else if((point[1]-point[0]) == 4)
                ipd[1] = (String.at(point[0]+1).toLatin1()-0x30)*100 + (String.at(point[0]+2).toLatin1()-0x30)*10 + (String.at(point[0]+3).toLatin1()-0x30);
            else ipd[1] = 192;

            if((point[2]-point[1]) == 2)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30);
            else if((point[2]-point[1]) == 3)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*10 + (String.at(point[1]+2).toLatin1()-0x30);
            else if((point[2]-point[1]) == 4)
                ipd[2] = (String.at(point[1]+1).toLatin1()-0x30)*100 + (String.at(point[1]+2).toLatin1()-0x30)*10 + (String.at(point[1]+3).toLatin1()-0x30);
            else ipd[2] = 1;

            if((length-point[2]) == 2)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30);
            else if((length-point[2]) == 3)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*10 + (String.at(point[2]+2).toLatin1()-0x30);
            else if((length-point[2]) == 4)
                ipd[3] = (String.at(point[2]+1).toLatin1()-0x30)*100 + (String.at(point[2]+2).toLatin1()-0x30)*10 + (String.at(point[2]+3).toLatin1()-0x30);
            else ipd[3] = 1;

            for(int i=0; i<4; i++) temp_var[temp_num++] = ipd[i];
        }
        else
        {
            statusMsg = tr("新的服务器地址数据错误！");
            emit setMainStatusBar(statusMsg);
            return;
        }

        //服务器端口号
        quint16 ServerSocket = ui->lineEdit_ServerPort->text().toInt();
        temp_var[temp_num++] = ServerSocket>>8;
        temp_var[temp_num++] = ServerSocket&0xff;
        temp_var[temp_num++] = 0x00;//通讯类型

        //时区信息
        quint16 TimeZoneSeconds;
        double TimeZone = ui->spinBox_TimeZone->value();
        if(TimeZone >= 0)
        {
            TimeZoneSeconds = TimeZone*3600;
            temp_var[temp_num++] = 0x01;
            temp_var[temp_num++] = 0x00;
            temp_var[temp_num++] = TimeZoneSeconds>>8;
            temp_var[temp_num++] = TimeZoneSeconds&0xff;
        }
        else
        {
            TimeZoneSeconds = TimeZone*3600*-1;
            temp_var[temp_num++] = 0x00;
            temp_var[temp_num++] = 0x00;
            temp_var[temp_num++] = TimeZoneSeconds>>8;
            temp_var[temp_num++] = TimeZoneSeconds&0xff;
        }

        //信号机编号 0xFFFFFFFF = 4,294,967,295
        quint32 TscNum = ui->spinBox_TscNumber->value();
        temp_var[temp_num++] = TscNum>>24;
        temp_var[temp_num++] = TscNum>>16;
        temp_var[temp_num++] = TscNum>>8;
        temp_var[temp_num++] = TscNum&0xff;

        temp_var[temp_num++] = 0x01;    //路口数
        temp_var[temp_num++] = 0x00;    //GPS

        for(int i=0; i<11; i++) temp_var[temp_num++] = 0x00;//4字节的校验+7字节的保留数据
    }
    else if(Object_id == O_DeviceInfo)//设置基础信息
    {
        statusMsg += tr("基础信息表");
        qDebug()<<tr("set DeviceInfo");
        gbtx[4] = DL_BasicInfo;
        gbtx[8] = OT_Set;
        gbtx[9] = O_DeviceInfo;
        num = 11;
        temp_num = 0;

        //路口名称转换为字节数据流
        QString ManufacturerInfoStr = ui->lineEdit_ManufacturerInfo->text();
        quint8 StrNum = ManufacturerInfoStr.count();
        memset(temp_var, 0, 128);
        if(StrNum > 0)
        {
            quint16 data;
            for(int i=0; i<StrNum; i++)
            {
                data = ManufacturerInfoStr.at(i).unicode();
                temp_var[temp_num++] = data>>8;
                temp_var[temp_num++] = data&0xff;
                if(i >= 63)break;
            }
        }

        memcpy(&temp_var[128], deviceInfoBuf, 48);

        /*
        quint32 deviceversion = ui->label_DeviceVersion->text().toInt;
        quint8 temp_data = deviceversion/1000000;
            temp_var[129] = ((temp_data/10)<<4)|(temp_data%10);
        temp_data = (deviceversion/10000)%100;
            temp_var[130] = ((temp_data/10)<<4)|(temp_data%10);
        temp_data = (deviceversion/100)%100;
            temp_var[131] = ((temp_data/10)<<4)|(temp_data%10);
        temp_data = deviceversion%100;
            temp_var[132] = ((temp_data/10)<<4)|(temp_data%10);

        QString str = ui->label_DeviceVersion->text() + \
                      ui->label_ProductionDate->text() + \
                      ui->label_ConfigurationDate->text();


        */
        QString deviceNum = ui->lineEdit_DeviceNumber->text();


        QByteArray ret;
        deviceNum = deviceNum.trimmed();
        StrNum = deviceNum.count();

        while(StrNum > 0)
        {
            if(deviceNum.at(0) == '0')
                deviceNum.remove(0,1);
            else break;
            StrNum = deviceNum.count();
        }

        StrNum = deviceNum.count();
        if((StrNum%2) == 1) deviceNum.insert(0,'0');
        StrNum = deviceNum.count();
        qDebug() << StrNum;

        formatString(deviceNum,2,' ');
        QStringList sl=deviceNum.split(" ");
        foreach(QString s,sl)
        {
            if(!s.isEmpty())
                ret.append((char)s.toInt(0,16)&0xff);
        }
        StrNum = ret.size();

        //16 - StrNum + i
        for(int i = 0; i < 16; i++)
        {
            if(i < 16 - StrNum)
                temp_var[132 + i] = 0;
            else
                temp_var[132 + i] = ret.at(i + StrNum - 16);
        }

        /*
        for(quint8 i=0;i<4;i++)
        {
            deviceversion[i] = rx_var[128+i];
        }
        deviceversion = deviceversion.toHex();
        ui->label_DeviceVersion->setText(deviceversion);

        QByteArray deviceNumber;
        deviceNumber.resize(16);
        for(quint8 i=0;i<16;i++)
        {
            deviceNumber[i] = rx_var[132+i];
        }
        deviceNumber = deviceNumber.toHex();
        ui->lineEdit_DeviceNumber->setText(deviceNumber);

        QByteArray productionDate;
        deviceversion.resize(6);
        for(quint8 i=0;i<6;i++)
        {
            productionDate[i] = rx_var[148+i];
        }
        productionDate = productionDate.toHex();
        ui->label_ProductionDate->setText(productionDate);

        QByteArray configurationDate;
        deviceversion.resize(6);
        for(quint8 i=0;i<6;i++)
        {
            configurationDate[i] = rx_var[154+i];
        }
        configurationDate = configurationDate.toHex();
        ui->label_ConfigurationDate->setText(configurationDate);
        */


        temp_num = 176;
    }
    else if(Object_id == O_RemoteControl)//清除故障
    {
        statusMsg = tr("清除故障");
        qDebug()<<tr("Clear Error");
        gbtx[4] = DL_Intervention;
        gbtx[8] = OT_Set;
        gbtx[9] = O_RemoteControl;
        gbtx[11] = ClearError;
        num = 12;
        temp_num = 0;
    }

    //转义字符的实施
    for(quint16 n = 0; n < temp_num; n++)
    {
        if(temp_var[n] == 0xC0)
        {
            gbtx[num++] = 0xDB;
            gbtx[num++] = 0xDC;
        }
        else if(temp_var[n] == 0xDB)
        {
            gbtx[num++] = 0xDB;
            gbtx[num++] = 0xDD;
        }
        else
            gbtx[num++] = temp_var[n];
    }
    quint8 CheckSumCalc = 0;
    for(quint16 i = 1; i < num; i++)
    {
        CheckSumCalc += gbtx[i];
    }
    if(CheckSumCalc == 0xC0)
    {
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDC;
    }else if(CheckSumCalc == 0xDB){
        gbtx[num++]= 0xDB;
        gbtx[num++]= 0xDD;
    }else{
        gbtx[num++]= CheckSumCalc;
    }
    gbtx[num++]= frame_tail;

    //AscPort = 5000;
    //AscIpStr = ui->lineEdit_ipStr->text();
    QByteArray msg(QByteArray::fromRawData((const char *)gbtx, num));
    udpSocket->writeDatagram(msg, QHostAddress(AscIpStr), AscPort);
    emit setMainStatusBar(statusMsg);
}

void main_dialog::on_pushButton_Set_clicked()
{
    if(ui->comboBox_OP->currentText() == tr("信号机时间"))SetData(O_CurrentTime);
    else if(ui->comboBox_OP->currentText() == tr("调度计划表"))SetData(O_Schedule);
    else if(ui->comboBox_OP->currentText() == tr("时段表"))SetData(O_Plan);
    else if(ui->comboBox_OP->currentText() == tr("动作表"))SetData(O_Action);
    else if(ui->comboBox_OP->currentText() == tr("方案表"))SetData(O_Pattern);
    else if(ui->comboBox_OP->currentText() == tr("绿信比"))SetData(O_Split);
    else if(ui->comboBox_OP->currentText() == tr("相序表"))SetData(O_Sequence);
    else if(ui->comboBox_OP->currentText() == tr("相位表"))SetData(O_Phase);
    else if(ui->comboBox_OP->currentText() == tr("通道表"))SetData(O_Channel);
    else if(ui->comboBox_OP->currentText() == tr("单元参数"))SetData(O_Unit);
    else if(ui->comboBox_OP->currentText() == tr("协调参数"))SetData(O_Coord);
    else if(ui->comboBox_OP->currentText() == tr("跟随相位表"))SetData(O_Overlap);
}

void main_dialog::ReadParProcess(void)
{
    quint8 i = 0;
    if(ReadFalg != AllPar)
    {
        quint16 temp = 0x0001;
        for(i = 1; i <= 15; i++)
        {
            if((temp & ReadFalg)==0)
            {
                //ReadData(temp);
                ui->comboBox_OP->setCurrentIndex(i-1);
                on_pushButton_Read_clicked();
                ui->progressBar->setValue(i*100/15);
                break;
            }
            temp <<= 1;
        }
    }
    else
    {
        timerConnect->stop();
        ui->progressBar->setValue(0);
        ui->pushButtonConnect->setStyleSheet("background-color: rgb(80, 250, 70);");
    }
}

void main_dialog::tableViewOnlineSelectChange()
{
    quint8 selectRow = ui->tableViewOnline->currentIndex().row();
    if(OnLineModel->data(OnLineModel->index(selectRow,2)).isNull())
    {
        ui->pushButtonConnect->setEnabled(false);
    }
    else
    {
        ui->pushButtonConnect->setEnabled(true);
        AscIpStr = OnLineModel->data(OnLineModel->index(selectRow,2)).toString();
    }
}

void main_dialog::on_pushButtonConnect_clicked()
{
    qDebug() << "Connect";
    ReadFalg = 0;
    timerConnect->start(50);
}














