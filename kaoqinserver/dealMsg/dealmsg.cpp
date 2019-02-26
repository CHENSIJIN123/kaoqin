#include "dealmsg.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<":" << __LINE__<<"]"

dealMsg::dealMsg()
{
}

void dealMsg::judge_operator(Myprotocl *msg)
{
    switch(msg->getMsgOperate())
    {

        case LONGIN:
            switch(msg->getMsgCommand())
            {
                case LOGIN:             dealLogin(msg);break;
                case REGISTER:          dealRegister(msg);break;
                case FIND_PWD:          break;
                case QUIT_LOG:          break;
                case FORGET_COM_NAME:   dealforget(msg);break;
                case KAOQIN:            dealkaoqin(msg);break;
            }break;
        case PUNCH_THE_CLOCK:
            switch(msg->getMsgCommand())
            {

                case DAKA:              dealdaka(msg);break;
                case START_WORK:        dealStartWork(msg,QString("上班"));break;
                case AFTER_WORK:        dealStartWork(msg,QString("下班"));break;
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
                    case ADMINISTRATOR:dealApplyBudakaWatch(msg);break;   //以管理员身份查看
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

void dealMsg::dealMonthVersionChoose(Myprotocl *msg)
{
    exec.sqlMonthVersionChoose(msg);
}

void dealMsg::dealMonthVersion(Myprotocl *msg)
{
    if(false == exec.sqlMonthVersion(msg))
    {
        msg->setMsgContent("");
    }
}

void dealMsg::dealAllVersionChoose(Myprotocl *msg)
{
    exec.sqlAllVersionChoose(msg);
}

void dealMsg::dealAllVersion(Myprotocl *msg)
{
    exec.sqlAllVersion(msg);
}

void dealMsg::dealActuallyHappeningchoose(Myprotocl *msg)
{
    exec.sqlActuallyHappeningchoose(msg,msg->getMsgContent());
}

void dealMsg::dealActuallyHappening(Myprotocl *msg)
{
    exec.sqlActuallyHappening(msg);
}

void dealMsg::dealApplyBudakaWatchEmloyee(Myprotocl *msg)
{
    exec.sqlApplyBudakaWatchEmloyee(msg);
}

void dealMsg::dealApplyAgree(Myprotocl *msg)
{
    if(true == exec.sqldealApplyAgree(msg))
    {
    }
}

void dealMsg::dealApplyBudakaWatch(Myprotocl *msg)
{
    exec.sqldealApplyBudakaWatch(msg);
}

void dealMsg::dealApplyBudaka(Myprotocl *msg)
{
    if(true == exec.sqlApplyBudaka(msg))
    {
        msg->setMsgContent("ok");
    }
}

void dealMsg::dealChangePWD(Myprotocl *msg)
{
    if(true == exec.sqlChangePWD(msg))
    {
        msg->setMsgContent("ok");
    }
}

void dealMsg::deaPersonMsg(Myprotocl *msg)
{
    if(true == exec.sqlPersonMsg(msg))
    {
        msg->setMsgContent("true");
    }else if(false == exec.sqlPersonMsg(msg))
    {
        msg->setMsgContent("false");
    }
}

void dealMsg::dealManagerWatch(Myprotocl *msg)
{
    exec.sqlDepartmentWatch(msg);
}

void dealMsg::dealDepartmentWatch(Myprotocl *msg)
{
    exec.sqlDepartmentWatch(msg);
}

void dealMsg::dealEmployeeWatch(Myprotocl *msg)
{
    exec.sqlEmployeeWatch(msg);
}

void dealMsg::dealInsertDepartment(Myprotocl *msg)
{
    if(true == exec.sqlInsertDepartment(msg))
    {
        msg->setMsgContent("ok");
    }
}

void dealMsg::dealemployee(Myprotocl *msg)
{
    if(true == exec.sqlInsertEmployee(msg))
    {
        msg->setMsgContent("ok");
    }
}

void dealMsg::dealkaoqin(Myprotocl *msg)
{
    if(exec.findSqllogin(msg) == true)
    {
        msg->setMsgContent("ok");
    }
}

void dealMsg::dealLogin(Myprotocl *msg)
{
    if(true == exec.findSqlCompany(msg))
    {
        msg->setMsgContent("ok");
    }else
    {
        msg->setMsgContent("no");
    }
}

void dealMsg::dealdaka(Myprotocl *msg)
{
    if(true == exec.findSqlpassword(msg))
    {
        msg->setMsgContent("ok");
    }else
    {
        msg->setMsgContent("no");
    }
}

void dealMsg::dealStartWork(Myprotocl *msg,QString s)
{
    exec.sqlStarWork(msg,s);
}

void dealMsg::dealforget(Myprotocl *msg)
{
    if(true == exec.sqlForget(msg))
    {
        msg->setMsgContent("forget_ok");
    }
}

void dealMsg::dealRegister(Myprotocl *msg)
{    
   if(true == exec.sqlRegister(msg))
   {
        msg->setMsgContent("ok");
   }else
   {
        msg->setMsgContent("no");
   }
}
