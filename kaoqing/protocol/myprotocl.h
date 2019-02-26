#ifndef MYPROTOCL_H
#define MYPROTOCL_H
#include <QString>
#include <QByteArray>

#define OPERATE_NONE 0   //无操作
#define COMMAND_NONE 0   //无命令
#define LENGTH_NONE 0    //无长度
#define STATU_NONE 0     //无身份信息

enum STATUS{
    ADMINISTRATOR = 0,   //管理员身份
    MANAGER,             //经理身份
    EMPLOYEE             //员工身份
};

enum OPERATE{
    LONGIN = 0,          //登录
    PUNCH_THE_CLOCK,     //打卡
    EXAMINE_AND_APPROVE, //审批
    ACTUALLY_HAPPENING,  //实况
    ALL_VERSION,         //总览
    MONTH_VERSION,       //月视图
    TABLE_COUNT,         //报表统计
    SET,                 //设置
    MY_ATTENDANCE,       //我的考勤
    ATTENDANCE_POINT,    //考勤点
    QUIT                 //退出
};

enum EXAMINE_AND_APPROVE_COMMAND{
    APPLY_BUDAKA = 0,    //申请补打卡
    APPLY_BUDAKA_WATCH,  //审批表格查看
    APPLY_VACATION,      //申请休假
    APPLY_JIABAN,        //申请加班
    APPLY_AGREE,         //审批通过
    APPLY_FALSE          //审批不通过
};

enum LONGIN_COMMAND{
    LOGIN = 0,           //登录
    REGISTER,            //注册
    KAOQIN,              //进入考勤页面的登录
    FORGET_COM_NAME,     //忘记公司名称
    FIND_PWD,            //找回密码
    QUIT_LOG             //退出登录
};

enum PUNCH_THE_CLOCK_COMMAND{
    DAKA = 0,            //打卡
    START_WORK,          //上班
    AFTER_WORK           //下班
};

enum SET_COMMAND{
    EMPLOYEE_ADMINISTRATE = 0, //员工管理
    EMPLOYEE_ADMINISTRATE_WATCH,//查看员工信息
    COMPANY_SETTING,           //公司设置
    PART_ADMINISTRATE,         //部门管理
    PART_ADMINISTRATE_WATCH,   //查看部门信息
    MANAGER_SETTING,           //经理设置
    VACATION_TYPE,             //休假类型
    CLASS_TYPE,                //班次类型
    PERSONAL_SETTING,          //个人设置
    PERSON_PWD                 //修改个人密码
};

class Myprotocl
{
public:
    Myprotocl();
    void initMsgPackage(void);
    void clearMsgPackage(void);
    void updataMsg(Myprotocl *protocol);

    QByteArray *updataMsg(const QByteArray msgName,
                          const QByteArray msgCompanyName,
                          const qint16 msgstatus,
                          const qint16 msgoperate,
                          const qint16 msgcommand,
                          const QString content,
                          const qint16 msglength);
    QByteArray *packageMsg(void);
    void unpackageMsg(QDataStream &in);

    QByteArray getMsgName(void) const;
    void setMsgName(const QByteArray msgname);
    QByteArray getMsgCompany_name(void) const;
    void setMsgCompany_name(const QByteArray company_name);
    qint16 getMsgStatus(void) const;
    void setMsgStatus(const qint16 status);
    qint16 getMsgOperate(void) const;
    void setMsgOperate(const qint16 operate);
    qint16 getMsgCommand(void) const;
    void setMsgCommand(const qint16 command);
    QString getMsgContent(void) const;
    void setMsgContent(const QString content);
    qint16 getMsgLength(void) const;
    void setMsgLength(const qint16 length);

public:
    QByteArray name;          //放名字
    QByteArray company_name;  //放公司名字
    qint16 status;         //放身份信息
    qint16 operate;        //放操作
    qint16 command;        //放命令
    QString m_content;     //放内容
    qint16 m_length;       //放数据长度
};

#endif // MYPROTOCL_H
