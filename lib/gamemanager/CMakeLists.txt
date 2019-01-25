add_library(gamemanager
  src/WorldHandler.cpp
        src/WorldContainer.cpp
)

target_include_directories(gamemanager
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_link_libraries(gamemanager
  PUBLIC
        cusjson
        networking
  )
set_target_properties(gamemanager
  PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17
  )

install(TARGETS gamemanager
  ARCHIVE DESTINATION lib
  )
