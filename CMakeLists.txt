cmake_minimum_required(VERSION 3.16)
project(HeroJourney)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "D:/SFML")

find_package(SFML 3 REQUIRED COMPONENTS Graphics Window Audio System)

add_executable(HeroJourney src/main.cpp)

target_link_libraries(HeroJourney PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::Audio
    SFML::System
)

add_custom_command(TARGET HeroJourney POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_PREFIX_PATH}/bin/sfml-graphics-d-3.dll"
        "${CMAKE_PREFIX_PATH}/bin/sfml-window-d-3.dll"
        "${CMAKE_PREFIX_PATH}/bin/sfml-system-d-3.dll"
        "${CMAKE_PREFIX_PATH}/bin/sfml-audio-d-3.dll"
        $<TARGET_FILE_DIR:HeroJourney>
)
