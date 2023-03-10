cmake_minimum_required(VERSION 3.2)

project(PaintBucketAlgorithms)


option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)

if (${FORCE_COLORED_OUTPUT})
  if     ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options (-fdiagnostics-color=always)
  elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options (-fcolor-diagnostics)
  endif ()
endif ()

set(SFML_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -mavx2 ${SFML_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,leak,undefined -Wall -Wextra -Wpedantic -g -O0 ${SFML_FLAGS}")

set(MAIN_FILE main.cpp)
set(SOURCE main.cpp)

include_directories(include)

add_executable(main ${MAIN_FILE})

add_subdirectory(src)

target_link_libraries(main src)

find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
    file(GLOB_RECURSE ALL_CXX_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/*.[ch]pp
        ${PROJECT_SOURCE_DIR}/*.[ch]
    )

    add_custom_target(
        clang-force-format
        COMMAND clang-format
        -i
        -style=file
        ${ALL_CXX_SOURCE_FILES}
    )
endif()
