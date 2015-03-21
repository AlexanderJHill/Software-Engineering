  #ifndef _USERSETTINGS_H_
#define _USERSETTINGS_H_

#include <iostream>
#include <string>
using namespace std;

class UserSettings{
public:
      UserSettings();
      UserSettings(string NU, int FN, int L, int FT, int FP, int W, ); // FN: fisher number, L: FishLoc, FT: fishtype, FP: fishpop, W: weather
      ~UserSettings(){};
      void putnameUser(string NU); 
      void putfisherNum(int FN);
      void putfishLoc(int L);
      void putfishType(int FT);
      void putfishPop(int FP);
      void putfishTemp(int W);    
           
protected:
        string nameUser;
        int fisherNum;
        int fishLoc;
        int fishType;
        int fishPop;
        int fishTemp; // overcast, snow, rain
        
};

#endif
