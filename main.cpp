#include "data.h"
#include "ui.h"

using namespace std;

int main()
{
   data connect;
   connect.connectionToDatabase();

   UI people;
   people.userMenu();

   return 0;
}
