#include <iostream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <QtSql>
#include <QtDebug>
#include "services.h"
#include "ui.h"

using namespace std;

int main()
{
    UI people;
    people.userMenu();

    /*QString servername = "LOCALHOST\\SQLEXPRESS";
    //local host is your ip address on microsoft
    QString dbname = "test";
    //geri þetta til að connect to host

    QSqlDatabase db QSqlDatabase::addDatabase("QODBC");
    //universal driver QODBC

    db.setConnectOptions();
    QString dsn = QString("Driver=(SQL Native Client);SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);
    //copy and paste connection string from SQLite

    db.setDatabaseName(dsn);
    if(db.open())
    {
        qDebug() << "Opened!";
        db.close();
    }
    else
    {
        qDebug() << "Error = " << db.lastError().text();
        //figure out what happened here
    }
    //got to have a server name and method of connecting
    */
    return 0;
}
