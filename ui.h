#ifndef UI_H
#define UI_H
#include <QtSql>
#include <QtDebug>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "services.h"
#include "infotype.h"
#include "relationstype.h"
#include "comptype.h"

using namespace std;

class UI
{
public:
    UI();
    void userMenu();
    //INPUT
    void inputMenu();
    //PERSON INFO INPUT
    void getPersonInfo();
    string getName();
    char getGender();
    int getBirthYear();
    int getDeathYear(string name, int bYear);
    //COMPUTER INFO INPUT
    void getComputerInfo();
    string getComputerName();
    int getYearMade();
    string getComputerType();
    int getWasBuilt(int computerYearMade);
    //VIEW
    void viewInfoMenu();
    void viewStatistics();
    void backToView();
    //SORT
    void sortMenu();
    void backToSortMenu();
    //SORT PERSONS
    void sortPersonMenu();
    void sortNameMenu();
    void sortGenderMenu();
    void sortYearOfBirthMenu();
    void sortYearOfDeathMenu();
    //SORT COMPUTERS
    void sortComputerMenu();
    void sortComputerNameMenu();
    void sortComputerYearMadeMenu();
    void sortComputerTypeMenu();
    void sortComputerWasBuiltMenu();
    void sortComputerYearBuiltMenu();
    void sortComputerNotBuiltMenu();
    void sortComputerUnkownBuiltMenu();
    //SEARCH
    void searchMenu();
    void backToSearch();
    //SEARCH PERSONS
    void searchPersonMenu();
    //SEARCH COMPUTERS
    void searchComputerMenu();
    //RELATION INFO INPUT
    void relationMenu();
    void backToRelation();
    //REMOVE
    void removeMenu();
    void returnToRemove();
    void askToRemove(string name, int ID, char check);
    //DISPLAY
    void displayPersons(vector<InfoType> FP);
    void displayPersonsSpecial(int i, vector<InfoType> FP);
    void displayComputers(vector<CompType> Comp);
    void displayComputersSpecial(int i, vector<CompType> Comp);
    void searchPersDisplay(vector<InfoType> FP, string y);
    void searchCompDisplay(vector<CompType> Comp, string y);
    //OTHER
    bool checkDatabaseEmpty(vector<InfoType> FP, vector<CompType> C);
    int chooseNumber();
    void displayError();
    bool continueOption();
    void falseCheck(string nameSearch);
    void databaseCheckComputers(vector<CompType> Comp);
    void databaseCheckPersons(vector<InfoType> FP);
    bool duplicateCheckPersons(string name, char gender, int bYear, int dYear);
    bool duplicateCheckComputers(string computerName, int computerYearMade, string computerType, int wasBuilt);
};

#endif // UI_H
