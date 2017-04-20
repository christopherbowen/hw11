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
#define SIZE 10
struct Tsunami{
    int mo, da, yr, fatal;
    double max_height;
    char location[20];
};
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
    int j = 0, k;
    double max = 0, sum = 0, ave;
    struct Tsunami yo[SIZE];
    InF = fopen(dataFile1, "r");
    if(InF == NULL)
    {
        printf("Cannot read file, check for errors!\n");
        exit(1);
    }
    //    printf("File read successful!!\n");
    else
    {
        while(fscanf(InF, "%d %d %d %d %lf %s",
                    &yo[j].mo,
                    &yo[j].da,
                    &yo[j].yr,
                    &yo[j].fatal,
                    &yo[j].max_height,
                    yo[j].location) == 6)
        {
            printf("yo[j]: %lf\n", yo[j].max_height);
            sum = sum + yo[j].max_height;
            if(yo[j].max_height > max)
                max = yo[j].max_height;
            j++;
        }
        k = j;

        ave = sum/k;
        printf("Max  height in feet: [%.2f\n", max * 3.28);
        printf("Average height in feet: [%.2f\n", ave * 3.28);
        printf("Tsunamis that are greater than average:\n");
        for(j = 0; j < k-1; j++)
            if(yo[j].max_height > ave)
            {
                printf("[%s]\n", yo[j].location);
            }
        fclose(InF);
    }
    return;
}
