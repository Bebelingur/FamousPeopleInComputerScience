#ifndef UI_H
#define UI_H
#include <QtSql>
#include <QtDebug>

class UI
{
public:
    UI();

    void userMenu();

    void sortMenu();

    void sortNameMenu();

    void sortGenderMenu();

    void sortYearOfBirthMenu();

    void sortYearOfDeathMenu();

    void searchMenu();


    int chooseNumber();
    void displayError();
};

#endif // UI_H
