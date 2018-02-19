# ------------------------------ Versioning 
cmake_minimum_required (VERSION 2.6)
project (CMakeTutorial)

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Does this system provide the log and ex functions
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# ------------------------------ Options 
set(CMAKE_VERBOSE_MAKEFILE CACHE ON FORCE)
option(USE_FAHRENHEIT_TABLE "Use tutorial provided math implementation" 1)

# ------------------------------ Configuration 
configure_file("${PROJECT_SOURCE_DIR}/includes/c_prog_lang_config.h.in" "${PROJECT_SOURCE_DIR}/includes/c_prog_lang_config.h" )

# ------------------------------ Include Directories 

set(CPROG_LANG_INCLUDES 
    "${PROJECT_SOURCE_DIR}/includes ")

if (USE_FAHRENHEIT_TABLE)
    set(CPROG_LANG_INCLUDES ${CPROG_LANG_INCLUDES} 
        "${PROJECT_SOURCE_DIR}/fahrenheit_table ")
    set(EXTRA_LIBS ${EXTRA_LIBS} fahrenheit_table)
endif()

include_directories(${CPROG_LANG_INCLUDES})

MESSAGE (STATUS "CPROG_LANG_INCLUDES=" ${CPROG_LANG_INCLUDES})
MESSAGE (STATUS "USE_FAHRENHEIT_TABLE=" ${USE_FAHRENHEIT_TABLE})

# ------------------------------ Subdirectories 
add_subdirectory(fahrenheit_table)
add_subdirectory("math")

# ------------------------------ Libraries 
# ------------------------------ Executable & Libraries
add_executable(c_prog_lang_main c_prog_lang_main.c)
target_link_libraries(c_prog_lang_main ${EXTRA_LIBS})

# ------------------------------ Install 
install(TARGETS c_prog_lang_main DESTINATION bin)
install(FILES "${PROJECT_SOURCE_DIR}/includes/c_prog_lang_config.h"        
             DESTINATION include)

# ------------------------------ Testing 
enable_testing()
# Does the application run
add_test(runs c_prog_lang_main)

#
