add_library(services
    src/AccountService.cpp
    src/DataStorageService.cpp
    src/RoomConnectionService.cpp
    src/AvatarService.cpp
    src/CombatService.cpp
    src/InventoryService.cpp
    )


find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(services
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIR}
    )

target_link_libraries(services
    PUBLIC
        cusjson
        models
        utilities
    )

set_target_properties(services
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    )

install(TARGETS services
    ARCHIVE DESTINATION lib
    )

