add_library(database
        src/DBUtil.cpp
        src/SqlStatements.cpp
        )

#find_library(SQLITE3_LIBRARY NAMES sqlite3)

target_include_directories(database
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${SQLITE3_INCLUDE_DIRS}
        )
target_link_libraries(database
        PRIVATE
        sqlite3
        )
set_target_properties(database
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS database
        ARCHIVE DESTINATION lib
        )

