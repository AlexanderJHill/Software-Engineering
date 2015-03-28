@echo off
TITLE Update Latex Documentation

REM refference http://www.robvanderwoude.com/batchcommands.php

echo Running latex...
call ./latex/make.bat > NUL 2>&1
Echo Done...
echo Copying the new documentation file to Fisher_Sim_Technical_Documentation.pdf
COPY ".\latex\refman.pdf" ".\Fisher_Sim_Technical_Documentation.pdf" > NUL
pause