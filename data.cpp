#include <QtSql>
#include "data.h"
#include <QCoreApplication>
#include <QDebug>
#include <QtSql>

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

    QSqlQuery query(db);

    query.exec("SELECT * FROM persons");//vesen hér samt

    while(query.next())
    {
        p.name = query.value("name").toString().toStdString();

        //p.gender = query.value("gender").toChar();//þarf að ná að breyta qChar í char (mögulega breyti í string)

        p.birthYear = query.value("birthyear").toUInt();


        if(query.value("deathyear").toUInt() == NULL)//tjekka hvort deathyear sé relevant
            p.deathYear = 0;
        else
            p.deathYear = query.value("deathyear").toUInt();

        people.push_back(p);

        //get ég notað þetta fall fyrir computers líka, bara geta breytt filenameinu?
    }

    return people;
}

void data::saveData(vector<InfoType> p)//sama ves hér og í hinu, að þurfa ekki að tvíkóða, geta notað fyrir peeps og comps
{
    //Tjekka hvort database sé til, ef til þá halda áfram
        //ef ekki búa til DB í SQL(CREATE TABLE persons)
        //(id(INTEGER PRIMARY KEY AOTUINCREMENT), name(VARCHAR NOT NULL), gender(CHAR NOT NULL), yearBorn(INTEGER NOT NULL), yearDead(INTEGER)
    //setja úr vektor inn í databaseið persons(INSERT INTO persons (name, gender, yearBorn) VALUES(p.name, p.gender, p.birthyear)
}
