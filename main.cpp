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

/*struct People
{
    int id;
    string name;
};
People peoples(int id, string name)
{
    People p;
    p.id = id;
    p.name = name;
    return p;

}

int main()
{


    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "people.sqlite";

    db.setDatabaseName(dbName);
     vector<People>pep;
     db.open();

     QSqlQuery query(db);
     QSqlQuery qry(db);
     //QString sQuery = "INSERT INTO people(id,name) VALUES(50, Gulli)";
     //qry.exec(sQuery);

     std::string name;
     int id;
     cin>>id;
     cin>>name;
     QString qName = QString::fromUtf8(name.c_str());
     qry.prepare("INSERT INTO people(id,name) VALUES(:id,:name)");
     qry.bindValue(":id", id);
     qry.bindValue(":name", qName);
     qry.exec();

     query.exec("SELECT * FROM people");

     while(query.next())
     {
     int id = query.value("id").toUInt();
     string name = query.value("name").toString().toStdString();

     pep.push_back(peoples(id, name));

     }

     int size = pep.size();
     for( int i = 0; i < size; i++)
     {
        cout<<pep.at(i).id<<endl;
        cout<<pep.at(i).name<<endl;
     }
     */
