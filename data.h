#ifndef DATA
#define DATA
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <QtSql>
#include <QtDebug>
#include <QtCore>
#include <QCoreApplication>
#include "infotype.h"
#include "comptype.h"
#include "relationstype.h"
#include "services.h"

using namespace std;

class data{

public:
    data();
    //CONNECTION
    void connectionToDatabase();
    //VECTOR INPUT TO DATABASE
    vector<InfoType> loadPersData();
    vector<CompType> loadCompData();
    //VECTOR OUTPUT TO DATABASE
    void saveDataRelations(RelationsType p);
    void saveDataPersons(InfoType p);
    void saveDataComputers(CompType p);
    char convertToChar(string a);
    string convertToString(char a);
    bool getMakeRelation(int compID, int persID);
    int getFindIDPerson(string persName, vector<string> &names);
    int getFindIDComputer(string compName, vector<string>&names);
private:
    string personFilename, computerFilename;
};

#endif // DATA
