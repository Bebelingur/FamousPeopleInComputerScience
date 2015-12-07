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
<<<<<<< HEAD
    //ADD FÖLLIN
    void addPerson(string name, char gender, int bYear, int dYear);
    void addComputer(string compName, int yearMade, string type, int wasBuilt);
    //MAKE FÖLLIN
=======


    void addRelation(int personId, int computerId);

    void addPerson(string name, char gender, int bYear, int dYear);
    void addComputer(string compName, int yearMade, string type, int wasBuilt);
    void displaySortedPerson(vector<InfoType> FP);

    void makeRelation();
    void viewRelationPerson();
    void viewRelationComputer();

    void displaySorted(int i, vector<InfoType> FP);
    void backToSortMenu();
    void searchVector();


    vector<CompType> makeComputerVector();
>>>>>>> 5d58c9cace096a468f4091eb9d2ea5286109c777
    vector<InfoType> makePersonsVector();
    vector<CompType> makeComputerVector();
    //VIEW FÖLLIN
    vector<InfoType> viewPersonsInfo();
    vector<CompType> viewComputerInfo();
    //SORT PERSONS FÖLLIN
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
    //SORT COMPUTER FÖLLIN
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
    //SEARCH PERSONS FÖLLIN
    vector<InfoType> searchVectorName(string nameSearch);
    vector<InfoType> searchVectorGender(string genderSearch);
    vector<InfoType> searchVectorBirthYear(string birthYearSearch);
    vector<InfoType> searchVectorDeathYear(string deathYearSearch);
    //SEARCH COMPUTERS FÖLLIN
    vector<CompType> searchVectorComputersName(string);
    //RELATION FÖLLIN
    void viewRelationComputer();
    void viewRelationPerson();
    void addRelation(int personId, int computerId);
    void makeRelation();
    //ANNAÐ
    string changeName(InfoType p);

private:
    vector <InfoType> FP;
    vector <CompType> Comp;
    vector <RelationsType> Rel;
    data connection;
};

#endif // SERVICES_H
