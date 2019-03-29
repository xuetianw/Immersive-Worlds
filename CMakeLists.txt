cmake_minimum_required(VERSION 3.12)
project(WebSocketNetworking)

set(PACKAGE_NAME WebSocketNetworking)
set(PACKAGE_VERSION 0.1)
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_BUGREPORT "wsumner@sfu.ca")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fno-rtti")
set(CMAKE_CXX_FLAGS_DEBUG
    "-O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# And the project header and library paths
link_directories(${LIBRARY_OUTPUT_PATH})
set(CMAKE_TEMP_LIBRARY_PATH "${PROJECT_BINARY_DIR}/lib")

# Adding in json files to config folder in build
configure_file(config/areas/shire.json config/areas/shire.json COPYONLY)
configure_file(config/areas/mirkwood.json config/areas/mirkwood.json COPYONLY)
configure_file(config/areas/solace.json config/areas/solace.json COPYONLY)
configure_file(config/minigames/minigame.json config/minigames/minigame.json COPYONLY)


add_subdirectory(lib)
add_subdirectory(tools)
add_subdirectory(test)

