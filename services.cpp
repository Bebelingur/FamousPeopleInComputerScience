#include "services.h"

using namespace std;

//fasti sem gefur fólki gildi að það sé ennþá lifandi, nauðsynlegt fyrir sort föll
const int yearNow = 2015;
const int alive = (yearNow + 1);

Services::Services()
{
}

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

void Services::viewPersonsInfo()//displayar manneskjur, þurfum að annað sem birtir tölvur
{
    vector <InfoType> x = makePersonsVector();
    //UI c;

    for(unsigned int i = 0; i < x.size(); i++)
    {
        InfoType b;
        b.name = x.at(i).name;
        b.gender = x.at(i).gender;
        b.birthYear = x.at(i).birthYear;
        b.deathYear = x.at(i).deathYear;
        //c.displayPerson(b);
    }
}

void Services::returnToView()
{
    char input;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            UI p;
            p.viewInfoMenu();
        }
}

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

void Services::searchVectorName()
{
    UI c;
    vector <InfoType> FP = makePersonsVector();
    string nameSearch;
    cout << "Enter name: ";
    cin >> nameSearch;
    int nameSize = nameSearch.size();
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni

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
            c.displayPerson(FP[i]);
            check = true;

        }
    }

    if(check == false)
    {
        cout << "-------------------------------------------" << endl;
        cout << "   "<<nameSearch << " was not in database or input not in the right format" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "--- Please try again. ---" << endl;
        cout << endl;
    }
    FP.clear();
    backToSearchMenu();
}
void Services::searchVectorGender()
{
    UI c;
    vector <InfoType> FP = makePersonsVector();
    string genderSearch;
        bool check = false; //check til að athuga hvort það sé búið að finna í leitinni

        cout << "Enter gender (M for male, F for female or ? for undecided): ";
        cin >> genderSearch;
        string tempGender;
        if(genderSearch.size() == 1)
        {   for(int i = 0; i <1; i++)//setjum innsláttinn í lágstafi
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
                    c.displayPerson(FP[i]);
                    check = true;

                }
            }
        }

        if(check == false || genderSearch.size() != 1)
        {
            cout << "-------------------------------------------" << endl;
            cout << "Gender " << genderSearch << " was not in file or input not in the right format" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
        backToSearchMenu();
        FP.clear();
}

void Services::searchVectorBirthYear()
{
    UI c;
    vector <InfoType> FP = makePersonsVector();
    string birthYearSearch;
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni

    cout << "Enter year of birth: ";
        cin >> birthYearSearch;
        //athugum hvort innslátturinn sé af réttri stærð og hvort allir liðir innsláttarins séu tölur
        if(birthYearSearch.size()== 4 && isdigit(birthYearSearch[0])&& isdigit(birthYearSearch[1])&& isdigit(birthYearSearch[2])&& isdigit(birthYearSearch[3]))
        {
            int birthYearSearchI = atoi(birthYearSearch.c_str());//færum string innsláttinn í int til að geta borið saman við skjalið
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(birthYearSearchI == FP[i].birthYear)
                {
                    c.displayPerson(FP[i]);
                    check = true;
                }
            }
        }

        if(check == false)
        {
            cout << "-------------------------------------------" << endl;
            cout << "Birth year " << birthYearSearch << " is not in database or input not in the right format" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
        FP.clear();
        backToSearchMenu();
}
void Services::searchVectorDeathYear()
{
    UI c;
    vector <InfoType> FP = makePersonsVector();
    string deathYearSearch;
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni


        cout << "Enter death year: ";
        cin >> deathYearSearch;
        //athugum hvort innslátturinn sé af réttri stærð og hvort allir liðir innsláttarins séu tölur
        if(deathYearSearch.size() == 4 && isdigit(deathYearSearch[0]) && isdigit(deathYearSearch[1]) && isdigit(deathYearSearch[2]) && isdigit(deathYearSearch[3]))
        {
            int deathYearSearchI = atoi(deathYearSearch.c_str());//færum string innsláttinn í int til að geta borið saman við skjalið
            for(unsigned int i = 0; i < FP.size(); i++)
            {
                if(deathYearSearchI == FP[i].deathYear)
                {
                    c.displayPerson(FP[i]);
                    check = true;

                }
            }
        }

        if(check == false)
        {
            cout << "-------------------------------------------"<<endl;
            cout << "Death year "<<  deathYearSearch << " is not in database or input not in the right format" << endl;
            cout << "-------------------------------------------"<<endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
        FP.clear();
        backToSearchMenu();
}

void Services::searchVector()
{
    UI user;
    user.searchMenu();
}
void Services::backToSearchMenu()
{
    UI user;
    char input;
    cout << "--- Press any key and then enter to return to search menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.searchMenu();
        }
}

//þetta fall á að taka upplýsingar úr gagnagrunninum og birta þær
void Services::viewComputerInfo()
{
    UI p;
    vector <CompType> x = connection.loadCompData();

        cout << "* * * VIEW INFORMATION * * *" << endl;

        for(unsigned int i = 0; i < x.size(); i++)
        {
            CompType c;
            c.compName = x.at(i).compName;
            c.yearMade = x.at(i).yearMade;
            c.type = x.at(i).type;
            c.wasBuilt = x.at(i).wasBuilt;
            p.displayComputer(c);
        }

    char input;
    cout << "--- Press any key and then enter to return to main menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            p.viewInfoMenu();
        }
}

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

void Services::searchVectorComputersName()
{
    vector <CompType> x = makeComputerVector();
    UI p;
    string nameSearch;
    cout << "Enter name: ";
    cin >> nameSearch;
    int nameSize = nameSearch.size();
    bool check = false; //check til að athuga hvort það sé búið að finna í leitinni


    for(int i = 0; i < nameSize; i++)
    {
        nameSearch[i] = tolower(nameSearch[i]);
        //setjum innsláttinn í lower case
    }

    for(int i = 0; i < (int) x.size(); i++)
    {
        string tempName = x[i].compName;
        nameSize = tempName.size();

        for(int j = 0; j < nameSize; j++)
        {
            tempName[j] = tolower(tempName[j]);
            //setjum nafnið í skjalinu í lower case og berum svo saman
        }

        int found = tempName.find(nameSearch);//athugum hvort innslátturuinn sé hluti af einhverju nafni
        if(found != (int) std::string::npos)
        {
            p.displayComputer(x[i]);
            check = true;
            backToSearchMenu();
        }
    }
    if(check == false)
    {
        cout << "-------------------------------------------" << endl;
        cout << "   " << nameSearch << " was not in file or input not in the right format" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "--- Please try again. ---" << endl;
        cout << endl;
    }

}


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
