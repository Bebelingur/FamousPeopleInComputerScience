#ifndef INFOTYPE
#define INFOTYPE
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <data.h>
#include <services.h>
#include <QtSql>
#include <QtDebug>

using namespace std;

struct InfoType
{
    string name;
    char gender;
    int birthYear;
    int deathYear;
};

#endif // INFOTYPE

