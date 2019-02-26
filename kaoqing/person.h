#ifndef PERSON_H
#define PERSON_H

#include <QWidget>
#include "apply.h"
#include "myprotocl.h"
#include <QTableWidget>

namespace Ui {
class person;
}

class person : public QWidget
{
    Q_OBJECT

public:
    explicit person(QWidget *parent = 0);
    ~person();
    void Table3ExcelByHtml(QTableWidget *table,QString title);

signals:
    void state(QString s);

public slots:
    void dealsetchangepsw_true(int i);
    void dealsucceed_changepwd();
    void dealApplyBudakaWatchEmloyee(QString s);
    void on_tabWidget_tabBarClicked(int index);

private slots:
    void on_pb_apply_budaka_clicked();

    void on_pb_apply_vacation_clicked();

    void on_pb_apply_jiaban_clicked();

    void on_checkBox_clicked();

    void on_currentpsw_editingFinished();

    void on_querenpsw_editingFinished();

    void on_pb_return_clicked();

    void on_pb_save_clicked();

private:
    Ui::person *ui;
    apply *p;
    int flag;
    Myprotocl *msg;
};

#endif // PERSON_H
