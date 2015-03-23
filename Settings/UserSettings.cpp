#include "UserSettings.h"
using namespace std;



UserSettings::UserSettings()
{
   string nameUser = "";
   fisherNum = 0;
   fishLoc = 0;
   fishType = 0;
   fishPop = 0;
   fishTemp = 0; // overcast(1), rain(2), snow(3)
               
}

UserSettings::UserSettings(string NU, int FN, int L, int FT, int FP, int W, )
{
  string nameUser = NU;  
  fisherNum = FN;
  fishLoc = L;
  fishType = FT;
  fishPop = FP;
  fishTemp = W; // overcast(1), rain(2), snow(3)
              
}

void UserSettings::putnameUser(string NU)
{
  nameUser = NU;
}
void UserSettings::putfisherNum(int FN)
{
  fisherNum = FN;
}
void UserSettings::putfishLoc(int L)
{
  fishLoc = L;
}
void UserSettings::putfishType(int FT)
{
  fishType = FT;
}
void UserSettings::putfishPop(int FP)
{
  fishPop = FP;
}
void UserSettings::putfishTemp(int W
{
  fishTemp = W;
}
