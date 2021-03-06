#include "ui.h"

using namespace std;

//function that finds the time
int exactYearNow()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int exactYearNow = 1900 + ltm->tm_year;
    return exactYearNow;
}
const int yearNow = exactYearNow();
//birth year of Charles Babbage for beginning year of computer science
const int CstartYear = 1791;

UI::UI()
{

}
//user menu function
void UI::userMenu()
{


    Services p;
    int choice;

    do{
        cout << endl;
        cout << "===========================================" << endl;
        cout << "==   Famous People In Computer Science   ==" << endl;
        cout << "===========================================" << endl;
        cout << "1. Input information" << endl;
        cout << "2. View information" << endl;
        cout << "3. Sort information" << endl;
        cout << "4. Search information" << endl;
        cout << "5. Add or view relation between person and computer" << endl;
        cout << "6. Remove Information" << endl;
        cout << "7. Exit" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice !=6 && choice !=7);

        switch(choice)
        {
            case 1:
                inputMenu();
                break;
            case 2:
                viewInfoMenu();
                break;
            case 3:
                sortMenu();
                break;
            case 4:
                searchMenu();
                break;
            case 5:
                relationMenu();
                break;
            case 6:
                removeMenu();
            case 7:
                exit(1);
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6 || choice == 7);
}
//INPUT
//input menu function
void UI::inputMenu()
{
    int choice;

    do{
        cout << "* * * INPUT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Input person" << endl;
        cout << "2. Input computer" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                getPersonInfo();
                break;
            }
            case 2:
            {
                getComputerInfo();
                break;
            }
            case 3:
            {
                userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//PERSON INFO INPUT
//function that gets person info from user
void UI::getPersonInfo()
{
    Services p;
    bool check2 = false;

    cout << "* * * INPUT INFORMATION * * *" << endl;
    cout << endl;

    do{
        string name = getName();
        char gender = getGender();
        int bYear = getBirthYear();
        int dYear = getDeathYear(name, bYear);
        bool check = duplicateCheckPersons(name, gender, bYear, dYear);
        if(check == true)
        {
            p.addPerson(name, gender, bYear, dYear);
        }
        else
        {
            cout << endl;
            cout << "| | | Duplicate error. Person already in database. | | |" << endl;
            cout << "--- ERROR! will NEVER appear when Chuck Norris is using the PC ---" << endl;
            cout << endl;
        }

        check2 = continueOption();
    }while(check2 == true);
}
//function that gets the name from the user and returns it
string UI::getName()
{
    bool check = false;
    string name = " ";

    do{
        cout << "Input name (in the order first, middle and last name): ";
        cin.clear();
        getline(cin, name);
        check = false;
        //check if input contains digits
        for(unsigned int i = 0; i < name.size(); i++)
        {
            if(isdigit(name[i]))
            {
                check = true;
            }
        }
        if(check == true)
        {
           displayError();
        }
    }while(check == true);

    return name;
}
//function that gets the gender from the user and returns it
char UI::getGender()
{
    char gender = ' ';
    do{
        cout << "Input gender (F for female/M for male /? for undecided): ";
        cin >> gender;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(toupper(gender) != 'F' && toupper(gender) != 'M' && gender != '?')
            {
               displayError();
            }
    }while(toupper(gender) != 'F' && toupper(gender) != 'M' && gender != '?');

    return gender;
}
//function that gets the birthYear from the user and returns it
int UI::getBirthYear()
{
    int bYear = 0;

    do{
        cout << "Input year of birth: ";
        cin >> bYear;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(!((bYear < yearNow) && (bYear >= CstartYear)))
            {
                displayError();
            }
    }while(!((bYear < yearNow) && (bYear >= CstartYear)));

    return bYear;
}
//function that gets the deathYear from the user and returns it
int UI::getDeathYear(string name, int bYear)
{
    int dYear = 0;
    char personDead = ' ';

    do{
        cout << "Is " << name << " deceased? (Y for yes/ N for no): ";
        cin >> personDead;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

            if(toupper(personDead) != 'Y' && toupper(personDead) != 'N')
            {
                displayError();
            }

            if(toupper(personDead) == 'Y')
            {
                do{
                    cout << "Input year of death: ";
                    cin >> dYear;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                        if(!((dYear > bYear) && (dYear <= yearNow)))
                        {
                            displayError();
                        }
                }while(!((dYear > bYear) && (dYear <= yearNow)));
            }
            if(toupper(personDead) == 'N')
            {
                //all deceased get zero as input for year of death
                dYear = 0;
            }
    }while(toupper(personDead) != 'Y' && toupper(personDead) != 'N');
    return dYear;
}
//COMPUTER INFO INPUT
//function that gets the user computer info from user
void UI::getComputerInfo()
{
    Services c;
    bool check2 = false;

    cout << "* * * INPUT COMPUTER INFORMATION * * *" << endl;
    cout << endl;

    do{
        string computerName = getComputerName();
        int computerYearMade = getYearMade();
        string computerType = getComputerType();
        int wasBuilt = getWasBuilt(computerYearMade);
        bool check = duplicateCheckComputers(computerName, computerYearMade, computerType, wasBuilt);
        if(check == true)
        {
            c.addComputer(computerName, computerYearMade, computerType, wasBuilt);
        }
        else
        {
            cout << endl;
            cout << "| | | Duplicate error. Computer already in database. | | |" << endl;
            cout << "--- ERROR! will NEVER appear when Chuck Norris is using the PC ---" << endl;
            cout << endl;
        }
        check2 = continueOption();
    }while(check2 == true);
}
//function that gets the computer name from the user and returns it
string UI::getComputerName()
{
    string name = " ";
    cout << "Input computer name: ";
    cin.clear();
    getline(cin, name);
    return name;
}
//function that gets the yearMade from the user and returns it
int UI::getYearMade()
{
    int computerYearMade = 0;
    bool check = false;
    do{
        cout << "Input year made (input 1 for unknown): ";
        cin >> computerYearMade;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if((computerYearMade <=yearNow && computerYearMade >=CstartYear) || computerYearMade == 1)
        {
            computerYearMade = computerYearMade;
            check = true;
        }
       else
        {
            displayError();
            check = false;
        }
    }while(check == false);

    if(computerYearMade == 1)
    {
        computerYearMade = 0;
        return computerYearMade;
    }
    else
    {
        return computerYearMade;
    }
}
//function that gets the computer type from the user and returns it
string UI::getComputerType()
{
    char choice = ' ';
    string type = " ";

    do{
        cout << "Input computer type (M for mechanical/E for electronic/T for transistor/O for other: ";
        cin.clear();
        cin >> choice;
        cin.ignore(INT_MAX, '\n');
            if(toupper(choice) != 'M' && toupper(choice) != 'E' && toupper(choice) != 'T' && toupper(choice) != 'O')
            {
               displayError();
            }
            else
            {
                switch(toupper(choice))
                {
                    case 'M':
                    {
                        type = "Mechanical";
                        break;
                    }
                    case 'E':
                    {
                        type = "Electronic";
                        break;
                    }
                    case 'T':
                    {
                        type = "Transistor";
                        break;
                    }
                    case 'O':
                    {
                        cout  << "Input computer type name: ";
                        getline(cin, type);
                        break;
                    }
                }
            }
    }while(toupper(choice) != 'M' && toupper(choice) != 'E' && toupper(choice) != 'T' && toupper(choice) != 'O');
    return type;
}
//function that gets the yearBuilt from the user and returns it
int UI::getWasBuilt(int computerYearMade)
{
    char choice = ' ';
    int built = 0;
    do{
        cout << "Was the computer ever built? (Y for yes/N for no/? if unknown): ";
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(toupper(choice) != 'Y' && toupper(choice) != 'N' && choice != '?')
            {
               displayError();
            }
            else
            {
                if(toupper(choice) == 'Y')
                {
                    do
                    {
                        cout << "What year was the computer built?: ";
                        cin >> built;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if(!((built <= yearNow) && (built >= computerYearMade)))
                        {
                            displayError();
                        }
                    }while(!((built <= yearNow) && (built >= computerYearMade)));
                }
                else if(toupper(choice) == 'N')
                {
                    //if it was never built it gets the value 0
                    built = 0;
                }
                else if(choice == '?')
                {
                    //if it is unkown when it was built it gets the value 1
                    built = 1;
                }
            }
    }while(toupper(choice) != 'Y' && toupper(choice) != 'N' && choice != '?');

    return built;
}
//VIEW
//view info menu function
void UI::viewInfoMenu()
{
    Services p;
    int choice;

    do{
        cout << "* * * VIEW INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. View information of persons" << endl;
        cout << "2. View information of computers" << endl;
        cout << "3. View statistics information" << endl;
        cout << "4. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

        switch(choice)
        {
            case 1:
            {
                cout << "* * * VIEW PERSON INFORMATION * * *" << endl;
                vector<InfoType> FP = p.makePersonsVector();
                displayPersons(FP);
                backToView();
                break;
            }
            case 2:
            {
                cout << "* * * VIEW COMPUTER INFORMATION * * *" << endl;
                vector<CompType> Comp = p.makeComputerVector();
                displayComputers(Comp);
                backToView();
                break;
            }
            case 3:
            {
                cout << "* * * VIEW STATISTICS INFORMATION * * *" << endl;
                viewStatistics();
                break;
            }
            case 4:
            {
                userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}
//view statistics function
void UI::viewStatistics()
{
    Services s;
    vector<InfoType> FP = s.makePersonsVector();
    vector<CompType> Comp = s.makeComputerVector();

    int totalPersonCount = 0;
    int maleCount = 0;
    int femaleCount = 0;
    int deadCount = 0;
    int liveCount = 0;
    int totalComputerCount = 0;
    int wasBuilt = 0;
    int notBuilt = 0;

    for(unsigned int i = 0; i < FP.size(); i++)
    {
        if(FP[i].gender == 'F' || FP[i].gender == 'f')
            femaleCount++;
        if(FP[i].gender == 'M' || FP[i].gender == 'm')
            maleCount++;
        if(FP[i].deathYear > 0)
            deadCount++;
        if(FP[i].deathYear == 0)
            liveCount++;
        totalPersonCount++;
    }
    for(unsigned int i = 0; i < Comp.size(); i++)
    {
        if(Comp[i].wasBuilt != 0)
            wasBuilt++;
        if(Comp[i].wasBuilt == 0)
            notBuilt++;
        totalComputerCount++;
    }
    cout << endl;
    cout << "Persons  in database: " << totalPersonCount << endl;
    cout << "Male persons in database: " << maleCount << endl;
    cout << "Female persons in database: " << femaleCount << endl;
    cout << "Deceased persons in database: " << deadCount << endl;
    cout << "Alive persons in database: " << liveCount << endl;
    cout << endl;
    cout << "Computers in database: " << totalComputerCount << endl;
    cout << "Computers built in database: " << wasBuilt << endl;
    cout << "Computers not built in database: " << notBuilt << endl;
    cout << endl;
    cout << "Total of persons and computers in database: " << totalComputerCount + totalPersonCount << endl;
    cout << endl;
    backToView();
}
//function that returns the user to viewMenu by input
void UI::backToView()
{
    cout << "--- Press any key and then enter to return to view menu ---" << endl;
    char input;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            viewInfoMenu();
        }
}
//SORT
//sort menu function
void UI::sortMenu()
{
    int choice;

    do{
        cout << "* * * SORT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort person information" << endl;
        cout << "2. Sort computer information" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
            sortPersonMenu();
                break;
            }
            case 2:
            {
            sortComputerMenu();
                break;
            }
            case 3:
            {
            userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//function that returns the user to sortMenu by input
void UI::backToSortMenu()
{
    char input;
    cout << "--- Press any key and then enter to return to sort menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            sortMenu();
        }
}
//SORT PERSONS
//sort person menu function
void UI::sortPersonMenu()
{
    int choice;

    do{
        cout << "* * * SORT PERSON INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by name" << endl;
        cout << "2. Sort by gender" << endl;
        cout << "3. Sort by year of birth" << endl;
        cout << "4. Sort by year of death" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        switch(choice)
        {
            case 1:
            {
            sortNameMenu();
                break;
            }
            case 2:
            {
            sortGenderMenu();
                break;
            }
            case 3:
            {
            sortYearOfBirthMenu();
                break;
            }
            case 4:
            {
            sortYearOfDeathMenu();
                break;
            }
            case 5:
            {
            userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}
//sort name menu function, displays persons in sorted order
void UI::sortNameMenu()
{
    Services p;
    int choice;

    do{
        cout << "* * * SORT BY NAME INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by name (Ascending)" << endl;
        cout << "2. Sort by name (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying persons by name in ascending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByNameAsc();
                displayPersons(FP);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying persons by name in descending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByNameDesc();
                displayPersons(FP);
                backToSortMenu();
                break;
            }
            case 3:
            {
                sortMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//sort gender menu function, displays persons in sorted order
void UI::sortGenderMenu()
{
    Services p;
    int choice;

    do{
        cout << "* * * SORT BY GENDER INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by male" << endl;
        cout << "2. Sort by female" << endl;
        cout << "3. Sort by undecided" << endl;
        cout << "4. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying male persons ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByGenderMale();
                for(unsigned int i = 0; i < FP.size(); i++)
                {
                    if(toupper(FP.at(i).gender) == 'M')
                    {
                        displayPersonsSpecial(i, FP);
                    }
                }
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying female persons ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByGenderFemale();
                for(unsigned int i = 0; i < FP.size(); i++)
                {
                    if(toupper(FP.at(i).gender) == 'F')
                    {
                        displayPersonsSpecial(i, FP);
                    }
                }
                backToSortMenu();
                break;
             }
            case 3:
            {
                cout << endl;
                cout << "--- Displaying persons of undecided gender ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByGenderUndecided();
                for (unsigned int i = 0; i < FP.size(); i++)
                {
                    if(FP.at(i).gender == '?')
                    {
                        displayPersonsSpecial(i, FP);
                    }
                }
                backToSortMenu();
                break;
             }
             case 4:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}
//sort yearOfBirth menu function, displays persons in sorted order
void UI::sortYearOfBirthMenu()
{
    Services p;
    int choice;

    do{
        cout << "* * * SORT BY YEAR OF BIRTH INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by year of birth (Ascending)" << endl;
        cout << "2. Sort by year of birth (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying persons by year of birth in ascending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByYearAsc();
                displayPersons(FP);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying persons by year of birth in descending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByYearDesc();
                displayPersons(FP);
                backToSortMenu();
                break;
            }
            case 3:
            {
                sortMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 );
}
//sort yearOfDeath menu function, displays persons in sorted order
void UI::sortYearOfDeathMenu()
{
    Services p;
    int choice;

    do{
        cout << "* * * SORT BY YEAR OF DEATH INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by year of death (Ascending)" << endl;
        cout << "2. Sort by year of death (Descending)" << endl;
        cout << "3. Sort by year of death (deceased only)" << endl;
        cout << "4. Sort by year of death (not deceased)" << endl;
        cout << "5. Return to sort menu" << endl;
        cout << "===========================================" << endl;
        choice = chooseNumber();

        switch(choice)
        {
             case 1:
             {
                cout << endl;
                cout << "--- Displaying persons by year of death in ascending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByDeathYearAsc();
                displayPersons(FP);
                backToSortMenu();
                break;
             }
             case 2:
             {
                cout << endl;
                cout << "--- Displaying persons by year of death in descending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByDeathYearDesc();
                displayPersons(FP);
                backToSortMenu();
                break;
             }
            case 3:
            {
                cout << endl;
                cout << "--- Displaying deceased persons ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByDeceased();
                for (unsigned int i = 0; i < FP.size(); i++)
                {
                    if(FP.at(i).deathYear > 0)
                    {
                        displayPersonsSpecial(i, FP);
                    }
                }
                backToSortMenu();
                break;
            }
            case 4:
            {
                cout << endl;
                cout << "--- Displaying non deceased persons ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByNotDeceased();
                for (unsigned int i = 0; i < FP.size(); i++)
                {
                    if(FP.at(i).deathYear == 0)
                    {
                        displayPersonsSpecial(i, FP);
                    }
                }
                backToSortMenu();
                break;
            }
             case 5:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}
//SORT COMPUTERS
//sort computer menu function
void UI::sortComputerMenu()
{
    int choice;

    do{
        cout << "* * * SORT COMPUTER INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by name" << endl;
        cout << "2. Sort by year" << endl;
        cout << "3. Sort by computer type" << endl;
        cout << "4. Sort by built/not built" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "===========================================" << endl;

        choice = chooseNumber();

        switch(choice)
        {
            case 1:
            {
            sortComputerNameMenu();
                break;
            }
            case 2:
            {
            sortComputerYearMadeMenu();
                break;
            }
            case 3:
            {
            sortComputerTypeMenu();
                break;
            }
            case 4:
            {
            sortComputerWasBuiltMenu();
                break;
            }
            case 5:
            {
            userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}
//sort computer name menu function, displays computers in sorted order
void UI::sortComputerNameMenu()
{
    Services c;
    int choice;

    do{
        cout << "* * * SORT BY COMPUTER NAME INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by name (Ascending)" << endl;
        cout << "2. Sort by name (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying computers by name in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByComputerNameAsc();
                displayComputers(Comp);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by name in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByComputerNameDesc();
                displayComputers(Comp);
                backToSortMenu();
                break;
            }
            case 3:
            {
                sortMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//sort computer yearMade menu function, displays computers in sorted order
void UI::sortComputerYearMadeMenu()
{
    Services c;
    int choice;

    do{
        cout << "* * * SORT BY YEAR MADE INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by year made (Ascending)" << endl;
        cout << "2. Sort by year made (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying computers by year made in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearMadeAsc();
                displayComputers(Comp);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by year made in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearMadeDesc();
                displayComputers(Comp);
                backToSortMenu();
                break;
            }
            case 3:
            {
                sortMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 );
}
//sort computer type menu function, displays computers in sorted order
void UI::sortComputerTypeMenu()
{
    Services c;
    int choice;

    do{
        cout << "* * * SORT BY COMPUTER TYPE INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by type (Ascending)" << endl;
        cout << "2. Sort by type (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying computers by type in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByComputerTypeAsc();
                displayComputers(Comp);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by type in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByComputerTypeDesc();
                displayComputers(Comp);
                backToSortMenu();
                break;
            }
            case 3:
            {
                sortMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 );
}
//sort computer wasBuilt menu function, displays computers in sorted order
void UI::sortComputerWasBuiltMenu()
{
    Services c;
    int choice;
    do{
        cout << "* * * SORT BY BUILT/NOT BUILT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by built" << endl;
        cout << "2. Sort by not built" << endl;
        cout << "3. Sort by unknown" << endl;
        cout << "4. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

        switch(choice)
        {
            case 1:
            {
                sortComputerYearBuiltMenu();
                break;
            }
            case 2:
            {
                sortComputerNotBuiltMenu();
                break;
             }
            case 3:
            {
                sortComputerUnkownBuiltMenu();
                break;
             }
             case 4:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}
//sort computer yearBuilt menu function, displays computers in sorted order
void UI::sortComputerYearBuiltMenu()
{
    Services c;
    int choice;

    do{
        cout << "* * * SORT BY YEAR BUILT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by year built (Ascending)" << endl;
        cout << "2. Sort by year built (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying computers by year built in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearBuiltAsc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt > 1)
                    {
                        displayComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by year built in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearBuiltDesc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt > 1)
                    {
                        displayComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
             }
             case 3:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//sort computer notBuilt menu function, displays computers in sorted order
void UI::sortComputerNotBuiltMenu()
{
    Services c;
    int choice;

    do{
        cout << "* * * SORT BY NOT BUILT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by not built (Ascending)" << endl;
        cout << "2. Sort by not built (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying computers not built in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearNotBuiltAsc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 0)
                    {
                        displayComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers not built in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearNotBuiltDesc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 0)
                    {
                        displayComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
             }
             case 3:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//sort computer unknownBuilt menu function, displays computers in sorted order
void UI::sortComputerUnkownBuiltMenu()
{
    Services c;
    int choice;

    do{
        cout << "* * * SORT BY UNKNOWN IF BUILT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Sort by unkown if built (Ascending)" << endl;
        cout << "2. Sort by unkown if built (Descending)" << endl;
        cout << "3. Return to sort menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << endl;
                cout << "--- Displaying computers unkown if built in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearUnknownBuiltAsc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 1)
                    {
                        displayComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers unkown if built in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearUnknownBuiltDesc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 1)
                    {
                        displayComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
             }
             case 3:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//SEARCH
//search menu function
void UI::searchMenu()
{
    int choice;

    do{
        cout << "* * * SEARCH INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Search persons" << endl;
        cout << "2. Search computers" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
                searchPersonMenu();
                break;
            case 2:
            {
                searchComputerMenu();
                break;
            }
            case 3:
                userMenu();
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//function that returns the user to searchMenu by input
void UI::backToSearch()
{
    char input;
    cout << "--- Press any key and then enter to return to search menu ---" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            searchMenu();
        }
}
//SEARCH PERSONS
//search person menu function, displays searched persons if found
void UI::searchPersonMenu()
{
    Services p;
    int choice;

    do{
        cout << "* * * SEARCH PERSON INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Search by name"<< endl;
        cout << "2. Search by gender"<< endl;
        cout << "3. Search by year of birth"<< endl;
        cout << "4. Search by year of death"<< endl;
        cout << "5. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        switch(choice)
        {
            case 1:
            {
                string nameSearch;
                cout << "Enter name: ";
                cin >> nameSearch;
                vector <InfoType> FP = p.searchVectorName(nameSearch);
                searchPersDisplay(FP, nameSearch);
                backToSearch();
                break;
            }
            case 2:
            {
                string genderSearch;
                cout << "Enter gender (M for male, F for female or ? for undecided): ";
                cin >> genderSearch;
                vector <InfoType> FP = p.searchVectorGender(genderSearch);
                searchPersDisplay(FP, genderSearch);
                backToSearch();
                break;
            }
            case 3:
            {
                string birthYearSearch;
                cout << "Enter year of birth: ";
                cin >> birthYearSearch;
                vector <InfoType> FP = p.searchVectorBirthYear(birthYearSearch);
                searchPersDisplay(FP, birthYearSearch);
                backToSearch();
                break;
            }
            case 4:
            {
                string deathYearSearch;
                cout << "Enter death year (input 0 if still alive): ";
                cin >> deathYearSearch;
                vector <InfoType> FP = p.searchVectorDeathYear(deathYearSearch);
                searchPersDisplay(FP, deathYearSearch);
                backToSearch();
                break;
            }
            case 5:
                userMenu();
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5); //eða while(choice != 5);
}
//SEARCH COMPUTERS
//search computers menu function, displays searched computers if found
void UI::searchComputerMenu()
{
    Services p;
    string nameSearch;

    cout << "* * * SEARCH COMPUTER INFORMATION * * *" << endl;
    cout << endl;
    cout << "Enter name: ";
    cin >> nameSearch;

    vector<CompType> Comp = p.searchVectorComputersName(nameSearch);
    searchCompDisplay(Comp, nameSearch);
}
//RELATION INFO INPUT
//relation menu function
void UI::relationMenu()
{
    Services s;
    int choice;

    do{
        cout << " * * * RELATIONS * * * " << endl;
        cout << endl;
        cout << "1. Add relation between computer and person" << endl;
        cout << "2. Find persons related to computer" << endl;
        cout << "3. Find computers related to person" << endl;
        cout << "4. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

        switch(choice)
        {

            case 1:
            {
                Services s;
                vector<InfoType> FP = s.makePersonsVector();
                vector<CompType> C = s.makeComputerVector();
                bool checkDatabase = false;
                checkDatabase = checkDatabaseEmpty(FP, C);
                FP.clear();
                C.clear();
                int compID = 0, persID = 0;
                string compName = "", persName = "";
                vector <string> names;
                if(checkDatabase == true)
                {
                    do{
                        cout << "Enter name of computer: ";
                        cin.clear();
                        getline(cin, compName);
                        compID = s.findIDComputer(compName, names);
                        if(compID == 0)
                        {
                            if(names.size() == 0)
                            {
                                cout << "| | | " << compName << " was not found in database! | | |" << endl << endl;
                                relationMenu();
                            }
                            else
                            {
                                for(unsigned int i = 0; i < names.size(); i++)
                                {
                                    cout << "Did you mean: "<< names[i]<< endl;
                                }
                            }
                        }
                        names.clear();
                    }while(compID == 0);
                    do{
                    cout << "Enter name of person: ";
                    cin.clear();
                    getline(cin, persName);
                    persID = s.findIDPerson(persName, names);
                    if(persID == 0)
                    {
                        if(names.size() == 0)
                        {
                            cout << "| | | " << persName << " was not found in database! | | |" << endl << endl;
                            relationMenu();
                        }
                        else
                        {
                            for(unsigned int i = 0; i < names.size(); i++)
                            {
                                cout << "Did you mean: "<< names[i]<< endl;
                            }
                        }
                    }
                    names.clear();
                    }while(persID == 0);
                    bool check = s.makeRelation(compID, persID);
                    if(check == true)
                    {
                        cout << endl;
                        cout << "| | | Relation is already in database | | |" << endl;
                        cout << endl;
                        backToRelation();
                        break;
                    }
                    else
                    {
                        cout << endl;
                        cout << "* * * Relation between " << compName <<" and " << persName << " has been added * * *" << endl;
                        cout << endl;
                        backToRelation();
                        break;
                    }
                }
                if(checkDatabase == false)
                {
                    cout << endl;
                    cout << "There is not enough information in database to make relation" << endl;
                    cout << "Add a computer, or a person first" << endl;
                    cout << endl;
                    backToRelation();
                    break;
                }
            }
            case 2:
            {
                string name = "";
                vector<string> names;
                int ID = 0;
                do{
                    cout << "Enter name of computer: ";
                    cin.clear();
                    getline(cin, name);
                    ID = s.findIDComputer(name, names);
                    if(ID == 0)
                    {
                        if(names.size() == 0)
                        {
                            cout << "| | | " << name << " was not found in database! | | |" << endl << endl;
                            relationMenu();
                        }
                        else
                        {
                            for(unsigned int i = 0; i < names.size(); i++)
                            {
                                cout << "Did you mean: "<< names[i]<< endl;
                            }
                        }
                    }
                    names.clear();
                }while(ID == 0);
                vector<InfoType> FP = s.getViewRelationComputer(ID);
                cout << endl;
                cout << "* * * Persons related to " << name << " * * *" << endl;
                databaseCheckPersons(FP);
                backToRelation();
                break;
            }
            case 3:
            {
                string name = "";
                int ID = 0;
                vector<string> names;
                do{
                    cout << "Enter persons name: ";
                    cin.clear();
                    string name = "";
                    getline(cin, name);
                    ID = s.findIDPerson(name, names);
                    if(ID == 0)
                    {
                        if(names.size() == 0)
                        {
                            cout << "| | | " << name << " was not found in database! | | |" << endl << endl;
                            relationMenu();
                        }
                        else
                        {
                            for(unsigned int i = 0; i < names.size(); i++)
                            {
                                cout << "Did you mean: "<< names[i]<< endl;
                            }
                        }
                    }
                    names.clear();
                }while(ID == 0);
                vector<CompType> Comp = s.getViewRelationPerson(ID);
                cout << endl;
                cout << "* * * Computers related to " << name << " * * *" << endl;
                databaseCheckComputers(Comp);
                backToRelation();
                break;
            }
            case 4:
            {
                userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}
void UI::backToRelation()
{
    cout << "--- Press any key and then enter to return to relation menu ---" << endl;
    char input;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            relationMenu();
        }
}
//REMOVE
//remove menu function
void UI::removeMenu()
{
    Services s;
    int choice;
    do{
        cout << "* * * REMOVE INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Remove person" << endl;
        cout << "2. Remove computer" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                string name = "";
                char check = 'P';
                int ID = 0;
                vector<string> names;
                do{
                    cout << "Enter name of a person to remove: ";
                    cin.clear();
                    getline(cin, name);
                    ID = s.findIDPerson(name, names);
                    if(ID == 0)
                    {
                        if(names.size() == 0)
                        {
                            cout << "| | | " << name << " was not found in database! | | |" << endl << endl;
                            returnToRemove();
                        }
                        else{
                            for(unsigned int i = 0; i < names.size(); i++)
                            {
                                cout << "Did you mean: "<< names[i]<< endl;
                            }
                        }
                    }
                    names.clear();
                }while(ID == 0);
                cout << endl;
                vector<InfoType> person = s.getPerson(ID);
                displayPersons(person);
                askToRemove(name, ID, check);
                break;
            }
            case 2:
            {
                string name = "";
                char check = 'C';
                int ID = 0;
                vector <string> names;
                do{
                    cout << "Enter name of a computer to remove: ";
                    cin.clear();
                    getline(cin, name);
                    ID = s.findIDComputer(name, names);
                    if(ID == 0)
                    {
                        if(names.size() == 0)
                        {
                            cout << "| | | " << name << " was not found in database! | | |" << endl << endl;
                            returnToRemove();
                        }
                        else{
                            for(unsigned int i = 0; i < names.size(); i++)
                            {
                                cout << "Did you mean: "<< names[i]<< endl;
                            }
                        }
                    }
                    names.clear();
                }while(ID == 0);
                cout << endl;
                vector<CompType> computer = s.getComputer(ID);
                displayComputers(computer);
                askToRemove(name, ID, check);
                break;
            }
            case 3:
                userMenu();
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
//remove menu function, removes information through services if user is sure
void UI::askToRemove(string name, int ID, char check)
{
    Services s;
    string input = " ";
    do{
        if(check == 'P')
            cout << "Do you want to remove this person(y for yes, n for no)? " << endl;
        if(check =='C')
            cout << "Do you want to remove this computer (y for yes, n for no)? " << endl;

        cin >> input;
        if(toupper(input[0]) != 'Y' && toupper(input[0]) != 'N' && input.size() != 1)
        {
            displayError();
        }
    }while(toupper(input[0]) != 'Y' && toupper(input[0]) != 'N' && input.size() != 1);
    if(toupper(input[0]) == 'Y')
    {
        if(check == 'P')
        {
            s.getPersID(ID);
        }
        if(check == 'C')
        {
            s.getCompID(ID);
        }
        cout << endl;
        cout << name << " has been removed!" << endl << endl;

        returnToRemove();
    }
    else if(toupper(input[0]) == 'N')
    {
        cout << endl << name << " was not removed!" << endl << endl;
        returnToRemove();
    }
}
//function that returns the user to remove menu by input
void UI::returnToRemove()
{
    cout << "--- Press any key and then enter to return to remove menu ---" << endl;
    char input;
    cin >> input;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(input)
        {
            removeMenu();
        }
}
//DISPLAY
//funtion that displays persons/sorted persons
void UI::displayPersons(vector<InfoType> FP)
{
    for (unsigned int i = 0; i < FP.size(); i++)
    {
        displayPersonsSpecial(i, FP);
    }
}
//function that displays persons/special case sorted persons
void UI::displayPersonsSpecial(int i, vector<InfoType> FP)
{
    cout << endl;
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
//funtion that displays computers/sorted computers
void UI::displayComputers(vector<CompType> Comp)
{
    for (unsigned int i = 0; i < Comp.size(); i++)
    {
        displayComputersSpecial(i, Comp);
    }
}
//function that displays computers/special case sorted computers
void UI::displayComputersSpecial(int i, vector<CompType> Comp)
{
    cout << endl;
    cout << "Computer name: " << Comp.at(i).compName << endl;
    if(Comp.at(i).yearMade == 0)
    {
        cout << "Computer has been made, year is unknown." << endl;
    }
    else
    {
        cout << "Year made: " << Comp.at(i).yearMade << endl;
    }
    cout << "Computer type: " << Comp.at(i).type << endl;
    if(Comp.at(i).wasBuilt != 0 && Comp.at(i).wasBuilt != 1)
    {
        cout << "Year built: " << Comp.at(i).wasBuilt << endl;
    }
    else if (Comp.at(i).wasBuilt == 0)
    {
        cout << "Computer has not been built." << endl;
    }
    else if (Comp.at(i).wasBuilt == 1)
    {
        cout << "Computer has been built but year built is unknown." << endl;
    }
    cout << endl;
}
//function that displays searched persons
void UI::searchPersDisplay(vector<InfoType> FP, string y){
    if(!FP.empty())
    {
        displayPersons(FP);
    }
    else
    {
        falseCheck(y);
    }
}
//function that displays searched computers
void UI::searchCompDisplay(vector<CompType> Comp, string y){
    if(!Comp.empty())
    {
        displayComputers(Comp);
    }
    else
    {
        falseCheck(y);
    }
}
//OTHER
//function used in menus to navigate, utilizes user input and returns it
int UI::chooseNumber()
{
    int choice;
    cout << "Please choose one of these numbers: ";
    cin >> choice;
    cout << "===========================================" << endl;
    cout << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice !=6 && choice != 7)
    {
        displayError();
    }
    return choice;
}
//function that displays an error message
void UI::displayError()
{
    cout << "------------------------------------------" << endl;
    cout << "| | | Wrong input. Please try again. | | |" << endl;
    cout << "------------------------------------------" << endl;
}
//function that checks if user wants to input more information and returns true/false
bool UI::continueOption()
{
    bool check;
    char keepGoing = ' ';

    do{
        cout << "Input more information (Y for yes/N for no): ";
        cin >> keepGoing;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N')
            {
                displayError();
            }
        cout << endl;
    }while(toupper(keepGoing) != 'Y' && toupper(keepGoing) != 'N');
    if(toupper(keepGoing) == 'Y')
    {
        check = true;
    }
    if(toupper(keepGoing) == 'N')
    {
        check = false;
    }
    return check;
}
//function that displays an error message if user input is not in database
void UI::falseCheck(string x)
{

    cout << "-------------------------------------------" << endl;
    cout << "   "<< x << " was not in database or input not in the right format" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "--- Please try again. ---" << endl;
    cout << endl;
}
void UI::databaseCheckComputers(vector<CompType> Comp)
{
    if(Comp.size() == 0)
    {
        cout << endl;
        cout << "| | | Name not in database or no relations to show. | | |" << endl;
        cout << endl;
    }
    else
    {
        Services c;
        c.sortByComputerNameAsc();
        displayComputers(Comp);
    }
}
void UI::databaseCheckPersons(vector<InfoType> FP)
{
    if(FP.size() == 0)
    {
        cout << endl;
        cout << "| | | Name not in database or no relations to show. | | |" << endl;
        cout << endl;
    }
    else
    {   Services p;
        p.sortByNameAsc();
        displayPersons(FP);
    }
}
//checks if the computer and persons database is empty, if so relations can't be made
bool UI::checkDatabaseEmpty(vector<InfoType> FP, vector<CompType> C)
{

    if((FP.size() == 0) && (C.size() == 0))
    {
        return false;
    }

     else return true;
}
//function that checks for duplicate person input from user
bool UI::duplicateCheckPersons(string name, char gender, int bYear, int dYear)
{
    Services s;
    bool check = true;
    vector<InfoType> FP = s.makePersonsVector();
    string temp1, temp2;
    temp1 = s.changeName(name);
    for(unsigned int i = 0; i < FP.size(); i++)
    {
        temp2 = s.changeName(FP.at(i).name);
        if((temp1 == temp2) && (gender == FP.at(i).gender) && (bYear == FP.at(i).birthYear) && (dYear == FP.at(i).deathYear))
        {
            check = false;
        }
    }
    return check;
}
//function that checks for duplicate computer input from user
bool UI::duplicateCheckComputers(string computerName, int computerYearMade, string computerType, int wasBuilt)
{
    Services s;
    bool check = true;
    vector<CompType> Comp = s.makeComputerVector();
    string temp1, temp2, temp3, temp4;

    temp1 = s.changeName(computerName);
    temp2 = s.changeName(computerType);

    for(unsigned int i = 0; i < Comp.size(); i++)
    {
        temp3 = s.changeName(Comp.at(i).compName);
        temp4 = s.changeName(Comp.at(i).type);
        if((temp1 == temp3) && (computerYearMade == Comp.at(i).yearMade) && (temp2 == temp4) && (wasBuilt == Comp.at(i).wasBuilt))
        {
            check = false;
        }
    }
    return check;
}
