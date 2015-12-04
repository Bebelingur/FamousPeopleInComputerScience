#include <QtSql>
#include "data.h"
#include <QCoreApplication>
#include <QDebug>
#include <QtSql>
#include "string"

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

        //p.gender = query.value("gender").toChar();//þarf að ná að breyta QChar í char (mögulega breyti í string)

        p.birthYear = query.value("yearBorn").toUInt();

<<<<<<< HEAD

        if(query.value("yearDead").toUInt() == 0)//tjekka hvort deathyear sé relevant
=======
        if(query.value("yearDead").toUInt() == NULL)//tjekka hvort deathyear sé relevant

>>>>>>> 03e45536cb3700040580ebe4d6c765866349cdbb
            p.deathYear = 0;
        else
            p.deathYear = query.value("yearDead").toUInt();

        people.push_back(p);

        //get ég notað þetta fall fyrir computers líka, bara geta breytt filenameinu?
    }

    db.close();

    return people;

}
void data::saveData() //sama ves hér og í hinu, að þurfa ekki að tvíkóða, geta notað fyrir peeps og comps
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "persons.sqlite";
    db.setDatabaseName(dbName);
    db.open();

   /* if(!db.open())//má hafa villucheck hér?
    {
        qDebug() << "Error = " << db.lastError().text();
<<<<<<< HEAD
    }*/

    QSqlQuery query(db);

    string queryCreate = "CREATE TABLE Persons(id INTEGER, name VARCHAR, gender CHAR, yearBorn INTEGER, yearDead INTEGER);";
    query.exec(QString(queryCreate.c_str()));


    /*if(p.deathYear == 0)
=======
    }

    if(p.deathYear == 0)
>>>>>>> 03e45536cb3700040580ebe4d6c765866349cdbb
    {
        db.prepare( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );
        if( !db.exec() )
            qDebug() << db.lastError();
        else
            qDebug( "Inserted!" );
    }
    else
    {
        db.prepare( "INSERT INTO persons (name, gender, yearBorn, yearDead) VALUES (p.name, p.gender, p.birthYear, p.deathYear)" );
        if( !db.exec() )
            qDebug() << db.lastError();
        else
            qDebug( "Inserted!" );
    }*/



        //ef ekki búa til DB í SQL(CREATE TABLE persons)
        //(id(INTEGER PRIMARY KEY AOTUINCREMENT), name(VARCHAR NOT NULL), gender(CHAR NOT NULL), yearBorn(INTEGER NOT NULL), yearDead(INTEGER)
    //setja úr vektor inn í databaseið persons(INSERT INTO persons (name, gender, yearBorn) VALUES(p.name, p.gender, p.birthyear)
}
