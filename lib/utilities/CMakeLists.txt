add_library(utilities
    src/User.cpp
    src/ID.cpp
    src/DBUtil.cpp
    )

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(utilities
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${Boost_INCLUDE_DIR}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${SQLITE3_INCLUDE_DIRS}
    )

target_link_libraries(utilities
    PUBLIC
        networking
    PRIVATE
        sqlite3
    )

set_target_properties(utilities
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    )

install(TARGETS utilities
    ARCHIVE DESTINATION lib
    )