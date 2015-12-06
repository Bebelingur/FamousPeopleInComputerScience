#include "services.h"

using namespace std;

const int yearNow = 2015;
const int alive = (yearNow + 1);
//Fasti sem gefur fólki gildi að það sé ennþá lifandi, nauðsynlegt fyrir sort föll

Services::Services()
{}

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

void Services::addComputer(string compName, int yearMade, string type, char wasBuilt)
{
    CompType p;
    p.compName = compName;
    p.yearMade = yearMade;
    p.type = type;
    p.wasBuilt = wasBuilt;

    data computersToData;
    computersToData.saveDataComputers(p);
}

void Services::fillVector()//loaddata fallið skilar vektor úr databaseinu, þorði ekki að eyða samt - SDS
{
    //breyta file fyrir sql og fylla þaðan í vektor
    ifstream getFile;
    getFile.open("InfoFile.txt");

        if(getFile.fail())
        {
            cout << "Could not open file." << endl;
        }
        else{
            while(!getFile.eof())
            {
                InfoType p;
                getline(getFile, p.name, '*');
                getFile >> p.gender;
                getFile >> p.birthYear;
                getFile >> p.deathYear;
                FP.push_back(p);
            }
            getFile.close();
        }
}
void Services::viewInfo()//displayar manneskjur, þurfum að annað sem birtir tölvur
{
    UI p;
    vector <InfoType> x = connection.loadPersData();

    /*geymi villumeldingu ef við viljum nota lookið

        {
            cout << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| | | Could not open file. No data to display. | | |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << endl;
            p.userMenu();
         }*/

        cout << "* * * VIEW INFORMATION * * *" << endl;

        for(unsigned int i = 0; i < x.size(); i++)
        {
            InfoType b;
            b.name = x.at(i).name;
            b.gender = x.at(i).gender;
            b.birthYear = x.at(i).birthYear;
            b.deathYear = x.at(i).deathYear;
            displayPerson(b);
        }

    char input;
    cout << "--- Press any key and then enter to return to main menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            p.userMenu();
        }
}

void Services::displayPerson(InfoType p)
{
    cout << endl;
    string tempName = changeName(p);

    cout << "Name: " << tempName << endl;
    cout << "Gender: ";
        if(toupper(p.gender) == 'F')
        {
            cout << "Female" << endl;
        }
        else if (toupper(p.gender) == 'M')
        {
            cout << "Male" << endl;
        }
        else if (p.gender == '?')
        {
            cout << "Undecided" << endl;
        }
    cout << "Year of birth: " << p.birthYear << endl;

        if(p.deathYear != 0)
        {
            cout << "Year of death: " << p.deathYear << endl;
        }

    cout << endl;
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

//Fall sem birtir persónur eftir að búið er að sorta lista
void Services::displaySortedPerson()
{
    for (unsigned int i = 0; i < FP.size(); i++)
    {
        displaySorted(i);
    }
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
void Services::sortByNameAsc()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying persons by name in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);

    displaySortedPerson();

    FP.clear();
    backToSortMenu();
}

//Fall sem birtir lista sem er sortaður eftir nöfnum í öfugri stafrófsröð
void Services::sortByNameDesc()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying persons by name in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameDesc);

    displaySortedPerson();

    FP.clear();
    backToSortMenu();
}

//Fall sem birtir lista sem er sortaður eftir kyni, Males
void Services::sortByGenderMale()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying male persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderMaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(toupper(FP.at(i).gender) == 'M')
        {
            displaySorted(i);
        }
    }

    FP.clear();
    backToSortMenu();
}

//Fall sem birtir lista sem er sortaður eftir kyni, Females
void Services::sortByGenderFemale()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying female persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(toupper(FP.at(i).gender) == 'F')
        {
            displaySorted(i);
        }
    }

    FP.clear();
    backToSortMenu();
}

//Fall sem birtir lista sem er sortaður eftir kyni, undecided
void Services::sortByGenderUndecided()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying persons of undecided gender ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareGenderFemaleFirst);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).gender != '?')
        {
            cout << "------------------------------------------------------------" << endl;
            cout << "| | | There aren't any persons of undecided gender | | |" << endl;
            cout << "------------------------------------------------------------" << endl;
            cout << endl;
        }
        else
        {
            for (unsigned int i = 0; i < FP.size(); i++)
            {
                if(FP.at(i).gender == '?')
                {
                    displaySorted(i);
                }
            }
        }
        FP.clear();
        backToSortMenu();
    }
}
//Fall sem birtir lista sem er sortaður eftir fæðingarári elst til yngst
void Services::sortByYearAsc()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying persons by year of birth in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearAsc);

    displaySortedPerson();

    FP.clear();
    backToSortMenu();
}

//Fall sem birtir lista sem er sortaður eftir fæðingarár yngst til elst
void Services::sortByYearDesc()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying persons by year of birth in descending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareYearDesc);

    displaySortedPerson();

    FP.clear();


    backToSortMenu();
}

//Fall sem birtir lista sem er sortaður eftir dánarári elst til yngst
void Services::sortByDeathYearDesc()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying persons by year of death in descending order ---" << endl;
    cout << endl;


    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    displaySortedPerson();

    FP.clear();

   backToSortMenu();
}

//Fall sem birtir lista sem er sortaður eftir dánarári yngst til elst
void Services::sortByDeathYearAsc()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying persons by year of death in ascending order ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearDesc);

    displaySortedPerson();

    FP.clear();

   backToSortMenu();
}


void Services::sortByDeceased()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying deceased persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).deathYear > 0)
        {
            displaySorted(i);
        }
    }

    FP.clear();

    backToSortMenu();
}


void Services::sortByNotDeceased()
{
    fillVector();
    cout << endl;
    cout << "--- Displaying non deceased persons ---" << endl;
    cout << endl;

    sort(FP.begin(), FP.end(), compareNameAsc);
    sort(FP.begin(), FP.end(), compareDeathYearAsc);

    for (unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP.at(i).deathYear == 0)
        {
            displaySorted(i);
        }
    }

    FP.clear();
    backToSortMenu();
}
void Services::displaySorted(int i)
{
    cout << "Name: " << FP.at(i).name<< endl;

    if(toupper(FP.at(i).gender) == 'F')
    {
        cout << "Gender: " << "Female" << endl;
    }
    else if(toupper(FP.at(i).gender) == 'M')
    {
        cout << "Gender: " << "Male" << endl;
    }
    else
    {
        cout << "Gender: " << "Undecided" << endl;
    }

    cout << "Year of birth: " << FP.at(i).birthYear << endl;

    if(FP.at(i).deathYear == 0)
    {
        cout << "Not deceased!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Year of death: " << FP.at(i).deathYear << endl;
        cout << endl;
    }
}

void Services::backToSortMenu()
{
    UI user;
    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            user.sortMenu();
        }
}

void Services::searchVectorName()
{
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
            displayPerson(FP[i]);
            check = true;
            backToSearchMenu();
        }
    }
    if(check == false)
    {
        cout << "-------------------------------------------" << endl;
        cout << "   "<<nameSearch << " was not in file or input not in the right format" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "--- Please try again. ---" << endl;
        cout << endl;
    }

}
void Services::searchVectorGender()
{
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
                    displayPerson(FP[i]);
                    check = true;
                    backToSearchMenu();
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
}

void Services::searchVectorBirthYear()
{
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
                    displayPerson(FP[i]);
                    check = true;
                    backToSearchMenu();
                }
            }
        }
        if(check == false)
        {
            cout << "-------------------------------------------" << endl;
            cout << "Birth year " << birthYearSearch << " is not in file or input not in the right format" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
}
void Services::searchVectorDeathYear()
{
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
                    displayPerson(FP[i]);
                    check = true;
                    backToSearchMenu();
                }
            }
        }
        if(check == false)
        {
            cout << "-------------------------------------------"<<endl;
            cout << "Death year "<<  deathYearSearch << " is not in file or input not in the right format" << endl;
            cout << "-------------------------------------------"<<endl;
            cout << "--- Please try again. ---" << endl;
            cout << endl;
        }
}

void Services::searchVector()
{
    UI user;
    fillVector();//búum til vektorinn
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
            displayComputer(c);
        }

    char input;
    cout << "--- Press any key and then enter to return to main menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            p.userMenu();
        }
}

void Services::displayComputer(CompType c)
{
    cout << endl;

    cout << "Computer name: " << c.compName << endl;

    cout << "Year designed: " << c.yearMade << endl;

    cout << "Computer type: " << c.type << endl;

        if(c.wasBuilt != 0 && c.wasBuilt != 1)
        {
            cout << "Year built: " << c.wasBuilt << endl;
        }
        else if (c.wasBuilt == 0)
        {
            cout << "Computer has not been built." << endl;
        }
        else if (c.wasBuilt == 1)
        {
            cout << "Computer has been built but year built is unknown." << endl;
        }

    cout << endl;
}

void Services::searchVectorComputersName()
{
    vector <CompType> x = connection.loadCompData();

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
            displayComputer(x[i]);
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

