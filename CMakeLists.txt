cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
# Если версия установленой программы
# старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME Application)     # имя проекта
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)    # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)   # дефайны

include_directories("ext/SFML/include/") # добавляем директории
include_directories("inc/")
link_directories("ext/SFML/lib/")

add_executable("${PROJECT_NAME}" main.cpp
        inc/Game.hpp src/Game.cpp
        inc/Window.hpp src/Window.cpp
        inc/Direction.hpp src/Direction.cpp inc/Snake.hpp src/Snake.cpp src/World.cpp inc/World.hpp src/SnakeSegment.cpp inc/SnakeSegment.hpp inc/TextBox.hpp src/TextBox.cpp)


target_link_libraries("${PROJECT_NAME}" 
        sfml-graphics-s
        sfml-window-s
        sfml-system-s
        sfml-audio-s
        )

target_link_libraries("${PROJECT_NAME}"
        opengl32
        freetype
        winmm
        gdi32
        openal32
        flac
        vorbisenc
        vorbisfile
        vorbis
        ogg)
