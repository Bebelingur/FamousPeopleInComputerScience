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

using namespace std;

class data{

public:
    data();
    void connectionToDatabase();

    vector<InfoType> loadPersData();
    vector<CompType> loadCompData();

    void saveDataRelations(RelationsType p);
    void saveDataPersons(InfoType p);
    void saveDataComputers(CompType p);

private:
    string personFilename, computerFilename;
};

#endif // DATA
