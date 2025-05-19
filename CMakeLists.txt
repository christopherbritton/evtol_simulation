
set(SOURCES
    main.cpp
    EVTOL.cpp
    ChargerManager.cpp
    FaultManager.cpp
    StatisticsTracker.cpp
)

add_executable(evtol_simulation ${SOURCES})
enable_testing()
add_subdirectory(tests)
