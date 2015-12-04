#ifndef DATA
#define DATA
#include <fstream>
#include <vector>
#include <iostream>
#include <QtSql>
#include <QtDebug>
#include <QtCore>
#include "infotype.h"
#include <QCoreApplication>
#include <QDebug>


using namespace std;

class data {

public:
    data();
    vector<InfoType> loadData();
    void saveData(InfoType p);
    char convertToChar(QChar a);
private:
    string personFilename, computerFilename;
};

#endif // DATA
