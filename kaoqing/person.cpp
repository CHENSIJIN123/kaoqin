#include "person.h"
#include "ui_person.h"
#include "userwork.h"
#include "register_company.h"
#include <QAxObject>
#include <QFileDialog>
#include <QMessageBox>
#include <QDesktopServices>

person::person(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::person)
{
    ui->setupUi(this);
    p = new apply();
    this->setWindowFlags(Qt::FramelessWindowHint);
    ui->le_name->setText(userwork::name);
    flag = 1;
    msg = new Myprotocl();
}

person::~person()
{
    delete ui;
}

void person::on_pb_apply_budaka_clicked()  //点击申请补打卡
{
    p->show();
    emit state("补打卡");
}

void person::on_pb_apply_vacation_clicked()   //申请休假
{
    p->show();
    emit state("休假");
//    Table3ExcelByHtml(ui->tableWidget,"审核表");
}

void person::Table3ExcelByHtml(QTableWidget *table,QString title)
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


void person::on_pb_apply_jiaban_clicked()    //申请加班
{
    p->show();
    emit state("加班");
}

void person::dealApplyBudakaWatchEmloyee(QString s)
{
    QStringList list = s.split("%");
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

void person::on_tabWidget_tabBarClicked(int index)
{
    switch(index)
    {
        case 0:   //查看审核信息
        {
        QByteArray block;
        msg->clearMsgPackage();

        msg->setMsgName(userwork::name.toUtf8());
        msg->setMsgStatus(EMPLOYEE);
        msg->setMsgOperate(EXAMINE_AND_APPROVE);
        msg->setMsgCommand(APPLY_BUDAKA_WATCH);
        msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
        block = *(msg->packageMsg());

        register_company::tcpsocket->write(block);
        break;
        }
        case 1:break;
        case 2:this->close();break;
    }
}

void person::on_checkBox_clicked()
{
    flag ++;
    if(flag % 2 == 0)
    {
        ui->currentpsw->setReadOnly(false);
    }
}

void person::on_currentpsw_editingFinished()  //判断当前密码是否正确
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgStatus(EMPLOYEE);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(PERSONAL_SETTING);
    msg->setMsgContent(ui->currentpsw->text());   //存放密码
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}

void person::dealsetchangepsw_true(int i)    //判断密码所填是否正确的槽函数
{
    if(i == 0)   //说明所写密码正确
    {
        ui->lb_currentpsw->setText("所填密码正确");
        ui->newpsw->setReadOnly(false);
        ui->querenpsw->setReadOnly(false);
    }else       //说明所写密码不正确
    {
        ui->lb_currentpsw->setText("所填密码不正确");
    }
}

void person::on_querenpsw_editingFinished()   //确认密码栏填完的事件
{
    QString str = ui->newpsw->text();
    if(str.isEmpty() == false)
    {
        QString repeat = ui->querenpsw->text();
        if(str == repeat)
        {
            ui->lb_queren->setText("所填新密码一致");
        }else
        {
            ui->lb_queren->setText("请重新输入");
        }
    }
    else
    {
        ui->lb_queren->setText("请先填入新密码");
    }
}

void person::on_pb_return_clicked()    //返回按钮点击事件
{
    ui->tabWidget->setCurrentIndex(0);
}

void person::dealsucceed_changepwd()    //成功修改密码事件
{
    ui->lb_show->setText("成功修改密码");
}

void person::on_pb_save_clicked()    //保存按钮点击事件
{
    QByteArray block;
    msg->clearMsgPackage();

    msg->setMsgName(userwork::name.toUtf8());
    msg->setMsgStatus(EMPLOYEE);
    msg->setMsgOperate(SET);
    msg->setMsgCommand(PERSON_PWD);
    msg->setMsgContent(ui->querenpsw->text());   //存放密码
    msg->setMsgLength(qint16(block.size() + sizeof(qint16)));
    block = *(msg->packageMsg());

    register_company::tcpsocket->write(block);
}
