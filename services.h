#ifndef SERVICES_H
#define SERVICES_H
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include "data.h"
#include "infotype.h"
#include "comptype.h"
#include "relationstype.h"
#include <string>
#include "ui.h"

using namespace std;

class Services
{
public:
    Services();

    void addPerson(string name, char gender, int bYear, int dYear);
    void addComputer(string compName, int yearMade, string type, int wasBuilt);

    void viewPersonsInfo();

    string changeName(InfoType p);

    vector <InfoType> sortByNameAsc();
    vector <InfoType> sortByNameDesc();
    vector <InfoType> sortByYearAsc();
    vector <InfoType> sortByYearDesc();
    vector <InfoType> sortByGenderMale();
    vector <InfoType> sortByGenderFemale();
    vector <InfoType> sortByGenderUndecided();
    vector <InfoType> sortByDeathYearAsc();
    vector <InfoType> sortByDeathYearDesc();
    vector <InfoType> sortByDeceased();
    vector <InfoType> sortByNotDeceased();

    void searchVector();
    void searchVectorName();
    void searchVectorGender();
    void searchVectorBirthYear();
    void searchVectorDeathYear();
    void backToSearchMenu();
    void viewComputerInfo();
    void searchVectorComputersName();
    vector<CompType> makeComputerVector();
    vector<InfoType> makePersonsVector();

    vector <CompType> sortByComputerNameAsc();
    vector <CompType> sortByComputerNameDesc();
    vector <CompType> sortByYearMadeAsc();
    vector <CompType> sortByYearMadeDesc();
    vector <CompType> sortByComputerTypeAsc();
    vector <CompType> sortByComputerTypeDesc();
    vector <CompType> sortByYearBuiltAsc();
    vector <CompType> sortByYearBuiltDesc();
    vector <CompType> sortByYearNotBuiltAsc();
    vector <CompType> sortByYearNotBuiltDesc();
    vector <CompType> sortByYearUnknownBuiltAsc();
    vector <CompType> sortByYearUnknownBuiltDesc();

    void returnToView();

private:
    vector <InfoType> FP;
    vector <CompType> Comp;
    vector <RelationsType> Rel;
    data connection;
};

#endif // SERVICES_H
