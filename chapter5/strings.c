/*
 * K & R "The C Programming Language"
 * Exercises 5.3 - 5.5
 * Strings and pointers
 * By Anton Sakharov (sakharov@mlsdev.com)
 * June 2014
 */

#include <stdio.h>


// definitions
#define STRLEN       256

#define eval_lu(expr)       printf(#expr " = %lu\n", expr)
#define eval_s(expr)        printf(#expr " = %s\n", expr)
#define eval_i(expr)        printf(#expr " = %d\n", expr)

// prototypes
size_t strlen(char *s);
char *strcpy(char *s, char *t);
char *strcat(char *s, char *t);
int strcmp(char *s, char *t);
int strend(char *s, char *t);

char *strncpy(char *s, char *t, size_t n);
char *strncat(char *s, char *t, size_t n);
int strncmp(char *s, char *t, size_t n);


int main() {
    eval_lu(strlen("Hello!"));
    
    char s[STRLEN];
    char *p = "This is a copy!";
    eval_s(strcpy(s, p));
    eval_s(strcat(s, "Copy, I said!"));
    
    eval_i(strcmp("Should", "Could"));
    eval_i(strcmp("Would", "would"));
    eval_i(strcmp("would", "would"));

    eval_i(strend("Could", "could"));    
    eval_i(strend("Could", "ould"));
    eval_i(strend("", ""));
    eval_i(strend("", "string"));
    eval_i(strend("str", "string"));
    
    eval_s(strncpy(s, "string", 3));
    eval_s(strncpy(s, "string", 32));
    
    
    eval_s(strncat(s, " + another string", 8));    
    eval_s(strncat(s, " + another string", 64));
    eval_s(strncat(s, "1", 1));    
    eval_s(strncat(s, "", 1));
    
    eval_i(strncmp("Should", "Could", 6));
    eval_i(strncmp("Would", "would", 5));
    eval_i(strncmp("Would", "would", 32));    
    eval_i(strncmp("would", "would", 5));
    eval_i(strncmp("would", "woulD", 4));    
    eval_i(strncmp("would", "woulD", 5));    
    return 0;
}


size_t strlen(char *s) {
    char *p = s;
    while (*p) p++;
    return p - s;
}


char *strcpy(char *s, char *t) {
    char *d = s;
    while ((*d++ = *t++)) ;
    return s;
}


char *strcat(char *s, char *t) {
    char *p = s;
    while (*s) s++;
    while ((*s++ = *t++));
    return p;
}


int strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (!*s)
            return 0;
    }
    return *s - *t;
}


int strend(char *s, char *t) {
    int sl, tl;
    
    sl = strlen(s);
    tl = strlen(t);
        
    if (tl > sl)
        return 0;
    
    char *p = s + sl - tl;
    
    return !strcmp(p, t) ? 1 : 0;
}


char *strncpy(char *s, char *t, size_t n) {
    char *d = s;
    for ( ; (*d++ = *t++) && --n > 0; ) ;
    *d = '\0';
    return s;
}


char *strncat(char *s, char *t, size_t n) {
    char *d = s;
    while (*d) d++;
    for ( ; (*d++ = *t++) && --n > 0; ) ;
    *d = '\0';
    return s;
}


int strncmp(char *s, char *t, size_t n) {
    for (; *s == *t && --n > 0; s++, t++) {
        if (!*s)
            return 0;
    }
    return *s - *t;
}