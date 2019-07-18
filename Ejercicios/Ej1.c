#include <stdio.h>
#include <stdlib.h>

int main()
{   int numeros[5],x,prom=0;
    for(x= 0 ; x<5 ; x++)
     {
         scanf("%d",&numeros[x]);
         prom += numeros[x];
     }
    prom= prom / 5 ;
    printf("el promedio es de %d",prom);
    return 0;
}
