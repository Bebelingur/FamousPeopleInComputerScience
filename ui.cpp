#include "ui.h"

using namespace std;

const int yearNow = 2015;
const int CstartYear = 1791;
//birth year of Charles Babbage should do for beginning year of computer science - BóE


UI::UI()
{

}
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
        cout << "5. Add Relatinon" << endl;
        cout << "6. Exit" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice !=6);
Services a;
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
                a.makeRelation();
                break;
            case 6:
                exit(1);
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6); //eða while(choice != 5);
    //náði að láta virka aðeins, google to the rescue :)  - BóE
}
//INPUT
void UI::inputMenu()
{
    int choice;

    do{
        cout << "* * * INPUT INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Input person" << endl;
        cout << "2. Input computer" << endl;
        cout << "3. Add relation between person and computer" << endl;
        cout << "4. Return to main menu" << endl;
        cout << "===========================================" << endl;
        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4);

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
                addRelation();
                break;
            }
            case 4:
            {
                userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
    userMenu();
}
//PERSON INFO INPUT
void UI::getPersonInfo()
{
    char keepGoing = ' ';
    //færibreytur núllstilltar svo rusl fylgi ekki með - BóE

    cout << "* * * INPUT INFORMATION * * *" << endl;
    cout << endl;
    do{
        string name = getName();
        char gender = getGender();
        int bYear = getBirthYear();
        int dYear = getDeathYear(name, bYear);

        Services p;
        p.addPerson(name, gender, bYear, dYear);

        //CONTINUE
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

    }while(toupper(keepGoing) == 'Y');
}
string UI::getName()
{
    bool check = false;
    string name = " ";

    do{
        cout << "Input name (in the order first, middle and last name): ";
        cin.clear();
        getline(cin, name);
        check = false;
        //athuga hvort innslátturinn innihaldi nokkuð tölur
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
                //fallegra að nota toupper frekar en langa uppröðun - BóE
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
                    //year of birth has to be less than year of death - BÓE
                    //do not do equal since it is highly unlikely that a famous person would be less than 1 years old - BóE
                    //use a constant for the year, now it is set to 2015, death year should be less or equal

                }
                if(toupper(personDead) == 'N')
                {
                    //all deceased get zero as input for year of death, equals NULL in SQL - BóE
                    dYear = 0;
                }
        }while(toupper(personDead) != 'Y' && toupper(personDead) != 'N');
    return dYear;
}
//COMPUTER INFO INPUT
void UI::getComputerInfo()
{
        char keepGoing = ' ';
        //færibreytur núllstilltar svo rusl fylgi ekki með - BóE

        cout << "* * * INPUT INFORMATION * * *" << endl;
        cout << endl;
        do{
            string computerName = getComputerName();
            int computerYearMade = getYearMade();
            string computerType = getComputerType();
            int wasBuilt = getWasBuilt(computerYearMade);

            Services c;
            c.addComputer(computerName, computerYearMade, computerType, wasBuilt);

            //CONTINUE
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

        }while(toupper(keepGoing) == 'Y');
}
string UI::getComputerName()
{
    string name = " ";

        cout << "Input computer name: ";
        cin.clear();
        getline(cin, name);

    return name;
}
int UI::getYearMade()
{
    int computerYearMade = 0;

    bool check = false;
    do{
        cout << "Input year designed (input 1 for unknown): ";
        cin >> computerYearMade;
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        if((computerYearMade <=yearNow && computerYearMade >=CstartYear)||computerYearMade == 1)
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

    //virkaði ekki að hafa 0 sem parameter og því er þetta fall hér til að grípa input 1 og skila 0 í gagnagrunnin
    if(computerYearMade == 1)
    {
        computerYearMade = 0;
        return computerYearMade;
    }
    else
    return computerYearMade;
}
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
                        cout  << " \t Input computer type name: ";
                        getline(cin, type);
                        break;
                    }
                }
            }
    }while(toupper(choice) != 'M' && toupper(choice) != 'E' && toupper(choice) != 'T' && toupper(choice) != 'O');
    return type;
}
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
                    //ef hún var aldrei byggð(var bara til á pappírum/theoretical) þá fær hún gildið 0
                    built = 0;
                }
                else if(choice == '?')
                {
                    //ef ekki er vitað hvenær hún var byggð(sett saman og hún virkaði) þá fær hún gildið 1
                    built = 1;
                }
            }
    }while(toupper(choice) != 'Y' && toupper(choice) != 'N' && choice != '?');

    return built;
}
//RELATION INFO INPUT
//VIEW
void UI::viewInfoMenu()
{
    Services p;
    int choice;

    do{
        cout << "* * * VIEW INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. View person info" << endl;
        cout << "2. View computer info" << endl;
        cout << "3. Return to main menu" << endl;
        cout << "===========================================" << endl;


        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3);

        switch(choice)
        {
            case 1:
            {
                cout << "* * * VIEW PERSON INFORMATION * * *" << endl;
                vector<InfoType> x = p.viewPersonsInfo();
                for(unsigned int i = 0; i < x.size(); i++)
                {
                    displayPerson(x[i]);
                }
                backToView();
                break;
            }
            case 2:
            {
                cout << "* * * VIEW COMPUTER INFORMATION * * *" << endl;
                vector<CompType> x = p.viewComputerInfo();
                for(unsigned int i = 0; i < x.size(); i++)
                {
                    displayComputer(x[i]);
                }
                break;
            }
            case 3:
            {
                userMenu();
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
    userMenu();
}
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
    userMenu();
}
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
    sortMenu();
}
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
                displaySortedPersons(FP);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying persons by name in descending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByNameDesc();
                displaySortedPersons(FP);
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
                        displaySortedPersonsSpecial(i, FP);
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
                        displaySortedPersonsSpecial(i, FP);
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
                for(unsigned int i = 0; i < FP.size(); i++)
                {
                    if(FP.at(i).gender == '?')
                    {
                        displaySortedPersonsSpecial(i, FP);
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
                displaySortedPersons(FP);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying persons by year of birth in descending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByYearDesc();
                displaySortedPersons(FP);
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
                displaySortedPersons(FP);
                backToSortMenu();
                break;
             }
             case 2:
             {
                cout << endl;
                cout << "--- Displaying persons by year of death in descending order ---" << endl;
                cout << endl;
                vector <InfoType> FP = p.sortByDeathYearDesc();
                displaySortedPersons(FP);
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
                        displaySortedPersonsSpecial(i, FP);
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
                        displaySortedPersonsSpecial(i, FP);
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
    sortComputerMenu();
}
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
                displaySortedComputers(Comp);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by name in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByComputerNameDesc();
                displaySortedComputers(Comp);
                backToSortMenu();
                break;
            }
            case 3:
<<<<<<< HEAD
                s.viewRelationPerson();
=======
            {
                sortMenu();
>>>>>>> 625f3fd01cc2d8825614a2b0e53a20bad49bd634
                break;
            }
        }
    }while(choice == 1 || choice == 2 || choice == 3);
}
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
                displaySortedComputers(Comp);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by year made in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearMadeDesc();
                displaySortedComputers(Comp);
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
                displaySortedComputers(Comp);
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by type in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByComputerTypeDesc();
                displaySortedComputers(Comp);
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
                cout << "--- Displaying computers by year made in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearBuiltAsc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt > 1)
                    {
                        displaySortedComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers by year made in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearBuiltDesc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt > 1)
                    {
                        displaySortedComputersSpecial(i, Comp);
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
                cout << "--- Displaying computers not made in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearNotBuiltAsc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 0)
                    {
                        displaySortedComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers not made in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearNotBuiltDesc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 0)
                    {
                        displaySortedComputersSpecial(i, Comp);
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
void UI::sortComputerUnkownBuiltMenu()
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
                cout << "--- Displaying computers not made in ascending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearUnknownBuiltAsc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 1)
                    {
                        displaySortedComputersSpecial(i, Comp);
                    }
                }
                backToSortMenu();
                break;
            }
            case 2:
            {
                cout << endl;
                cout << "--- Displaying computers not made in descending order ---" << endl;
                cout << endl;
                vector <CompType> Comp = c.sortByYearUnknownBuiltDesc();
                for (unsigned int i = 0; i < Comp.size(); i++)
                {
                    if(Comp.at(i).wasBuilt == 1)
                    {
                        displaySortedComputersSpecial(i, Comp);
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
                cout << "Enter name: " << endl;
                cin >> nameSearch;
                vector <InfoType> x = p.searchVectorName(nameSearch);
                searchPersDisplay(x, nameSearch);
                x.clear();
                backToSearch();
                break;
            }
            case 2:
            {
                string genderSearch;
                cout << "Enter gender (M for male, F for female or ? for undecided): ";
                cin >> genderSearch;
                vector <InfoType> x = p.searchVectorGender(genderSearch);
                searchPersDisplay(x, genderSearch);
                x.clear();
                backToSearch();
                break;
            }
            case 3:
            {
                string birthYearSearch;
                cout << "Enter year of birth: ";
                cin >> birthYearSearch;
                vector <InfoType> x = p.searchVectorBirthYear(birthYearSearch);
                searchPersDisplay(x, birthYearSearch);
                x.clear();
                backToSearch();
                break;
            }
            case 4:
            {
                string deathYearSearch;
                cout << "Enter death year: ";
                cin >> deathYearSearch;
                vector <InfoType> x = p.searchVectorDeathYear(deathYearSearch);
                searchPersDisplay(x, deathYearSearch);
                x.clear();
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
void UI::searchComputerMenu()
{
    Services p;
    cout << "* * * SEARCH COMPUTER INFORMATION * * *" << endl;
    cout << endl;
    string nameSearch;
    cout << "Enter name: ";
    cin >> nameSearch;
    vector<CompType> x = p.searchVectorComputersName(nameSearch);
    searchCompDisplay(x, nameSearch);
}
//DISPLAY
void UI::displayPerson(InfoType p)
{
    Services c;
    cout << endl;
    string tempName = c.changeName(p);
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
void UI::displaySortedPersons(vector<InfoType> FP)
{
    for (unsigned int i = 0; i < FP.size(); i++)
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
    else if(FP.at(i).gender != '?')
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "| | | There aren't any persons of undecided gender | | |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;
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
}
void UI::displaySortedPersonsSpecial(int i, vector<InfoType> FP)
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
    else if(FP.at(i).gender != '?')
    {
        cout << "------------------------------------------------------------" << endl;
        cout << "| | | There aren't any persons of undecided gender | | |" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;
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
void UI::displayComputer(CompType c)
{
    cout << endl;
    cout << "Computer name: " << c.compName << endl;

        if(c.yearMade == 0)
        {
            cout << "Computer has been designed, year is unknown." << endl;
        }
        else
        {
            cout << "Year designed: " << c.yearMade << endl;
        }

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
void UI::displaySortedComputers(vector<CompType> Comp)
{
    for (unsigned int i = 0; i < Comp.size(); i++)
    {
    cout << endl;
    cout << "Computer name: " << Comp.at(i).compName << endl;
    cout << "Year designed: " << Comp.at(i).yearMade << endl;
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
}
void UI::displaySortedComputersSpecial(int i, vector<CompType> Comp)
{
    cout << endl;
    cout << "Computer name: " << Comp.at(i).compName << endl;
    cout << "Year designed: " << Comp.at(i).yearMade << endl;
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
void UI::searchPersDisplay(vector<InfoType> x, string y){
    if(!x.empty())
    {
        for(unsigned int i =  0; i < x.size(); i++)
        {
            displayPerson(x[i]);
        }
    }
    else
    {
        falseCheck(y);
    }
}
void UI::searchCompDisplay(vector<CompType> x, string y){
    if(!x.empty())
    {
        for(unsigned int i =  0; i < x.size(); i++)
        {
            displayComputer(x[i]);
        }
    }
    else
    {
        falseCheck(y);
    }
}
//ANNAÐ
int UI::chooseNumber()
{
    int choice;
    cout << "Please choose one of these numbers: ";
    cin >> choice;
    cout << "===========================================" << endl;
    cout << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice !=6)
        {
            displayError();
        }
    return choice;
}
void UI::displayError()
{
    cout << "------------------------------------------" << endl;
    cout << "| | | Wrong input. Please try again. | | |" << endl;
    cout << "------------------------------------------" << endl;
}
void UI::falseCheck(string x)
{

    cout << "-------------------------------------------" << endl;
    cout << "   "<< x << " was not in database or input not in the right format" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "--- Please try again. ---" << endl;
    cout << endl;

}
void UI::addRelation()
{
       cout << "Need stuff here" << endl;
}
