
add_library(user
        src/User.cpp
        )

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(user
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIR}
        )

target_link_libraries(user

        PUBLIC
        models
        networking
        commands
        )

set_target_properties(user
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS services
        ARCHIVE DESTINATION lib
        )

