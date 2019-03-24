add_library(controllers
    src/GameController.cpp
    src/AccountController.cpp
    src/AvatarController.cpp)

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(controllers
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        ${Boost_INCLUDE_DIR}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_link_libraries(controllers
    PUBLIC
        services
        utilities
        models
    )

set_target_properties(controllers
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    )

install(TARGETS controllers
    ARCHIVE DESTINATION lib
    )
