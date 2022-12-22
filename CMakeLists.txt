cmake_minimum_required(VERSION 3.14)
project(spacegame)

set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/local/opt/ncurses/include)

link_directories(/usr/local/opt/ncurses/lib)

add_executable(spacegame main.cpp)

target_link_libraries(libmenutest menu ncurses)