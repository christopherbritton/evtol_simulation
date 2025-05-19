add_executable(test_evtol test_evtol.cpp ../EVTOL.cpp)
add_executable(test_fault_manager test_fault_manager.cpp ../FaultManager.cpp)
add_executable(test_statistics_tracker test_statistics_tracker.cpp ../StatisticsTracker.cpp ../EVTOL.cpp)
add_executable(test_charger_manager test_charger_manager.cpp ../ChargerManager.cpp ../EVTOL.cpp)

add_test(NAME TestEVTOL COMMAND test_evtol)
add_test(NAME TestFaultManager COMMAND test_fault_manager)
add_test(NAME TestStatisticsTracker COMMAND test_statistics_tracker)
add_test(NAME TestChargerManager COMMAND test_charger_manager)
