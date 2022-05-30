#include <stdio.h>
#include "conversion.h"

int main(void){
    int inferior=0;
    int superior=100;
    int salto=10;

    for (int i=inferior;i<superior; i+=salto){
        printf ("%d %d\n",i, aFahrenheit(i));
    }
    scanf("%d",inferior);
}