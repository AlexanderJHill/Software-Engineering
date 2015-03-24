#ifndef _USERSETTINGS_H_
#define _USERSETTINGS_H_

class UserSettings{
public:

      UserSettings();
      int getfisherNum();
      int getfishLoc();
      int getfishType();
      int getfishPop();
      int getfishTemp();
      int getRuntime();
           
protected:

        int fisherNum;
        int fishLoc;
        int fishType;
        int fishPop;
        int fishTemp; // overcast, snow, rain
        int runtime;

};

#endif
