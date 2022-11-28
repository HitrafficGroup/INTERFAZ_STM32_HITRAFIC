#ifndef main_dialog_H
#define main_dialog_H

#include <QTableView>
#include <QMainWindow>
#include <QStandardItemModel>

#include <QMessageBox>
#include <QInputDialog>

//https://www.baidu.com/
#include <QtNetwork/QNetworkInterface>
#include <QTcpSocket>
#include <QUdpSocket>

#include <QtSql>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include "schedule_dialog.h"
#include "plan_dialog.h"
#include "action_dialog.h"
#include "pattern_dialog.h"
#include "sequence_dialog.h"
#include "split_dialog.h"
#include "peddet_dialog.h"
#include "vehdet_dialog.h"
#include "phase_dialog.h"
#include "channel_dialog.h"
#include "overlap_dialog.h"
#include "readonlydelegate.h"
#include "ItemDelegate.h"

namespace Ui {
class main_dialog;
}

class main_dialog : public QDialog
{
    Q_OBJECT

public:
    main_dialog(QWidget *parent = 0);
    ~main_dialog();
protected:
    void closeEvent(QCloseEvent *e);
    /* 表格框架的构建和显示 */
    void SignalStateTableShow();
    void ChannelTableShow(void);
    void PhaseTableShow(void);
    void PatternTableShow(void);
    void SplitTableShow(void);
    void SequenceTableShow(void);
    void ActionTableShow(void);
    void PlanTableShow(void);
    void ScheduleTableShow(void);
    void OverlapTableShow(void);
    void VehdetTableShow(void);
    void PeddetTableShow(void);
    void PeddetStateTableShow(void);
    void PreemptTableShow(void);

    void OnLineTableShow(void);//在线表格的显示


    /* 初始化部分数据 */
    void datainit(void);

    /* 读取数据库，初始化参数 */
    void UnitInit(void);
    void ScheduleTabInit(void);
    void PlanTabInit(void);
    void ActionTabInit(void);
    void PatternTabInit(void);
    void SequenceTabInit(void);
    void SplitTabInit(void);
    void PhaseTabInit(void);
    void ChannelTabInit(void);
    void OverlapTabInit(void);
    void VehdetDataInit(void);
    void PeddetDataInit(void);
    void PreemptDataInit(void);

    /* 参数显示到表格中 */
    void tableSignalStateShowData(void);
    void tableChannelShowData(void);
    void tablePhaseShowData(void);
    void tableScheduleShowData(void);
    void tableActionShowData(void);
    void tablePatternShowData(void);
    void tableOverlapShowData(void);
    void tableVehdetShowData(void);
    void tablePeddetShowData(void);
    void tablePeddetStateShowData(void);

    void CalcPatternCycleTime(void);//计算所有方案的周期
    QString WorkModeStr(quint8 mode);

signals:
    void setMainStatusBar(QString);
    void ScheduleDataSet(Schedule);
    void PlanDataSet(Plan);
    void ActionDataSet(ActionType);
    void PatternDataSet(PatternType);
    void SequenceDataSet(SequenceType);
    void SplitDataSet(Split);
    void PhaseDataSet(Phase);
    void ChannelDataSet(Channel);
    void OverlapDataSet(OverlapType);
    void VehdetDataSet(Vehdet);
    void PeddetDataSet(Peddet);

private slots:
    void OpenDatabase(QString newtsc);
    void SaveDatabase(void);
    void ReadParProcess(void);

    void tablePlanShowData(int PlanIndex);
    void tableSplitShowData(int SplitIndex);
    void tableSequenceShowData(int SequenceIndex);

    void SetData(quint8 Object_id);
    void ReadData(quint8 Object_id);

    void SendEditSchedule(void);
    void SendEditPlan(void);
    void SendEditAction(void);
    void SendEditPattern(void);
    void SendEditSequence(void);
    void SendEditSplit(void);
    void SendEditPhase(void);
    void SendEditChannel(void); //双击通道表的槽函数
    void SendEditOverlap(void);
    void SendEditPeddet(void);
    void SendEditVehdet(void);

    void manual_unselect(void);

    void ScheduleDataReceive(Schedule schedule);
    void PlanDataReceive(Plan plan);
    void ActionDataReceive(ActionType action);
    void PatternDataReceive(PatternType pattern);
    void SequenceDataReceive(SequenceType sequence);
    void SplitDataReceive(Split split);
    void PhaseDataReceive(Phase phase);
    void ChannelDataReceive(Channel channel);
    void OverlapDataReceive(OverlapType Overlap);
    void PeddetDataReceive(Peddet peddet);
    void VehdetDataReceive(Vehdet vehdet);
    void readPendingDatagrams();

    void tablePatternSelectChange(void);
    void tableActionSelectChange(void);
    void tablePhaseSelectChange(QModelIndex index);
    void tableViewOnlineSelectChange(void);

    void DoorStateShow(bool stateflag, bool statusflag);
    void WorkState(quint8* rx_var);

    void on_pbPattern_delete_clicked();
    void on_pbPattern_copy_clicked();
    void on_pbPhase_copy_clicked();
    void on_pbPhase_delete_clicked();
    void on_pushButton_SplitDelRow_clicked();
    void on_pushButton_Save_clicked();
    void on_pushButton_OpenSocket_clicked();
    void on_pushButton_Read_clicked();
    void on_pushButton_Set_clicked();

    void on_pushButton_ActionDelete_clicked();
    void on_pushButton_ActionCopy_clicked();
    void on_pushButton_PeriodDelete_clicked();
    void on_pushButton_ScheduleDelete_clicked();
    void on_pushButtonSearch_clicked();
    void on_pushButtonConnect_clicked();

    void on_pushButton_OverlapDelete_clicked();

    void on_pushButton_OverlapCopy_clicked();

    void on_pbPhase_set_clicked();

    void on_pushButton_sequenceSet_clicked();

    void on_pushButton_SplitSet_clicked();

    void on_pbPattern_set_clicked();

    void on_pushButton_ActionSet_clicked();

    void on_pushButton_PeriodSet_clicked();

    void on_pushButton_ScheduleSet_clicked();

    void on_pushButton_OverlapSet_clicked();

    void on_pushButton_ChannelSet_clicked();

    void on_pushButton_BasicInfoRead_clicked();

    void on_pushButton_DeviceInfoRead_clicked();

    void on_pbPhase_read_clicked();

    void on_pushButton_sequenceRead_clicked();

    void on_pushButton_SplitRead_clicked();

    void on_pbPattern_read_clicked();

    void on_pushButton_PeriodRead_clicked();

    void on_pushButton_ScheduleRead_clicked();

    void on_pushButton_OverlapRead_clicked();

    void on_pushButton_UnitRead_clicked();

    void on_pushButton_ChannelRead_clicked();

    void on_pushButton_ActionRead_clicked();

    void on_pushButton_CoordRead_clicked();

    void on_pushButton_TimeRead_clicked();

    void on_pushButton_BasicInfoSet_clicked();

    void on_pushButton_TimeSet_clicked();

    void on_pushButton_DeviceInfoSet_clicked();

    void on_pushButton_StateMonitoring_clicked();

    void on_pushButton_PeddetDelete_clicked();

    void on_pushButton_PeddetRead_clicked();

    void on_pushButton_PeddetSet_clicked();

    void on_pushButton_UnitSet_clicked();

    void on_pushButton_ClearError_clicked();

    void on_pushButton_PeddetState_clicked();

    void on_pushButton_manual_clicked();

    void on_pushButton_VehdetRead_clicked();

    void on_pushButton_VehdetDelete_clicked();

    void on_pushButton_VehdetSet_clicked();

private:
    Ui::main_dialog *ui;
    schedule_dialog *schedule_dlg;
    channel_dialog  *channel_dlg;
    phase_dialog    *phase_dlg;
    pattern_dialog  *pattern_dlg;
    split_dialog    *split_dlg;
    sequence_dialog *sequence_dlg;
    plan_dialog     *plan_dlg;
    action_dialog   *action_dlg;
    overlap_dialog  *overlap_dlg;
    peddet_dialog   *peddet_dlg;
    vehdet_dialog   *vehdet_dlg;

    QSqlDatabase db;
    QStandardItemModel *PeddetStateModel;
    QStandardItemModel *SignalStateModel;
    QStandardItemModel *ChannelModel;
    QStandardItemModel *PhaseModel;
    QStandardItemModel *PatternModel;
    QStandardItemModel *SplitModel;
    QStandardItemModel *SequenceModel;
    QStandardItemModel *SequenceModel2;
    QStandardItemModel *ActionModel;
    QStandardItemModel *PlanModel;
    QStandardItemModel *ScheduleModel;
    QStandardItemModel *OverlapModel;
    QStandardItemModel *VehdetModel;
    QStandardItemModel *PeddetModel;
    QStandardItemModel *PreemptModel;
    QStandardItemModel *OnLineModel;

    QStringList channelControlTypeStrList;
    QStringList channelFlashStrList;
    QStringList channelDimStrList;
    QStringList channelPositionStrList;
    QStringList channelDirectionStrList;
    QStringList SplitModeStrList;
    QStringList WeekList;
    QStringList OverlapTypeList;
    QStringList WorkModeList;

    QString         ParName;
    UnitType        Unit;
    ScheduleTable   ScheduleTab;
    ActionTable     ActionTab;
    PhaseTable      PhaseTab;
    ChannelTable    ChannelTab;
    ChannelStatusType ChannelStatus;
    SplitTable      SplitTab;
    SequenceTable   SeqTab;
    PlanTable       PlanTab;
    PatternTable    PatternTab;
    OverlapTable    OverlapTab;
    CoordType       Coord;
    VehdetTable     VehdetTab;
    PeddetTable     PeddetTab;
    PeddetStateTable PeddetStateTab;

    QUdpSocket      *udpSocket;
    QMetaObject::Connection udpcon;
    quint8 gbtx[2048];
    quint8 temp_var[2048];
    quint8 rx_var[2048];
    quint8 deviceInfoBuf[48];
    quint8 mac[6];

    QTimer *timerConnect;
    QString RemoteIPAddressStr;
    quint16 RemotePort;

    bool netOpenFlag = false;

    quint8 areaNum;
    quint8 inteNumL;
    quint8 inteNumH;
    quint8 OnLineCount;
    quint16 AscPort;
    QString AscIpStr;

    quint16 ReadState;
    quint16 ReadReg;
    quint32 ReadFalg;
    quint32 WriteFalg;

    QBrush gre;
    QBrush yel;
    QBrush red;
    QBrush gra;
};


#endif // main_dialog_H
