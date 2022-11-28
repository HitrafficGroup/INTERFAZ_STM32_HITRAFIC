#ifndef TSC_H
#define TSC_H

#include <QtCore>
//#include <QtGlobal>

typedef unsigned char   uint8_t;

#define ScheduleMax     40
#define PlanMax         16
#define PeriodMax       24
#define ActionMax       100
#define PatternMax      100
#define SequenceMax     16
#define SplitMax        20
#define OverlapMax      16

#define RingMax         4
#define IsRing(n)       ((n) > 0 && (n) <= RingMax)

#define PhaseMax        16
#define IsPhase(n)      ((n) > 0 && (n) <= PhaseMax)

//本机最大通道数量
#define ChannelMax      16
#define VehdetMax       32
#define IsVehicleDetector(n)    ((n) > 0 && (n) <= VehdetMax)

#define PeddetMax               8
#define IsPeddet(n)             ((n) > 0 && (n) <= PeddetMax)


//单元参数定义**************************************************
struct UnitType
{
    quint8     StartupFlash;       //开机黄闪时间 0-255
    quint8     StartupAllRed;      //开机全红时间 0-255
    quint8     AutomaticPedClear;  //1不能 2能    设置自动行人清空时间
    quint8     RedRevert;          //最小红灯时间 0-255
    quint16    BackupTime;         //系统设置的备份时间 0-65535
    quint8     FlowCycle;          //流量采集周期
    quint8     FlashStatus;
    quint8     Status;
    quint8     GreenConflictDetectFlag;
    quint8     RedGreenConflictDetectFlag;
    quint8     RedFailedDetectFlag;
};

//调度计划定义**************************************************
struct Schedule
{
    quint8  Number;
    quint16 Month;
    quint8  Day;
    quint32 Date;
    quint8  DayPlan;
};
struct ScheduleTable
{
    quint8   Maximum;
    Schedule schedule[ScheduleMax];
};

//时段表定义**************************************************
struct TimeType
{
    quint8 Hour;       //1
    quint8 Minute;     //2
};
struct Plan
{
    quint8  EventNum;  //时段号
    TimeType Time;     //1,2 时间
    quint8  ActionNum; //3 动作表号
};//时段表
struct PlanType
{
    quint8 Num;         //1  时段计划表号
    Plan    Period[PeriodMax]; //96 时段定义,最多分24个时间段 3*24 = 72
};//时段表
struct PlanTable
{
    quint8  Maximum;
    PlanType Plan[PlanMax];       //16 * 73
};  //时段表 16*74 = 1184 = 0x04A0

//动作定义**************************************************
struct ActionType
{
    quint8 Num;        //1 动作号1-255
    quint8 PatternNum; //2 方案号0-255
    quint8 Auxillary;  //3 辅助功能
    quint8 Special;    //4 特殊功能
};  //动作表 信息
typedef struct
{
    quint8 Maximum;
    ActionType Action[ActionMax];
}ActionTable;

//方案定义**************************************************
struct PatternType
{
    quint8     Number;
    quint16    CycleTime;
    quint8     OffsetTime;
    quint8     SplitNumber;
    quint8     SequenceNumber;
    quint8     WorkMode;
};
struct PatternTable  //方案表
{
    quint8 Maximum;
    PatternType Pattern[PatternMax];  //7*100
};

//绿信比定义**************************************************
struct Split
{
    quint8 Phase;
    quint8 Time;
    quint8 Mode;
    quint8 Coord;
};
struct Split_Type
{
    quint8 Num;     //绿信比号
    Split  Phase[PhaseMax];    //16
};//绿信比数据
struct SplitTable
{
    quint8 Maximum;
    Split_Type  Split[SplitMax];                //20
};

//相序定义**************************************************
struct SequenceType
{
    quint8 RingNum;            //环号
    quint8 Phase[PhaseMax];    //环相序
};  //环相序定义
struct Sequence_Type
{
    quint8             Num;            //相序号
    SequenceType    Ring[RingMax];  //环相序定义 4个环
};//相序表信息
struct SequenceTable
{
    quint8 Maximum;
    Sequence_Type Seq[SequenceMax];     //16
};//相序表  16 + (17*4+1)*16 = 1120 = 0x0460

//相位定义**************************************************
struct Phase
{
    quint8 Number;           //1
    quint8 Walk;             //2
    quint8 PedestrianClear;  //3
    quint8 MinimumGreen;     //4
    quint8 Passage;          //5

    quint8 Maximum1;         //6
    quint8 Maximum2;         //7
    quint8 YellowChange;     //8
    quint8 RedClear;         //9
    quint8 RedRevert;        //10

    quint8 AddedInitial;     //11
    quint8 MaximumInitial;   //12
    quint8 TimeBeforeReduction;//13
    quint8 CarsBeforeReduction;//14
    quint8 TimeToReduce;     //15

    quint8 ReduceBy;         //16
    quint8 MinimumGap;       //17
    quint8 DynamicMaxLimit;  //18
    quint8 DynamicMaxStep;   //19
    quint8 Startup;          //20

    quint8  Ring;            //21
    quint8  VehicleClear;    //22
    quint16 Options;         //23
    quint32 Concurrency;     //24
    quint32 ReleasePhase;    //放行的通道
};
struct PhaseTable
{
    quint8 Maximum;
    Phase phase[PhaseMax];
};

//通道定义**************************************************
struct Channel
{
    quint8 Num;            //通道号
    quint8 ControlSource;  //控制源
    quint8 ControlType;    //控制类型
    quint8 Flash;          //闪光模式
    quint8 Dim;            //辉度模式
    quint8 Position;       //
    quint8 Direction;      //
    quint8 CountdownID;    // ……考虑独立一张倒计时配置表
}; //通道数据定义
struct ChannelTable
{
    quint8 Maximum;//最大通道设计数量32
    Channel channel[ChannelMax];
};
struct ChannelStatusType//每bit代表一个通道的对应颜色状态
{
    quint32 Reds;
    quint32 Yellows;
    quint32 Greens;
    quint32 Flash;     //1闪，0不闪
};


//协调定义**************************************************
#define CoordAutomatic      0
#define CoordManualFree     254
#define CoordManualFlash    255

struct CoordType    //协调表
{
    quint8 OperationalMode;   //协调运行模式 0自动 1-253手动方案 254本地感应 255闪光
    quint8 CorrectionMode;    //协调校正方式 1其他 2驻留等待 3平滑过渡 4仅增加
    quint8 MaximumMode;       //协调最大方式 1其他 2最大1 3最大2 4最大约束
    quint8 ForceMode;         //协调强制方式 1其他 2浮动 3固定
};
//跟随相位定义**************************************************
struct OverlapType
{
    quint8 Num;                //编号 1-255
    quint8 Type;               //类型 1其他 2常规 3黄绿停止
    quint16 IncludedPhases;    //母相位 所跟随放行的机动车相位
    quint16 ModifierPhases;    //修正相位
    quint8 TrailGreen;         //跟随绿灯 0-255 跟随相位跟随母相位结束放行绿灯后，继续放行的绿灯时间，单位：秒。
    quint8 TrailClear;
    quint8 TrailYellow;        //跟随黄灯 0-255 当跟随相位的绿灯或绿闪时间不为零时，放行的黄灯时间。绿灯和绿闪时间都为零时，黄灯时间使用母相位黄灯时间。
    quint8 TrailRed;           //跟随红灯 0-255 当跟随相位的绿灯或绿闪时间不为零时，放行的全红时间。绿灯和绿闪时间都为零时，全红时间使用母相位全红时间。
}; //跟随相位

struct OverlapTable
{
    quint8 Maximum;
    OverlapType Overlap[OverlapMax];
}; //跟随相位表

/****************************************************************
NoActivity : 行人检测器故障诊断参数，分钟（0–255分钟）。如果有源探测器在规定时间无动作，则将其诊断为故障，并将探测器分类为故障。此对象的值为0时，将禁用此探测器的诊断。
MaxPresence: Pedestrian Detector Maximum Presence diagnostic Parameter in minutes (0-255 min.).
             If an active detector exhibits continuous detection for too long a period,
             it is considered a fault by the diagnostics and the detector is classified as Failed.
             A value of 0 for this object shall disable this diagnostic for this detector.
*/

struct Peddet
{
    quint8 Num;            //编号 1-8
    quint8 CallPhase;      //
    quint8 NoActivity;     //
    quint8 MaxPresence;    //
    quint8 ErraticCounts;  //
    quint8 Alarms;         //
};//行人检测器

struct PeddetTable
{
    quint8 Maximum;
    Peddet peddet[PeddetMax];
};//行人检测器表


struct PeddetState
{
    quint8  Valid;
    quint8  Alarms;
    quint16 NoActivity;
    quint16 Presence;
    quint16 ErraticCounts;
};

struct PeddetStateTable
{
    PeddetState peddet[PeddetMax];
    quint8      Maximum;
};
/*****************************************************************/

//Options bits
#define VDO_require             0x80
#define VDO_queue               0x40
#define VDO_strategy            0x20
#define VDO_extend              0x10
#define VDO_redRequireLock      0x08
#define VDO_yellowRequireLock   0x04
#define VDO_recordOccupancy     0x02
#define VDO_recordFlow          0x01

struct Vehdet //15
{
    uint8_t Num;            //检测器编号
    uint8_t Options;        //检测器选项
    uint8_t CallPhase;      //请求相位  车辆检测器对应的机动车相位，当该检测器检测到车辆通过的信号时，对应的请求相位将做出反应。
    uint8_t SwitchPhase;    //开关相位  检测器转换相位参数，当指定相位是黄灯或红灯且转换相位是绿灯时，车辆检测器感应将转换到该相位
    uint8_t Extend;         //延长绿    在感应控制下，请求相位绿灯时间延长一次的时间。功能与相位参数的单位延长绿相同。但它只在选择“使用检测器的延长绿”选项后才有效，反之使用“请求相位”的单位延长绿
    uint8_t QueueLimit;     //队列限制  检测器排队限制参数，单位：秒。
    uint8_t NoActivity;     //无响应时间         检测器在该段时间内，没有检测到车辆通过，表示该检测器出现故障，该故障被信号机记入故障日志。该值为零时，该项功能不启用。单位为：分钟。
    uint8_t MaxPresence;    //最大持续响应时间   检测器在该段时间内，一直检测到车辆通过，表示该检测器出现故障，该故障被信号机记入故障日志。该值为零时，该项功能不启用。单位为：分钟。
    uint8_t ErraticCounts;  //最大车辆数    检测器不确定计数诊断参数。如果一个活动检测器出现感应过强，诊断设备就认为存在故障，该检测器被认为是失败的。如果将这个对象的值设为零，将关闭对该检测器的诊断，单位：次/分钟。
    uint8_t FailTime;       //失败时间      检测器的请求在没有得到响应之前，如果失败时间内没有任何请求，则取消本次记录的请求，不再予以响应。
    uint8_t Alarms;         //故障
    uint8_t ReportedAlarms; //报警
    uint8_t Reset;          //重置0-1       重置操作放到检测器状态里面
    uint8_t Reserve;
    uint16_t Delay;         //延迟      检测器的请求时间达到延迟时间设置的长度，才记录一次请求,标准单位10S
};

struct VehdetTable
{
    Vehdet vehdet[VehdetMax];
};

/*****************************************************************/
typedef enum
{
    WMR_Normal = 0,
    WMR_LocalManual,
    WMR_RemoteManual,
    WMR_RemoteGuard,

    WMR_NoDayPlan = 0xA0,
    WMR_NoAction,
    WMR_NoPattern,
    WMR_NoSequence,
    WMR_NoSplit,
    WMR_RedGreenConflict,
    WMR_GreenConflict,
    WMR_RedFailed,
    WMR_WMR_NoPar,
    WMR_Hardware,
    WMR_Other = 0xff,
}WorkMode_Reason_Type;

/*****************************************************************/
#define SPECIAL_MODE    0xA0
typedef enum
{
    StarupMode  = 0,        //起动时序
    FixedTime,              //01固定配时
    LineCtrl,               //02本地无电缆线控
    VehicleSense,           //03单点感应
    Flashing,               //04时段闪光
    AllRed,                 //时段设定全红
    LampOff,                //时段设定关灯

    /*****************************************/
    //本地手动
    ManualStep = 0xA0,      //手动步进
    ManualAppoint,          //本地指定放行
    ManualFlashing,         //本地手动黄闪
    ManualAllRead,          //本地手动黄闪
    ManualLampOff,          //本地手动黄闪

    NoPatternFlash,         //无方案黄闪
    ConflictFlash,          //冲突黄闪
    ErrorOff,               //故障关灯

    LampTestMode,           //测试专用指令,可用于测试输出或者内部软硬件测试.
    DegradingFlashing = 0xD0,
    DegradingLampOff,
}RUN_MODE;



/* 协议状态标识 */
#define Frame_right         0xa0
#define Frame_wrong         0xa1
#define CheckSum_failed     0xa2
#define Unsupport_OT        0xa3
#define Unsupport_DL        0xa4
#define Unsupport_OB        0xa5
#define DataError           0xa6

//0帧头-1版本-2发送-3接收-4链路-5区域-6路口高-7路口低-8操作-9对象-10保留-*数据*-校验-帧尾
//通讯协议数据定义
#define frame_head  0xC0
#define frame_tail  0xC0
#define frame_ver   0x20
#define ID_PC       0x20
#define ID_TSC      0x10

//data link code 数据链路码
#define DL_Com              0x01
#define DL_BasicInfo        0x02
#define DL_CharacPar        0x03
#define DL_Intervention     0x04

//Operation type操作类型
#define OT                  0x80
#define OT_Query            0x80
#define OT_Set              0x81
#define OT_InitiativeReport 0x82
#define OT_QueryAnswer      0x83
#define OT_SetAnswer        0x84
#define OT_ErrorAnswer      0x85

//Object对象标识
#define O_Linking         0x01
#define O_TrafficFlow     0x02
#define O_WorkState       0x03
#define O_SignalState     0x04
#define O_CurrentTime     0x05
#define O_Channel         0x06
#define O_Phase           0x07
#define O_Pattern         0x08
#define O_Schedule        0x09
#define O_WorkMode        0x0a
#define O_Error           0x0b
#define O_Version         0x0c
#define O_CharacParVer    0x0d
#define O_IDCODE          0x0e
#define O_RemoteControl   0x0f
#define O_Vehdet          0x10
#define O_Plan            0x11
#define O_Action          0x12
#define O_Sequence        0x13
#define O_Split           0x14
#define O_Unit            0x15
#define O_Coord           0x16
#define O_Overlap         0x17
#define O_Peddet          0x18

#define O_PeddetState     0x28

#define O_Alarm           0xA0
#define O_BasicInfo       0xBD
#define O_DeviceInfo      0xBE
#define O_Call            0xBF  //不超过0xC0


#define TypeAlarm_Light         0x10
#define TypeAlarm_Detetor       0x30
#define TypeAlarm_Device        0x40
#define TypeAlarm_Environment   0x60

#define DoorState       0x70




//O_RemoteControl远程控制 指令码
#define Restart         0x24
#define Shutdown        0x25
#define ExtendTime      0x26
#define ClearError      0x27
#define Manual_auto     0x30//恢复自动
#define Manual_start    0x31//手控开始

//手控模式
#define Manual_NONE             0x00
#define Manual_yellowflash      0x30//
#define Manual_allred           0x31
#define Manual_lampoff          0x32
#define Manual_nextphase        0x33
#define Manual_appoint          0x34

//手控指定放行 方位码
#define MANUAL_POS_Other       ((uint8_t)0x00)     //其他
#define MANUAL_POS_East        ((uint8_t)0x01)     //东
#define MANUAL_POS_South       ((uint8_t)0x02)     //南
#define MANUAL_POS_West        ((uint8_t)0x04)     //西
#define MANUAL_POS_North       ((uint8_t)0x08)     //北
#define MANUAL_POS_NorthEast   ((uint8_t)0x10)     //东北
#define MANUAL_POS_SouthEast   ((uint8_t)0x20)     //东南
#define MANUAL_POS_SouthWest   ((uint8_t)0x40)     //西南
#define MANUAL_POS_NorthWest   ((uint8_t)0x80)     //西北

//手控指定放行 方向码
#define MANUAL_DIR_Other       ((uint8_t)0x00)     //其他
#define MANUAL_DIR_Left        ((uint8_t)0x01)     //左转
#define MANUAL_DIR_Straight    ((uint8_t)0x02)     //直行
#define MANUAL_DIR_Right       ((uint8_t)0x04)     //右转
#define MANUAL_DIR_Pedestrian  ((uint8_t)0x08)     //人行
#define MANUAL_DIR_Turn        ((uint8_t)0x10)     //掉头
#define MANUAL_DIR_Bicycle     ((uint8_t)0x20)     //自行车


//保留字数据
#define Reserve_Data      0x01


#define TimePar         0x0001
#define SchedulePar     0x0002
#define PlanPar         0x0004
#define ActionPar       0x0008
#define PatternPar      0x0010
#define SplitPar        0x0020
#define SequencePar     0x0040
#define PhasePar        0x0080
#define ChannelPar      0x0100
#define UnitPar         0x0200
#define CoordPar        0x0400
#define OverlapPar      0x0800
#define DevicePar       0x1000
#define BasicPar        0x2000
#define PeddetPar       0x4000
#define VehdetPar       0x8000

#define AllPar          0x00003FFF  //0x00007FFF


typedef struct
{
    quint8 Head;
    quint8 Version;
    quint8 Sendid;
    quint8 Reciveid;

    quint8 DataLinkCode;
    quint8 AreaNum;
    quint8 IntersectionH;
    quint8 IntersectionL;

    quint8 OperationType;
    quint8 ObjectCode;
    quint8 Reserve;
}GBMSG_TYPE;





#endif // TSC_H
