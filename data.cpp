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
        //p.gender = query.value("gender").toChar();
        p.birthYear = query.value("birthyear").toUInt();

        //if deathyear is NULL, ekki ná í deathyear ef null annars ná í það? spurja gulla eða holmfriði

        people.push_back(p);

        //get ég notað þetta fall fyrir computers líka, bara geta breytt filenameinu?
    }

    return people;
}

void data::saveData(vector<InfoType> p)//sama ves hér og í hinu, að þurfa ekki að tvíkóða, geta notað fyrir peeps og comps
{

    //setja úr vektor inn í data, þarf að læra

}
