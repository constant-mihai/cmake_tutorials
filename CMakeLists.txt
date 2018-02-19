# ------------------------------ Versioning 
cmake_minimum_required (VERSION 2.6)
project (CMakeTutorial)

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


# ------------------------------ Configuration 
configure_file("${PROJECT_SOURCE_DIR}/includes/c_prog_lang_config.h.in" "${PROJECT_SOURCE_DIR}/includes/c_prog_lang_config.h" )
option(USE_FAHRENHEIT_TABLE "Use tutorial provided math implementation" ON)

# ------------------------------ Include Directories 

set(CPROG_LANG_INCLUDES 
    "${PROJECT_SOURCE_DIR}/includes ")

include_directories(${CPROG_LANG_INCLUDES})


if (USE_FAHRENHEIT_TABLE)
    set(CPROG_LANG_INCLUDES ${CPROG_LANG_INCLUDES} 
        "${PROJECT_SOURCE_DIR}/fahrenheit_table ")
    set(EXTRA_LIBS ${EXTRA_LIBS} fahrenheit_table)
endif()

MESSAGE (STATUS "CPROG_LANG_INCLUDES=" ${CPROG_LANG_INCLUDES})
MESSAGE (STATUS "USE_FAHRENHEIT_TABLE=" ${USE_FAHRENHEIT_TABLE})

# ------------------------------ Subdirectories 
add_subdirectory(fahrenheit_table)

# ------------------------------ Libraries 
# ------------------------------ Executable & Libraries
add_executable(c_prog_lang_main c_prog_lang_main.c)
target_link_libraries(c_prog_lang_main ${EXTRA_LIBS})

# ------------------------------ Install 
install(TARGETS c_prog_lang_main DESTINATION bin)
install(FILES "${PROJECT_SOURCE_DIR}/includes/c_prog_lang_config.h"        
             DESTINATION include)

