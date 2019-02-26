#ifndef KAOQIN_H
#define KAOQIN_H

#include <QWidget>
#include "myprotocl.h"
#include "increasemanager.h"
#include <QTableWidgetItem>

namespace Ui {
class kaoqin;
}

class kaoqin : public QWidget
{
    Q_OBJECT

public:
    explicit kaoqin(QWidget *parent = 0);
    ~kaoqin();
    void watchDepartmentMsg();
    void watchManagerMsg();
    void Table3ExcelByHtml(QTableWidget *table,QString title);
    void initShow();
public slots:
    void dealinsertEmployee();
    void dealemployeeWatch(QString s);
    void dealdapartmentWatch(QString s);
    void dealshow_departmentMsg();
    void dealtianjiaEvent();
    void dealManagerWatch(QString);
    void dealshenpiWatch(QString);
    void dealsetchangepsw_true(int i);
    void dealsucceed_changepwd();
    void dealActuallyHappening(QString s);
    void dealActuallyHappeningchoose(QString s);
    void dealAllVersion(QString s);
    void dealMonthVersion(QString s);
    void dealMonthVersionChoose(QString s);
private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_9_clicked();

    void on_currentpsw_editingFinished();

    void on_querenpsw_editingFinished();

    void on_pb_save_clicked();

    void on_pb_return_clicked();

    void on_tableWidget_4_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pb_correct_clicked();

    void on_comboBoxDep_currentIndexChanged(const QString &arg1);

    void on_comboBoxMonth_currentIndexChanged(const QString &arg1);

private:
    Ui::kaoqin *ui;
    Myprotocl *msg;
    QString employeeMsg;
    increaseManager *increase;
    QString departmentMsg;
    QString managerMsg;
    int flag;
    int isCanShenghe;
    int row;
    QString tableMsg;
    int first;
    int all_version_show_table;
    QString all_version_choose_employee;
    QString all_version_choose_vacation;

    int first_month;
    static QStringList listmonth;
};

#endif // KAOQIN_H
