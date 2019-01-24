add_library(worldhandler
  src/WorldHandler.cpp
)

target_include_directories(worldhandler
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)


target_link_libraries(worldhandler
  PRIVATE
        worldcontainer
        ${CMAKE_THREAD_LIBS_INIT}
  )
set_target_properties(worldhandler
  PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17
  )

install(TARGETS worldhandler
  ARCHIVE DESTINATION lib
  )
