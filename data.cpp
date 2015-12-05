#include "data.h"

using namespace std;

data::data()
{
    //personFilename = ''persons.sqlite'';
    //computerFilename = ''computers.sqlite'';
}

vector<InfoType> data::loadPersData()
{
    vector<InfoType> people;

    QSqlDatabase db;
    db = QSqlDatabase::database("first");
    QSqlQuery query(db);

    query.exec("SELECT * FROM persons");

    while(query.next())
    {
        InfoType p;
        p.name = query.value("name").toString().toStdString();
        p.gender = convertToChar(query.value("sex").toString().toStdString());
        p.birthYear = query.value("yearBorn").toUInt();
        p.deathYear = query.value("yearDead").toUInt();
        people.push_back(p);
    }
    return people;
}

vector<CompType> data::loadCompData()
{
    vector<CompType> computers;
    QSqlDatabase db;
    db = QSqlDatabase::database("second");
    QSqlQuery query(db);

    query.exec("SELECT * FROM computers");

    while(query.next())
    {
        CompType c;
        c.compName = query.value("compName").toString().toStdString();
        c.yearMade = query.value("yearMade").toUInt();
        c.type = query.value("type").toString().toStdString();
        c.wasBuilt = convertToChar(query.value("wasBuilt").toString().toStdString());
        computers.push_back(c);
    }
    return computers;

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
}
void data::saveDataComputers(CompType p)
{
    QSqlDatabase db2;
    db2 = QSqlDatabase::database("second");
    QSqlQuery query(db2);
    string wasBuilt = convertToString(p.wasBuilt);
    QString qcompName = QString::fromUtf8(p.compName.c_str());
    QString qtype = QString::fromUtf8(p.type.c_str());
    QString qwasBuilt = QString::fromUtf8(wasBuilt.c_str());
    query.prepare("INSERT INTO computers(compName, yearMade, type, wasBuilt)VALUES(:compName, :yearMade, :type, :wasBuilt)");
    query.bindValue(":compName", qcompName);
    query.bindValue(":yearMade", p.yearMade);
    query.bindValue(":type", qtype);
    query.bindValue(":wasBuilt", qwasBuilt);
    if(!query.exec())
    {
        qDebug() << "addPerson error:  " << query.lastError();
    }
}

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
