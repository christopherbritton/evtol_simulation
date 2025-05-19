@echo off
setlocal

:: Set compiler and tool paths (optional override for Windows users)
:: set PATH=C:\MinGW\bin;%PATH%

:: Create build directory
if not exist build mkdir build
cd build

:: Generate build files with CMake
cmake -G "MinGW Makefiles" ..

:: Compile the simulation
mingw32-make

:: Run the simulation if the build succeeded
if exist evtol_simulation.exe (
    echo Running EVTOL Simulation...
    evtol_simulation.exe
) else (
    echo Build failed. Executable not found.
)

pause
endlocal
