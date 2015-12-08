#include "services.h"
#include "ui.h"
#include "data.h"

using namespace std;

//er bæði í ui og services væri til í að hafa það bara á einum stað
//function that finds the time
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
//ADD FUNCTIONS
//takes info from user input regarding persons and sends down to data
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

//takes info/(variables) from user input regarding computers and sends down to data
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

//takes info/(variables) from user input regarding relation and sends down to data
void Services::addRelation(int personId, int computerId)
{
    RelationsType p;
    p.personId = personId;
    p.computerId = computerId;

    data relationsToData;
    relationsToData.saveDataRelations(p);
}
//MAKE FUNCTIONS
//loads a vector of person information from data and returns it
vector<InfoType> Services::makePersonsVector()
{
   vector<InfoType> p = connection.loadPersData();
   return p;
}

//loads a vector of computer information from data and returns it
vector<CompType> Services::makeComputerVector()
{
   vector<CompType> c = connection.loadCompData();
   return c;
}
//function that makes relation between person and computer
void Services::makeRelation()
{
      string compName = "", name = "", compNameCompare = "", nameCompare = "";
      int compID = 0, persID = 0;
      //bool compCheck = false;
      QSqlDatabase db = QSqlDatabase::database("first");
      QSqlQuery query(db);
      do{
          cout << "Enter name of computer: ";
          //VILLA HÉRNA skrifar út cout endalaust
          getline(cin, compName);
          QString qName = QString::fromUtf8(compName.c_str());
          query.exec("SELECT compName, id FROM computers WHERE compName LIKE '%" + qName + "%'");
          while(query.next())
          {
              CompType c;
              c.id = query.value("id").toUInt();
              c.compName = query.value("compName").toString().toStdString();
              compNameCompare = c.compName;

              if(compNameCompare == compName)
              {
                  compID = c.id;
              }
              else
              cout<< "did you mean: "<< c.compName << endl;
          }

      }while(compID == 0);

      do{
          cout << "Enter person: ";
          getline(cin, name);
          QString qName = QString::fromUtf8(name.c_str());
          query.exec("SELECT name, id FROM persons WHERE name LIKE '%" + qName + "%'");
          while(query.next())
          {
              InfoType p;
              p.name = query.value("name").toString().toStdString();
              p.id = query.value("id").toUInt();
              nameCompare = p.name;

              if(nameCompare == name)
              {
                  persID = p.id;
              }
              else
              cout<< "did you mean: "<< p.name << endl;
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
                cout << endl;
                cout << "| | | Relation is already in database | | |" << endl;
                cout << endl;
                check = true;
          }
      }
      if(check == false)
      {
          cout << endl;
          cout << "| | | Relation between " << compName <<" and " << name << " has been added | | |" << endl;
          cout << endl;
          addRelation(persID, compID);
      }
}
//VIEW FUNCTIONS
//loads a vector of person information from services and returns it(er þetta ekki eiginlega sama fall og makepersonVector?)
vector<InfoType> Services::viewPersonsInfo()
{
    vector <InfoType> FP = makePersonsVector();
    return FP;

}
//loads a vector of computer information from services and returns it(er þetta ekki eiginlega sama fall og makecomputerVector?)
vector<CompType> Services::viewComputerInfo()
{
    vector <CompType> Comp = makeComputerVector();
    return Comp;
}

int Services::findIDPerson(string name)
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

int Services::findIDComputer(string name)
{
    int ID = 0;
    QSqlDatabase db = QSqlDatabase::database("first");
    QSqlQuery query(db);
    do
    {
            QString qName = QString::fromUtf8(name.c_str());
            query.exec("SELECT compName, id FROM computers WHERE compName LIKE '"+qName+"'");
            while(query.next())
            {
                CompType c;
                c.id = query.value("id").toUInt();
                ID = c.id;
            }
        }while(name == "");
    return ID;
}

//function that finds relations between person and computers
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

//function that finds relations between computer and persons
vector<InfoType> Services::viewRelationComputer(int ID)
{
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
//SORT PERSONS BOOL FUNCTIONS
//function that compares the first character of each string, used to sort in alphabetical order
bool compareNameAsc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//function that compares the first character of each string, used to sort in reverse alphabetical order
bool compareNameDesc(const InfoType& a, const InfoType& b)
{
    string str1 = a.name;
    str1[0] = tolower(str1[0]);

    string str2 = b.name;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}

//function that compares M and F and returns M(true) to sort list by gender, where M is first in list
bool compareGenderMaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender > b.gender;
}

//function that compares M and F and returns F(true) to sort list by gender, where F is first in list
bool compareGenderFemaleFirst(const InfoType& a, const InfoType& b)
{
    return a.gender < b.gender;
}

//function that compares birthYear and returns the older
bool compareYearAsc(const InfoType& a, const InfoType& b)
{
    return a.birthYear < b.birthYear;
}

//function that compares birthYear and returns the younger
bool compareYearDesc(const InfoType& a, const InfoType& b)
{
    return a.birthYear > b.birthYear;
}

//function that compares deathYear and returns the older
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
    return year1 < year2;
}
//function that compares birthYear and returns the younger
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
    return year1 > year2;
}
//SORT PERSONS FUNCTIONS
//function that returns the sorted vector in alphabetical order
vector <InfoType> Services::sortByNameAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    return FP;
}
//function that returns the sorted vector in reverse alphabetical order
vector <InfoType> Services::sortByNameDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameDesc);
    return FP;
}

//function that returns the sorted vector by gender, males first
vector <InfoType> Services::sortByGenderMale()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderMaleFirst);
    return FP;
}
//function that returns the sorted vector by gender, females first
vector <InfoType> Services::sortByGenderFemale()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);
    return FP;
}
//function that returns the sorted vector by gender, undecided first
vector <InfoType> Services::sortByGenderUndecided()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);
    return FP;
}

//function that returns the sorted vector by birthYear in ascending order
vector <InfoType> Services::sortByYearAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearAsc);
    return FP;
}
//function that returns the sorted vector by birthYear in descending order
vector <InfoType> Services::sortByYearDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearDesc);
    return FP;
}

//function that returns the sorted vector by deathYear in ascending order
vector <InfoType> Services::sortByDeathYearAsc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);
    return FP;
}
//function that returns the sorted vector by deathYear in descending order
vector <InfoType> Services::sortByDeathYearDesc()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearDesc);
    return FP;
}
//function that returns the sorted vector by deathYear in ascending order, used in special case
vector <InfoType> Services::sortByDeceased()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);
    return FP;
}
//function that returns the sorted vector by deathYear in ascending order, used in special case
vector <InfoType> Services::sortByNotDeceased()
{
    vector <InfoType> FP = makePersonsVector();
    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);
    return FP;
}
//SORT COMPUTER BOOL FUNCTIONS
//function that compares the first character of each string, used to sort computers in alphabetical order
bool compareCompNameAsc(const CompType& a, const CompType& b)
{
    string str1 = a.compName;
    str1[0] = tolower(str1[0]);

    string str2 = b.compName;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//function that compares the first character of each string, used to sort computers in reverse alphabetical order
bool compareCompNameDesc(const CompType& a, const CompType& b)
{
    string str1 = a.compName;
    str1[0] = tolower(str1[0]);

    string str2 = b.compName;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
//function that compares yearMade and returns the older
bool compareComputerYearMadeAsc(const CompType& a, const CompType& b)
{
    return a.yearMade < b.yearMade;
}
//function that compares yearMade and returns the younger
bool compareComputerYearMadeDesc(const CompType& a, const CompType& b)
{
    return a.yearMade > b.yearMade;
}
//function that compares the first character of each string, used to sort computers by type in alphabetical order
bool compareCompTypeAsc(const CompType& a, const CompType& b)
{
    string str1 = a.type;
    str1[0] = tolower(str1[0]);

    string str2 = b.type;
    str2[0] = tolower(str2[0]);

    return str1 < str2;
}
//function that compares the first character of each string, used to sort computers by type in reverse alphabetical order
bool compareCompTypeDesc(const CompType& a, const CompType& b)
{
    string str1 = a.type;
    str1[0] = tolower(str1[0]);

    string str2 = b.type;
    str2[0] = tolower(str2[0]);

    return str1 > str2;
}
//function that compares wasBuilt and returns the older
bool compareComputerYearBuiltAsc(const CompType& a, const CompType& b)
{
    return a.wasBuilt < b.wasBuilt;
}
//function that compares wasBuilt and returns the younger
bool compareComputerYearBuiltDesc(const CompType& a, const CompType& b)
{
    return a.wasBuilt > b.wasBuilt;
}
//SORT COMPUTER FUNCTIONS
//function that returns the sorted vector in alphabetical order
vector <CompType> Services::sortByComputerNameAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    return Comp;
}
//function that returns the sorted vector in reverse alphabetical order
vector <CompType> Services::sortByComputerNameDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameDesc);
    return Comp;
}
//function that returns the sorted vector by yearMade in ascending order
vector <CompType> Services::sortByYearMadeAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearMadeAsc);
    return Comp;
}
//function that returns the sorted vector by yearMade in descending order
vector <CompType> Services::sortByYearMadeDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearMadeDesc);
    return Comp;
}
//function that returns the sorted vector by type in ascending order
vector <CompType> Services::sortByComputerTypeAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompTypeAsc);
    return Comp;
}
//function that returns the sorted vector by type in descending order
vector <CompType> Services::sortByComputerTypeDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompTypeDesc);
    return Comp;
}
//function that returns the sorted vector by yearBuilt in ascending order
vector <CompType> Services::sortByYearBuiltAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltAsc);
    return Comp;
}
//function that returns the sorted vector by yearBuilt in descending order
vector <CompType> Services::sortByYearBuiltDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltDesc);
    return Comp;
}
//function that returns the sorted vector by yearBuilt in ascending order, used in special case
vector <CompType> Services::sortByYearNotBuiltAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltAsc);
    return Comp;
}
//function that returns the sorted vector by yearBuilt in descending order, used in special case
vector <CompType> Services::sortByYearNotBuiltDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltDesc);
    return Comp;
}
//function that returns the sorted vector by yearBuilt in ascending order, used in special case
vector <CompType> Services::sortByYearUnknownBuiltAsc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltAsc);
    return Comp;
}
//function that returns the sorted vector by yearBuilt in descending order, used in special case
vector <CompType> Services::sortByYearUnknownBuiltDesc()
{
    vector <CompType> Comp = makeComputerVector();
    sort(Comp.begin(), Comp.end(), compareCompNameAsc);
    sort(Comp.begin(), Comp.end(), compareComputerYearBuiltDesc);
    return Comp;
}
//SEARCH PERSONS FUNCTIONS
//function that searches for name/part of name, set results from search to vector and returns the vector
vector<InfoType> Services::searchVectorName(string nameSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;

    int nameSize = nameSearch.size();

    for(int i = 0; i < nameSize; i++)
    {
        //set the input to lower case
        nameSearch[i] = tolower(nameSearch[i]);
    }
    for(unsigned int i = 0; i < FP.size(); i++)
    {
        string tempName = FP[i].name;
        nameSize = tempName.size();

        for(int j = 0; j < nameSize; j++)
        {
            //set name in database to lower case and then compare
            tempName[j] = tolower(tempName[j]);
        }
        int found = tempName.find(nameSearch);//check if input is part of name
        if(found != (int) string::npos)
        {
            result.push_back(FP[i]);
        }
    }
    return result;
}
//function that searches for gender, set results from search to vector and returns the vector
vector<InfoType> Services::searchVectorGender(string genderSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;
    string tempGender;

    for(int i = 0; i <1; i++)//set input to lower case
    {
        genderSearch[i] = tolower(genderSearch[i]);
    }
    for(unsigned int i = 0; i < FP.size(); i++)
    {
        tempGender = FP[i].gender;
        for(int j = 0; j <1; j++)//set info from database to lower case
        tempGender[j] = tolower(tempGender[j]);

        if(genderSearch == tempGender)
        {
            result.push_back(FP[i]);
        }
    }
    FP.clear();
    return result;
}
//function that searches for birthYear, set results from search to vector and returns the vector
vector<InfoType> Services::searchVectorBirthYear(string birthYearSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;
        //check if input is of correct length and check if it only contains numbers
        if(birthYearSearch.size()== 4 && isdigit(birthYearSearch[0])&& isdigit(birthYearSearch[1])&& isdigit(birthYearSearch[2])&& isdigit(birthYearSearch[3]))
        {
            int birthYearSearchI = atoi(birthYearSearch.c_str());//set string to int to be able to compare
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
//function that searches for deathYear, set results from search to vector and returns the vector
vector<InfoType> Services::searchVectorDeathYear(string deathYearSearch)
{
    vector <InfoType> FP = makePersonsVector();
    vector <InfoType> result;
    //check if input is of correct length and check if it only contains numbers
    if(deathYearSearch.size() == 4 && isdigit(deathYearSearch[0]) && isdigit(deathYearSearch[1]) && isdigit(deathYearSearch[2]) && isdigit(deathYearSearch[3]))
    {
        int deathYearSearchI = atoi(deathYearSearch.c_str());//set string to int to be able to compare
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

//SEARCH COMPUTERS FUNCTIONS
//function that searches for computer name, set results from search to vector and returns the vector
vector<CompType> Services::searchVectorComputersName(string name)
{
    vector<CompType> Comp = makeComputerVector();
        vector<CompType> result;

        for(unsigned int i = 0; i < name.size() ; i++)
        {
            name[i] = tolower(name[i]);
            //setjum innsláttinn í lower case
        }
        for(unsigned int i = 0; i < Comp.size(); i++)
        {
           string tempName = Comp[i].compName;

           for(unsigned int j = 0; j < tempName.size() ; j++)
           {
               tempName[j] = tolower(tempName[j]);
               //setjum nafnið í skjalinu í lower case og berum svo saman
           }

           int found = tempName.find(name);//athugum hvort innslátturuinn sé hluti af einhverju nafni
           if(found != (int) std::string::npos)
           {
               result.push_back(Comp[i]);
           }
        }
        Comp.clear();
        return result;
}
//OTHER
//changes name uppercase/lowercase
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
