@ECHO OFF

SETLOCAL

SET LIB_HOME=%userprofile%\Documents\Arduino\libraries
SET LIB_NAMES=BatReader EnableInterrupt LedMatrix Oscillator Otto OttoSerialCommand US

ECHO This script is for use with the Microsoft Windows 10 operating systems.  It may work on other versions of Windows.
ECHO This script performs two steps:
ECHO Step 1: Deletes any existing Otto libraries from %LIB_HOME%\
ECHO Step 2: Copies Otto libraries from %cd% to %LIB_HOME%\
ECHO --

ECHO The following directories will be deleted:
(for /D %%a in (%LIB_NAMES%) do (
ECHO %LIB_HOME%\%%a
))
ECHO Nothing deleted, yet.
ECHO Press Ctrl+C to Cancel
@PAUSE

(for /D %%a in (%LIB_NAMES%) do (
ECHO Deleting %LIB_HOME%\%%a
RMDIR /S /Q %LIB_HOME%\%%a
))

ECHO --
ECHO Completed deleting.  Press any key to copy Otto libraries from %cd% to %LIB_HOME%\
ECHO Press Ctrl+C to Cancel
@PAUSE

ECHO Copying...
(for /D %%a in (%LIB_NAMES%) do (
xcopy /E /I %%a %LIB_HOME%\%%a
))
ECHO Completed copying.

ENDLOCAL
@PAUSE
