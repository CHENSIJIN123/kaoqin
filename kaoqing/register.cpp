#include "register.h"
#include "ui_register.h"
#include "register_company.h"
#include <QMessageBox>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    msg = new Myprotocl();
    initRegister();
}

Register::~Register()
{
    delete ui;
}

void Register::initRegister()
{
    this->setWindowFlags(Qt::FramelessWindowHint);
//    ui->company_email->setEnabled(false);
    ui->company_queren_email->setEnabled(false);
    ui->company_pwd->setEnabled(false);
    ui->company_queren_pwd->setEnabled(false);
    ui->company_xingming->setEnabled(false);
    ui->company_pwd->setEchoMode(QLineEdit::Password);
    isfirstOnClickVersion = true;
    isfirstOnClickquerenVersion = true;
    ui->pb_zhuce->setEnabled(false);
}

void Register::on_pb_zhuce_clicked()   //注册按钮点击事件
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgCompany_name(ui->register_company_name->text().toUtf8());
    msg->setMsgName(ui->company_xingming->text().toUtf8());
    msg->setMsgOperate(LONGIN);
    msg->setMsgCommand(REGISTER);
    msg->setMsgContent(QString(ui->company_email->text() + "%" + ui->company_pwd->text()));
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void Register::on_pb_quxiao_clicked()  //取消按钮点击事件
{
    emit zhuce_cancel();
}

void Register::dealRegister_fail()   //注册失败 显示提示信息
{
    QMessageBox::information(this,"注册失败","请您换一个公司名进行注册");
}

void Register::deal_register_ok()   //注册成功处理的槽函数
{
    ui->label_6->setText("注册成功");
}

void Register::on_company_email_editingFinished()   //邮件内容编写完毕的处理事件
{
    QString email = ui->company_email->text();
    if(false == email.contains("@qq.com"))
    {
        ui->company_email->clear();
        ui->company_email->setPlaceholderText("请输入正确的邮箱^_^");
    }else
    {
        ui->company_queren_email->setEnabled(true);   //确认邮箱可以编辑
    }
}

void Register::on_company_queren_email_editingFinished()   //确认邮箱编写完毕的处理事件，判断两个是否一致
{
    if(ui->company_email->text() != ui->company_queren_email->text())
    {
        ui->company_queren_email->clear();
        ui->company_queren_email->setPlaceholderText("请输入一致的邮箱^_^");
    }else
    {
        ui->company_xingming->setEnabled(true);  //姓名栏可以编辑
    }
}

void Register::on_company_xingming_editingFinished()  //姓名栏编辑完毕
{
    ui->company_pwd->setEnabled(true);     //密码栏可以编辑
}

void Register::on_pb_isVersion_clicked()   //是否可见密码按下的处理事件
{
    if(isfirstOnClickVersion == true)
    {
        ui->company_pwd->setEchoMode(QLineEdit::Normal);
        isfirstOnClickVersion = false;
        return;
    }else
    {
        ui->company_pwd->setEchoMode(QLineEdit::Password);
        isfirstOnClickVersion = true;
        return;
    }
}

void Register::on_company_pwd_editingFinished()  //密码栏编辑完成
{
    ui->company_queren_pwd->setEnabled(true);
}

void Register::on_company_queren_pwd_editingFinished()   //确认密码栏编辑完成
{
    if(ui->company_pwd->text() != ui->company_queren_pwd->text())
    {
        ui->company_queren_pwd->clear();
        ui->company_queren_pwd->setPlaceholderText("请与输入的密码一致^_^");
    }else
    {
        ui->pb_zhuce->setEnabled(true);   //确认按钮可以按下
    }
}

void Register::on_pb_isVersion_queren_clicked()    //确认密码是否可见按下事件
{
    if(isfirstOnClickquerenVersion == true)
    {
        ui->company_queren_pwd->setEchoMode(QLineEdit::Normal);
        isfirstOnClickquerenVersion = false;
        return;
    }else
    {
        ui->company_queren_pwd->setEchoMode(QLineEdit::Password);
        isfirstOnClickquerenVersion = true;
        return;
    }
}
