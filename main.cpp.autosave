#include "comptype.h"
#include "data.h"
#include "infotype.h"
#include "relationstype.h"
#include "services.h"
#include "ui.h"



using namespace std;

int main()
{

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "persons.sqlite";
    db.setDatabaseName(dbName);

    /*QSqlQuery query(db);
    if(db.open())
    {
        qDebug()<<"Opened";
    }
    else
    {
        qDebug()<<"Error ="<<db.lastError().text();
    }
    string queryCreate = "CREATE TABLE persons(id INTEGER PRIMAY KEY AUTOINCREMENT, name VARCHAR, sex VARCHAR, yearBorn INTEGER, yearDead INTEGER);";
    */
    if(db.open())
    {
        qDebug() << "Opened!";
    }
    else
    {
        qDebug() << "Error = " << db.lastError().text();
        //figure out what happened here
    }

    QSqlQuery query(db);
    string queryCreate = "CREATE TABLE persons(id INTEGER PRIMARY KEY AUTOINCREMENT, name VARCHAR NOT NULL, sex VARCHAR NOT NULL, yearBorn INTEGER NOT NULL, yearDead INTEGER NOT NULL);";
    query.exec(QString(queryCreate.c_str()));

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
