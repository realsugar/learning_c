/*
 * K & R "The C Programming Language"
 * Exercise 3.1
 * By Anton Sakharov (sakharov@mlsdev.com)
 * June 2014
 */

#include <stdio.h>


int binsearch(int x, int v[], int n) {
    int low, high;
    
    low = 0;
    high = n - 1;
    
    if (x < v[low] || x > v[high]) {
        return -1;
    }
    
    int index = -1;    
    while (low < high) {
        int mid = (low + high) / 2;
        if (x > v[mid]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    if (low == high && x == v[low])
        index = low;
        
    return index;
}


void print_array(int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d%c", v[i], (i == n - 1) ? '\n' : ' ');
    }
}


int main() {
    int v[5] = { 1, 4, 9, 16, 25 };    
    print_array(v, 5);
    printf("Index of 16: %d\n", binsearch(16, v, 5));
    printf("Index of  8: %d\n", binsearch(8, v, 5));
    
    int u[6] = { 0, 1, 2, 4, 8, 16 };
    print_array(u, 6);
    printf("Index of 16: %d\n", binsearch(16, u, 6));
    printf("Index of  0: %d\n", binsearch(0, u, 6));
    printf("Index of -1: %d\n", binsearch(-1, u, 6));    
    printf("Index of 32: %d\n", binsearch(32, u, 6));    
       
    return 0;
}