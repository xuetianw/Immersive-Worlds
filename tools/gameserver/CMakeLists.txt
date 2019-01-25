add_executable(gameserver
        gameserver.cpp
        ../../lib/networking/src/ClientManager.cpp ../../lib/networking/include/ClientManager.h)

set_target_properties(gameserver
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        PREFIX ""
        )

find_package(Threads REQUIRED)

target_link_libraries(gameserver
        networking
        clientManager
        ${CMAKE_THREAD_LIBS_INIT}
        )

install(TARGETS gameserver
        RUNTIME DESTINATION bin
        )

