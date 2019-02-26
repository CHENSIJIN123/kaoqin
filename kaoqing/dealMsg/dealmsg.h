#ifndef DEALMSG_H
#define DEALMSG_H
#include "myprotocl.h"
#include <QWidget>

class dealMsg : public QWidget
{
    Q_OBJECT

public:
    explicit dealMsg(QWidget *parent = 0);
    ~dealMsg(){};
    void judge_msg(Myprotocl *msg);
    void dealLogin(Myprotocl *msg);
    void dealforget(Myprotocl *msg);
    void dealdaka(Myprotocl *msg);
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
    void dealStartWork(Myprotocl *msg);
signals:
    void succeed_login();
    void pwd_correct();
    void pwderror();
    void startWork(Myprotocl *msg);
    void com_name(QString s);
    void register_ok();
    void register_fail();
    void log_kaoqin();
    void insertEmployee();
    void employeeWatch(QString s);
    void insertDepartment();
    void dapartmentWatch(QString s);
    void log_person();
    void setchangepsw_true(int i);
    void succeed_changepwd();
    void shenpiWatch(QString s);
    void ApplyBudakaWatchEmloyee(QString s);
    void signalActuallyHappening(QString s);
    void signalActuallyHappeningchoose(QString s);
    void failure_login();
    void signalAllVersion(QString s);
    void signalAllVersionChoose(QString s);
    void signalMonthVersion(QString s);
    void signalMonthVersionChoose(QString s);
};

#endif // DEALMSG_H
