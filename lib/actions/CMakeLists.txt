add_library(actions
    src/GameActions.cpp
    src/MiniGameActions.cpp
    )

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(actions
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${Boost_INCLUDE_DIR}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_link_libraries(actions
    PUBLIC
    services
    utilities
    models
    )

set_target_properties(actions
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    )

install(TARGETS actions
    ARCHIVE DESTINATION lib
    )
