/*
 * =====================================================================================
 *
 *       Filename:  hw11_task3.c
 *    Description:  process mp3 file
 *
 *        Created:  04/22/2017 05:52:20 PM
 *         Author:  Christopher Bowen (), christopherbowen@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>
/* Function Prototypes */
void Usage(void);
void ReadFile(char *fname, unsigned int num[]);
void FieldB(unsigned int hex);
/* Main Program */
int main(int argc, char *argv[])
{
    unsigned int hex[10];
    if(strcmp(argv[1], "--help")==0)
    {
        Usage();
        exit(1);
    }
    if(argc != 2)
    {
        Usage();
        exit(1);
    }
    ReadFile(argv[1], hex);
    unsigned int first=  hex[0];
    FieldB(first);
	return 0;
}


/* Function Defenitions */
void Usage(void)
{
    printf("Usage: ./task3 <mp3 file>\n");
    printf("checks for only two parameters\n");
}

void ReadFile(char *fname, unsigned int num[])
{
    FILE *infile=fopen(fname,"r");
    if(infile == NULL)
    {
        printf("couldn't open file\n");
        Usage();
        exit(1);
    }
    printf("succesfully opened file\n");
    int i = 0;
    while(fscanf(infile, "%X", &num[i])!=EOF)
    {
        i++;
    }
    return;
}

void FieldB(unsigned int hex)
{
    hex &= 0b00000000000110000000000000000000;
    hex = hex >> 19;
    switch (hex) {
        case 0:
            printf("[0] MPEG Version  2.5\n");
            break;

        case 1:
            printf("[1] Reserved\n");
            break;

        case 2:
            printf("[2] MPEG Version 2.0\n");
            break;

        default:
            printf("[3] MPEG Version 1.0\n");
            break;
    }
    return;
}






