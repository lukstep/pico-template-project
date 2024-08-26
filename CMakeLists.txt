cmake_minimum_required(VERSION 3.13)
project(sample C CXX ASM)

set(PICO_BOARD pico2)

set(PICO_PLATFORM rp2350-riscv)

set(PICO_TOOLCHAIN_PATH /opt/riscv/gcc14-rp2350-no-zcmp/)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

set(CMAKE_C_COMPILER /opt/riscv/gcc14-rp2350-no-zcmp/bin/riscv32-unknown-elf-gcc CACHE PATH "" FORCE)
set(CMAKE_CXX_COMPILER /opt/riscv/gcc14-rp2350-no-zcmp/bin/riscv32-unknown-elf-g++ CACHE PATH "" FORCE)
set(CMAKE_ASM_COMPILER /opt/riscv/gcc14-rp2350-no-zcmp/bin/riscv32-unknown-elf-gcc CACHE PATH "" FORCE)
set(CMAKE_OBJCOPY /opt/riscv/gcc14-rp2350-no-zcmp/bin/riscv32-unknown-elf-objcopy CACHE FILEPATH "" FORCE)
set(CMAKE_OBJDUMP /opt/riscv/gcc14-rp2350-no-zcmp/bin/riscv32-unknown-elf-objdump CACHE FILEPATH "" FORCE)

include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

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
