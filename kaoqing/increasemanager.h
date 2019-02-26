#ifndef INCREASEMANAGER_H
#define INCREASEMANAGER_H

#include <QWidget>
#include "myprotocl.h"

namespace Ui {
class increaseManager;
}

class increaseManager : public QWidget
{
    Q_OBJECT

public:
    explicit increaseManager(QWidget *parent = 0);
    ~increaseManager();
protected:
    void closeEvent(QCloseEvent *e);

public slots:
    void dealinsertDepartment();

private slots:
    void on_pb_increase_clicked();
signals:
    void show_departmentMsg();
    void tianjia_event();

private:
    Ui::increaseManager *ui;
    Myprotocl *msg;
};

#endif // INCREASEMANAGER_H
