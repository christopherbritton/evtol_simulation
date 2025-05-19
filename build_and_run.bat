@echo off
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make
if exist main.exe (
    echo Build complete.
    main.exe
) else (
    echo Executable not found: main.exe
)
pause
