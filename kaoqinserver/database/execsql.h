#ifndef EXECSQL_H
#define EXECSQL_H
#include <QSqlDatabase>
#include "myprotocl.h"

class execSql
{
public:
    execSql();
    bool findSqlCompany(Myprotocl *msg);
    bool findSqlpassword(Myprotocl *msg);
    bool findSqllogin(Myprotocl *msg);
    bool sqlStarWork(Myprotocl *msg,QString s);
    bool sqlForget(Myprotocl *msg);
    bool sqlRegister(Myprotocl *msg);
    bool sqlLoginperson(Myprotocl *msg);
    bool sqlInsertEmployee(Myprotocl *msg);
    bool sqlEmployeeWatch(Myprotocl *msg);
    bool sqlInsertDepartment(Myprotocl *msg);
    bool sqlDepartmentWatch(Myprotocl *msg);
    bool sqlPersonMsg(Myprotocl *msg);
    bool sqlChangePWD(Myprotocl *msg);
    bool sqlApplyBudaka(Myprotocl *msg);
    bool sqldealApplyBudakaWatch(Myprotocl *msg);
    bool sqldealApplyAgree(Myprotocl *msg);
    bool sqlApplyBudakaWatchEmloyee(Myprotocl *msg);
    bool sqlActuallyHappening(Myprotocl *msg);
    bool sqlActuallyHappeningchoose(Myprotocl *msg,QString s);
    bool sqlAllVersion(Myprotocl *msg);  //总览的信息查询
    bool sqlAllVersionChoose(Myprotocl *msg);
    bool sqlMonthVersion(Myprotocl *msg);
    bool sqlMonthVersionChoose(Myprotocl *msg);
};

#endif // EXECSQL_H
