add_library(channel
  src/Room.cpp
  src/Area.cpp
  src/World.cpp
)

target_include_directories(channel
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(channel
  PRIVATE
        cusjson
  )

set_target_properties(channel
  PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17
  )

install(TARGETS channel
  ARCHIVE DESTINATION lib
  )