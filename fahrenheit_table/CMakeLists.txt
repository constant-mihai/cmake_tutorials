# ------------------------------ Libraries 
add_library(fahrenheit_table SHARED fahrenheit_table.c)

# ------------------------------ Installing
install (TARGETS fahrenheit_table DESTINATION bin)
install (FILES fahrenheit_table.h DESTINATION include)
