#ifndef COMPTYPE
#define COMPTYPE
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <data.h>


using namespace std;

struct CompType
{
    string compName;
    int yearMade;
    string type; //eða strengur ef við viljum að notandinn skrifi sjálfur type
    char wasBuilt;
};

#endif // COMPTYPE

