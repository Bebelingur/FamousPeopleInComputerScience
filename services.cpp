#include "services.h"
#include <ctime>

using namespace std;

int exactYearNow()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int exactYearNow = 1900 + ltm->tm_year;
    return exactYearNow;
}

const int yearNow = exactYearNow();
const int alive = (yearNow + 1);

Services::Services()
{

}
//ADD FÖLLIN
void Services::addPerson(string name, char gender, int bYear, int dYear)
{
    InfoType p;
    p.name = name;
    p.gender = gender;
    p.birthYear = bYear;
    p.deathYear = dYear;

    data personsToData;
    personsToData.saveDataPersons(p);
}
void Services::addComputer(string compName, int yearMade, string type, int wasBuilt)
{
    CompType p;
    p.compName = compName;
    p.yearMade = yearMade;
    p.type = type;
    p.wasBuilt = wasBuilt;

    data computersToData;
    computersToData.saveDataComputers(p);
}
void Services::addRelation(int personId, int computerId)
{
    RelationsType p;
    p.personId = personId;
    p.computerId = computerId;

    data relationsToData;
    relationsToData.saveDataRelations(p);
}
//MAKE FÖLLIN
vector<InfoType> Services::makePersonsVector()
{
   vector<InfoType> p = connection.loadPersData();
   return p;
}
vector<CompType> Services::makeComputerVector()
{
   vector<CompType> c = connection.loadCompData();
   return c;
}
void Services::makeRelation()
{
      string compName = "";
      string name = "";
      int compID = 0;
      int persID = 0;

      QSqlDatabase db;
      db = QSqlDatabase::database("first");
      db.open();
      QSqlQuery query(db);
        do{
            cout << "Enter name of computer: ";
            getline(cin, compName);
            QString qName = QString::fromUtf8(compName.c_str());
            query.exec("SELECT compName, id FROM computers WHERE compName LIKE '" + qName + "'");
                while(query.next())
                {
                    CompType c;
                    c.id = query.value("id").toUInt();
                    compID = c.id;
                }
            }while(compID == 0);

        do{
            cout << "Enter person: ";
            getline(cin, name);
            QString qName = QString::fromUtf8(name.c_str());
            query.exec("SELECT name, id FROM persons WHERE name LIKE '" + qName + "'");
                while(query.next())
                {
                    InfoType p;
                    p.id = query.value("id").toUInt();
                    persID = p.id;
                }
            }while(persID == 0);

      bool check = false;
      query.exec("SELECT* FROM relations");
      while(query.next())
      {
          RelationsType r;
          r.computerId = query.value("idComputer").toUInt();
          r.personId = query.value("idPerson").toUInt();

          if((r.computerId == compID) && (r.personId == persID))
          {
                cout << "| | | Relation is already in database | | |" << endl;
                cout << endl;
                check = true;
          }
      }
      if(check == false)
      {
          addRelation(persID, compID);
      }
}
//VIEW FÖLLIN
vector<InfoType> Services::viewPersonsInfo()//displayar manneskjur, þurfum að annað sem birtir tölvur
{
    vector <InfoType> x = makePersonsVector();
    return x;

}
vector<CompType> Services::viewComputerInfo()
{
    vector <CompType> x = makeComputerVector();
    return x;
}
/*
void Services::viewRelationPerson()
{
    UI a;
    string name = "";
    int persID = 0;

<<<<<<< HEAD
    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    do
    {
        cout<<"Enter name: ";
        cin>>name;
        QString qName = QString::fromUtf8(name.c_str());
        query.exec("SELECT name, id FROM persons WHERE name LIKE '"+qName+"'");
=======
        string name = "";
        QSqlDatabase db;
        int ID = 0;
        db = QSqlDatabase::database("first");
        QSqlQuery query(db);
        do
        {
            cout<<"Enter name: ";
            getline(cin, name);
            QString qName = QString::fromUtf8(name.c_str());
            query.exec("SELECT name, id FROM persons WHERE name LIKE '"+qName+"'");
            while(query.next())
            {
                InfoType p;
                p.id = query.value("id").toUInt();
                ID = p.id;
            }
        }while(name == "");

        vector<CompType> computers;
        query.exec("SELECT computers.* FROM computers INNER JOIN relations ON persons.id = relations.idPerson INNER JOIN persons ON computers.id = relations.idComputer WHERE idPerson = "+QString::number(ID)+"");
>>>>>>> d50e41187ead18d698532996fa10e2d30cbec848
        while(query.next())
        {
            InfoType p;
            p.id = query.value("id").toUInt();
            persID = p.id;
        }
    }while(name == "");

    string stringID = to_string(persID);
    QString qString = QString::fromUtf8(stringID.c_str());
    vector<CompType> computers;
    query.exec("SELECT computers.* FROM computers INNER JOIN relations ON persons.id = relations.idPerson INNER JOIN persons ON computers.id = relations.idComputer WHERE idPerson = '"+qString+"'");

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
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        a.displayComputer(computers[i]);
    }
    if(computers.size() == 0)
    {
        cout << endl;
        cout << "| | | Name not in database or no relations to show. | | |" << endl;
        cout << endl;
    }
}
void Services::viewRelationComputer()
{
    UI a;
    data b;

    string name = "";
<<<<<<< HEAD
    int persID = 0;

    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    do
    {
        cout << "Enter computer name: ";
        cin >> name;

=======
    QSqlDatabase db;
    int ID = 0;
    db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    do
    {
        cout<<"Enter computer name: ";
        getline(cin, name);
>>>>>>> d50e41187ead18d698532996fa10e2d30cbec848
        QString qName = QString::fromUtf8(name.c_str());
        query.exec("SELECT compName, id FROM computers WHERE compName LIKE '"+qName+"'");

        while(query.next())
        {
            InfoType p;
            p.id = query.value("id").toUInt();
            ID = p.id;
        }
    }while(name == "");

<<<<<<< HEAD
    string stringID = to_string(persID);
    QString qString = QString::fromUtf8(stringID.c_str());

    vector<InfoType> people;

    query.exec("SELECT persons.* FROM persons INNER JOIN relations ON persons.id = relations.idPerson INNER JOIN computers ON computers.id = relations.idComputer WHERE idComputer ='"+qString+"'");
=======
    vector<InfoType> people;
    query.exec("SELECT persons.* FROM persons INNER JOIN relations ON persons.id = relations.idPerson INNER JOIN computers ON computers.id = relations.idComputer WHERE idComputer ='"+QString::number(ID)+"'");
>>>>>>> d50e41187ead18d698532996fa10e2d30cbec848
    while(query.next())
    {
        InfoType p;
        p.id = query.value("id").toUInt();
        p.name = query.value("name").toString().toStdString();
        p.gender = b.convertToChar(query.value("sex").toString().toStdString());
        p.birthYear = query.value("yearBorn").toUInt();
        p.deathYear = query.value("yearDead").toUInt();
        people.push_back(p);
    }
    for(unsigned int i = 0; i < people.size(); i++)
    {
        a.displayPerson(people[i]);
    }
    if(people.size() ==0)
    {
        cout<<endl;
        cout<<"| | |name not in database or no relations to show| | |"<<endl;
        cout<<endl;
    }
}*/
//SORT PERSONS BOOL FÖLLIN
//Fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í stafrófsröð
bool compareNameAsc(const InfoType& a, const InfoType& b);
bool compareNameAsc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//Fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í öfugri stafrófsröð
bool compareNameDesc(const InfoType& a, const InfoType& b);
bool compareNameDesc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
//Fall sem ber saman M og F og skilar M til að sorta lista eftir kyni þar sem M kemur fyrst fyrir í lista
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b);
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender > b.gender;
}
//Fall sem ber saman M og F og skilar F til að sorta lista eftir kyni þar sem F kemur fyrst fyrir í lista
bool compareGenderFemaleFirst(const InfoType& a, const InfoType& b);
bool compareGenderFemaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender < b.gender;
}
//Fall sem ber saman fæðingarár og skilar elst fyrst
bool compareYearAsc(const InfoType& a, const InfoType& b);
bool compareYearAsc(const InfoType& a, const InfoType& b)
{
    return a.birthYear < b.birthYear;
}
//Fall sem ber saman fæðingarár og skilar yngst fyrst
bool compareYearDesc(const InfoType& a, const InfoType& b);
bool compareYearDesc(const InfoType& a, const InfoType& b)
{
    return a.birthYear > b.birthYear;
}
//Fall sem ber saman dánarár og skilar elst fyrst
bool compareDeathYearAsc(const InfoType& a, const InfoType& b);
bool compareDeathYearAsc(const InfoType& a, const InfoType& b)
{
    int year1 = a.deathYear;
    int year2 = b.deathYear;

    if(year1 == 0)
    {
        year1 = alive;
    }
    else if(year2 == 0)
    {
        year2 = alive;
    }
    return year1 > year2;
}
//Fall sem ber saman dánarár og skilar yngst fyrst
bool compareDeathYearDesc(const InfoType& a, const InfoType& b);
bool compareDeathYearDesc(const InfoType& a, const InfoType& b)
{
    int year1 = a.deathYear;
    int year2 = b.deathYear;

    if(year1 == 0)
    {
        year1 = alive;
    }
    else if(year2 == 0)
    {
        year2 = alive;
    }
    return year1 < year2;
}
//SORT PERSONS FÖLLIN
//Fall sem birtir lista sem er sortaður eftir nöfnum í stafrófsröð
vector <InfoType> Services::sortByNameAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir nöfnum í öfugri stafrófsröð
vector <InfoType> Services::sortByNameDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameDesc);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir kyni, Males
vector <InfoType> Services::sortByGenderMale()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderMaleFirst);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir kyni, Females
vector <InfoType> Services::sortByGenderFemale()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir kyni, undecided
vector <InfoType> Services::sortByGenderUndecided()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir fæðingarári elst til yngst
vector <InfoType> Services::sortByYearAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearAsc);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir fæðingarár yngst til elst
vector <InfoType> Services::sortByYearDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearDesc);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir dánarári yngst til elst
vector <InfoType> Services::sortByDeathYearAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearDesc);
    return FP;
}
//Fall sem birtir lista sem er sortaður eftir dánarári elst til yngst
vector <InfoType> Services::sortByDeathYearDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);
    return FP;
}
vector <InfoType> Services::sortByDeceased()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);
    return FP;
}
vector <InfoType> Services::sortByNotDeceased()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);
    return FP;
}
//SORT COMPUTER BOOL FÖLLIN
bool compareCompNameAsc(const CompType& a, const CompType& b);
bool compareCompNameAsc(const CompType& a, const CompType& b)
{
    string str1 = a.compName;
    str1[0] = tolower(str1[0]);

    string str2 = b.compName;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//Fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í öfugri stafrófsröð
bool compareCompNameDesc(const CompType& a, const CompType& b);
bool compareCompNameDesc(const CompType& a, const CompType& b)
{
    string str1 = a.compName;
    str1[0] = tolower(str1[0]);

    string str2 = b.compName;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
bool compareComputerYearMadeAsc(const CompType& a, const CompType& b);
bool compareComputerYearMadeAsc(const CompType& a, const CompType& b)
{
    return a.yearMade < b.yearMade;
}
bool compareComputerYearMadeDesc(const CompType& a, const CompType& b);
bool compareComputerYearMadeDesc(const CompType& a, const CompType& b)
{
    return a.yearMade > b.yearMade;
}
bool compareCompTypeAsc(const CompType& a, const CompType& b);
bool compareCompTypeAsc(const CompType& a, const CompType& b)
{
    string str1 = a.type;
    str1[0] = tolower(str1[0]);

    string str2 = b.type;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//Fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í öfugri stafrófsröð
bool compareCompTypeDesc(const CompType& a, const CompType& b);
bool compareCompTypeDesc(const CompType& a, const CompType& b)
{
    string str1 = a.type;
    str1[0] = tolower(str1[0]);

    string str2 = b.type;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
bool compareComputerYearBuiltAsc(const CompType& a, const CompType& b);
bool compareComputerYearBuiltAsc(const CompType& a, const CompType& b)
{
    return a.wasBuilt < b.wasBuilt;
}
bool compareComputerYearBuiltDesc(const CompType& a, const CompType& b);
bool compareComputerYearBuiltDesc(const CompType& a, const CompType& b)
{
    return a.wasBuilt > b.wasBuilt;
}
//SORT COMPUTER FÖLLIN
vector <CompType> Services::sortByComputerNameAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    return Comp;
}
vector <CompType> Services::sortByComputerNameDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameDesc);
    return Comp;
}
vector <CompType> Services::sortByYearMadeAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearMadeAsc);
    return Comp;
}
vector <CompType> Services::sortByYearMadeDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearMadeDesc);
    return Comp;
}
vector <CompType> Services::sortByComputerTypeAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompTypeAsc);
    return Comp;
}
vector <CompType> Services::sortByComputerTypeDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompTypeDesc);
    return Comp;
}
vector <CompType> Services::sortByYearBuiltAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltAsc);
    return Comp;
}
vector <CompType> Services::sortByYearBuiltDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltDesc);
    return Comp;
}
vector <CompType> Services::sortByYearNotBuiltAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltAsc);
    return Comp;
}
vector <CompType> Services::sortByYearNotBuiltDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltDesc);
    return Comp;
}
vector <CompType> Services::sortByYearUnknownBuiltAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltAsc);
    return Comp;
}
vector <CompType> Services::sortByYearUnknownBuiltDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltDesc);

    return Comp;
}
//SEARCH PERSONS FÖLLIN
vector<InfoType> Services::searchVectorName(string nameSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;

    int nameSize = nameSearch.size();

    for(int i = 0; i < nameSize; i++)
    {
        nameSearch[i] = tolower(nameSearch[i]);
        //setjum innsláttinn í lower case
    }

    for(unsigned int i = 0; i < FP.size(); i++)
    {
        string tempName = FP[i].name;
        nameSize = tempName.size();

        for(int j = 0; j < nameSize; j++)
        {
            tempName[j] = tolower(tempName[j]);
            //setjum nafnið í skjalinu í lower case og berum svo saman
        }
        int found = tempName.find(nameSearch);//athugum hvort innslátturuinn sé hluti af einhverju nafni
        if(found != (int) std::string::npos)
        {
            result.push_back(FP[i]);
        }
    }
    return result;
}
vector<InfoType> Services::searchVectorGender(string genderSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;
    string tempGender;

    for(int i = 0; i <1; i++)//setjum innsláttinn í lágstafi
    {
        genderSearch[i] = tolower(genderSearch[i]);
    }
    for(unsigned int i = 0; i < FP.size(); i++)
    {
        tempGender = FP[i].gender;
        for(int j = 0; j <1; j++)//færum gender í möppunni yfir í temp breytu og færum í lágstafi
        tempGender[j] = tolower(tempGender[j]);

        if(genderSearch == tempGender)
        {
            result.push_back(FP[i]);
        }
    }
    //pusha inn gervimanneskjunni ef engin manneskja fannst af þessu kyni;
    FP.clear();
    return result;
}
vector<InfoType> Services::searchVectorBirthYear(string birthYearSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;
        //athugum hvort innslátturinn sé af réttri stærð og hvort allir liðir innsláttarins séu tölur
        if(birthYearSearch.size()== 4 && isdigit(birthYearSearch[0])&& isdigit(birthYearSearch[1])&& isdigit(birthYearSearch[2])&& isdigit(birthYearSearch[3]))
        {
            int birthYearSearchI = atoi(birthYearSearch.c_str());//færum string innsláttinn í int til að geta borið saman við skjalið
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(birthYearSearchI == FP[i].birthYear)
                {
                    result.push_back(FP[i]);
                }
            }
        }
        return result;
}
vector<InfoType> Services::searchVectorDeathYear(string deathYearSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;
    //athugum hvort innslátturinn sé af réttri stærð og hvort allir liðir innsláttarins séu tölur
    if(deathYearSearch.size() == 4 && isdigit(deathYearSearch[0]) && isdigit(deathYearSearch[1]) && isdigit(deathYearSearch[2]) && isdigit(deathYearSearch[3]))
    {
        int deathYearSearchI = atoi(deathYearSearch.c_str());//færum string innsláttinn í int til að geta borið saman við skjalið
        for(unsigned int i = 0; i < FP.size(); i++)
        {
            if(deathYearSearchI == FP[i].deathYear)
            {
                result.push_back(FP[i]);
            }
        }
    }
    return result;
}
//SEARCH COMPUTERS FÖLLIN
vector<CompType> Services::searchVectorComputersName(string nameSearch)
{
    vector<CompType> x = makeComputerVector();
    vector<CompType> result;
    int nameSize = nameSearch.size();

    for(int i = 0; i < nameSize; i++)
    {
        nameSearch[i] = tolower(nameSearch[i]);
        //setjum innsláttinn í lower case
    }
    return result;
}
//ANNAÐ
string Services::changeName(InfoType p)
{
    string tempName = p.name;
    int NameLength = tempName.size();
        for (int i = 0; i < NameLength; i++)
        {
            if(tempName[i] == ' ')
            {
                tempName[i+1] = toupper(tempName[i+1]);
                i++;
            }
            else if(i ==0)
            {
                tempName[i] = toupper(tempName[i]);
            }
            else
            {
                tempName[i] = tolower(tempName[i]);
            }
        }
    return tempName;
}
