#include "apply.h"
#include "ui_apply.h"
#include "userwork.h"
#include "register_company.h"
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"


apply::apply(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apply)
{
    ui->setupUi(this);
    ui->dateEdit->setDateTime(QDateTime::currentDateTime());  //设置当前时间
    ui->timeEdit->setTime(QTime::currentTime());        //设置当前时间
    msg = new Myprotocl();

}

apply::~apply()
{
    delete ui;
}

void apply::dealstate(QString s)
{
    if(s == "补打卡")
    {
        msg->setMsgCommand(APPLY_BUDAKA);
    }else if(s == "加班")
    {
        msg->setMsgCommand(APPLY_JIABAN);
    }else if(s == "休假")
    {
        msg->setMsgCommand(APPLY_VACATION);
    }
}

void apply::on_pb_queren_clicked()   //确认按钮点击事件
{
    QString date = ui->dateEdit->dateTime().toString("yyyy年MM月dd日");
    QString time = ui->timeEdit->dateTime().toString("HH:mm");
    QString state = ui->textEdit->toPlainText();
    QString content = date+"%" + time + "%" + state;

    QByteArray block;

    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgOperate(EXAMINE_AND_APPROVE);
    msg->setMsgContent(content);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());
    register_company::tcpsocket->write(block);

    emit updatetable(0);

    this->close();
}
