#include "UserSettings.h"

// UserSettings made by
// Vincent Vindel Dura

UserSettings::UserSettings()
{
   fisherNum = 0;
   fishLoc = 0;
   fishType = 0;
   fishPop = 0;
   fishTemp = 0; // overcast(1), rain(2), snow(3)
   runtime = 0;
}

int UserSettings::getfisherNum(){
    return fisherNum;
}

int UserSettings::getfishLoc(){
    return fishLoc;
}

int UserSettings::getfishType(){
    return fishType;
}

int UserSettings::getfishPop(){
    return fishPop;
}

int UserSettings::getfishTemp(){
    return fishTemp;
}

int UserSettings::getRuntime(){
    return runtime;
}
