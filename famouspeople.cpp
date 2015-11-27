#include "famouspeople.h"

FamousPeople::FamousPeople()
{

}
void FamousPeople::userMenu()
{
    char choice;
    do{

    cout << "===========================================" << endl;
    cout << "==== Famous People In Computer Science ====" << endl;
    cout << "===========================================" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Input information" << endl;
    //Berglind, eftir getline þá stjarna
    cout << "2. View information" << endl;
    //Dagur
    cout << "3. Sort information" << endl;
    //Hjálmar og Kristófer
    cout << "4. Search information" << endl;
    //Drífa
    cout << "5. Exit" << endl;


    cout << "Please choose one of these numbers: ";
    cin >> choice;
    cout << endl;

        switch(choice)
        {
            case '1':
                getInfo();
                break;
            case '2':
                cout << "2" << endl;
                break;
            case '3':
                cout << "3" << endl;
                break;
            case '4':
                cout << "4" << endl;
                break;
            case '5':
                cout << "5" << endl;
                break;
            default:
                cout << "Wrong input! Please try again" << endl;
                break;
        }
    }while(choice != '5');
}

void FamousPeople::getInfo()
{
    ofstream getFile;
    getFile.open("InfoFile.txt");
    if(!getFile)
    {
        cout << "File did not open" << endl;
    }
    else
    {
        char keepOn;
        do{
            cout << "Input name: ";
            cout << endl;
            cout << "Input gender (F for female, M for male or ? for other): ";
            cout << endl;
            cout << "Input birthYear: ";
            cout << endl;
            cout << "Input deathYear: ";
            cout << endl;
            cout << "Input more information (Y for yes N for no): ";
            cin >> keepOn;
            cout << endl;
        }while(keepOn == 'Y' || keepOn == 'y');
    }
    getFile.close();
}


