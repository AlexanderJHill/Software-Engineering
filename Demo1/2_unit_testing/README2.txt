Running the unit tests (Windows):

1. Download and install Qt (version 5.4 was used).
http://www.qt.io/download/

2. Edit the Windows PATH Environment Variables.

Control Panel -> System -> Advanced system settings -> Environment Variables -> edit PATH variable

Add the location of Qt's dlls for example C:\Qt\5.4\msvc2013_64\bin

3. Run a Visual Studio command prompt (for example 'VS2013 x64 Native Tools Command Prompt') as administrator.

4. Navigate to the unit test directory.

5. Input these commands:
qmake -project "QT += testlib widgets"
qmake
nmake
cd release
2_unit_testing.exe