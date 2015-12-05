#ifndef DATA
#define DATA
#include <fstream>
#include <vector>
#include <iostream>
#include <QtSql>
#include <QtDebug>
#include <QtCore>
#include "infotype.h"
#include "comptype.h"
#include <QCoreApplication>
#include <QDebug>
#include <string>

using namespace std;

class data {

public:
    data();

    vector<InfoType> loadData();

    void saveDataPersons(InfoType p);

    void saveDataComputers(CompType p);

    char convertToChar(string a);

    string convertToString(char a);

    void connectToDatabase(string filename);

private:
    string personFilename, computerFilename;
};

#endif // DATA
