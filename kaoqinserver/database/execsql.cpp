#include "execsql.h"
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QStringList>
#include <QString>
#include <QDateTime>
#define cout qDebug()<<"["<<__FILE__<<":" << __LINE__<<"]"

execSql::execSql()
{
    ///为什么构造函数必须写上东西，才能访问到数据库？
    QSqlQuery query;
    QString queryString = QString("select * from employee;");
}

bool execSql::sqlMonthVersionChoose(Myprotocl *msg)
{
    cout << msg->getMsgContent();
    QStringList list = msg->getMsgContent().split("%");  //部门+ 名字
    QSqlQuery query;
    QString queryString = QString("select employee_msg.department,daka_msg.name,"
                                  "daka_msg.date,daka_msg.gowork,daka_msg.afterwork "
                                  "from employee_msg,daka_msg where "
                                  "employee_msg.name=daka_msg.name and employee_msg.department='%1' and daka_msg.name='%2';")
                                 .arg(list[0])
                                 .arg(list[1]);
    QString sum="";
    if(query.exec(queryString))
    {
        int date_idx = query.record().indexOf("date");
        int go_idx = query.record().indexOf("gowork");
        int after_idx = query.record().indexOf("afterwork");
        if(query.next())
        {
            QString date = query.value(date_idx).toString();
            QString goWork = query.value(go_idx).toString();
            QString afterWork = query.value(after_idx).toString();
            int a[3];
            QString period;
            if(afterWork!=""&&goWork!="")
            {
                QStringList listgo = goWork.split(":");
                QStringList listaft = afterWork.split(":");

                    for(int i = 0; i < 3;i++)
                    {
                     a[i] =listaft[i].toInt() - listgo[i].toInt();
                    }
                    period = QString(" %1时%2分").arg(a[0]).arg(a[1]);
            }else
            {
                period = " ";
            }
            sum = sum + date+"/"+goWork+"/"+afterWork+"/"+period+"%";

            while(query.next())
            {
                QString date = query.value(date_idx).toString();
                QString goWork = query.value(go_idx).toString();
                QString afterWork = query.value(after_idx).toString();
                int a[3];
                QString period;
                if(afterWork!=""&&goWork!="")
                {
                    QStringList listgo = goWork.split(":");
                    QStringList listaft = afterWork.split(":");

                        for(int i = 0; i < 3;i++)
                        {
                         a[i] =listaft[i].toInt() - listgo[i].toInt();
                        }
                        period = QString(" %1时%2分").arg(a[0]).arg(a[1]);
                }else
                {
                    period = " ";
                }
                sum = sum + date+"/"+goWork+"/"+afterWork+"/"+period+"%";
            }
        }else
        {
            sum = "";
        }
        cout << sum;
        msg->setMsgContent(sum);
    }
}

bool execSql::sqlMonthVersion(Myprotocl *msg)    //处理月视图点击按下
{
    QString month = msg->getMsgContent();  //八月
    cout << "month" << month;
    if(month == "请选择月份"){return false;}
    QSqlQuery sql;
    QString sqlString = QString("select department,count(*) from employee_msg group by department");
    sql.exec(sqlString);
    QMap<QString,int> mymap;
    while(sql.next())
    {        
        QString department = sql.value("department").toString();
        int count = sql.value("count(*)").toInt();
        mymap[department] = count;
    }
    cout <<mymap;


    QSqlQuery query;
    QString queryString = QString("select date,department,daka_msg.name from daka_msg,employee_msg "
                                  "where daka_msg.name=employee_msg.name;");
    query.exec(queryString);
    QMap<QString,int> map;
    while(query.next())
    {
        QString date = query.value("date").toString();
        QString department = query.value("department").toString();

        QStringList list = date.split("月");
        cout << list.at(0)<< "     "<<QString("2018年%1").arg(month);
        if(QString(list.at(0)+"月") == QString("2018年%1").arg(month))  //月份一样。
        {
            if(map.contains(department))
            {
                map[department] = map.value(department)+1;
            }else
            {
                map[department] = 1;
            }
        }
    }cout << map;
    if(map.isEmpty())
    {
        return false;
    }

    QList<QString> list = mymap.keys();
    QList<QString> work = map.keys();

    QString content;
    int pepleCount = mymap.keys().size(); //3   QMap(("人事部", 1)("技术部", 4)("董事会", 1))
    int workCount = map.keys().size();   //2    QMap(("人事部", 4)("技术部", 1)("董事会", 1))
    for(int i = 0;i<workCount;i++)
    {
        QString dep = work.at(i);
        if(list.contains(dep))
        {
            int pvalue = mymap[dep];
            int wvalue = map[dep];
            double p = (double(wvalue)/double(pvalue*20))*100;
            cout << p;
            content = content + dep + "/" + QString::number(p)+"%";
        }
    }
    cout << content;
    msg->setMsgContent(content);
}

bool execSql::sqlAllVersionChoose(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select distinct(name) from employee_msg;");
    if(query.exec(queryString))
    {
        QString name_sum = "";
        int name_idx = query.record().indexOf("name");
        while(query.next())
        {
            QString name = query.value(name_idx).toString();
            name_sum = name_sum + name+"%";
        }
        msg->setMsgContent(name_sum);
        cout << name_sum;
    }
}

bool execSql::sqlAllVersion(Myprotocl *msg)
{
    QStringList list = msg->getMsgContent().split("%");
    QString name = list[0];
    QString vacation = list[1];
    QSqlQuery query;
    QString queryString;

        queryString = QString(" select employee_msg.department,daka_msg.name,daka_msg.date,daka_msg.gowork,"
                                      "daka_msg.afterwork from employee_msg,daka_msg where employee_msg.name=daka_msg.name;");

    QString sum = "";
    if(query.exec(queryString))
    {
        int dep_idx = query.record().indexOf("department");
        int name_idx = query.record().indexOf("name");
        int date_idx = query.record().indexOf("date");
        int go_idx = query.record().indexOf("gowork");
        int after_idx = query.record().indexOf("afterwork");
        while(query.next())
        {
            QString department = query.value(dep_idx).toString();
            QString name = query.value(name_idx).toString();
            QString date = query.value(date_idx).toString();
            QString goWork = query.value(go_idx).toString();
            QString afterWork = query.value(after_idx).toString();
            cout<<name<< department<<date<< goWork<<" "<<afterWork;

            int a[3];
            QString period;
            if(afterWork!=""&&goWork!="")
            {
                QStringList listgo = goWork.split(":");
                QStringList listaft = afterWork.split(":");

                for(int i = 0; i < 3;i++)
                {
                 a[i] =listaft[i].toInt() - listgo[i].toInt();

                }
                period = QString(" %1时%2分").arg(a[0]).arg(a[1]);
//                cout << period;
            }
            else
            {
                period = " ";
            }
            sum = sum+department+"/"+name+"/"+date+"/"+goWork+"/"+afterWork+"/"+period+"%";
        }
    }
    msg->setMsgContent(sum);
//    cout << sum;
}

bool execSql::sqlActuallyHappeningchoose(Myprotocl *msg,QString s)
{
    QString sum ="";
    QSqlQuery query;
    QString queryString;
    if(s == "所有部门")
    {
        queryString = QString("select daka_msg.name,daka_msg.operate,daka_msg.date,employee_msg.department from daka_msg, employee_msg where daka_msg.name=employee_msg.name;");
    }
    else
    {
        queryString = QString("select daka_msg.name,daka_msg.operate,daka_msg.date,employee_msg.department from daka_msg, employee_msg where daka_msg.name=employee_msg.name and employee_msg.department='%1';").arg(s);
    }
    if(query.exec(queryString))
    {
         int name_idx = query.record().indexOf("name");
         int ope_idx = query.record().indexOf("operate");
         int date_idx = query.record().indexOf("date");
         int dep_idx = query.record().indexOf("department");

         while(query.next())
         {
              QString name = query.value(name_idx).toString();
              QString operate = query.value(ope_idx).toString();
              QString date = query.value(date_idx).toString();
              QString department = query.value(dep_idx).toString();
              QString str = QString(name+"/"+operate+"/"+date+"/"+department+"%");
              sum = str + sum;
         }
         msg->setMsgContent(sum);
    }
    else
    {
        cout <<"查询失败";
    }
}

bool execSql::sqlActuallyHappening(Myprotocl *msg)
{
    QString sum = "";
    QString department_msg = "";
    QString queryString;
    //select daka_msg.name,daka_msg.operate,daka_msg.date,employee_msg.department from daka_msg, employee_msg where daka_msg.name=employee_msg.name;

    queryString = QString("select daka_msg.name,daka_msg.operate,daka_msg.date,employee_msg.department from daka_msg, employee_msg where daka_msg.name=employee_msg.name;");
    QSqlQuery query;

    if(query.exec(queryString))
    {
         int name_idx = query.record().indexOf("name");
         int ope_idx = query.record().indexOf("operate");
         int date_idx = query.record().indexOf("date");
         int dep_idx = query.record().indexOf("department");

         while(query.next())
         {
              QString name = query.value(name_idx).toString();
              QString operate = query.value(ope_idx).toString();
              QString date = query.value(date_idx).toString();
              QString department = query.value(dep_idx).toString();
              QString str = QString(name+"/"+operate+"/"+date+"/"+department+"%");
              sum = str + sum;
         }
    }

    queryString = QString("select department from employee_msg union select department_name from department;");
    if(query.exec(queryString))
    {
        int dep_idx = query.record().indexOf("department");
        while(query.next())
        {
            QString department = query.value(dep_idx).toString();
            QString str = QString(department+"/");
            department_msg = department_msg + str;
        }
    }
    sum = sum + department_msg;
//    cout << sum;
    msg->setMsgContent(sum);
    return true;
}

bool execSql::sqldealApplyAgree(Myprotocl *msg)    //审核通过
{
    QStringList list = msg->getMsgContent().split("%");
    QString name = list[0];
    QString date = list[1];
    QString type = list[2];
    cout << name << date << type;
    //update apply_msg set state = '通过' where name='%1' and date='%2' and type='%3';
    QSqlQuery query;
    QString queryString = QString("update apply_msg set state = '通过' where name='%1' and date='%2' and type='%3';")
                          .arg(name)
                          .arg(date)
                          .arg(type);
    return query.exec(queryString);
}

bool execSql::sqlApplyBudakaWatchEmloyee(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from apply_msg where name = '%1';").arg(QString(msg->getMsgName()));
    if(query.exec(queryString))
    {
        int name_idx = query.record().indexOf("name");
        int date_idx = query.record().indexOf("date");
        int time_idx = query.record().indexOf("time");
        int type_idx = query.record().indexOf("type");
        int describtion_idx = query.record().indexOf("describtion");
        int state_idx = query.record().indexOf("state");
        QString sum = "";
        while (query.next())
        {
            QString name = query.value(name_idx).toString();
            QString date = query.value(date_idx).toString();
            QString time = query.value(time_idx).toString();
            QString type = query.value(type_idx).toString();
            QString describtion = query.value(describtion_idx).toString();
            QString state = query.value(state_idx).toString();
            QString str = QString(name+"/"+date+"/"+time+"/"+type+"/"+describtion+"/"+state+"%");
            sum = str + sum;
        }
        qDebug()<<sum;
        msg->setMsgContent(sum);
    }
}

bool execSql::sqldealApplyBudakaWatch(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from apply_msg where state = '%1';").arg("未审批");
    if(query.exec(queryString))
    {
        int name_idx = query.record().indexOf("name");
        int date_idx = query.record().indexOf("date");
        int time_idx = query.record().indexOf("time");
        int type_idx = query.record().indexOf("type");
        int describtion_idx = query.record().indexOf("describtion");
        int state_idx = query.record().indexOf("state");
        QString sum = "";
        while (query.next())
        {
            QString name = query.value(name_idx).toString();
            QString date = query.value(date_idx).toString();
            QString time = query.value(time_idx).toString();
            QString type = query.value(type_idx).toString();
            QString describtion = query.value(describtion_idx).toString();
            QString state = query.value(state_idx).toString();
            QString str = QString(name+"/"+date+"/"+time+"/"+type+"/"+describtion+"/"+state+"/"+" "+"%");
            sum = str + sum;
        }
        qDebug()<<sum;
        msg->setMsgContent(sum);
    }
}

bool execSql::sqlApplyBudaka(Myprotocl *msg)
{
    ///2018年07月28日%15:18%我肚子疼来
    QStringList list = msg->getMsgContent().split("%");
    QSqlQuery query;

    ///insert into employee_msg(`name`,`id`,`phone_number`,`password`,`department`,`job`) "
    ///"values('%1','%2','%3','%4','%5','%6')")
    QString queryString = QString("insert into apply_msg(`name`,`date`,`time`,`type`,`describtion`,`state`) "
                                  "values('%1','%2','%3','%4','%5','%6')")
                                  .arg(QString(msg->getMsgName()))
                                  .arg(list[0])
                                  .arg(list[1])
                                  .arg("补打卡")
                                  .arg(list[2])
                                  .arg("未审批");
    cout << queryString;
    return query.exec(queryString);

}

bool execSql::sqlChangePWD(Myprotocl *msg)
{
    /// update employee_msg set password = '100' where name='张三'
    QSqlQuery query;
    QString queryString = QString("update employee_msg set password = '%1' where name='%2';")
                                 .arg(QString(msg->getMsgContent()))
                                 .arg(QString(msg->getMsgName()));
    return query.exec(queryString);
}

bool execSql::sqlPersonMsg(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from employee_msg;");
    if(query.exec(queryString))
    {
        int name_idx = query.record().indexOf("name");
        int pwd_idx = query.record().indexOf("password");
        while (query.next())
        {
            QString name = query.value(name_idx).toString();
            if(name == msg->getMsgName())
            {
                  QString password = query.value(pwd_idx).toString();
                  if(password == msg->getMsgContent())
                  {
                      return true;
                  }else
                  {
                      return false;
                  }
            }
        }

    }
}

bool execSql::sqlInsertDepartment(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from department;");
    if(query.exec(queryString))
    {
        int com_name_idx = query.record().indexOf("company_name");
        int dep_name_idx = query.record().indexOf("department_name");
        while (query.next())
        {
           QString company_name = query.value(com_name_idx).toString();

           if(company_name == msg->getMsgCompany_name())
           {
                QString department_name = query.value(dep_name_idx).toString();
                if(department_name == msg->getMsgContent())
                {
                    ;
                }
                else
                {
                    qDebug()<<msg->getMsgContent();
                    QString queryString1 = QString("insert into department(`company_name`,`department_name`)"
                                                   " values('%1','%2')")
                                                   .arg(QString(msg->getMsgCompany_name()))
                                                   .arg(QString(msg->getMsgContent()));
                    return query.exec(queryString1);
                }
           }
        }
    }
}

bool execSql::sqlLoginperson(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from company_msg;");
}

bool execSql::findSqlCompany(Myprotocl *msg)    //查找是否有该公司eg:腾讯
{
    QSqlQuery query;
    QString queryString = QString("select * from company_msg "
                                  "where compamy_name='%1';").arg(QString(msg->getMsgCompany_name()));
    if(query.exec(queryString))
    {
        if(query.next())
        {
            return true;
        }else
        {
            return false;
        }
    }
}

bool execSql::sqlInsertEmployee(Myprotocl *msg)
{
    QStringList list = msg->getMsgContent().split("%");
    QSqlQuery query;
    QString queryString = QString("insert into employee_msg(`name`,`id`,`phone_number`,`password`,`department`,`job`) "
                                  "values('%1','%2','%3','%4','%5','%6')")
                                   .arg(QString(msg->getMsgName()))
                                   .arg(list[1])
                                   .arg(list[2])
                                   .arg(list[0])
                                   .arg(list[3])
                                   .arg(list[4]);

    return query.exec(queryString);

}

bool execSql::findSqllogin(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from employee_msg;");
    if(query.exec(queryString))
    {
        int name_idx = query.record().indexOf("name");
        int pwd_idx = query.record().indexOf("password");
        int job_idx = query.record().indexOf("job");
        while (query.next())
        {
           QString name = query.value(name_idx).toString();
           if(name == msg->getMsgName())
           {
                QString pwd = query.value(pwd_idx).toString();
                if(pwd == msg->getMsgContent())
                {
                    QString job = query.value(job_idx).toString();
                    if(job == "管理员")
                    {
                          msg->setMsgStatus(ADMINISTRATOR);
                    }else if(job == "经理")
                    {
                          msg->setMsgStatus(MANAGER);
                    }else
                    {
                          msg->setMsgStatus(EMPLOYEE);
                    }
                    return true;
                }
                else
                {
                    return false;
                }
           }
        }
    }
}

bool execSql::sqlDepartmentWatch(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from department;");
    if(query.exec(queryString))
    {
        int dep_name_idx = query.record().indexOf("department_name");
        int dep_manager_idx = query.record().indexOf("department_manager");
        QString sum = "";
        while (query.next())
        {
            QString department_name = query.value(dep_name_idx).toString();
            QString department_manager = query.value(dep_manager_idx).toString();
            if(department_manager.isEmpty())
            {
                department_manager = "null";
            }
            QString str = QString(department_name+"/"+department_manager+"%");
            sum = str + sum;
        }
//        qDebug()<<sum;
        msg->setMsgContent(sum);
    }
}

bool execSql::sqlEmployeeWatch(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from employee_msg;");
    if(query.exec(queryString))
    {
        int name_idx = query.record().indexOf("name");
        int id_idx = query.record().indexOf("id");
        int phone_idx = query.record().indexOf("phone_number");
        int dep_idx = query.record().indexOf("department");
        int job_idx = query.record().indexOf("job");
        QString sum = "";
        while (query.next())
        {
            QString name = query.value(name_idx).toString();
            QString id = query.value(id_idx).toString();
            QString phone = query.value(phone_idx).toString();
            QString department = query.value(dep_idx).toString();
            QString job = query.value(job_idx).toString();
            QString str = QString(name+"/"+id+"/"+phone+"/"+department+"/"+job+"%");
            sum = str + sum;
        }
//        qDebug()<<sum;
        msg->setMsgContent(sum);
    }
}

bool execSql::findSqlpassword(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from employee_msg where name='%1' and password='%2'")
            .arg(QString(msg->getMsgName()))
            .arg(QString(msg->getMsgContent()));
    query.exec(queryString);
    return query.next();
}

bool execSql::sqlStarWork(Myprotocl *msg, QString s)
{
    QSqlQuery query;
    QString queryString = QString("select * from daka_msg where date='%1' and name='%2';")
            .arg(QDateTime::currentDateTime().toString("yyyy年MM月dd日"))
            .arg(QString(msg->getMsgName()));

    if(query.exec(queryString))
    {
        if(query.next())   //如果有这天的这个人打卡的信息，那么就更新
        {
            if(s == "上班")
            {
                queryString = QString("update daka_msg set gowork='%1' where date='%2';")
                        .arg(msg->getMsgContent())
                        .arg(QDateTime::currentDateTime().toString("yyyy年MM月dd日"));
            }else
            {
                queryString = QString("update daka_msg set afterwork='%1' where date='%2';")
                        .arg(msg->getMsgContent())
                        .arg(QDateTime::currentDateTime().toString("yyyy年MM月dd日"));
            }
            query.exec(queryString);
        }else    //没有这个人在这一天的打卡记录，那就插入这条记录
        {
            if(s == "上班")
            {
                queryString = QString("insert into daka_msg(date,gowork,name,operate) values('%1','%2','%3','打卡');")
                        .arg(QDateTime::currentDateTime().toString("yyyy年MM月dd日"))
                        .arg(msg->getMsgContent())
                        .arg(QString(msg->getMsgName()));
            }else
            {
                queryString = QString("insert into daka_msg(date,name,afterwork) values('%1','%2','%3');")
                        .arg(QDateTime::currentDateTime().toString("yyyy年MM月dd日"))
                        .arg(msg->getMsgContent())
                        .arg(QString(msg->getMsgName()));
            }
            query.exec(queryString);
        }
    }
}

bool execSql::sqlRegister(Myprotocl *msg)   //注册新公司名，如果公司名已存在，则返回false
{
    if(true == findSqlCompany(msg))
    {
        return false;   //注册公司在数据库中已存在
    }else
    {   //如果注册公司在数据库中不存在，在将该公司写入数据库
        QSqlQuery query;

        QStringList  list= msg->getMsgContent().split("%");
        QString company_name = QString(msg->getMsgCompany_name());
        QString name = QString(msg->getMsgName());
        QString queryString = QString("INSERT INTO company_msg(compamy_name,company_manager,company_email,company_logpwd) "
                                      "VALUES('%1','%2','%3','%4')")
                .arg(company_name)
                .arg(name)
                .arg(list[0])
                .arg(list[1]);
        return query.exec(queryString);
    }
}

bool execSql::sqlForget(Myprotocl *msg)
{
    QSqlQuery query;
    QString queryString = QString("select * from company_msg;");
    if(query.exec(queryString))
    {
        int name_idx = query.record().indexOf("company_manager");
        int email_idx = query.record().indexOf("company_email");
        int com_name_idx = query.record().indexOf("compamy_name");

        while (query.next())
        {
           QString name = query.value(name_idx).toString();
           QString email = query.value(email_idx).toString();
           QString company = query.value(com_name_idx).toString();

           if((name == msg->getMsgName()) && (email == msg->getMsgContent()))
           {
               msg->setMsgCompany_name(company.toUtf8());
               return true;
           }else
           {
               return false;
           }
        }
    }
}
