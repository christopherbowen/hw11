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
int FieldB(unsigned int hex);
void FieldC(unsigned int hex1);
void FieldF(unsigned int hex2, int ver);
/*Main Program */
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
    for(int i=0; i<3;i++)
    {
        printf("You read [%X]\n", hex[i]);
        unsigned int dummy= hex[i];
        int version=FieldB(dummy);
        FieldC(dummy);
        FieldF(dummy, version);
    }
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

int FieldB(unsigned int hex)
{
    hex &= 0b00000000000110000000000000000000;
    hex = hex >> 19;
    switch (hex) {
        case 0:
            printf("[0] MPEG Version  2.5\n");
            return 0;
            break;

        case 1:
            printf("[1] Reserved\n");
            return 1;
            break;

        case 2:
            printf("[2] MPEG Version 2.0\n");
            return 2;
            break;

        default:
            printf("[3] MPEG Version 1.0\n");
            return 3;
            break;
    }
}

void FieldC(unsigned int hex1)
{
    hex1 &= 0b000000000001100000000000000000;
    hex1 = hex1 >> 17;
    switch (hex1) {
        case 0:
            printf("[0] Reserved\n");
            break;

        case 1:
            printf("[1] Layer 3\n");
            break;

        case 2:
            printf("[2] Layer 2\n");
            break;

        default:
            printf("[3] Layer 1\n");
            break;
    }
    return;
}

void FieldF(unsigned int hex2, int ver)
{
    hex2 &= 0b00000000000000000000110000000000;
    hex2 = hex2>>10;
    if(ver==0)
    {
        switch (hex2) {
            case 0:
                printf("[0] 11025 Hz\n");
                break;
            case 1:
                printf("[1] 12000 Hz\n");
                break;
            case 2:
                printf("[2] 8000 Hz\n");
                break;
            default:
                printf("[3] Reserved\n");
                break;
        }
    }
    else if(ver==2)
    {
        switch (hex2) {
            case 0:
                printf("[0] 22050 Hz\n");
                break;
            case 1:
                printf("[1] 24000 Hz\n");
                break;
            case 2:
                printf("[2] 16000 Hz\n");
                break;
            default:
                printf("[3] Reserved\n");
                break;
        }

    }
    else if(ver==3)
    {
        switch (hex2) {
            case 0:
                printf("[0] 44100 Hz\n");
                break;
            case 1:
                printf("[1] 48000 Hz\n");
                break;
            case 2:
                printf("[2] 32000 Hz\n");
                break;
            default:
                printf("[3] Reserved\n");
                break;
        }
    }
    else
    {
        printf("no sampling rate frequency index\n");
    }
    return;
}













