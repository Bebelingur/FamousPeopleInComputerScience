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
    void sortMenu();
    void sortNameMenu();
    void sortGenderMenu();
    void sortYearOfBirthMenu();
    void sortYearOfDeathMenu();
    void searchMenu();
    int chooseNumber();
    void displayError();
    void getInfo();
    string getName();
    char getGender();
    int getBirthYear();
    int getDeathYear(string name, int bYear);
    void getComputerInfo();
    void searchPersonMenu();
    void searchComputerMenu();

};

#endif // UI_H
