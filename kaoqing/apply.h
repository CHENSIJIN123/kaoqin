#ifndef APPLY_H
#define APPLY_H

#include <QWidget>
#include "myprotocl.h"

namespace Ui {
class apply;
}

class apply : public QWidget
{
    Q_OBJECT

public:
    explicit apply(QWidget *parent = 0);
    ~apply();
public slots:
    void dealstate(QString s);

private slots:
    void on_pb_queren_clicked();
signals:
    void updatetable(int i);

private:
    Ui::apply *ui;
    Myprotocl *msg;
};

#endif // APPLY_H
