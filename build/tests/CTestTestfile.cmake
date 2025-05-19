# CMake generated Testfile for 
# Source directory: /workspaces/evtol_simulation/tests
# Build directory: /workspaces/evtol_simulation/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestEVTOL "/workspaces/evtol_simulation/build/tests/test_evtol")
set_tests_properties(TestEVTOL PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/tests/CMakeLists.txt;6;add_test;/workspaces/evtol_simulation/tests/CMakeLists.txt;0;")
add_test(TestFaultManager "/workspaces/evtol_simulation/build/tests/test_fault_manager")
set_tests_properties(TestFaultManager PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/tests/CMakeLists.txt;7;add_test;/workspaces/evtol_simulation/tests/CMakeLists.txt;0;")
add_test(TestStatisticsTracker "/workspaces/evtol_simulation/build/tests/test_statistics_tracker")
set_tests_properties(TestStatisticsTracker PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/tests/CMakeLists.txt;8;add_test;/workspaces/evtol_simulation/tests/CMakeLists.txt;0;")
add_test(TestChargerManager "/workspaces/evtol_simulation/build/tests/test_charger_manager")
set_tests_properties(TestChargerManager PROPERTIES  _BACKTRACE_TRIPLES "/workspaces/evtol_simulation/tests/CMakeLists.txt;9;add_test;/workspaces/evtol_simulation/tests/CMakeLists.txt;0;")
