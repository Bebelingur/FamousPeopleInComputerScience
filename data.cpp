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
    QSqlQuery query(db);

    //query.exec("SELECT * FROM persons");//vesen hér samt

    while(query.next())
    {
        p.name = query.value("name").toString().toStdString();
        p.gender = convertToChar(query.value("sex").toString().toStdString());
        p.birthYear = query.value("yearBorn").toUInt();
        p.deathYear = query.value("yearDead").toUInt();
        people.push_back(p);
    }

    return people;
}
void data::saveDataPersons(InfoType p)
{
    QSqlDatabase db;
    db = QSqlDatabase::database("first");
    QSqlQuery query(db);

    string sex = convertToString(p.gender);

    QString qName = QString::fromUtf8(p.name.c_str());
    QString qSex = QString::fromUtf8(sex.c_str());
    query.prepare("INSERT INTO persons(name, sex, yearBorn, yearDead)VALUES(:name, :sex, :yearBorn, :yearDead)");
    query.bindValue(":name", qName);
    query.bindValue(":sex", qSex);
    query.bindValue(":yearBorn", p.birthYear);
    query.bindValue(":yearDead", p.deathYear);
    query.exec();

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
}
void data::saveDataComputers(CompType p)
{
    QSqlDatabase db2;
    db2 = QSqlDatabase::database("second");
    //QSqlQuery query("second", db2);
    QSqlQuery query(db2);


    string wasBuilt = convertToString(p.wasBuilt);

    QString qcompName = QString::fromUtf8(p.compName.c_str());
    QString qtype = QString::fromUtf8(p.type.c_str());
    QString qwasBuilt = QString::fromUtf8(wasBuilt.c_str());

    query.prepare("INSERT INTO computers(compName, yearMade, type, wasBuilt)VALUES(:compName, :yearMade, :type, :wasBuilt)");
    query.bindValue(":compName", qcompName);
    query.bindValue(":yearBorn", p.yearMade);
    query.bindValue(":type", qtype);
    query.bindValue(":wasBuilt", qwasBuilt);
    query.exec();
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
