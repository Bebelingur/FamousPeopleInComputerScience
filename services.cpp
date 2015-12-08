#include "services.h"
#include "ui.h"
#include "data.h"

using namespace std;

//er bæði í ui og services væri til í að hafa það bara á einum stað
int exactYearNow2()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int exactYearNow = 1900 + ltm->tm_year;
    return exactYearNow;
}
const int yearNow = exactYearNow2();
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
      string compName = "", name = "";
      int compID = 0, persID = 0;

      QSqlDatabase db = QSqlDatabase::database("first");
      QSqlQuery query(db);
      do{
          cout << "Enter name of computer: ";
          //VILLA HÉRNA skrifar út cout endalaust
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
vector<InfoType> Services::viewPersonsInfo()
{
    vector <InfoType> FP = makePersonsVector();
    return FP;

}
vector<CompType> Services::viewComputerInfo()
{
    vector <CompType> Comp = makeComputerVector();
    return Comp;
}

int Services::findID(string name)
{
    int ID = 0;
    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    do
    {
            QString qName = QString::fromUtf8(name.c_str());
            query.exec("SELECT name, id FROM persons WHERE name LIKE '"+qName+"'");
            while(query.next())
            {
                InfoType p;
                p.id = query.value("id").toUInt();
                ID = p.id;
            }
        }while(name == "");
    return ID;
}


vector<CompType> Services::viewRelationPerson(int ID)
{
    vector<CompType> computers;

    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    query.exec("SELECT computers.* FROM computers INNER JOIN relations ON persons.id = relations.idPerson INNER JOIN persons ON computers.id = relations.idComputer WHERE idPerson = "+QString::number(ID)+"");
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
void Services::viewRelationComputer(int ID)
{
<<<<<<< HEAD
=======
    UI a;

    string name = "";
    int ID = 0;

>>>>>>> 0463941aed07e11f8653481c97e4ef475b35c37f
    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);

    vector<InfoType> people;
    query.exec("SELECT persons.* FROM persons INNER JOIN relations ON persons.id = relations.idPerson INNER JOIN computers ON computers.id = relations.idComputer WHERE idComputer ='"+QString::number(ID)+"'");
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
//SORT PERSONS BOOL FÖLLIN
//fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í stafrófsröð
bool compareNameAsc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í öfugri stafrófsröð
bool compareNameDesc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
//fall sem ber saman M og F og skilar M til að sorta lista eftir kyni þar sem M kemur fyrst fyrir í lista
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender > b.gender;
}
//fall sem ber saman M og F og skilar F til að sorta lista eftir kyni þar sem F kemur fyrst fyrir í lista
bool compareGenderFemaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender < b.gender;
}
//fall sem ber saman fæðingarár og skilar elst fyrst
bool compareYearAsc(const InfoType& a, const InfoType& b)
{
    return a.birthYear < b.birthYear;
}
//fall sem ber saman fæðingarár og skilar yngst fyrst
bool compareYearDesc(const InfoType& a, const InfoType& b);
bool compareYearDesc(const InfoType& a, const InfoType& b)
{
    return a.birthYear > b.birthYear;
}
//fall sem ber saman dánarár og skilar elst fyrst
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
//fall sem ber saman dánarár og skilar yngst fyrst
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
//fall sem birtir lista sem er sortaður eftir nöfnum í stafrófsröð
vector <InfoType> Services::sortByNameAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    return FP;
}
//fall sem birtir lista sem er sortaður eftir nöfnum í öfugri stafrófsröð
vector <InfoType> Services::sortByNameDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameDesc);
    return FP;
}
//fall sem birtir lista sem er sortaður eftir kyni, Males
vector <InfoType> Services::sortByGenderMale()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderMaleFirst);
    return FP;
}
//fall sem birtir lista sem er sortaður eftir kyni, Females
vector <InfoType> Services::sortByGenderFemale()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);
    return FP;
}
//fall sem birtir lista sem er sortaður eftir kyni, undecided
vector <InfoType> Services::sortByGenderUndecided()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);
    return FP;
}
//fall sem birtir lista sem er sortaður eftir fæðingarári elst til yngst
vector <InfoType> Services::sortByYearAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearAsc);
    return FP;
}
//fall sem birtir lista sem er sortaður eftir fæðingarár yngst til elst
vector <InfoType> Services::sortByYearDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearDesc);
    return FP;
}

//fall sem birtir lista sem er sortaður eftir dánarári yngst til elst
vector <InfoType> Services::sortByDeathYearAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearDesc);
    return FP;
}
//fall sem birtir lista sem er sortaður eftir dánarári elst til yngst
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
bool compareCompNameAsc(const CompType& a, const CompType& b)
{
    string str1 = a.compName;
    str1[0] = tolower(str1[0]);

    string str2 = b.compName;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//Fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í öfugri stafrófsröð
bool compareCompNameDesc(const CompType& a, const CompType& b)
{
    string str1 = a.compName;
    str1[0] = tolower(str1[0]);

    string str2 = b.compName;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
bool compareComputerYearMadeAsc(const CompType& a, const CompType& b)
{
    return a.yearMade < b.yearMade;
}
bool compareComputerYearMadeDesc(const CompType& a, const CompType& b)
{
    return a.yearMade > b.yearMade;
}
bool compareCompTypeAsc(const CompType& a, const CompType& b)
{
    string str1 = a.type;
    str1[0] = tolower(str1[0]);

    string str2 = b.type;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//fall sem ber saman fyrsta staf í hverjum streng, notað til að sorta föll í öfugri stafrófsröð
bool compareCompTypeDesc(const CompType& a, const CompType& b)
{
    string str1 = a.type;
    str1[0] = tolower(str1[0]);

    string str2 = b.type;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
bool compareComputerYearBuiltAsc(const CompType& a, const CompType& b)
{
    return a.wasBuilt < b.wasBuilt;
}
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
        if(found != (int) string::npos)
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
        FP.clear();
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
    FP.clear();
    return result;
}

vector<CompType> Services::searchVectorComputersName(string nameSearch)
{
    vector<CompType> Comp = makeComputerVector();
    vector<CompType> result;
    int nameSize = name.size();

    for(int i = 0; i < nameSize; i++)
    {
        name[i] = tolower(name[i]);
        //setjum innsláttinn í lower case
    }
    for(unsigned int i = 0; i < Comp.size(); i++)
    {
       string tempName = Comp[i].compName;
       nameSize = tempName.size();

       for(int j = 0; j < nameSize; j++)
       {
           tempName[j] = tolower(tempName[j]);
           //setjum nafnið í skjalinu í lower case og berum svo saman
       }

       int found = tempName.find(nameSearch);//athugum hvort innslátturuinn sé hluti af einhverju nafni
       if(found != (int) std::string::npos)
       {
           result.push_back(Comp[i]);
       }
    }
    Comp.clear();
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

char Services::convertToChar(string a)//fall sem tekur string úr databaseinu og skilar char inní vectorinn
{
    char result;
    result = a.at(0);
    return result;
}
string Services::convertToString(char a)
{
    string result;
    result = a;
    return result;
}
