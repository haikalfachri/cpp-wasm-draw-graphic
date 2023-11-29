cmake_minimum_required(VERSION 3.5.0)
project(helloworld VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

include(CTest)
enable_testing()

include_directories(
  "C:\\vcpkg\\installed\\x64-windows\\include"
)
link_directories(
  "C:\\vcpkg\\installed\\x64-windows\\lib"
)

file(GLOB_RECURSE sources src/*.cpp src/*.cc src/*.h src/*.hpp)

add_executable(main ${sources})

# find_package(GEOS CONFIG REQUIRED)
# target_link_libraries(main GEOS::geos)

find_package(nlohmann_json CONFIG REQUIRED)
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(main PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)