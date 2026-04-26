cmake_minimum_required(VERSION 3.16)

project(CppMinesweeper VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(MINESWEEPER_CORE_SOURCES
    src/main.cpp
    src/Board.cpp
    src/Game.cpp
)

add_executable(minesweeper_console ${MINESWEEPER_CORE_SOURCES})
target_include_directories(minesweeper_console PRIVATE include)

if (MSVC)
    target_compile_options(minesweeper_console PRIVATE /W4 /permissive-)
else()
    target_compile_options(minesweeper_console PRIVATE -Wall -Wextra -Wpedantic)
endif()

option(MINESWEEPER_BUILD_SFML "Build the SFML graphical version" ON)

if (MINESWEEPER_BUILD_SFML)
    find_package(SFML 2.5 COMPONENTS graphics window system QUIET)

    if (SFML_FOUND)
        add_executable(minesweeper_sfml
            src/sfml_main.cpp
            src/Board.cpp
            src/SfmlApp.cpp
        )

        target_include_directories(minesweeper_sfml PRIVATE include)
        target_link_libraries(minesweeper_sfml PRIVATE sfml-graphics sfml-window sfml-system)

        if (MSVC)
            target_compile_options(minesweeper_sfml PRIVATE /W4 /permissive-)
        else()
            target_compile_options(minesweeper_sfml PRIVATE -Wall -Wextra -Wpedantic)
        endif()

        add_custom_command(TARGET minesweeper_sfml POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${CMAKE_CURRENT_SOURCE_DIR}/assets
                    $<TARGET_FILE_DIR:minesweeper_sfml>/assets
        )
    else()
        message(STATUS "SFML 2.5+ not found. Building console target only.")
    endif()
endif()
