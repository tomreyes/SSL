#include "conversion.h"
#include <stdio.h>

int aCelsius(int far){
    return (5.0 / 9.0) * (far - 32);
}
int aFahrenheit(int celsius){
    printf("de celcius a far ");
    return (int)(32 + (9.0 / 5.0 * celsius));
}
