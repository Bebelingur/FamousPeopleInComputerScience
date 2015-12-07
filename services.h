#ifndef SERVICES_H
#define SERVICES_H

#include "ui.h"
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include "data.h"
#include "infotype.h"
#include "comptype.h"
#include "relationstype.h"

#include <string>


using namespace std;

class Services
{
public:
    Services();

    void addPerson(string name, char gender, int bYear, int dYear);
    void addComputer(string compName, int yearMade, string type, int wasBuilt);
<<<<<<< HEAD
=======
    //tekur skjalið og setur inn í vektor
    vector<InfoType> viewPersonsInfo();
    string changeName(InfoType p);
    void sortByNameAsc();
    void sortByNameDesc();
    void sortByYearAsc();
    void sortByYearDesc();
    void sortByGenderMale();
    void sortByGenderFemale();
    void sortByGenderUndecided();
    void sortByDeathYearAsc();
    void sortByDeathYearDesc();
    void displaySortedPerson(vector<InfoType> FP);
    void sortByDeceased();
    void sortByNotDeceased();
>>>>>>> b71754ea35aee13a3c86ad894cffe754e1435e57

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

<<<<<<< HEAD
=======


>>>>>>> b71754ea35aee13a3c86ad894cffe754e1435e57
private:
    vector <InfoType> FP;
    vector <CompType> Comp;
    vector <RelationsType> Rel;
    data connection;
};

#endif // SERVICES_H
