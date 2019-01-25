add_library(inventory
        src/Inventory.cpp
        src/Object.cpp
        )


target_include_directories(inventory
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

set_target_properties(inventory
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS inventory
        ARCHIVE DESTINATION lib
        )

