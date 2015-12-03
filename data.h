#ifndef DATA
#define DATA
#include <fstream>
#include <vector>
#include <iostream>
#include <QtSql>
#include <QtDebug>

using namespace std;

class data {

public:
    data();
    void loadData();
    void saveData();
};

#endif // DATA
