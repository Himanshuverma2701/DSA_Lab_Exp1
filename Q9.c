#include <stdio.h>

struct MyStruct {
    int i;
    float f;
    char c;
};

union MyUnion {
    int i;
    float f;
    char c;
};

int main() {
    struct MyStruct s;
    union MyUnion u;

    printf("Memory allocated for structure: %lu bytes\n", sizeof(s));
    printf("Memory allocated for union: %lu bytes\n", sizeof(u));

    return 0;
}
