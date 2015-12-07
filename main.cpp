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

   string queryCreate = "CREATE TABLE persons(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR NOT NULL, sex VARCHAR NOT NULL, yearBorn INTEGER NOT NULL, yearDead INTEGER NOT NULL);";
   string queryCreate2 = "CREATE TABLE computers(id INTEGER PRIMARY KEY AUTOINCREMENT, compName VARCHAR NOT NULL, yearMade INTEGER NOT NULL, type VARCHAR NOT NULL, wasBuilt INTEGER NOT NULL);";
   string queryCreate3 = "CREATE TABLE relations(idPerson INEGER, idComputer INTEGER);";
   query.exec(QString(queryCreate.c_str()));
   query2.exec(QString(queryCreate2.c_str()));
   query3.exec(QString(queryCreate3.c_str()));

   UI people;
   people.userMenu();

   return 0;
}
