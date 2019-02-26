#include "myprotocl.h"
#include <QDataStream>
#include <QIODevice>

Myprotocl::Myprotocl()
{
    initMsgPackage();
}

void Myprotocl::initMsgPackage(void)
{
    clearMsgPackage();
}

void Myprotocl::clearMsgPackage(void)
{
    name.clear();
    company_name.clear();
    status = STATU_NONE;
    operate = OPERATE_NONE;
    command = COMMAND_NONE;
    m_content.clear();
    m_length = LENGTH_NONE;
}

QByteArray Myprotocl::getMsgName(void) const
{
    return name;
}
void Myprotocl::setMsgName(const QByteArray msgname)
{
    name = msgname;
}
QByteArray Myprotocl::getMsgCompany_name(void) const
{
    return company_name;
}

void Myprotocl::setMsgCompany_name(const QByteArray company_name)
{
    this->company_name = company_name;
}
qint16 Myprotocl::getMsgStatus(void) const
{
    return status;
}
void Myprotocl::setMsgStatus(const qint16 status)
{
    this->status = status;
}
qint16 Myprotocl::getMsgOperate(void) const
{
    return operate;
}
void Myprotocl::setMsgOperate(const qint16 operate)
{
    this->operate = operate;
}

qint16 Myprotocl::getMsgCommand(void) const
{
    return command;
}
void Myprotocl::setMsgCommand(const qint16 command)
{
    this->command = command;
}
QString Myprotocl::getMsgContent(void) const
{
    return m_content;
}
void Myprotocl::setMsgContent(const QString content)
{
    this->m_content = content;
}
qint16 Myprotocl::getMsgLength(void) const
{
    return m_length;
}
void Myprotocl::setMsgLength(const qint16 length)
{
    this->m_length = length;
}

void Myprotocl::updataMsg(Myprotocl *protocol)
{
    name = protocol->getMsgName();
    company_name = protocol->getMsgCompany_name();
    status = protocol->getMsgStatus();
    operate = protocol->getMsgOperate();
    command = protocol->getMsgCommand();
    m_content = protocol->getMsgContent();
    m_length = protocol->getMsgLength();
}

QByteArray *Myprotocl::updataMsg(const QByteArray msgName,
                      const QByteArray msgCompanyName,
                      const qint16 msgstatus,
                      const qint16 msgoperate,
                      const qint16 msgcommand,
                      const QString content,
                      const qint16 msglength)
{
    this->name = msgName;
    this->company_name = msgCompanyName;
    this->status = msgstatus;
    this->operate = msgoperate;
    this->command = msgcommand;
    this->m_content = content;
    this->m_length = msglength;
}

QByteArray *Myprotocl::packageMsg(void)
{
    QByteArray *buffer = new QByteArray;
    QDataStream out(buffer, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);

    out << name;
    out << company_name;
    out << status;
    out << operate;
    out << command;
    out << m_content;
    out << m_length;

    return buffer;
}
void Myprotocl::unpackageMsg(QDataStream &in)
{
    in >> name;
    in >> company_name;
    in >> status;
    in >> operate;
    in >> command;
    in >> m_content;
    in >> m_length;
}
