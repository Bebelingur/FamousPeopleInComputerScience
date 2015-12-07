#include "data.h"

using namespace std;

data::data()
{
    //personFilename = ''first'';
    //computerFilename = ''second'';
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
        p.id = query.value("id").toUInt();
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
    db = QSqlDatabase::database("first");
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
void data::saveDataRelations(RelationsType p)
{
    QSqlDatabase db;
    db = QSqlDatabase::database("first");
    QSqlQuery query(db);


    query.prepare("Insert Into relations(idPerson, idComputer)Values(:idPerson, :idComputer)");
    query.bindValue(":idPerson", p.personId);
    query.bindValue(":idComputer", p.computerId);
    if(!query.exec())
    {
        qDebug() << "addPersons error:  " << query.lastError();
    }
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

    if(!query.exec())
    {
        qDebug() << "addPersons error:  " << query.lastError();
    }
}
void data::saveDataComputers(CompType p)
{
    QSqlDatabase db;
    db = QSqlDatabase::database("first");
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
