#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include "myprotocl.h"
#include "dealmsg.h"

namespace Ui {
class widget;
}

class widget : public QWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = 0);
    ~widget();
public slots:
    void recvMsg(void);
    void sendMessage(void);

private:
    Ui::widget *ui;
    QTcpSocket *tcpsocket;
    QTcpServer *tcpserver;
    Myprotocl *msg;
    dealMsg deal;
};

#endif // WIDGET_H
