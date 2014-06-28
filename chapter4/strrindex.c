/*
 * K & R "The C Programming Language"
 * Exercise 4.1
 * By Anton Sakharov (sakharov@mlsdev.com)
 * June 2014
 */

#include <stdio.h>

int strrindex(char s[], char t[]);
void test_strrindex(char s[], char t[]);

int main() {
    test_strrindex("How could I do this?", "How");
    test_strrindex("Long long long time ago far far away!", "long");    
    test_strrindex("You should try different string.", "would");
    test_strrindex("Find me at last!", "!");    
    return 0;
}


void test_strrindex(char s[], char t[]) {
    printf("strrindex(\"%s\", \"%s\"):\t%d\n", 
        s, t, strrindex(s, t));
}


int strrindex(char s[], char t[]) {
    int slen, tlen;
    
    for (slen = 0; s[slen] != '\0'; slen++) ;
    for (tlen = 0; t[tlen] != '\0'; tlen++) ;
 
    if (tlen > slen)
        return -1;
    
    int i, j, k;
    for (i = slen - 1; i >= tlen - 1; i--) {
        for (j = tlen - 1, k = i; j >= 0 && s[k] == t[j]; j--, k--) ;
        
        if (j == -1)
            return k + 1;
    }
    
    return -1;
}