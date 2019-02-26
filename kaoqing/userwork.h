#ifndef USERWORK_H
#define USERWORK_H

#include <QWidget>
#include "daka.h"
#include "myprotocl.h"

namespace Ui {
class userwork;
}

class userwork : public QWidget
{
    Q_OBJECT

public:
    explicit userwork(QWidget *parent = 0);
    ~userwork();
    static QString name;
public slots:
    void dealpwderror();
    void dealstartWork();
private slots:
    void on_pb_daka_clicked();
    void dealtime();

    void on_pb_login_clicked();

private:
    Ui::userwork *ui;
    daka *d;
    Myprotocl *msg;
    QTimer *mytimer;
    int flag;

};

#endif // USERWORK_H
