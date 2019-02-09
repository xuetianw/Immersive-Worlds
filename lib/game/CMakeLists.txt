add_library(game
    src/WorldHandler.cpp
    src/WorldContainer.cpp
    src/ID.cpp
    src/YellCommand.cpp
    src/AttackCommand.cpp
    src/CommandProcessor.cpp
    src/GameController.cpp
    src/GameService.cpp)

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(game
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${Boost_INCLUDE_DIR}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${Boost_INCLUDE_DIR}
    )

target_link_libraries(game
    PUBLIC
    cusjson
    networking
    channel
    )

set_target_properties(game
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    )

install(TARGETS game
    ARCHIVE DESTINATION lib
    )
