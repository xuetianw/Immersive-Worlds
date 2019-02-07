add_library(gamemanager
  src/WorldHandler.cpp
        src/WorldContainer.cpp
        src/ID.cpp
)

find_package(Boost 1.68 COMPONENTS system REQUIRED)

target_include_directories(gamemanager
  PUBLIC
  $<INSTALL_INTERFACE:include>
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        ${CMAKE_CURRENT_SOURCE_DIR}/doc
        ${Boost_INCLUDE_DIR}
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIR}
)


target_link_libraries(gamemanager
  PUBLIC
        cusjson
        networking
        channel
  )
set_target_properties(gamemanager
  PROPERTIES
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17
  )

install(TARGETS gamemanager
  ARCHIVE DESTINATION lib
  )
