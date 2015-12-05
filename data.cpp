#include <QtSql>
#include "data.h"
#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include <string>


data::data()
{
    //personFilename = 'persons.sqlite';
    //computerFilename = 'computers.sqlite';
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

        p.gender = convertToChar(query.value("gender").toString().toStdString());

        p.birthYear = query.value("yearBorn").toUInt();

        if(query.value("yearDead").toUInt() == 0)//tjekka hvort deathyear sé relevant

        if(query.value("yearDead").toUInt() == NULL)//tjekka hvort deathyear sé relevant

            p.deathYear = 0;
        else
            p.deathYear = query.value("yearDead").toUInt();

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
    db.open();

    /*if(!db.open())//má hafa villucheck hér? - nope, muna að laga
    {
        qDebug() << "Error = " << db.lastError().text();
    }*/

    QSqlQuery query(db);

    string queryCreate = "CREATE TABLE Persons(id INTEGER, name VARCHAR, gender VARCHAR(sds), yearBorn INTEGER, yearDead INTEGER);";
    query.exec(QString(queryCreate.c_str()));

    /*if(p.deathYear == 0)
    }

    if(p.deathYear == 0
    {
        db.prepare( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );

    /*
        db.( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );

        if( !db.exec() )
            qDebug() << db.lastError();
        else
            qDebug( "Inserted!" );*/



        //ef ekki búa til DB í SQL(CREATE TABLE persons)
        //(id(INTEGER PRIMARY KEY AOTUINCREMENT), name(VARCHAR NOT NULL), gender(CHAR NOT NULL), yearBorn(INTEGER NOT NULL), yearDead(INTEGER)
    //setja úr vektor inn í databaseið persons(INSERT INTO persons (name, gender, yearBorn) VALUES(p.name, p.gender, p.birthyear)
}

//þarf að geyma gender sem VARCHAR í SQL og breyta því í char þegar ég set það í vector og öfugt
char data::convertToChar(string a)//fall sem tekur string úr databaseinu og skilar char inní vectorinn
{
    char result;
    result = a.at(0);
    return result;
}
