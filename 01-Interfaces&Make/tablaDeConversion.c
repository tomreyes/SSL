#include <stdio.h>
#include "conversion.h"


// prototipos
void printFilaCelcius(int);
void printFilaFar(int);
void printFilas(void (*)(int));

//punteros a las funciones que imprimen filas segun la conversion deseada
void (*FilaCelcius)(int) = &printFilaCelcius;
void (*FilaFar)(int) = &printFilaFar;

int inferior;
int superior;
int salto=10;

int main(void){
    int tipoConversion;
    printf ("ingresar inferior:\n");
    scanf ("%d", &inferior);
    printf ("ingresar superior:\n");
    scanf ("%d", &superior);
    printf("1 para Fahrenheit, 2 para celcius\n");
    scanf("%d", &tipoConversion);
    switch(tipoConversion){
        case 1:       //1 = far
            printFilas(FilaFar);
            break;
        case 2:         //2= celcius
            printFilas(FilaCelcius); 
            break;
    }
    scanf("%d",inferior);
}

void printFilas(void (*tipoFila)()){
    for (int i=inferior;i<superior; i+=salto){ // i = valor actual de la fila
        tipoFila(i);
    }
}

void printFilaCelcius(int i){
    printf ("%d %0.1f\n",i, Celsius(i));
}

void printFilaFar(int i){
    printf ("%d %0.1f\n",i, Fahrenheit(i));
}

