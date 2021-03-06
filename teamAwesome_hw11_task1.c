/*
 * =====================================================================================
 *
 *       Filename:  housePrice.c
 *
 *
 *       	Usage:  ./housePrice.c
 *    Description:  Ask user to specify the address and price
 *    				of two house that are on sale
 *    				It prints out which of the two houses is cheaper
 *
 *        Version:  1.0
 *        Created:  03/06/2014 04:03:12 PM
 *       Compiler:  gcc
 *         Author:  Dr. Hugo Valle (), hugovalle1@weber.edu
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teamAwesome_hw11_task1.h" // Rename this to your name name_hw#_task#.h
/* Function Prototypes */
struct House InputHouse(void)
{
    struct House home;
    printf("Enter in a street number: ");
    scanf("%d", &home.num);
    printf("\nEnter a street name: ");
    scanf("%s", home.name);
    /*while(scanf(" %c", &home.name[count])!='\n')
    {
        count++;
    }*/
    printf("Enter the price: ");
    scanf("%f", &home.price);
    return home;
}
void PrintHouse(char *name, struct House h)
{
    printf("%s: at %d %s for [%.2f]\n", name, h.num, h.name, h.price);
    return;
}
int ComparePrices(struct House first, struct House second)
{
    float home1 = first.price;
    float home2 = second.price;
    int cmp;
    if(home1 < home2)
    {
        cmp = -1;
    }
    else if(home1 > home2)
    {
        cmp = 1;
    }
    else
    {
        cmp=0;
    }
    return cmp;
}



