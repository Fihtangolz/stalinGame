cmake_minimum_required(VERSION 3.3.2)
project(Game)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -m64")
set(CMAKE_EXE_LINKER_FLAGS  "")

include_directories(/usr/local/Cellar/sdl2/2.0.5/include/SDL2/)
include_directories(/usr/local/Cellar/sdl2_ttf/2.0.14/include/)

include_directories(${PROJECT_SOURCE_DIR}/src)

link_directories(/usr/local/Cellar/sdl2_ttf/2.0.14/lib/)
link_directories(/usr/local/Cellar/sdl2/2.0.5/lib/)

file(GLOB source ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/src/*.hpp)
#file(GLOB headers2 ${PROJECT_SOURCE_DIR}/include/*.h)

add_executable(Game ${source} ${headers})


target_link_libraries(Game SDL2 SDL2_ttf)
 #g++ -std=c++11 -m64 -c  main.cpp keyboardHandler.cpp  $(sdl2-config --libs --cflags) -lstdc++ -lSDL2_ttf -I/usr/local/Cellar/sdl2_ttf/2.0.14/include/ -I/usr/local/Cellar/sdl2/2.0.5/include/ -L/usr/local/Cellar/sdl2_ttf/2.0.14/lib/
