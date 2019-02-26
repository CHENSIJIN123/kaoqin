#include "increasemanager.h"
#include "ui_increasemanager.h"
#include <QMessageBox>
#include "register_company.h"
#include <QCloseEvent>

increaseManager::increaseManager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::increaseManager)
{
    ui->setupUi(this);
    msg = new Myprotocl();
}

increaseManager::~increaseManager()
{
    delete ui;
}

void increaseManager::closeEvent(QCloseEvent *e)
{
    qDebug()<<"1111111";
    emit tianjia_event();
    e->accept();
}

void increaseManager::dealinsertDepartment()   //添加进去后收到的槽函数
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgCompany_name(register_company::company_name.toUtf8());
    msg->setMsgOperate(SET);
    msg->setMsgCommand(PART_ADMINISTRATE_WATCH);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);

    //this->close();
    QMessageBox::about(this,"watch","成功添加");
}

void increaseManager::on_pb_increase_clicked()   //点击添加部门界面的添加按钮
{
    QString department = ui->lineEdit->text();
    if(department.isEmpty())
    {
         QMessageBox::about(this,"提示","输入不能为空！！！");
    }
    else
    {
        QByteArray block;
        msg->clearMsgPackage();

        msg->setMsgCompany_name(register_company::company_name.toUtf8());
        msg->setMsgOperate(SET);
        msg->setMsgCommand(PART_ADMINISTRATE);
        msg->setMsgContent(department);
        msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
        block = *(msg->packageMsg());

        register_company::tcpsocket->write(block);
    }

    //emit show_departmentMsg();   //发出信号要求显示部门信息
}
