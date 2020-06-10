#include <stdio.h>
#include "tax.h"

void main()
{
    int my_tax;
   
    my_tax = tax(9500,1200);
   
    printf("I need tax %d\n",my_tax); 
}