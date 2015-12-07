#include "comptype.h"
#include "data.h"
#include "infotype.h"
#include "relationstype.h"
#include "services.h"
#include "ui.h"
#include <QSqlDatabase>

using namespace std;

void connect();

int main()
{
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "first");
   db = QSqlDatabase::database("first");
   QString dbName = "database.sqlite";

   db.setDatabaseName(dbName);
        if(!db.open())
        {
            qDebug() << "Error: " << db.lastError().text();
        }

   QSqlQuery query(db);
   QSqlQuery query2(db);
   QSqlQuery query3(db);
   QSqlQuery query4(db);
   QSqlQuery query5(db);
   QSqlQuery query6(db);
   QSqlQuery query7(db);

   string queryCreate = "CREATE TABLE persons(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR NOT NULL, sex VARCHAR NOT NULL, yearBorn INTEGER NOT NULL, yearDead INTEGER NOT NULL);";
   string queryCreate2 = "CREATE TABLE computers(id INTEGER PRIMARY KEY AUTOINCREMENT, compName VARCHAR NOT NULL, yearMade INTEGER NOT NULL, type VARCHAR NOT NULL, wasBuilt INTEGER NOT NULL);";
   string queryCreate3 = "CREATE TABLE relations(idPerson INEGER, idComputer INTEGER,FOREIGN KEY(idPerson) REFERENCES persons(id), FOREIGN KEY(idComputer) REFERENCES computers(id));";
   query.exec(QString(queryCreate.c_str()));
   query2.exec(QString(queryCreate2.c_str()));
   query3.exec(QString(queryCreate3.c_str()));
/*
   string queryCreate4 = "CREATE UNIQUE INDEX computerPrimaryKey on computers (id ASC);";
   string queryCreate5 = "CREATE UNIQUE INDEX relations ON person_machine_rel (idPerson ASC, idComputer ASC);";
   string queryCreate6 = "CREATE UNIQUE INDEX relations ON relations (ID ASC);";
   string queryCreate7 = "CREATE UNIQUE INDEX personPrimaryKey on persons (id ASC);";
   query4.exec(QString(queryCreate4.c_str()));
   query5.exec(QString(queryCreate5.c_str()));
   query6.exec(QString(queryCreate6.c_str()));
   query7.exec(QString(queryCreate7.c_str()));*/

   UI people;
   people.userMenu();

   return 0;
}
