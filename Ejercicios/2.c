
#include <stdio.h>
#include <stdlib.h>

int main()
{   int numeros[10],x;
    int par=0,cero=0;
    printf("ingrese num \n");
    for(x=0 ; x<10 ; x++)
     {
    scanf("%d",&numeros[x]);
    if(numeros[x] %2 == 0){
       par++;
    } else if(numeros[x]<0){
     cero++;
    }
}   printf("hay tal cant de 0: %d y tal de par :%d",cero,par);
    return 0;
}



