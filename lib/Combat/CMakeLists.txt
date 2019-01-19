add_library(Combat
        src/Combat.cpp
        )

target_include_directories(Combat
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

target_link_libraries(Combat
        PRIVATE
        )

set_target_properties(Combat
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS Combat
        ARCHIVE DESTINATION lib
        )
