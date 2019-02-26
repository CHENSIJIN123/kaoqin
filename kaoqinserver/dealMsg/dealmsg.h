#ifndef DEALMSG_H
#define DEALMSG_H
#include "myprotocl.h"
#include "execsql.h"

class dealMsg
{
public:
    dealMsg();
    void judge_operator(Myprotocl *msg);
    void dealLogin(Myprotocl *msg);
    void dealdaka(Myprotocl *msg);
    void dealStartWork(Myprotocl *msg,QString s);
    void dealforget(Myprotocl *msg);
    void dealRegister(Myprotocl *msg);
    void dealkaoqin(Myprotocl *msg);
    void dealemployee(Myprotocl *msg);
    void dealEmployeeWatch(Myprotocl *msg);
    void dealInsertDepartment(Myprotocl *msg);
    void dealDepartmentWatch(Myprotocl *msg);
    void dealManagerWatch(Myprotocl *msg);
    void deaPersonMsg(Myprotocl *msg);
    void dealChangePWD(Myprotocl *msg);
    void dealApplyBudaka(Myprotocl *msg);
    void dealApplyBudakaWatch(Myprotocl *msg);
    void dealApplyAgree(Myprotocl *msg);
    void dealApplyBudakaWatchEmloyee(Myprotocl *msg);
    void dealActuallyHappening(Myprotocl *msg);
    void dealActuallyHappeningchoose(Myprotocl *msg);
    void dealAllVersion(Myprotocl *msg);
    void dealAllVersionChoose(Myprotocl *msg);
    void dealMonthVersion(Myprotocl *msg);
    void dealMonthVersionChoose(Myprotocl *msg);
    execSql exec;
};

#endif // DEALMSG_H
