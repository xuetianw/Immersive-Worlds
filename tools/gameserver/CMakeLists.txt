add_executable(gameserver
    GameServer.cpp
    )

set_target_properties(gameserver
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    PREFIX ""
    )

find_package(Threads REQUIRED)

target_link_libraries(gameserver
    networking
    utilities
    processors
    ${CMAKE_THREAD_LIBS_INIT}
    )

install(TARGETS gameserver
    RUNTIME DESTINATION bin
    )

