#ifndef UI_H
#define UI_H
#include <QtSql>
#include <QtDebug>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <QtSql>
#include <QtDebug>
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
    //RELATION INFO INPUT
    void relationMenu();
    //VIEW
    void viewInfoMenu();
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
    void sortComputerBuiltMenu();
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
    //DISPLAY
    void displayPerson(InfoType p);
    void displaySortedPersons(vector<InfoType> FP);
    void displaySortedPersonsSpecial(int i, vector<InfoType> FP);
    void displayComputer(CompType c);
    void displaySortedComputers(vector<CompType> Comp);
    void displaySortedComputersSpecial(int i, vector<CompType> Comp);
    void searchPersDisplay(vector<InfoType> x, string y);
    void searchCompDisplay(vector<CompType> x, string y);
    //ANNAÐ
    int chooseNumber();
    void displayError();
    void falseCheck(string nameSearch);
};

#endif // UI_H
