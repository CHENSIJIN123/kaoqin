#include "userwork.h"
#include "ui_userwork.h"
#include <QByteArray>
#include "register_company.h"
#include <QDebug>
#include <QDateTime>
#include <QPainter>
#include <QMessageBox>
#include "docxml.h"

QString userwork::name;
userwork::userwork(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userwork)
{
    this->setWindowFlags(Qt::WindowTitleHint);
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->le_pwd->setEchoMode(QLineEdit::Password);
    msg = new Myprotocl();
    ui->mytime->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
    mytimer = new QTimer(this);
    mytimer->start(1000);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(dealtime()));
    flag = 0;
    name = ui->le_name_workNum->text();

}

userwork::~userwork()
{
    delete ui;
}

void userwork::dealtime()
{
    ui->mytime->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
}

void userwork::on_pb_daka_clicked()   //打开按钮点击事件
{
    if(ui->le_name_workNum->text()=="")    //如果姓名输入栏内容为空
    {
        ui->le_name_workNum->setPlaceholderText("姓名不能为空");
    }
    if(ui->le_pwd->text()=="")   //如果密码输入栏内容为空
    {
        ui->le_pwd->setPlaceholderText("请输入密码");
    }
    else
    {

        name = ui->le_name_workNum->text();
        QByteArray block;
        msg->clearMsgPackage();
        msg->setMsgName(name.toUtf8());   //姓名
        msg->setMsgOperate(PUNCH_THE_CLOCK);
        msg->setMsgCommand(DAKA);
        msg->setMsgContent(ui->le_pwd->text());               //密码
        msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
        block = *(msg->packageMsg());
        register_company::tcpsocket->write(block);
    }
}

void userwork::on_pb_login_clicked()    //登录按钮点击事件
{
    if(ui->le_name_workNum->text()=="")
    {
        ui->le_name_workNum->setPlaceholderText("姓名不能为空");
    }
    if(ui->le_pwd->text()=="")
    {
        ui->le_pwd->setPlaceholderText("请输入密码");
    }
    else
    {
        name = ui->le_name_workNum->text();
        QByteArray block;
        msg->clearMsgPackage();

        msg->setMsgName(name.toUtf8());
        msg->setMsgOperate(LONGIN);
        msg->setMsgCommand(KAOQIN);
        msg->setMsgContent(ui->le_pwd->text());
        msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
        block = *(msg->packageMsg());

        register_company::tcpsocket->write(block);
    }
}

void userwork::dealpwderror()
{
    QMessageBox::information(this,"账号密码不正确","请输入正确的姓名和密码^_^");
}

void userwork::dealstartWork()
{
    docxml::appendXML("../demo.xml", register_company::company_name,name);
}
