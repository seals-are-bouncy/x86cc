cmake_minimum_required(VERSION 3.15)

project(x86cc VERSION 0.1 DESCRIPTION "A x86 targeted C compiler.")

file(GLOB_RECURSE source_files "src/*.c" "src/*/*.c")

add_executable(${PROJECT_NAME} ${source_files})

set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    C_STANDARD 99
    C_STANDARD_REQUIRED ON
)