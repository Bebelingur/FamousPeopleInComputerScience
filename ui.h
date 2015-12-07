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
    void inputMenu();
    void viewInfoMenu();
    void relationMenu();

    void displaySortedPersons(vector<InfoType> FP);
    void displaySortedPersonsSpecial(int i, vector<InfoType> FP);
    void sortMenu();
    void sortNameMenu();
    void sortGenderMenu();
    void sortYearOfBirthMenu();
    void sortYearOfDeathMenu();

    void searchMenu();
    int chooseNumber();
    void displayError();
    void getPersonInfo();
    string getName();
    char getGender();
    int getBirthYear();
    int getDeathYear(string name, int bYear);
    void getComputerInfo();
    string getComputerType();
    int getYearMade();
    int getWasBuilt(int computerYearMade);
    string getComputerName();
    void searchPersonMenu();

    void displaySortedComputers(vector<CompType> Comp);
    void displaySortedComputersSpecial(int i, vector<CompType> Comp);
    void sortComputerNameMenu();
    void sortComputerYearMadeMenu();
    void sortComputerTypeMenu();
    void sortComputerWasBuiltMenu();
    void sortComputerMenu();
    void sortPersonMenu();
    void displayPerson(InfoType p);
    void displayComputer(CompType c);

    void falseCheck(string nameSearch);

    void sortComputerBuiltMenu();
    void sortComputerYearBuiltMenu();
    void sortComputerNotBuiltMenu();
    void sortComputerUnkownBuiltMenu();
    void backToSortMenu();

    void backToSearch();
    void backToView();
    void searchPersDisplay(vector<InfoType> x, string y);
    void searchCompDisplay(vector<CompType> x, string y);
    void searchComputerMenu();
};

#endif // UI_H
