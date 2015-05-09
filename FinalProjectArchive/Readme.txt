###################################################
## Rutgers University Software Engineering Project
##
##	Group 12

## The current code can be built using QT Creator.
## Qt creator can be downloaded from https://www.qt.io/download-open-source/ 
## it will also need a suitable compiler already your system.

Folder descriptions:

	/code -- Contains the Qt project file and project code.
	/docs -- Contains user and technical documentation as well as the reports and demo presentations. Also includes the marketing brochure.
	/tests -- Contains the integration and unit tests as well as instructions on how to run them.
	/Fisher Sim (standalone version) -- Contains a runnable version of the program.

How to use:

Run 'CrowdAnalysys.exe' in the Fisher Sim (standalone version) folder.
If any error messages appear, install the C++ redistributables
'vcredist_x64.exe' in the same folder, restart your machine and
try again. The standalone version runs only on Windows.

The code can be built using Qt Creator.
 Qt can be downloaded from https://www.qt.io/download-open-source/. You also need a suitable compiler already on your system.

Open 'FisherSim.pro', then build and run the project. Modify the auto generated ui_graphview.h file and replace
#include "../../qcustomplot.h"
with
#include "qcustomplot.h"


Documentation:
	Technical documentation is maintained through Doxygen.
	with the help of: Graphviz (download from http://www.graphviz.org/pub/graphviz/stable/windows/graphviz-2.30.1.msi)


Updating the project documentation requires Doxygen and Graphviz to be installed on the system.


		

to update the documentation, load the main project doxgen configuration file located in ./CrowdAnalysys/Doxyfile


