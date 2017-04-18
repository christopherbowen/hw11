/*
 * =====================================================================================
 *
 *       Filename:  teamAwesome_hw11_task3.c
 *       	Usage:  ./teamAwesome_hw11_task3.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/18/2017 02:32:17 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Tysen Bair (), tysenbair@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>

#define FILEOPEN "mp3Header.txt"
/* Function Prototypes */
void Usage(void);
void ReadFile(void);
void Layer(void);
void Rate(void);
/* Main Program */
int main(int argc, char *argv[])
{
	if(argc > 1 && strcmp(argv[1], "--help") == 0)
	{
		Usage();
		exit(1);
	}
	if(argc < 2 || argc > 2)
	{
		Usage();
		exit(1);
	}
	
	
	return 0;
}


/* Function Defenitions */
void Usage(void)
{
	printf("Could Not Open\n");
	printf("You must use <mp3data.txt>\n");
	exit(1);;
}

void ReadFile(void)
{
	return;
}

void Layer(void)
{
	return;
}

void Rate(void)
{
	return;
}
