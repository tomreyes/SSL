#include<assert.h>
#include<stdio.h>
#include "conversion.h"
int main (void){
    assert(Celsius(32) == 0);
    puts("far OK");
    assert(Fahrenheit(0) == 32);
    puts("celcius okk");
}