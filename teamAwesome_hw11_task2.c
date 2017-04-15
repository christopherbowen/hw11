/*
 * =====================================================================================
 *
 *       Filename:  teamAwesome_hw11_task2.c
 *       	Usage:  ./teamAwesome_hw11_task2.c
 *    Description:  Tsunami Analysis
 *
 *        Version:  1.0
 *        Created:  04/15/2017 09:49:33 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Breckin Lassen (), breckinlassen@weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>		/* For exit */
#include <string.h>

/* Function Prototypes */
void Usage(char** info);

/* Main Program */
int main(int argc, char *argv[])
{
    if(argc != 2 || strcmp((argv[1]), "--help") == 0)
    {
        Usage(argv);
    }
	return 0;
}
/* Function Defenitions */
void Usage(char** info)
{
    printf("Error Opening\n");
    printf("Usage <filename>\n");
    exit(1);
}


