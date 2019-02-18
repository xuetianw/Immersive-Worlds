add_library(datastorage
        src/DataStorage.cpp
        )


target_include_directories(datastorage
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

set_target_properties(datastorage
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

target_link_libraries(datastorage
        PUBLIC
        cusjson
        networking
        models
        )

install(TARGETS datastorage
        ARCHIVE DESTINATION lib
        )

