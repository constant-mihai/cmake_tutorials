/***************************************** 

* File Name : main.c

* Creation Date : 19-02-2018

* Last Modified :

* Created By : Mihai Constantin constant.mihai@googlemail.com

* License :

******************************************/

/**
 *  Purpose:
 *
 */

// Config
#include "c_prog_lang_config.h"

#if USE_FAHRENHEIT_TABLE
#include "fahrenheit_table.h"
#endif
#include <stdio.h>

int main(int argc, char ** argv) {
    printf("Hello world\n");
#if USE_FAHRENHEIT_TABLE
    printf("This should be a table header\n");
    int ret = fahrenheit_table();
#endif
}
