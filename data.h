#ifndef DATA
#define DATA
#include <fstream>
#include <vector>
#include <iostream>
#include <QtSql>
#include <QtDebug>
#include <QtCore>
#include "infotype.h"

using namespace std;

class data {

public:
    data();
    vector<InfoType> loadData();
    void saveData(vector<InfoType> p);
private:
    string personFilename, computerFilename;
};

#endif // DATA
