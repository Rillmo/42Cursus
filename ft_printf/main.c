#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
   int   size1;
   int   size2;

   size1 = ft_printf(" %p ", -1);
   printf("\n%d\n", size1);

   size2 = printf(" %p ", -1);
   printf("\n%d\n", size2);
}