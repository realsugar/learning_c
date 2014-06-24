/*
 * K & R "The C Programming Language"
 * Chapter 1
 * By Anton Sakharov (sakharov@mlsdev.com)
 * June 2014
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#define CELSIUS_UPPER   40
#define CELSIUS_LOWER   -30
#define CELSIUS_STEP    5


float celsius_to_fahr(float celsius) {
    return (9 / 5.0f) * celsius + 32.0f;
}


void celsius_to_fahr_table() {
    for (int celsius = CELSIUS_UPPER; celsius >= CELSIUS_LOWER; celsius -= CELSIUS_STEP) {
        printf("C %6.2f - F %6.2f\n", 
            (float) celsius, 
            celsius_to_fahr(celsius));
    }    
}


int main() {
    celsius_to_fahr_table();
    return 0;
}