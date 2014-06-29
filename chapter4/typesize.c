/*
 * K & R "The C Programming Language"
 * Macros
 * By Anton Sakharov (sakharov@mlsdev.com)
 * June 2014
 */

#include <stdio.h>
#include <stdbool.h>

#define print_type_size(type)   printf("sizeof(" #type ") = %lu\n", sizeof(type))

int main() {
    print_type_size(char);
    print_type_size(unsigned char);
    print_type_size(short);
    print_type_size(unsigned short);
    print_type_size(int);
    print_type_size(unsigned int);
    print_type_size(long);
    print_type_size(unsigned long);
    print_type_size(long long);
    print_type_size(long long int);
    print_type_size(float);
    print_type_size(double);
    print_type_size(long double);
    print_type_size(void);
    print_type_size(void*);
    print_type_size(char*);
    print_type_size(int*);
    print_type_size(long*);
    print_type_size(float*);
    print_type_size(double*);
    print_type_size(bool);
    print_type_size(bool*);
    return 0;
}