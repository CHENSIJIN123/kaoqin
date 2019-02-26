#include "daka.h"
#include "ui_daka.h"
#include <QDateTime>
#include <QTimer>
#include "register_company.h"
#include "userwork.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"

QString daka::work_flag;
daka::daka(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::daka)
{
    ui->setupUi(this);
    ui->mytime->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
    ///打开一个定时器
    mytimer = new QTimer(this);
    mytimer->start(1000);
    connect(mytimer,SIGNAL(timeout()),this,SLOT(dealtime()));
    this->setWindowFlags(Qt::FramelessWindowHint); //去边框
    msg = new Myprotocl();
}

daka::~daka()
{
    delete ui;
}

void daka::dealtime()   //timeout的槽函数，不断对准时间
{
    ui->mytime->setText(QDateTime::currentDateTime().toString("hh:mm:ss"));
    int hour = QDateTime::currentDateTime().toString("hh").toInt();
    if(hour < 12 && hour > 6)
    {
        ui->pb_work_state->setText("上班");
    }else
    {
        ui->pb_work_state->setText("下班");
    }
}

void daka::on_pb_work_state_clicked()   //点击上班事件
{
    QByteArray block;
    msg->clearMsgPackage();
    int hour = QDateTime::currentDateTime().toString("hh").toInt();
    if(hour < 12 && hour > 6)   //上班
    {      
        msg->setMsgCommand(START_WORK);
    }
    else   //下班
    {
        msg->setMsgCommand(AFTER_WORK);      
    }

    cout<<userwork::name;
    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgOperate(PUNCH_THE_CLOCK);
    msg->setMsgContent(ui->mytime->text());
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);

    this->close();    //关闭此页面
}
