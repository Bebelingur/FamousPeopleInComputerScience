#include "data.h"

using namespace std;

data::data()
{
}
//CONNECTION
//function that connects the program to the database
void data::connectionToDatabase()
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
    string queryCreate3 = "CREATE TABLE relations(idPerson INEGER, idComputer INTEGER,FOREIGN KEY(idPerson) REFERENCES persons(id), FOREIGN KEY(idComputer) REFERENCES computers(id));";

    query.exec(QString(queryCreate.c_str()));
    query2.exec(QString(queryCreate2.c_str()));
    query3.exec(QString(queryCreate3.c_str()));
}
//VECTOR INPUT TO DATABASE
//function that loads person information from database to vector and returns it
vector<InfoType> data::loadPersData()
{
    vector<InfoType> people;

    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    query.exec("SELECT * FROM persons");

    while(query.next())
    {
        InfoType p;
        p.id = query.value("id").toUInt();
        p.name = query.value("name").toString().toStdString();
        p.gender = convertToChar(query.value("sex").toString().toStdString());
        p.birthYear = query.value("yearBorn").toUInt();
        p.deathYear = query.value("yearDead").toUInt();
        people.push_back(p);
    }
    return people;
}
//function that loads computer information from database to vector and returns it
vector<CompType> data::loadCompData()
{
    vector<CompType> computers;

    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    query.exec("SELECT * FROM computers");

    while(query.next())
    {
        CompType c;
        c.id = query.value("id").toUInt();
        c.compName = query.value("compName").toString().toStdString();
        c.yearMade = query.value("yearMade").toUInt();
        c.type = query.value("type").toString().toStdString();
        c.wasBuilt = query.value("wasBuilt").toUInt();
        computers.push_back(c);
    }
    return computers;
}
//VECTOR OUTPUT TO DATABASE
//function that saves relation info between person and computer to database
void data::saveDataRelations(RelationsType p)
{
    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);

    query.prepare("Insert Into relations(idPerson, idComputer)Values(:idPerson, :idComputer)");
    query.bindValue(":idPerson", p.personId);
    query.bindValue(":idComputer", p.computerId);
    if(!query.exec())
    {
        qDebug() << "addRelations error:  " << query.lastError();
    }
}

//function that saves person info to database
void data::saveDataPersons(InfoType p)
{
    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);

    string sex = convertToString(p.gender);
    QString qName = QString::fromUtf8(p.name.c_str());
    QString qSex = QString::fromUtf8(sex.c_str());

    query.prepare("INSERT INTO persons(name, sex, yearBorn, yearDead)VALUES(:name, :sex, :yearBorn, :yearDead)");
    query.bindValue(":name", qName);
    query.bindValue(":sex", qSex);
    query.bindValue(":yearBorn", p.birthYear);
    query.bindValue(":yearDead", p.deathYear);

    if(!query.exec())
    {
        qDebug() << "addPersons error:  " << query.lastError();
    }
}
//function that saves computer info to database
void data::saveDataComputers(CompType p)
{
    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);

    QString qcompName = QString::fromUtf8(p.compName.c_str());
    QString qtype = QString::fromUtf8(p.type.c_str());

    query.prepare("INSERT INTO computers(compName, yearMade, type, wasBuilt)VALUES(:compName, :yearMade, :type, :wasBuilt)");
    query.bindValue(":compName", qcompName);
    query.bindValue(":yearMade", p.yearMade);
    query.bindValue(":type", qtype);
    query.bindValue(":wasBuilt", p.wasBuilt);

    if(!query.exec())
    {
        qDebug() << "addComputer error:  " << query.lastError();
    }
}
//function that converts string to char and returns it
char data::convertToChar(string a)//fall sem tekur string úr databaseinu og skilar char inní vectorinn
{
    char result;
    result = a.at(0);
    return result;
}
//function that converts char to string and returns it
string data::convertToString(char a)
{
    string result;
    result = a;
    return result;
}
