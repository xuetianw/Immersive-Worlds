add_library(message
  include/Message.h
)

target_include_directories(message
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(message
  PRIVATE
        user
        networking
  )

set_target_properties(message
  PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17
  )

install(TARGETS message
  ARCHIVE DESTINATION lib
  )
