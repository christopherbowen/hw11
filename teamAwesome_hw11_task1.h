/*
 * =====================================================================================
 *
 *       Filename:  teamAwesome_hw11_task1.h
 *
 *    Description:  the header file for the house sample
 *
 *        Version:  1.0
 *        Created:  04/14/2017 01:00:14 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Christopher Bowen (), christopherbowen@mail.weber.edu
 *   Organization:
 *
 * =====================================================================================
 */
struct House{
int num,
char name[],
float price
};
/* Function Headers */
struct house InputHouse(void);
void PrintHouse(char *name, struct house h);
int ComparePrices(struct house first, struct house second);

