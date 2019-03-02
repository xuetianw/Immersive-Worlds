add_library(cusjson
  src/CusJson.cpp
        src/NPCJsonWrapper.cpp
        src/GiveNPCAction.cpp src/EquipNPCAction.cpp)



target_include_directories(cusjson
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(cusjson
                      PROPERTIES
                      LINKER_LANGUAGE CXX
                      CXX_STANDARD 17
)

install(TARGETS cusjson
  ARCHIVE DESTINATION lib
)

