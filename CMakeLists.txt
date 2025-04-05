cmake_minimum_required(VERSION 3.30)

    # Define the project name and language
project(Lab02-Test C) # You can rename MyDatabaseProject

# Set the C standard (optional, but good practice)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# --- Configuration ---

# Add the 'inc' directory to the include path
# This allows #include "header.h" to find files in inc/
include_directories(inc)

# --- Library Definition ---

# Define a library target using the source files in lib/
# We'll call this library 'dblib' (you can choose another name)
add_library(dblib STATIC # STATIC is usually simpler for direct testing
        lib/buffer_manager.c
        lib/replacer.c
        lib/storage_manager.c
)
# Note: uthash.h is header-only, it doesn't need to be listed here,
# just accessible via include_directories.

# --- Executable for Testing ---

# Create an executable target for your main test file.
# Let's assume you'll create a 'main.c' in the project root.
add_executable(run_tests main.c) # You can rename run_tests and main.c

# Link the executable against the library we defined above.
# This makes the functions compiled in 'dblib' available to 'run_tests'.
target_link_libraries(run_tests PRIVATE dblib)

# --- Optional: Compiler Flags (Good Practice) ---
if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_CLANG)
    # Add warnings for the library
    target_compile_options(dblib PRIVATE -Wall -Wextra -pedantic)
    # Add warnings for the executable
    target_compile_options(run_tests PRIVATE -Wall -Wextra -pedantic)
endif()

# --- Optional: Output Directories (For Cleaner Build Folders) ---
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Print a message upon configuration
message(STATUS "CMake configured for ${PROJECT_NAME}")
message(STATUS "Include directory: ${CMAKE_SOURCE_DIR}/inc")
message(STATUS "Library sources: lib/*.c")
message(STATUS "Test executable source: main.c")
