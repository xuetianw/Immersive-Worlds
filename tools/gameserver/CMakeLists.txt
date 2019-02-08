add_executable(gameserver
    GameServer.cpp
    )

set_target_properties(gameserver
    PROPERTIES
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
    PREFIX ""
    )

target_link_libraries(gameserver
    networking
    game
    user
    commands
    controllers
    )

install(TARGETS gameserver
    RUNTIME DESTINATION bin
    )

