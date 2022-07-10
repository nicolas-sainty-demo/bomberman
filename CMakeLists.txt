cmake_minimum_required(VERSION 3.17)

project("bomberman")

find_package(raylib 4.0.0 QUIET)

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

set(EXECUTABLE_OUTPUT_PATH ../)

#set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(INCLUDE_DIR
    Src/Includes
)

include(Src/CMakeLists.txt)
include(Src/GameEngine/CMakeLists.txt)
include(Src/Map/CMakeLists.txt)
include(Src/Menu/CMakeLists.txt)
include(Src/Player/CMakeLists.txt)
include(Src/Save/CMakeLists.txt)

add_executable(${PROJECT_NAME} ${CORE_SRC} ${GAME_ENGINE_SRC} ${MAP_SRC} ${MENU_SRC} ${PLAYER_SRC} ${SAVE_SRC})

set_target_properties(bomberman PROPERTIES PREFIX "")

target_compile_options(
        bomberman
        PRIVATE
        ${CXX_FLAGS}
)

target_link_libraries(
        bomberman
        PRIVATE
        raylib
)

target_include_directories(
        bomberman
        PUBLIC
        ${INCLUDE_DIR}
)