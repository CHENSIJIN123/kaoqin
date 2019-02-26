#include "kaoqin.h"
#include "ui_kaoqin.h"
#include <QDebug>
#include "register_company.h"
#include <QTableWidgetItem>
#include <QAxObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>
#include <QDateTime>
#include "histogram.h"
#include "pie.h"

#define cout qDebug()<<"["<<__FILE__<<":"<<__LINE__<<"]"
QStringList kaoqin::listmonth;
kaoqin::kaoqin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kaoqin)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    msg = new Myprotocl();
    ui->lineEdit_9->setEchoMode(QLineEdit::Password);
    ui->stackedWidget_2->setCurrentIndex(0);
    increase = new increaseManager();
    flag = 1;
    first = 0;
    first_month= 0;

    ui->tableWidget_4->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //设置等宽
    ui->tableWidget_6->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    isCanShenghe = 0;
    all_version_show_table = 0;
    all_version_choose_employee= "所有员工";
    all_version_choose_vacation = "所有出勤";
    initShow(); //初始化界面
}

kaoqin::~kaoqin()
{
    delete ui;
}

void kaoqin::dealshenpiWatch(QString s)
{
    //张三/2017年07月28日/15:32/补打卡/我脑子疼/未审批%
    QStringList list = s.split("%");
    ui->tableWidget_4->setRowCount(list.size() - 1);

    for(int i = 0;i < ui->tableWidget_4->rowCount();i++)
    {
        QStringList li = list[i].split("/");
        for(int j = 0;j < ui->tableWidget_4->columnCount();j++)
        {
            QTableWidgetItem *item_min = new QTableWidgetItem();
            item_min->setText(li[j]);
            ui->tableWidget_4->setItem(i, j, item_min);
        }
    }
}

void kaoqin::dealemployeeWatch(QString s)
{
    employeeMsg = s;
    QStringList list = employeeMsg.split("%");
    ui->tableWidget->setRowCount(list.size() - 1);

    for(int i = 0;i < ui->tableWidget->rowCount();i++)
    {
        QStringList li = list[i].split("/");
        for(int j = 0;j < ui->tableWidget->columnCount();j++)
        {
            QTableWidgetItem *item_min = new QTableWidgetItem();
            item_min->setText(li[j]);
            ui->tableWidget->setItem(i, j, item_min);
        }
    }
}

void kaoqin::dealActuallyHappening(QString s)   //展示实况信息的槽函数
{
//    cout << s;
    QStringList list = s.split("%");
    ui->tableWidget_5->setRowCount(list.size() - 1);

    for(int i = 0;i < ui->tableWidget_5->rowCount();i++)
    {
        QStringList li = list[i].split("/");
        for(int j = 0;j < ui->tableWidget_5->columnCount();j++)
        {
            QTableWidgetItem *item_min = new QTableWidgetItem();
            item_min->setText(li[j]);
            ui->tableWidget_5->setItem(i, j, item_min);
        }
    }
    QString department = list[ui->tableWidget_5->rowCount()];
    QStringList department_list = department.split("/");
    ui->comboBox->clear();
    ui->comboBox->addItem("所有部门");
    for(int i = 0;i<department_list.size()-1;i++)
    {
        ui->comboBox->addItem(department_list[i]);
    }
}

void kaoqin::on_pushButton_12_clicked()   //点击公司设置按钮，
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->le_company_name->setText(register_company::company_name);
}

void kaoqin::dealtianjiaEvent()   //关闭添加按钮的槽函数
{
    watchDepartmentMsg();       //去查看部门信息
}

void kaoqin::on_pushButton_13_clicked()      //1 先点击部门管理按钮
{
    ui->stackedWidget->setCurrentIndex(2);   //2 设置当前页
    watchDepartmentMsg();                    //3 去查看部门信息

}
void kaoqin::watchDepartmentMsg()            //3 查看部门信息
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgCompany_name(register_company::company_name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(PART_ADMINISTRATE_WATCH);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void kaoqin::watchManagerMsg()       //查看经理信息
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgCompany_name(register_company::company_name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(MANAGER_SETTING);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void kaoqin::initShow()  //界面初始化
{
    cout << "    dsasdas********************************";
    QStringList list;
    list<<"请选择月份"<<"01月"<<"02月"<<"03月"<<"04月"<<"05月"<<"06月"
       <<"07月"<<"08月"<<"09月"<<"10月"<<"11月"<<"12月";
    ui->comboBoxMonth->addItems(list);
}

void kaoqin::dealManagerWatch(QString s)    //得到经理和部门的信息的槽函数
{
    managerMsg = s;
    if(s.isEmpty())
    {
        ui->stackedWidget_4->setCurrentIndex(0);  //设置显示没有部门的那一页
    }
    else
    {
        ui->stackedWidget_4->setCurrentIndex(1);  //5 设置显示有部门信息表格的那一页

        QStringList list = s.split("%");
        ui->tableWidget_3->setRowCount(list.size() - 1);
        for(int i = 0;i < ui->tableWidget_3->rowCount();i++)
        {
            QStringList li = list[i].split("/");
            for(int j = 0;j < ui->tableWidget_3->columnCount();j++)
            {
                QTableWidgetItem *item_min = new QTableWidgetItem();
                item_min->setText(li[j]);
                ui->tableWidget_3->setItem(i, j, item_min);
            }
        }
    }
}

void kaoqin::dealdapartmentWatch(QString s)  //4 得到部门的信息s的槽函数
{
    departmentMsg = s;
    if(s.isEmpty())
    {
        ui->stackedWidget_3->setCurrentIndex(1);  //设置显示没有部门的那一页
    }
    else
    {     //部门信息不为空
        ui->stackedWidget_3->setCurrentIndex(0);  //5 设置显示有部门信息表格的那一页

        QStringList list = s.split("%");   //人事部/陈思瑾
        ui->tableWidget_2->setRowCount(list.size() - 1);
        for(int i = 0;i < ui->tableWidget_2->rowCount();i++)
        {
            QStringList li = list[i].split("/");
            for(int j = 0;j < ui->tableWidget_2->columnCount();j++)
            {
                QTableWidgetItem *item_min = new QTableWidgetItem();
                item_min->setText(li[j]);
                ui->tableWidget_2->setItem(i, j, item_min);
            }
        }

//        cout << "list" << list;
        for(int i = 0;i < list.size() - 1;i++)
        {
                QStringList li = list.at(i).split("/");
                ui->comboBoxDep_2->addItem(li.at(0));
        }
    }
}

void kaoqin::dealshow_departmentMsg()   //显示部门信息的槽函数
{
    ui->stackedWidget->setCurrentIndex(8);
    dealdapartmentWatch(departmentMsg);
}

void kaoqin::on_pushButton_31_clicked()    //点击了添加员工信息界面的取消按钮
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void kaoqin::on_pushButton_30_clicked()   //点击了添加员工信息界面的添加按钮
{
    QString name = ui->lineEdit_8->text();
    QString password = ui->lineEdit_9->text();
    QString gonghao = ui->lineEdit_10->text();
    QString phoneNumber = ui->lineEdit_11->text();
//    QString email = ui->lineEdit_12->text();
    QString role = ui->comboBox_6->currentText();
    QString department = ui->lineEdit_14->text();

    QString str = password + "%" + gonghao + "%" + phoneNumber + "%" + department + "%" + role;

//    qDebug()<<str;
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgName(name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(EMPLOYEE_ADMINISTRATE);
    msg->setMsgContent(str);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void kaoqin::dealinsertEmployee()
{
    ui->stackedWidget_2->setCurrentIndex(0);

    on_pushButton_11_clicked();
}

void kaoqin::on_pushButton_23_clicked()   //点击添加部门按钮
{
    increase->show();    //添加部门界面显示
}

void kaoqin::on_pushButton_11_clicked()    //点击员工管理按钮，出现员工信息
{
    ui->stackedWidget->setCurrentIndex(0);

    QByteArray block;
    msg->clearMsgPackage();

    QString name = ui->lineEdit_8->text();
    msg->setMsgName(name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(EMPLOYEE_ADMINISTRATE_WATCH);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void kaoqin::on_tabWidget_tabBarClicked(int index)    //最上方点击退出可直接退出整个界面
{
    switch(index)
    {
        case 0:{  //审批
                QByteArray block;
                msg->clearMsgPackage();
                msg->setMsgStatus(ADMINISTRATOR);
                msg->setMsgOperate(EXAMINE_AND_APPROVE);
                msg->setMsgCommand(APPLY_BUDAKA_WATCH);
                msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
                block = *(msg->packageMsg());
                register_company::tcpsocket->write(block);
                break;
                }
        case 1:{   //实况
                QByteArray block;
                msg->clearMsgPackage();
                msg->setMsgStatus(ADMINISTRATOR);
                msg->setMsgOperate(ACTUALLY_HAPPENING);
                msg->setMsgCommand(COMMAND_NONE);
                msg->setMsgContent("所有部门");
                msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
                block = *(msg->packageMsg());
                register_company::tcpsocket->write(block);
                break;
                }
        case 2:{     //总览
                if(all_version_show_table == 0)
                {
                    ui->stackedWidget_5->setCurrentIndex(0);
                }
                else
                {
                    ui->stackedWidget_5->setCurrentIndex(1);
                }

                break;
                }
        case 3:{  //月视图

                first_month=0;
                QByteArray block;
                msg->clearMsgPackage();
                msg->setMsgStatus(ADMINISTRATOR);
                msg->setMsgOperate(MONTH_VERSION);
                msg->setMsgCommand(COMMAND_NONE);
                msg->setMsgContent(ui->comboBoxMonth->currentText());
                msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
                block = *(msg->packageMsg());
                register_company::tcpsocket->write(block);

                break;
                }
        case 4:break;
        case 5:break;
        case 6:{
                ui->le_name->setText(userwork::name);
                flag = 1;
                break;
                }
        case 7:this->close();break;
    }
}

void kaoqin::on_comboBoxMonth_currentIndexChanged(const QString &arg1)   //选择月份
{
    if(arg1 == "请选择月份")
    {
        return;
    }else
    {
//    cout <<"选择 ？ 月" <<arg1;
    ui->widgetH->Clear();
    QByteArray block;
    msg->clearMsgPackage();
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(MONTH_VERSION);
    msg->setMsgCommand(COMMAND_NONE);
    msg->setMsgContent(arg1);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());
    register_company::tcpsocket->write(block);
    }
}

void kaoqin::dealMonthVersion(QString s)
{
    if(s=="")
    {
        cout <<"empty";
        ui->widgetH->Clear();
        return;
    }
    ui->widgetH->SetMaxValue(40);
    ui->comboBoxDep->clear();
    QString depName;
    double p;
    double copy;
    listmonth = s.split("%");//人事部/20%技术部/1.25%董事会/5%
    for(int i = 0;i < listmonth.size() - 1;i++)
    {
        QStringList dep = listmonth.at(i).split("/");  //人事部/20
        depName =  dep.at(0);  //人事部
        p = dep.at(1).toDouble();     //20
        if(i == 0)
        {
            copy = p;
        }
        ui->comboBoxDep->addItem(depName);
        ui->widgetH->AddItem(depName,p);
    }

    QVector<SectorInfo> result;

    SectorInfo info;
    info.description = "缺勤率";
    info.percent = 100 - copy;
    result.push_back(info);

    info.description = "出勤率";
    info.percent = copy;
    result.push_back(info);

    ui->widgetP->setData(result);

}

void kaoqin::on_comboBoxDep_currentIndexChanged(const QString &arg1)
{
    QString depName;
    double p;
    double copy;
    for(int i = 0;i < listmonth.size() - 1;i++)
    {
        QStringList dep = listmonth.at(i).split("/");  //人事部/20
        depName =  dep.at(0);
        p = dep.at(1).toDouble();
        if(depName == arg1)
        {
            copy = p;
            break;
        }
    }

    QVector<SectorInfo> result;

    SectorInfo info;
    info.description = "缺勤率";
    info.percent = 100 - copy;
    result.push_back(info);

    info.description = "出勤率";
    info.percent = copy;
    result.push_back(info);

    ui->widgetP->setData(result);
}

void kaoqin::on_pushButton_14_clicked()   //点击经理设置按钮
{
    ui->stackedWidget->setCurrentIndex(3);
    watchManagerMsg();
}

void kaoqin::on_pushButton_15_clicked()     //点击休假类型按钮
{
    ui->stackedWidget->setCurrentIndex(4);
}

void kaoqin::on_pushButton_16_clicked()    //点击班次类型按钮
{
    ui->stackedWidget->setCurrentIndex(5);
}

void kaoqin::on_pushButton_17_clicked()    //点击考勤点授权按钮
{
    ui->stackedWidget->setCurrentIndex(6);
}

void kaoqin::on_pushButton_18_clicked()   //点击个人设置按钮
{
    ui->stackedWidget->setCurrentIndex(7);
}

void kaoqin::on_pushButton_19_clicked()    //点击添加员工按钮
{
    //获得部门信息
    QByteArray block;
    msg->clearMsgPackage();
    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(PART_ADMINISTRATE_WATCH);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());
    register_company::tcpsocket->write(block);

    ui->stackedWidget_2->setCurrentIndex(1); 
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_14->clear();
}

void kaoqin::on_checkBox_9_clicked()   //修改密码时的选择按钮
{
    flag ++;
    if(flag % 2 == 0)
    {
        ui->currentpsw->setReadOnly(false);
    }
}

void kaoqin::dealsetchangepsw_true(int i)
{
    if(i == 0)   //说明所写密码正确
    {
        ui->lb_currentpsw_3->setText("所填密码正确");
        ui->newpsw->setReadOnly(false);
        ui->querenpsw->setReadOnly(false);
    }else       //说明所写密码不正确
    {
        ui->lb_currentpsw_3->setText("所填密码不正确");
    }
}

void kaoqin::on_currentpsw_editingFinished()
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(PERSONAL_SETTING);
    msg->setMsgContent(ui->currentpsw->text());   //存放密码
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void kaoqin::on_querenpsw_editingFinished()
{
    QString str = ui->newpsw->text();
    if(str.isEmpty() == false)
    {
        QString repeat = ui->querenpsw->text();
        if(str == repeat)
        {
            ui->lb_queren_3->setText("所填新密码一致");
        }else
        {
            ui->lb_queren_3->setText("请重新输入");
        }
    }
    else
    {
        ui->lb_queren_3->setText("请先填入新密码");
    }
}

void kaoqin::on_pb_save_clicked()
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(PERSON_PWD);
    msg->setMsgContent(ui->querenpsw->text());   //存放密码
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void kaoqin::dealsucceed_changepwd()
{
    ui->lb_show->setText("成功修改密码");
}

void kaoqin::on_pb_return_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
}

void kaoqin::on_tableWidget_4_clicked(const QModelIndex &index)
{
    row = ui->tableWidget_4->currentIndex().row();
    isCanShenghe = 1;
    tableMsg = ui->tableWidget_4->item(row,0)->text() + "%" + ui->tableWidget_4->item(row,1)->text()
            + "%" + ui->tableWidget_4->item(row,3)->text();
}

void kaoqin::on_pushButton_clicked()    //审批通过处理
{
    if(isCanShenghe == 1)
    {
        isCanShenghe = 0;

        QByteArray block;
        msg->clearMsgPackage();

        msg->setMsgName(userwork::name.toUtf8());
        msg->setMsgStatus(ADMINISTRATOR);   //管理员身份
        msg->setMsgOperate(EXAMINE_AND_APPROVE);
        msg->setMsgCommand(APPLY_AGREE);   //审批通过
        msg->setMsgContent(tableMsg);
        msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
        block = *(msg->packageMsg());

        register_company::tcpsocket->write(block);

        ui->tableWidget_4->removeRow(row);
    }
}

void kaoqin::on_pushButton_2_clicked()   //审批不通过处理
{
    if(isCanShenghe == 1)
    {
        isCanShenghe = 0;

        QByteArray block;
        msg->clearMsgPackage();

        msg->setMsgName(userwork::name.toUtf8());
        msg->setMsgStatus(ADMINISTRATOR);
        msg->setMsgOperate(EXAMINE_AND_APPROVE);
        msg->setMsgCommand(APPLY_FALSE);       //审批不通过
        msg->setMsgContent(tableMsg);              //审批对象所在行号
        msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
        block = *(msg->packageMsg());

        register_company::tcpsocket->write(block);

        ui->tableWidget_4->removeRow(row);    //删除所在行
    }
}

void kaoqin::dealActuallyHappeningchoose(QString s)
{
    QStringList list = s.split("%");
    ui->tableWidget_5->setRowCount(list.size() - 1);

    for(int i = 0;i < ui->tableWidget_5->rowCount();i++)
    {
        QStringList li = list[i].split("/");
        for(int j = 0;j < ui->tableWidget_5->columnCount();j++)
        {
            QTableWidgetItem *item_min = new QTableWidgetItem();
            item_min->setText(li[j]);
            ui->tableWidget_5->setItem(i, j, item_min);
        }
    }
}

void kaoqin::on_comboBox_currentIndexChanged(const QString &arg1)
{
//        cout << arg1;
        QString current;
        current = arg1;
        if(arg1 == "")
        {
            current = "所有部门";
        }
        QByteArray block;
        msg->clearMsgPackage();

        msg->setMsgName(userwork::name.toUtf8());
        msg->setMsgStatus(ADMINISTRATOR);
        msg->setMsgOperate(ACTUALLY_HAPPENING);
        msg->setMsgCommand(EMPLOYEE_ADMINISTRATE_WATCH);
        msg->setMsgContent(current);
        msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
        block = *(msg->packageMsg());

        register_company::tcpsocket->write(block);
}

void kaoqin::Table3ExcelByHtml(QTableWidget *table,QString title)
{
    QString fileName = QFileDialog::getSaveFileName(table, "保存",QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),"Excel 文件(*.xls *.xlsx)");
    if (fileName!="")
    {
        QAxObject *excel = new QAxObject;
        if (excel->setControl("Excel.Application")) //连接Excel控件
        {
            excel->dynamicCall("SetVisible (bool Visible)","false");//不显示窗体
            excel->setProperty("DisplayAlerts", false);//不显示任何警告信息。如果为true那么在关闭是会出现类似“文件已修改，是否保存”的提示
            QAxObject *workbooks = excel->querySubObject("WorkBooks");//获取工作簿集合
            workbooks->dynamicCall("Add");//新建一个工作簿
            QAxObject *workbook = excel->querySubObject("ActiveWorkBook");//获取当前工作簿
            QAxObject *worksheet = workbook->querySubObject("Worksheets(int)", 1);

            int i,j;
            int colcount=table->columnCount();//QTablewidget 获取数据的列数
            int rowscount=table->rowCount();//QTablewidget 获取数据的行数

            QAxObject *cell,*col;
            cell=worksheet->querySubObject("Cells(int,int)", 1, 1);//标题行
            cell->dynamicCall("SetValue(const QString&)", title);
            cell->querySubObject("Font")->setProperty("Size", 18);
            worksheet->querySubObject("Range(const QString&)", "1:1")->setProperty("RowHeight", 30);//调整行高

            QString cellTitle;              //合并标题行
            cellTitle.append("A1:");
            cellTitle.append(QChar(colcount - 1 + 'A'));
            cellTitle.append(QString::number(1));
            QAxObject *range = worksheet->querySubObject("Range(const QString&)", cellTitle);
            range->setProperty("WrapText", true);
            range->setProperty("MergeCells", true);
            range->setProperty("HorizontalAlignment", -4108);//xlCenter
            range->setProperty("VerticalAlignment", -4108);//xlCenter

            for(i=0;i<colcount;i++)           //列标题
            {
                QString columnName;
                columnName.append(QChar(i  + 'A'));
                columnName.append(":");
                columnName.append(QChar(i + 'A'));
                col = worksheet->querySubObject("Columns(const QString&)", columnName);
                col->setProperty("ColumnWidth", table->columnWidth(i)/6);
                cell=worksheet->querySubObject("Cells(int,int)", 2, i+1);
                columnName=table->horizontalHeaderItem(i)->text();                //QTableWidget 获取表格头部文字信息
                cell->dynamicCall("SetValue(const QString&)", columnName);
                cell->querySubObject("Font")->setProperty("Bold", true);
                cell->querySubObject("Interior")->setProperty("Color",QColor(191, 191, 191));
                cell->setProperty("HorizontalAlignment", -4108);                 //xlCenter
                cell->setProperty("VerticalAlignment", -4108);                   //xlCenter
            }
            for(i=0;i<rowscount;i++)         //QTableWidget 获取表格数据部分
            {
                for (j=0;j<colcount;j++)
                {
                    worksheet->querySubObject("Cells(int,int)", i+3, j+1)->dynamicCall("SetValue(const QString&)", table->item(i,j)?table->item(i,j)->text():"");
                }
            }
            QString lrange;                  //画框线
            lrange.append("A2:");
            lrange.append(colcount - 1 + 'A');
            lrange.append(QString::number(table->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", lrange);
            range->querySubObject("Borders")->setProperty("LineStyle", QString::number(1));
            range->querySubObject("Borders")->setProperty("Color", QColor(0, 0, 0));

            QString rowsName;                //调整数据区行高
            rowsName.append("2:");
            rowsName.append(QString::number(table->rowCount() + 2));
            range = worksheet->querySubObject("Range(const QString&)", rowsName);
            range->setProperty("RowHeight", 20);
            workbook->dynamicCall("SaveAs(const QString&)",QDir::toNativeSeparators(fileName));//保存至fileName
            workbook->dynamicCall("Close()");    //关闭工作簿
            excel->dynamicCall("Quit()");        //关闭excel
            delete excel;
            excel=NULL;
            if (QMessageBox::question(NULL,"完成","文件已经导出，是否现在打开？",QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl("file:///" + QDir::toNativeSeparators(fileName)));
            }
        }
        else
        {
            QMessageBox::warning(NULL,"错误","未能创建 Excel 对象，请安装 Microsoft Excel。",QMessageBox::Apply);
        }
    }
}

void kaoqin::on_pushButton_9_clicked()   //员工信息报表
{
    Table3ExcelByHtml(ui->tableWidget,"员工信息");
}


void kaoqin::on_pushButton_6_clicked()   //部门信息报表
{
    Table3ExcelByHtml(ui->tableWidget_3,"部门信息");
}

void kaoqin::on_pushButton_7_clicked()
{
    Table3ExcelByHtml(ui->tableWidget_5,"考勤信息");
}


void kaoqin::dealAllVersion(QString s)   //收到总览信息的槽函数
{
    QStringList list = s.split("%");
    ui->tableWidget_6->setRowCount(list.size() - 1);

    for(int i = 0;i < ui->tableWidget_6->rowCount();i++)
    {
        QStringList li = list[i].split("/");
        for(int j = 0;j < ui->tableWidget_6->columnCount();j++)
        {
            QTableWidgetItem *item_min = new QTableWidgetItem();
            item_min->setText(li[j]);
            ui->tableWidget_6->setItem(i, j, item_min);
        }
    }
}

void kaoqin::on_pb_correct_clicked()   //总览页面确认按钮按下
{
    all_version_show_table = 1;   //设置表格可见
    ui->stackedWidget_5->setCurrentIndex(1);

    QString content = all_version_choose_employee + "%" + all_version_choose_vacation;

    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgStatus(ADMINISTRATOR);
    msg->setMsgOperate(ALL_VERSION);
    msg->setMsgCommand(COMMAND_NONE);
    msg->setMsgContent(content);
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void kaoqin::dealMonthVersionChoose(QString s)
{

}


