#ifndef REGISTER_COMPANY_H
#define REGISTER_COMPANY_H

#include <QWidget>
#include <QtNetwork>
#include "Register.h"
#include <QTcpSocket>
#include "myprotocl.h"
#include "dealmsg.h"
#include "userwork.h"
#include "forgetcompanyname.h"
#include "kaoqin.h"
#include "increasemanager.h"
#include "person.h"
#include "apply.h"

namespace Ui {
class register_company;
}

class register_company : public QWidget
{
    Q_OBJECT

public:
    explicit register_company(QWidget *parent = 0);
    ~register_company();
    static QTcpSocket *tcpsocket;    //用于传输数据的socket
    static QString company_name;
    void initGui();    //初始化界面
    void initSocket();   //初始化socket
    void initOtherGui();  //其他界面的变量初始化
    void initConnect();    //信号和槽连接函数
public slots:
    void dealfailure_login();

private slots:
    void on_register_new_company_clicked();

    void on_register_login_clicked();

    void dealmsg(void);

    void deal_succeed_login(void);

    void deal_pwd_correct(void);

    void on_register_forget_company_name_clicked();


private:
    Ui::register_company *ui;


    Register *regiter;    //注册类
    Myprotocl *msg;     //协议类
    dealMsg deal;   //处理TCP传来的消息的类
    userwork *user; //打卡类
    daka *d;
    forgetcompanyname *f;
    kaoqin *k;
    increaseManager i;
    person *p;
    apply a;
    QString xmlfilepath;

    int firstPunchMorining;
    int firstPunchAfternoon;
};

#endif // REGISTER_COMPANY_H
