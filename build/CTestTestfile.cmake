# CMake generated Testfile for 
# Source directory: /workspaces/evtol_simulation
# Build directory: /workspaces/evtol_simulation/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestEVTOL "/workspaces/evtol_simulation/build/test_evtol")
set_tests_properties(TestEVTOL PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/CMakeLists.txt;28;add_test;/workspaces/evtol_simulation/CMakeLists.txt;0;")
add_test(TestFleetManager "/workspaces/evtol_simulation/build/test_fleetmanager")
set_tests_properties(TestFleetManager PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/CMakeLists.txt;29;add_test;/workspaces/evtol_simulation/CMakeLists.txt;0;")
add_test(TestChargerManager "/workspaces/evtol_simulation/build/test_chargermanager")
set_tests_properties(TestChargerManager PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/CMakeLists.txt;30;add_test;/workspaces/evtol_simulation/CMakeLists.txt;0;")
add_test(TestFaultManager "/workspaces/evtol_simulation/build/test_fault_manager")
set_tests_properties(TestFaultManager PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/CMakeLists.txt;31;add_test;/workspaces/evtol_simulation/CMakeLists.txt;0;")
add_test(TestStatisticsTracker "/workspaces/evtol_simulation/build/test_statisticstracker")
set_tests_properties(TestStatisticsTracker PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/CMakeLists.txt;32;add_test;/workspaces/evtol_simulation/CMakeLists.txt;0;")
