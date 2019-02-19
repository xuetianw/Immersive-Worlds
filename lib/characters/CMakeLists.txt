add_library(characters
        src/Avatar.cpp
        src/character.cpp
        src/NonUserCharacter.cpp
        )


target_include_directories(characters
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        )

set_target_properties(characters
        PROPERTIES
        LINKER_LANGUAGE CXX
        CXX_STANDARD 17
        )

install(TARGETS characters
        ARCHIVE DESTINATION lib
        )

target_link_libraries(characters
        PUBLIC
        models
        inventory)
