#include "data.h"

using namespace std;


data::data()
{

    //personFilename = ''persons.sqlite'';
    //computerFilename = ''computers.sqlite'';

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

    db.open();

    //db.( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );
    QSqlQuery query(db);

    string sex = convertToString(p.gender);

    string queryCreate = "CREATE TABLE Persons(id INTEGER, name VARCHAR, sex VARCHAR, yearBorn INTEGER, yearDead INTEGER);";
    query.exec(QString(queryCreate.c_str()));

    /*if(p.deathYear == 0)
    {
        db.prepare( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );

        db.( "INSERT INTO persons (name, gender, yearBorn) VALUES (p.name, p.gender, p.birthYear)" );

        if( !db.exec() )
            qDebug() << db.lastError();
        else
            qDebug( "Inserted!" );

        //ef ekki búa til DB í SQL(CREATE TABLE persons)
        //(id(INTEGER PRIMARY KEY AOTUINCREMENT), name(VARCHAR NOT NULL), gender(CHAR NOT NULL), yearBorn(INTEGER NOT NULL), yearDead(INTEGER)
    //setja úr vektor inn í databaseið persons(INSERT INTO persons (name, gender, yearBorn) VALUES(p.name, p.gender, p.birthyear)*/
    db.close();
}

//þarf að geyma gender sem VARCHAR í SQL og breyta því í char þegar ég set það í vector og öfugt
char data::convertToChar(string a)//fall sem tekur string úr databaseinu og skilar char inní vectorinn
{
    char result;
    result = a.at(0);
    return result;
}

string data::convertToString(char a)
{
    string result;
    result = a;
    return result;
}
