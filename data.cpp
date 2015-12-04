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

vector <InfoType> data::loadData()//setja string(filename) her inn til að geta notað fyrir computers og persons
{
    vector<InfoType> people;
    InfoType p;

    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "persons.sqlite";
    db.setDatabaseName(dbName);//þarf þetta?

    db.open();

    if(!db.open())//má hafa villucheck hér?
    {
        qDebug() << "Error = " << db.lastError().text();
    }


    QSqlQuery query(db);

    query.exec("SELECT * FROM persons");//vesen hér samt

    while(query.next())
    {
        p.name = query.value("name").toString().toStdString();


        p.gender = convertToChar(query.value("gender").toChar());

        p.birthYear = query.value("yearBorn").toUInt();

        p.deathYear = query.value("yearDead").toUInt();

        people.push_back(p);

        //get ég notað þetta fall fyrir computers líka, bara geta breytt filenameinu?
    }

    db.close();

    return people;
}

void data::saveData(InfoType p)//sama ves hér og í hinu, að þurfa ekki að tvíkóða, geta notað fyrir peeps og comps
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "persons.sqlite";
    db.setDatabaseName(dbName);
    db.open();

    if(!db.open())//má hafa villucheck hér?
    {
        qDebug() << "Error = " << db.lastError().text();
    }

       /* db.( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );
        if( !db.exec() )
            qDebug() << db.lastError();
        else
            qDebug( "Inserted!" );*/



        //ef ekki búa til DB í SQL(CREATE TABLE persons)
        //(id(INTEGER PRIMARY KEY AOTUINCREMENT), name(VARCHAR NOT NULL), gender(CHAR NOT NULL), yearBorn(INTEGER NOT NULL), yearDead(INTEGER)
    //setja úr vektor inn í databaseið persons(INSERT INTO persons (name, gender, yearBorn) VALUES(p.name, p.gender, p.birthyear)
}

char data::convertToChar(QChar a)//fall sem QChar í Char
{
    char result;
    string b = a.decomposition().toStdString();

    result = b.at(0);
    return result;
}
