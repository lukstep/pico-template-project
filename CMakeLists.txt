cmake_minimum_required(VERSION 3.13)

set(PICO_BOARD pico2)

# set(PICO_PLATFORM rp2350-arm-s)
set(PICO_PLATFORM rp2350-riscv)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(sample C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

pico_enable_stdio_usb(${CMAKE_PROJECT_NAME} 1)
pico_enable_stdio_uart(${CMAKE_PROJECT_NAME} 1)
pico_add_extra_outputs(${CMAKE_PROJECT_NAME})

target_link_libraries(${CMAKE_PROJECT_NAME} pico_stdlib)

# Export path to project executable to file. File is used in vscode tasks (task.json and launch.json)
set(ELF_PATH "${CMAKE_CURRENT_BINARY_DIR}/${TARGET_FILE}${CMAKE_PROJECT_NAME}.elf")
file(WRITE "${CMAKE_BINARY_DIR}/elf_path.txt" "${ELF_PATH}\n")
