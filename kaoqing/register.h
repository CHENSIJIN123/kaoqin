#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>
#include "myprotocl.h"

namespace Ui {
class Register;
}

class Register : public QWidget
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = 0);
    ~Register();
    void initRegister();
signals:
    void zhuce_cancel();
public slots:
    void dealRegister_fail();

private slots:
    void on_pb_zhuce_clicked();
    void on_pb_quxiao_clicked();
    void deal_register_ok(); 
    void on_company_email_editingFinished();
    void on_company_queren_email_editingFinished();
    void on_company_xingming_editingFinished();
    void on_pb_isVersion_clicked();
    void on_company_pwd_editingFinished();
    void on_company_queren_pwd_editingFinished();
    void on_pb_isVersion_queren_clicked();

private:
    Ui::Register *ui;
    Myprotocl *msg;
    bool isfirstOnClickVersion;
    bool isfirstOnClickquerenVersion;
};

#endif // REGISTER_H
