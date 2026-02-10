#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data d;

    d.i = 100;
    printf("Integer: %d\n", d.i);   

    d.f = 98.76; 
    printf("Float: %.2f\n", d.f);    

    d.c = 'A';   
    printf("Char: %c\n", d.c);

    printf("\nAll the members share the same memory location\n");
    printf("Size of union: %lu bytes\n",sizeof(d));

    return 0;
}
