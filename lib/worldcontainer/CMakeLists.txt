add_library(worldcontainer
        src/WorldContainer.cpp
)

target_include_directories(worldcontainer
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src

)
configure_file(solace.json ${CMAKE_CURRENT_BINARY_DIR}/solace.json COPYONLY)


target_link_libraries(worldcontainer
        cusjson
        channel
        )
set_target_properties(worldcontainer
  PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17
  )

install(TARGETS worldcontainer
  ARCHIVE DESTINATION lib
  )
