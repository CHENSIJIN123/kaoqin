#include "forgetcompanyname.h"
#include "ui_forgetcompanyname.h"
#include "register_company.h"

forgetcompanyname::forgetcompanyname(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forgetcompanyname)
{
    ui->setupUi(this);
    msg = new Myprotocl();
    this->setWindowFlags(Qt::FramelessWindowHint);
}

forgetcompanyname::~forgetcompanyname()
{
    delete ui;
}

void forgetcompanyname::on_pb_ok_clicked()    //确认按钮点击事件
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgName(ui->le_name->text().toUtf8());
    msg->setMsgOperate(LONGIN);
    msg->setMsgCommand(FORGET_COM_NAME);
    msg->setMsgContent(ui->le_email->text());
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void forgetcompanyname::deal_com_name(QString s)    //收到公司名称的槽函数
{
    ui->label->setText(s);
}

void forgetcompanyname::on_pb_cancel_clicked()       //点击取消按钮事件,发射信号关闭该页面
{
    emit close_forget();    //发射关闭该页面的信号
}

void forgetcompanyname::on_le_email_editingFinished()
{

}
