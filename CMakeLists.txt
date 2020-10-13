cmake_minimum_required(VERSION 3.0.0)
project(HelloWorld VERSION 0.1.0)

file(GLOB sources "src/*.cpp")
add_executable(HelloWorld ${sources})
set_target_properties(HelloWorld PROPERTIES COMPILE_FLAGS -DSFML_STATIC)
# target_link_options(HelloWorld PRIVATE -mwindows)

target_include_directories(HelloWorld PRIVATE "C:/Users/martin/Documents/Dev/SFML-2.5.1/include")
target_link_directories(HelloWorld PRIVATE "C:/Users/martin/Documents/Dev/SFML-2.5.1/lib")
target_link_libraries(HelloWorld sfml-graphics-s sfml-window-s sfml-system-s gdi32 opengl32 winmm freetype -static)