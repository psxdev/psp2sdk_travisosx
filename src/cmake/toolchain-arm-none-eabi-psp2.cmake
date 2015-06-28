# Copyright (C) 2015 PSP2SDK Project
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

include(CMakeForceCompiler)

# Setup arch info
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR cortex-a9)
set(CMAKE_CROSSCOMPILING ON)
CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GNU)

# Set compilation flags
set(CMAKE_C_FLAGS "-mcpu=cortex-a9 -mfpu=neon-fp16" CACHE STRING "" FORCE)

# Do a no-op access on the CMAKE_TOOLCHAIN_FILE variable
# so that CMake will not issue a warning on it being unused.
if (CMAKE_TOOLCHAIN_FILE)
endif()

# Find the target environment prefix
execute_process(COMMAND ${CMAKE_C_COMPILER} -print-file-name=libc.a
    OUTPUT_VARIABLE TOOLCHAIN_INSTALL_PREFIX OUTPUT_STRIP_TRAILING_WHITESPACE)

# Strip the filename off
get_filename_component(TOOLCHAIN_INSTALL_PREFIX "${TOOLCHAIN_INSTALL_PREFIX}" PATH)
# Then find the canonical path to the directory one up from there
get_filename_component(TOOLCHAIN_INSTALL_PREFIX "${TOOLCHAIN_INSTALL_PREFIX}/.." REALPATH)
set(TOOLCHAIN_INSTALL_PREFIX  ${TOOLCHAIN_INSTALL_PREFIX} CACHE FILEPATH
    "Install path prefix, prepended onto install directories.")

message(STATUS "Cross-compiling with gcc-arm-none-eabi toolchain")
message(STATUS "Toolchain prefix: ${TOOLCHAIN_INSTALL_PREFIX}")

set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_INSTALL_PREFIX})

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
