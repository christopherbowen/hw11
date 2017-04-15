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

#define SIZE 21
/* Function Prototypes */
void Usage(char** info);
void ReadFile(char *dataFile1, float data[]);

/* Main Program */
int main(int argc, char *argv[])
{
    float data[SIZE];
    if(argc != 2 || strcmp((argv[1]), "--help") == 0)
    {
        Usage(argv);
    }
    else
    {
        ReadFile(argv[1], data);  //or "strcpy(In, argv[1])"
    }
	return 0;
}
/* Function Defenitions */
void Usage(char** info)
{
    printf("Error Opening\n");
    printf("Usage <waves.txt>\n");
    exit(1);
}
void ReadFile(char *dataFile1, float data[])
{
    FILE *InF;
    InF = fopen(dataFile1, "r");
    if(InF == NULL)
    {
        printf("Cannot read file, check for errors!\n");
        exit(1);
    }
    printf("File read successful!!\n");
    return;
}
