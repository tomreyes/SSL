#include "conversion.h"
#include <stdio.h>

double Celsius(double far){
    return (5.0 / 9.0) * (far - 32);
}
double Fahrenheit(double celsius){
    return (int)(32 + (9.0 / 5.0 * celsius));
}