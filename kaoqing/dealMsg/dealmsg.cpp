#include "dealmsg.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"

dealMsg::dealMsg(QWidget *parent)
{

}

void dealMsg::judge_msg(Myprotocl *msg)
{
    switch(msg->getMsgOperate())
    {
        case LONGIN:
            switch(msg->getMsgCommand())
            {
                case LOGIN:dealLogin(msg);break;
                case REGISTER:dealRegister(msg);break;
                case FIND_PWD:break;
                case QUIT_LOG:break;
                case FORGET_COM_NAME:dealforget(msg);break;
                case KAOQIN:dealkaoqin(msg);break;
            }break;
        case PUNCH_THE_CLOCK:
            switch (msg->getMsgCommand())
            {
                case DAKA:dealdaka(msg);break;
                case START_WORK:dealStartWork(msg);break;
                case AFTER_WORK:dealStartWork(msg);break;
                default:break;
            }break;
        case SET:
           switch(msg->getMsgCommand())
           {
                case EMPLOYEE_ADMINISTRATE:dealemployee(msg);break;
                case EMPLOYEE_ADMINISTRATE_WATCH:dealEmployeeWatch(msg);break;
                case PART_ADMINISTRATE:dealInsertDepartment(msg);break;
                case PART_ADMINISTRATE_WATCH:dealDepartmentWatch(msg);break;
                case MANAGER_SETTING:dealManagerWatch(msg);break;
                case PERSONAL_SETTING:deaPersonMsg(msg);break;
                case PERSON_PWD:dealChangePWD(msg);break;
           }break;
        case EXAMINE_AND_APPROVE:
           switch(msg->getMsgCommand())
           {
                case APPLY_BUDAKA:dealApplyBudaka(msg);break;
                case APPLY_BUDAKA_WATCH:
                    switch(msg->getMsgStatus())
                    {
                    case ADMINISTRATOR:dealApplyBudakaWatch(msg);break;  //以管理员身份查看
                    case EMPLOYEE:dealApplyBudakaWatchEmloyee(msg);break;   //以普通员工身份查看
                    }break;
                case APPLY_AGREE:dealApplyAgree(msg);break;
           }break;
        case ACTUALLY_HAPPENING:
            switch(msg->getMsgCommand())
            {
                case COMMAND_NONE:dealActuallyHappening(msg);break;
                case EMPLOYEE_ADMINISTRATE_WATCH:dealActuallyHappeningchoose(msg);break;
            }break;
        case ALL_VERSION:
            switch(msg->getMsgCommand())
            {
                case COMMAND_NONE:dealAllVersion(msg);break;
                case EMPLOYEE_ADMINISTRATE_WATCH:dealAllVersionChoose(msg);break;
            }break;
        case MONTH_VERSION:
           switch(msg->getMsgCommand())
           {
                case COMMAND_NONE:dealMonthVersion(msg);break;
                case EMPLOYEE_ADMINISTRATE_WATCH:dealMonthVersionChoose(msg);break;
           }
    }
}

void dealMsg::dealStartWork(Myprotocl *msg)
{
    emit startWork(msg);   //成功打卡上下班的信号
}

void dealMsg::dealMonthVersionChoose(Myprotocl *msg)
{
    cout << msg->getMsgContent();
    emit signalMonthVersionChoose(msg->getMsgContent());
}

void dealMsg::dealMonthVersion(Myprotocl *msg)
{
    emit signalMonthVersion(msg->getMsgContent());
}

void dealMsg::dealAllVersionChoose(Myprotocl *msg)
{
    emit signalAllVersionChoose(msg->getMsgContent());
}

void dealMsg::dealAllVersion(Myprotocl *msg)
{
    emit signalAllVersion(msg->getMsgContent());
}

void dealMsg::dealActuallyHappeningchoose(Myprotocl *msg)  //combox选择
{
//    cout << msg->getMsgContent();
    emit signalActuallyHappeningchoose(msg->getMsgContent());
}

void dealMsg::dealActuallyHappening(Myprotocl *msg)  //实况
{
//    cout << msg->getMsgContent();
    emit signalActuallyHappening(msg->getMsgContent());
}

void dealMsg::dealApplyBudakaWatchEmloyee(Myprotocl *msg)
{
    cout << msg->getMsgContent();
    emit ApplyBudakaWatchEmloyee(msg->getMsgContent());
}

void dealMsg::dealApplyAgree(Myprotocl *msg)
{

}

void dealMsg::dealApplyBudakaWatch(Myprotocl *msg)
{
    emit shenpiWatch(msg->getMsgContent());
}

void dealMsg::dealApplyBudaka(Myprotocl *msg)
{
    if(msg->getMsgContent() == "ok")
    {
    }
}

void dealMsg::dealChangePWD(Myprotocl *msg)
{
    if(msg->getMsgContent() == "ok")
    {
        emit succeed_changepwd();
    }
}

void dealMsg::deaPersonMsg(Myprotocl *msg)
{
    if(msg->getMsgContent() == "true")
    {
        emit setchangepsw_true(0);
    }else if(msg->getMsgContent() == "false")
    {
        emit setchangepsw_true(1);
    }
}

void dealMsg::dealManagerWatch(Myprotocl *msg)
{
    emit dapartmentWatch(msg->getMsgContent());
}

void dealMsg::dealDepartmentWatch(Myprotocl *msg)
{
//    qDebug()<<msg->getMsgContent();
    emit dapartmentWatch(msg->getMsgContent());
}

void dealMsg::dealInsertDepartment(Myprotocl *msg)
{
    if(msg->getMsgContent() == "ok")
    {
        emit insertDepartment();
    }
}

void dealMsg::dealEmployeeWatch(Myprotocl *msg)
{
    QString str = msg->getMsgContent();
//    qDebug()<<str;
    emit employeeWatch(str);
}

void dealMsg::dealemployee(Myprotocl *msg)
{
    if(msg->getMsgContent() == "ok")
    {
        emit insertEmployee();
    }
}

void dealMsg::dealkaoqin(Myprotocl *msg)
{
    if(msg->getMsgStatus() == ADMINISTRATOR)
    {
        if(msg->getMsgContent() == "ok")
        {
            emit log_kaoqin();
        }
    }
    else
    {
        emit log_person();
    }

}

void dealMsg::dealRegister(Myprotocl *msg)
{
    if(msg->getMsgContent() == "ok")
    {
        emit register_ok();   //成功注册，发送成功注册信号
    }else
    {
        emit register_fail();  //注册失败，发送失败注册信号
    }
}

void dealMsg::dealdaka(Myprotocl *msg)    //如果姓名和密码都正确，则发送成功登录信号
{
    if(msg->getMsgContent() == "ok")
    {
        emit pwd_correct();
        msg->setMsgContent("");
    }else    //姓名密码不正确
    {
        emit pwderror();
        msg->setMsgContent("");
    }
}

void dealMsg::dealforget(Myprotocl *msg)
{
    if(msg->getMsgContent() == "forget_ok")
    {
        emit com_name(msg->getMsgCompany_name());
        msg->setMsgContent("");
    }
}

void dealMsg::dealLogin(Myprotocl *msg)
{
    if(msg->getMsgContent() == "ok")  //如果成功查找到该公司名，说明公司存在  发送信号 让其成功进入用户登录界面
    {
        emit succeed_login();    //成功进入用户登录界面
    }
    else
    {
        emit failure_login();     //未能找到公司注册的名字，说明该公司还没有注册
    }
    msg->setMsgContent("");
}
