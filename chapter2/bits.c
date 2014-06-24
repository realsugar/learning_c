/*
 * K & R "The C Programming Language"
 * Section 2.9 "Bitwise Operations"
 * Exercises 2.6 - 2.8
 * By Anton Sakharov (sakharov@mlsdev.com)
 * June 2014
 */

#include <stdio.h>

// definitions
#define BITS_IN_UNSIGNED    (sizeof(unsigned) * 8)   // ;)

// function prototypes
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

void test_getbits(unsigned x, int p, int n);
void test_setbits(unsigned x, int p, int n, unsigned y);
void test_invert(unsigned x, int p, int n);
void test_rightrot(unsigned x, int n);

void print_bits(unsigned x, char* s);
void print_var(const char* name, unsigned x);

void and_table();
void or_table();
void xor_table();


int main() {
    and_table();
    or_table();
    xor_table();
    
    test_getbits(94, 4, 3);
    test_setbits(106, 5, 3, 3);
    test_invert(106, 5, 3);
    test_rightrot(56, 5);
    return 0;
}


unsigned getbits(unsigned x, int p, int n) {
    return (x  >> (p + 1 - n) & ~(~0 << n));
}


unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned shift = p + 1 - n;
    unsigned mask = ~(~0 << n);
    x = x & ~(mask << shift);
    y = (y & mask) << shift;
    return x | y;
}


unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p + 1 - n));
}


unsigned rightrot(unsigned x, int n) {
    unsigned shift = n % BITS_IN_UNSIGNED;
    x = (x >> shift) | (x << (BITS_IN_UNSIGNED - shift));
    return x;
}


void test_getbits(unsigned x, int p, int n) {
    printf("getbits(%u, %d, %d):\n", x, p, n);
    print_var("x", x);
    print_var("y", getbits(x, p, n));
}


void test_setbits(unsigned x, int p, int n, unsigned y) {
    printf("setbits(%u, %d, %d, %u):\n", x, p, n, y);
    print_var("x", x);
    print_var("y", x);
    print_var("x", setbits(x, p, n, y));    
}


void test_invert(unsigned x, int p, int n) {
    printf("invert(%u, %d, %d):\n", x, p, n);
    print_var("x", x);
    print_var("x", invert(x, p, n));
}


void test_rightrot(unsigned x, int n) {
    printf("rightrot(%u, %d):\n", x, n);
    print_var("x", x);
    print_var("x", rightrot(x, n));
}


void and_table() {
    printf("0 & 0 = %d\n", 0 & 0);
    printf("0 & 1 = %d\n", 0 & 1);
    printf("1 & 0 = %d\n", 1 & 0);
    printf("1 & 1 = %d\n", 1 & 1);    
}


void or_table() {
    printf("0 | 0 = %d\n", 0 | 0);
    printf("0 | 1 = %d\n", 0 | 1);
    printf("1 | 0 = %d\n", 1 | 0);
    printf("1 | 1 = %d\n", 1 | 1);    
}


void xor_table() {
    printf("0 ^ 0 = %d\n", 0 ^ 0);
    printf("0 ^ 1 = %d\n", 0 ^ 1);
    printf("1 ^ 0 = %d\n", 1 ^ 0);
    printf("1 ^ 1 = %d\n", 1 ^ 1);
}


void print_bits(unsigned x, char* s) {
    unsigned num_bits = BITS_IN_UNSIGNED;
    char* p = s;
    
    while (num_bits--) {
        int bit = (x & (1 << num_bits)) >> num_bits;
        *p++ = '0' + bit;
    }
    *p = '\0';
}


void print_var(const char* name, unsigned x) {
    char s[BITS_IN_UNSIGNED + 1];
    print_bits(x, s);
    printf("\t%s = %u\t (%s)\n", name, x, s);
}