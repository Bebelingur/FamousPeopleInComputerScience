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

    void addRelation(int personId, int computerId);
    void addPerson(string name, char gender, int bYear, int dYear);
    // setti upp eins fall og addPerson nema bara fyrir tölvurnar
    // spurning um að bæta við vector (gerði vector<CompType> Comp) til að halda utan um tölvurnar
    void addComputer(string compName, int yearMade, string type, int wasBuilt);
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


    void makeRelation();
    void viewRelationPerson();
    void viewRelationComputer();

    void displaySorted(int i, vector<InfoType> FP);
    void backToSortMenu();



    void searchVector();
    //leitar í vektornum úr skjalinu
    void searchVectorName();
    void searchVectorGender();
    void searchVectorBirthYear();
    void searchVectorDeathYear();
    void backToSearchMenu();
    void viewComputerInfo();

    void searchVectorComputersName();
    vector<CompType> makeComputerVector();
    vector<InfoType> makePersonsVector();

    void displaySortedComputer(vector <CompType> Comp);
    void displaySortedComp(int i, vector<CompType> Comp);
    void sortByComputerNameAsc();
    void sortByComputerNameDesc();
    void sortByYearMadeAsc();
    void sortByYearMadeDesc();
    void sortByComputerTypeAsc();
    void sortByComputerTypeDesc();
    void sortByYearBuiltAsc();
    void sortByYearBuiltDesc();
    void sortByYearNotBuiltAsc();
    void sortByYearNotBuiltDesc();
    void sortByYearUnknownBuiltAsc();
    void sortByYearUnknownBuiltDesc();


    void returnToView();



private:
    vector <InfoType> FP;
    vector <CompType> Comp;
    vector <RelationsType> Rel;
    data connection;
    //UI uiconnection;
};

#endif // SERVICES_H
