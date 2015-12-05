#include <QtSql>
#include "data.h"
#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include "string"


data::data()
{
<<<<<<< HEAD

    //personFilename = 'persons.sqlite';
    //computerFilename = 'computers.sqlite';
=======
    //personFilename = ''persons.sqlite'';
    //computerFilename = ''computers.sqlite'';

>>>>>>> 2f2d84517bbb239381a21eb98de6b8363cafc19e
}

vector <InfoType> data::loadData()
{
    vector<InfoType> people;
    InfoType p;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "persons.sqlite";
    db.setDatabaseName(dbName);

    db.open();

    if(!db.open())//má hafa villucheck hér?  - má ekki þurfum að laga
    {
        qDebug() << "Error = " << db.lastError().text();
    }

    QSqlQuery query(db);

    query.exec("SELECT * FROM persons");//vesen hér samt

    while(query.next())
    {
        p.name = query.value("name").toString().toStdString();

        p.gender = convertToChar(query.value("sex").toString().toStdString());

        p.birthYear = query.value("yearBorn").toUInt();

        p.deathYear = query.value("yearDead").toUInt();

        people.push_back(p);
    }

    db.close();

    return people;
}
void data::saveData(InfoType p)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "persons.sqlite";
    db.setDatabaseName(dbName);

<<<<<<< HEAD
    db.open();

    db.( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );
=======
    QSqlQuery query(db);

    string sex = convertToString(p.gender);

    string queryCreate = "CREATE TABLE Persons(id INTEGER, name VARCHAR, sex VARCHAR, yearBorn INTEGER, yearDead INTEGER);";
    query.exec(QString(queryCreate.c_str()));

    /*if(p.deathYear == 0)
    {
        db.prepare( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );

        db.( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );

>>>>>>> 2f2d84517bbb239381a21eb98de6b8363cafc19e
        if( !db.exec() )
            qDebug() << db.lastError();
        else
            qDebug( "Inserted!" );

        //ef ekki búa til DB í SQL(CREATE TABLE persons)
        //(id(INTEGER PRIMARY KEY AOTUINCREMENT), name(VARCHAR NOT NULL), gender(CHAR NOT NULL), yearBorn(INTEGER NOT NULL), yearDead(INTEGER)
    //setja úr vektor inn í databaseið persons(INSERT INTO persons (name, gender, yearBorn) VALUES(p.name, p.gender, p.birthyear)
    db.close();
}

/*//þarf að geyma gender sem VARCHAR í SQL og breyta því í char þegar ég set það í vector og öfugt
char data::convertToChar(string a)//fall sem tekur string úr databaseinu og skilar char inní vectorinn
{
    char result;
    result = a.at(0);
    return result;
<<<<<<< HEAD
}*/
=======
}

string data::convertToString(char a)
{
    string result;
    result = a;
    return result;
}
>>>>>>> 2f2d84517bbb239381a21eb98de6b8363cafc19e
