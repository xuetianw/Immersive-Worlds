add_library(commands
    src/CommandProcessor.cpp)

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(commands
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${Boost_INCLUDE_DIR}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
    )

target_link_libraries(commands
    networking
    controllers
    services
    utilities
    )

set_target_properties(commands
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    )

install(TARGETS commands
    ARCHIVE DESTINATION lib
    )
