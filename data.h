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
<<<<<<< HEAD
    void saveData();
=======
    void saveData(InfoType p);
>>>>>>> 03e45536cb3700040580ebe4d6c765866349cdbb
private:
    string personFilename, computerFilename;
};

#endif // DATA
