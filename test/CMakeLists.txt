configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googletest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/googletest-download" )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_CURRENT_BINARY_DIR}/googletest-src"
        "${CMAKE_CURRENT_BINARY_DIR}/googletest-build")

if(CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
        "${gmock_SOURCE_DIR}/include")
endif()

enable_testing()

## Add your test .cpp file here


add_executable(run_tests
    models/modelsTest.cpp
    gameManager/idTest.cpp
        NetworkingTests/UserServiceManagementTest.cpp
    NetworkingTests/ConsoleCommandTests.cpp
    NetworkingTests/ServerTests.cpp
    databaseTest/DatabaseTest.cpp
    controllersTest/GameControllerTest.cpp
        models/areaTests.cpp
        inventory/inventoryTest.cpp
        models/roomTest.cpp
  )


target_link_libraries(run_tests gmock gtest gtest_main)

set_target_properties(run_tests
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        PREFIX ""
        )

##TO DO: Add Lib Here
target_link_libraries(run_tests networking models cusjson Combat controllers database inventory)
add_test(NAME network_tests COMMAND run_tests)