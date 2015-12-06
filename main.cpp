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
   //CONNECTIONS TO DATABASE
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "first");
<<<<<<< HEAD
   //QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE", "second");
   //QSqlDatabase db3 = QSqlDatabase::addDatabase("QSQLITE", "third");
=======
>>>>>>> 1fb720227bd7017425750d58c179599fad98017c

   db = QSqlDatabase::database("first");
<<<<<<< HEAD
   QString dbName = "database.sqlite";

=======
   QString dbName = "CSdatabase.sqlite";
>>>>>>> 1fb720227bd7017425750d58c179599fad98017c
   db.setDatabaseName(dbName);
        if(!db.open())
        {
            qDebug() << "Error: " << db.lastError().text();
        }

   QSqlQuery query(db);
   QSqlQuery query2(db);
   string queryCreate = "CREATE TABLE persons(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR NOT NULL, sex VARCHAR NOT NULL, yearBorn INTEGER NOT NULL, yearDead INTEGER NOT NULL);";
<<<<<<< HEAD
   string queryCreate2 = "CREATE TABLE computers(id INTEGER PRIMARY KEY AUTOINCREMENT, compName VARCHAR NOT NULL, yearMade INTEGER NOT NULL, type VARCHAR NOT NULL, wasBuilt INTEGER NOT NULL, FOREIGN KEY (id)REFERENCES persons (id));";

   query.exec(QString(queryCreate.c_str()));
   query2.exec(QString(queryCreate2.c_str()));
=======
   string queryCreate2 = "CREATE TABLE computers(id INTEGER PRIMARY KEY AUTOINCREMENT, compName VARCHAR NOT NULL, yearMade INTEGER NOT NULL, type VARCHAR NOT NULL, wasBuilt INTEGER NOT NULL);";

   query.exec(QString(queryCreate.c_str()));
   query.exec(QString(queryCreate2.c_str()));
>>>>>>> 1fb720227bd7017425750d58c179599fad98017c

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
