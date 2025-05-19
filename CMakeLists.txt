cmake_minimum_required(VERSION 3.10)
project(EVTOLSimulation)

set(CMAKE_CXX_STANDARD 17)

# Add all source files
set(SOURCES
    main.cpp
    EVTOL.cpp
    ChargerManager.cpp
    FaultManager.cpp
    StatisticsTracker.cpp
)

# Add all header files (optional but good for IDEs)
set(HEADERS
    EVTOL.hpp
    ChargerManager.hpp
    FaultManager.hpp
    StatisticsTracker.hpp
)

add_executable(main ${SOURCES} ${HEADERS})