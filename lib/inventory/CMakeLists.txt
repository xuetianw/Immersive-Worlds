add_library(inventory
        src/Inventory.cpp
        src/SingleItem.cpp
    src/InventoryItem.cpp
        )


target_include_directories(inventory
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

target_link_libraries(inventory
        PRIVATE
        utilities
        )

set_target_properties(inventory
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS inventory
        ARCHIVE DESTINATION lib
        )

