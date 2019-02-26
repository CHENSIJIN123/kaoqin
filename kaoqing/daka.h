#ifndef DAKA_H
#define DAKA_H

#include <QWidget>
#include "myprotocl.h"

namespace Ui {
class daka;
}

class daka : public QWidget
{
    Q_OBJECT

public:
    explicit daka(QWidget *parent = 0);
    ~daka();
    static QString work_flag;
private slots:
    void dealtime();

    void on_pb_work_state_clicked();

private:
    Ui::daka *ui;
    QTimer *mytimer;
    Myprotocl *msg;
};

#endif // DAKA_H
