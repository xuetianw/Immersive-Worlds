add_library(models
    src/Room.cpp
    src/RoomConnection.cpp
    src/Avatar.cpp
    src/Inventory.cpp
    src/InventoryItem.cpp
    src/SingleItem.cpp
    src/MiniGame.cpp
    src/Combat.cpp
    )

target_include_directories(models
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

target_link_libraries(models
    PUBLIC
        cusjson
        utilities
    )

set_target_properties(models
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    )

install(TARGETS models
    ARCHIVE DESTINATION lib
    )