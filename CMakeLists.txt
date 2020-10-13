cmake_minimum_required(VERSION 3.0.0)
project(SFML-Game VERSION 0.1.0)

file(GLOB sources "src/*.cpp")
add_executable(SFML-Game ${sources})
set_target_properties(SFML-Game PROPERTIES COMPILE_FLAGS -DSFML_STATIC)
# target_link_options(SFML-Game PRIVATE -mwindows)

set(SFML_DIR "C:/Users/martin/Documents/Dev/SFML-2.5.1")

target_include_directories(SFML-Game PRIVATE ${SFML_DIR}/include)
target_link_directories(SFML-Game PRIVATE ${SFML_DIR}/lib)
target_link_libraries(SFML-Game sfml-graphics-s sfml-window-s sfml-system-s gdi32 opengl32 winmm freetype -static)