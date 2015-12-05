#include <iostream>
//#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <QtSql>
#include <QtDebug>
#include "services.h"
#include "ui.h"
#include "string"
#include <QCoreApplication>

using namespace std;

int main()
{

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "persons.sqlite";
    db.setDatabaseName(dbName);
    db.open();

    QSqlQuery query(db);

    string queryCreate = "CREATE TABLE Persons(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR NOT NULL, sex VARCHAR NOT NULL, yearBorn INTEGER NOT NULL, yearDead INTEGER);";
    query.exec(QString(queryCreate.c_str()));

    db.close();

    UI people;
    people.userMenu();

    return 0;
}
