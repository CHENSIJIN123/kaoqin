#ifndef FORGETCOMPANYNAME_H
#define FORGETCOMPANYNAME_H

#include <QWidget>
#include "myprotocl.h"

namespace Ui {
class forgetcompanyname;
}

class forgetcompanyname : public QWidget
{
    Q_OBJECT

public:
    explicit forgetcompanyname(QWidget *parent = 0);
    ~forgetcompanyname();
signals:
    void close_forget();
private slots:
    void on_pb_ok_clicked();

    void deal_com_name(QString s);

    void on_pb_cancel_clicked();

    void on_le_email_editingFinished();

private:
    Ui::forgetcompanyname *ui;
    Myprotocl *msg;     //协议类
};

#endif // FORGETCOMPANYNAME_H
