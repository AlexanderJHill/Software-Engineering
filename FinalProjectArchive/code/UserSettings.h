#ifndef _USERSETTINGS_H_
#define _USERSETTINGS_H_
//! \file usersettings.h 
//! \brief contains the users global simulation parameters.


//! \brief contains the users global simulation parameters.
class UserSettings{
public:

      UserSettings();
      int getfisherNum();   /*!< Returns the number of Fishers to use in the simulation*/
      int getfishLoc();     /*!< Returns the number of different locations */
      int getfishType();    /*!< Returns the number of fish types.*/
      int getfishPop();     /*!< Returns the inital population of fish when the simulation starts. */
      int getfishTemp();    /*!< Returns the conditions: overcast, snow, rain. */
      int getRuntime();     /*!< Returns the number of days to run the simulation. */
           
protected:

        int fisherNum;  /*!< The number of Fishers to use in the simulation*/
        int fishLoc;    /*!< The number of different locations */
        int fishType;   /*!< The number of fish types. */
        int fishPop;    /*!< The inital population of fish when the simulation starts. */
        int fishTemp;   /*!< The conditions: overcast, snow, rain */
        int runtime;    /*!< The number of days to run the simulation */

};

#endif
