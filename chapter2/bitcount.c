/*
 * K & R "The C Programming Language"
 * Exercise 2.10
 * By Anton Sakharov (sakharov@mlsdev.com)
 * June 2014
 */

#include <stdio.h>


int fast_bitcount(unsigned x) {
    int count;
    for (count = 0; x; x &= x - 1, count++)
        ;
    return count;
}


int main() {
    printf("0: bitcount = %d\n", fast_bitcount(0));
    printf("7: bitcount = %d\n", fast_bitcount(7));
    printf("127: bitcount = %d\n", fast_bitcount(0x7F));    
    printf("128: bitcount = %d\n", fast_bitcount(0x80));    
    printf("255: bitcount = %d\n", fast_bitcount(0xFF));
    return 0;
}