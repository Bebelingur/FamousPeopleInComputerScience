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
        cout << "5. Exit" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

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
                exit(1);
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5); //eða while(choice != 5);
    //náði að láta virka aðeins, google to the rescue :)  - BóE
}

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
                p.sortByNameAsc();
                break;
            }
            case 2:
            {
                p.sortByNameDesc();
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
                p.sortByGenderMale();
                break;
            }
            case 2:
            {
                p.sortByGenderFemale();
                break;
             }
            case 3:
            {
                p.sortByGenderUndecided();
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
                p.sortByYearAsc();
                break;
            }
            case 2:
            {
                p.sortByYearDesc();
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
                p.sortByDeathYearAsc();
                break;
             }
             case 2:
             {
                p.sortByDeathYearDesc();
                break;
             }
            case 3:
            {
               p.sortByDeceased();
               break;
            }
            case 4:
            {
               p.sortByNotDeceased();
               break;
            }
             case 5:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}


void UI::searchMenu()
{
    Services p;

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
                searchComputerMenu();
                break;
            case 3:
                //FP.clear();//hreinsum vektorinn eftir notkun
                userMenu();
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3); //eða while(choice != 5);
}

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
                p.searchVectorName();
                break;
            case 2:
                p.searchVectorGender();
                break;
            case 3:
                p.searchVectorBirthYear();
                break;
            case 4:
                p.searchVectorBirthYear();
                break;
            case 5:
                //FP.clear();//hreinsum vektorinn eftir notkun
                userMenu();
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5); //eða while(choice != 5);
}


//á eftir að græja search föllin fyrir computers
void UI::searchComputerMenu()
{
    Services p;

    int choice;

    do{
        cout << "* * * SEARCH COMPUTER INFORMATION * * *" << endl;
        cout << endl;
        cout << "1. Search by name" << endl;
        cout << "2. Search by year made" << endl;
        cout << "3. Search by type" << endl;
        cout << "4. Search by was built" << endl;
        cout << "5. Return to main menu" << endl;
        cout << "===========================================" << endl;

        do{
            choice = chooseNumber();
        }while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        switch(choice)
        {
            case 1:
                p.searchVectorName();
                break;
            case 2:
                p.searchVectorGender();
                break;
            case 3:
                p.searchVectorBirthYear();
                break;
            case 4:
                p.searchVectorBirthYear();
                break;
            case 5:
                //FP.clear();//hreinsum vektorinn eftir notkun
                userMenu();
                break;
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5); //eða while(choice != 5);
}

int UI::chooseNumber()
{
    int choice;
    cout << "Please choose one of these numbers: ";
    cin >> choice;
    cout << "===========================================" << endl;
    cout << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');
        if(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
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

    do{
        cout << "Input year designed (input 0 for unknown): ";
        cin >> computerYearMade;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        if(computerYearMade == 0)
        {
            computerYearMade = 0;
        }
        if(!(((computerYearMade <= yearNow)) && (computerYearMade >= CstartYear) && (computerYearMade == 0)))
            {
                displayError();
            }

    }while(!(((computerYearMade <= yearNow)) && (computerYearMade >= CstartYear) && (computerYearMade == 0)));

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
    int built = 0;
    char choice = ' ';
    do{
        cout << "Was the computer ever built? (Y for yes/N for no/? if unknown): ";
        cin >> choice;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
            if(toupper(choice) != 'Y' && toupper(choice) != 'N' && choice != '?')
            {
               displayError();
            }

        if(toupper(choice) == 'Y')
            {
                do{
                    cout << "What year was the computer built?: ";
                    cin >> built;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                        if(!((built < yearNow) && (built >= computerYearMade)))
                        {
                            displayError();
                        }
                    }while(!((built < yearNow) && (built >= computerYearMade)));
                }
            if(toupper(choice) == 'N')
            {
                //ef hún var aldrei byggð(var bara til á pappírum/theoretical) þá fær hún gildið 0
                built = 0;
            }
            if(choice == '?')
            {
                //ef ekki er vitað hvenær hún var byggð(sett saman og hún virkaði) þá fær hún gildið 1
                built = 1;
            }

    }while(toupper(choice) != 'Y' && toupper(choice) != 'N' && choice != '?');

    return built;
}
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
    userMenu();
}

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
            p.viewPersonsInfo();
                break;
            }
            case 2:
            {
            p.viewComputerInfo();
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
            sortComputerBuiltMenu();
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
                //c.sortByComputerNameAsc();
                break;
            }
            case 2:
            {
                //c.sortByComputerNameDesc();
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
                //c.sortByYearMadeAsc();
                break;
            }
            case 2:
            {
                //c.sortByYearMadeDesc();
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
                //c.sortByComputerTypeAsc();
                break;
            }
            case 2:
            {
                //c.sortByComputerTypeDesc();
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

void UI::sortComputerBuiltMenu()
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
                //c.sortByBuilt();
                break;
            }
            case 2:
            {
                //c.sortByNotBuilt();
                break;
             }
            case 3:
            {
                //c.sortByBuiltUnknown();
                break;
             }
             case 4:
             {
                sortMenu();
             }
        }
    }while(choice == 1 || choice == 2 || choice == 3 || choice == 4);
}

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
