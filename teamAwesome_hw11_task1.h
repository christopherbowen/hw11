/*
 * =====================================================================================
 *
 *       Filename:  teamAwesome_hw11_task1.h
 *
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
struct House
{
int num;
char name[81];
float price;
};
/* Function Headers */
struct House InputHouse(void);
void PrintHouse(char *name, struct House h);
int ComparePrices(struct House first, struct House second);

