add_executable(commandProcessor
        commandProcessor.cpp
        )

target_link_libraries(commandProcessor
        networking
        ${CMAKE_THREAD_LIBS_INIT},
        ${Boost_LIBRARIES}
        )