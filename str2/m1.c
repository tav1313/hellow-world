#include <stdio.h>

#define SIZE 4

int main1 (void)
{
    short dates[SIZE];
    short * pti;
    short index;
    double bills[SIZE];

    double * ptf;
    pti = dates; // н а знач ение ук а з ателю адр е с а ма с сива
    ptf = bills;
    printf(" %23s %10s \n " , " short " , " double " ) ;
    for (index = 0; index < SIZE ; index++ )
        printf("pointers + %d: %10p %10p \n " , index , pti + index , ptf + index);
    return 0;
}