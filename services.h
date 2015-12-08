#ifndef SERVICES_H
#define SERVICES_H
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <string>
#include <ctime>
#include "data.h"
#include "infotype.h"
#include "comptype.h"
#include "relationstype.h"
#include "ui.h"

using namespace std;

class Services{

public:
    Services();
    //ADD FUNCTIONS
    void addPerson(string name, char gender, int bYear, int dYear);
    void addComputer(string compName, int yearMade, string type, int wasBuilt);
    void addRelation(int personId, int computerId);

    //MAKE FUNCTIONS
    vector<InfoType> makePersonsVector();
    vector<CompType> makeComputerVector();
    void makeRelation();

    //VIEW FUNCTIONS
    vector<InfoType> viewPersonsInfo();
    vector<CompType> viewComputerInfo();
    vector<CompType> viewRelationPerson(int ID);
    vector<InfoType> viewRelationComputer(int ID);

    //SORT PERSONS FUNCTIONS
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

    //SORT COMPUTER FUNCTIONS
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

    //SEARCH PERSONS FUNCTIONS
    vector<InfoType> searchVectorName(string nameSearch);
    vector<InfoType> searchVectorGender(string genderSearch);
    vector<InfoType> searchVectorBirthYear(string birthYearSearch);
    vector<InfoType> searchVectorDeathYear(string deathYearSearch);

    //SEARCH COMPUTERS FUNCTIONS
    vector<CompType> searchVectorComputersName(string name);

    //REMOVE FUNCTIONS
    vector<InfoType> findPerson(int ID);
    vector<CompType> findComputer(int ID);
    void removePerson(int ID);
    void removeComputer(int ID);

    //OTHER
    string changeName(string tempName);
    char convertToChar(string a);
    string convertToString(char a);
    int findIDPerson(string name);
    int findIDComputer(string name);

private:
    vector <InfoType> FP;
    vector <CompType> Comp;
    vector <RelationsType> Rel;
    data connection;
};

#endif // SERVICES_H
