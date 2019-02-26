#include "register_company.h"
#include "ui_register_company.h"
#include <QByteArray>
#include "daka.h"
#include "dealmsg.h"
#include <QMessageBox>
#include "docxml.h"
#include <QCompleter>
#include <QDebug>
#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"

QTcpSocket *register_company::tcpsocket;
QString register_company::company_name;

register_company::register_company(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::register_company)
{
    ui->setupUi(this);

    initSocket();          //初始化socket
    initGui();             //初始化界面
    initOtherGui();        //初始化其他界面变量
    initConnect();         //信号和槽连接函数
}

void register_company::initGui()    //初始化界面
{
    ui->register_new_company->setStyleSheet("background-color:transparent");
    ui->register_forget_company_name->setStyleSheet("background-color:transparent");

    this->setWindowFlags(Qt::FramelessWindowHint);

    firstPunchMorining = 0;
    firstPunchAfternoon = 0;

    xmlfilepath = "../demo.xml";

    docxml::createXML(xmlfilepath);   //创建XML文件

    QStringList l;
    docxml::readXML(xmlfilepath,l);    //读xml文件中的信息
    cout <<"l"<< l;

    QCompleter *com = new QCompleter(l,this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->register_company_name->setCompleter(com);
    //ui->register_company_name->setText(l.at(l.size()-1));  //在填写公司名处设置提示信息和初始化名字
}

void register_company::initSocket()   //初始化socket
{
    tcpsocket = new QTcpSocket(this);
    tcpsocket->abort();
    tcpsocket->connectToHost("localhost",8888);
    cout <<"试图连接"<<endl;
}

void register_company::initOtherGui()  //其他界面的变量初始化
{
    regiter = new Register();
    msg     = new Myprotocl();
    user    = new userwork();
    d       = new daka();
    f       = new forgetcompanyname();
    k       = new kaoqin();
    p       = new person();
}

void register_company::initConnect()    //信号和槽连接函数
{
    connect(tcpsocket,SIGNAL(readyRead()),this,SLOT(dealmsg()));    //信息来和信息处理的信号和槽
    connect(&deal,SIGNAL(succeed_login()),this,SLOT(deal_succeed_login()));//公司登录成功
    connect(&deal,SIGNAL(pwd_correct()),this,SLOT(deal_pwd_correct()));    //员工输入密码正确
    connect(&deal,SIGNAL(com_name(QString)),f,SLOT(deal_com_name(QString))); //忘记公司名称传来公司名称
    connect(&deal,SIGNAL(register_ok()),regiter,SLOT(deal_register_ok()));   //注册成功公司
    connect(&deal,&dealMsg::insertEmployee,k,&kaoqin::dealinsertEmployee);     //添加员工
    connect(&deal,&dealMsg::employeeWatch,k,&kaoqin::dealemployeeWatch);     //查看员工信息
    connect(&deal,&dealMsg::insertDepartment,&i,&increaseManager::dealinsertDepartment);//添加进部门
    connect(&deal,&dealMsg::dapartmentWatch,k,&kaoqin::dealdapartmentWatch);       //得到部门的信息
    connect(&i,&increaseManager::show_departmentMsg,k,&kaoqin::dealshow_departmentMsg);//显示部门信息
    connect(&i,increaseManager::tianjia_event,k,kaoqin::dealtianjiaEvent);     //添加部门小页面
    connect(&deal,&dealMsg::dapartmentWatch,k,&kaoqin::dealManagerWatch);      //设置经理
    connect(&deal,&dealMsg::setchangepsw_true,p,&person::dealsetchangepsw_true);  //修改密码页面原始密码正确
    connect(&deal,&dealMsg::setchangepsw_true,k,&kaoqin::dealsetchangepsw_true);
    connect(&deal,&dealMsg::succeed_changepwd,p,&person::dealsucceed_changepwd);   //成功修改密码
    connect(&deal,&dealMsg::succeed_changepwd,k,&kaoqin::dealsucceed_changepwd);
    connect(p,&person::state,&a,&apply::dealstate);    //审批状态
    connect(&deal,&dealMsg::shenpiWatch,k,&kaoqin::dealshenpiWatch);  //管理员查看审批信息
    connect(&deal,&dealMsg::ApplyBudakaWatchEmloyee,p,&person::dealApplyBudakaWatchEmloyee);//员工查看审批信息
    connect(&a,&apply::updatetable,p,&person::on_tabWidget_tabBarClicked);   //点击添加完成后更新审核表 --不对
    connect(&deal,&dealMsg::signalActuallyHappening,k,&kaoqin::dealActuallyHappening);  //总览表的展示
    connect(&deal,&dealMsg::signalActuallyHappeningchoose,k,&kaoqin::dealActuallyHappeningchoose); //选择不同的部门
    connect(&deal,&dealMsg::failure_login,this,&register_company::dealfailure_login);
    connect(&deal,&dealMsg::signalAllVersion,k,&kaoqin::dealAllVersion);
    connect(&deal,&dealMsg::signalMonthVersion,k,&kaoqin::dealMonthVersion);
    connect(&deal,&dealMsg::signalMonthVersionChoose,k,&kaoqin::dealMonthVersionChoose);
    connect(&deal,&dealMsg::register_fail,regiter,&Register::dealRegister_fail);
    connect(&deal,&dealMsg::pwderror,user,&userwork::dealpwderror);
    connect(&deal,&dealMsg::startWork,user,&userwork::dealstartWork);
    connect(regiter,&Register::zhuce_cancel,this,
            [=]()
            {
                regiter->close();  //取消注册,关闭注册公司界面
                this->show();      //回到首页面
            }
            );
    connect(f,&forgetcompanyname::close_forget,this,
            [=]()
            {
                f->close();   //关闭忘记公司名称界面
                this->show();   //回到首页面
            }
            );

    connect(&deal,&dealMsg::log_kaoqin,this,
            [=]()
            {
                user->close();
                k->show();
            }
            );   //如果是管理员，登录考勤界面

    connect(&deal,&dealMsg::log_person,this,
            [=]()
            {
                user->close();
                p->show();
            }
            );    //如果是员工，就进入员工界面
}

register_company::~register_company()
{
    delete ui;
}

void register_company::dealfailure_login()     //发现不存在该公司名，提示先注册公司
{
    QMessageBox::information(this,"不存在当前公司","亲~~请先注册公司^_^",QMessageBox::Ok);   //输出提示信息
    ui->register_company_name->clear();     //输入公司名处清除内容
}

void register_company::dealmsg(void)         //服务器端传来数据的处理函数
{
    cout << "接受到服务器端传来数据"<<endl;
    QDataStream in(tcpsocket);
    in.setVersion(QDataStream::Qt_4_6);     //设置数据流版本，这里要和服务器端相同
    msg->unpackageMsg(in);
    deal.judge_msg(msg);
}

void register_company::on_register_new_company_clicked()   //注册新公司页面显示
{
    regiter->show();
    this->hide();
}

void register_company::deal_succeed_login(void)      //存在该公司名成功进入用户登录界面
{
    company_name = QString(msg->getMsgCompany_name());

    //添加到配置文件中
    docxml::appendXML(xmlfilepath,company_name);      //将公司名添加到配置文件中

    user->show();    //用户登录界面显示
    this->hide();  
}

void register_company::on_register_login_clicked()  //点击公司登录，若成功登录，则进入打卡界面
{
    cout << "点击登录"<<endl;
    if(ui->register_company_name->text()=="")    //如果填写内容为空，则提示“公司名称不能为空！！！”
    {
            ui->register_company_name->setPlaceholderText("公司名称不能为空！！！");
            return;
    }
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgCompany_name(ui->register_company_name->text().toUtf8());
    company_name = ui->register_company_name->text();   //公司名称为全局变量
    msg->setMsgOperate(LONGIN);    //登录操作
    msg->setMsgCommand(LOGIN);     //登录命令
    msg->setMsgContent("");
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    tcpsocket->write(block);
}

void register_company::deal_pwd_correct(void)     //进入打开页面
{
    cout << "早上是否是否已打卡上班";
    int time = QDateTime::currentDateTime().toString("hh").toInt();
    if(time < 12 && time > 06)
    {
        //从配置文件中找今天早上是否是否已打卡上班
        if("上班" == docxml::readXML(xmlfilepath,company_name,userwork::name))
        {
            QMessageBox::information(this,"打卡提示","已打卡上班^_^");
            return;
        }else
        {
            cout << "打卡上班";
            firstPunchAfternoon = 0;
            if(firstPunchMorining == 0)   //第一次打卡
            {
                d->show();      //打卡页面显示
                firstPunchMorining = 1;  //打开次数改为1
                return;
            }else
            {
                QMessageBox::information(this,"打卡提示","已打卡上班^_^");
            }
        }
    }else
    {
        //从配置文件中找今天早上是否是否已打卡上班
        if("下班" == docxml::readXML(xmlfilepath,company_name,userwork::name))
        {
            QMessageBox::information(this,"打卡提示","已打卡下班^_^");
            return;
        }else
        {
            firstPunchMorining = 0;
            if(firstPunchAfternoon == 0)   //第一次打卡
            {
                d->show();
                firstPunchAfternoon = 1;  //打开次数加一
                return;
            }else
            {
                QMessageBox::information(this,"打卡提示","已打卡下班^_^");
            }
        }

    }
}

void register_company::on_register_forget_company_name_clicked()  //点击忘记公司按钮，进入忘记公司界面
{
    f->show();
    this->show();
}
