
#include <stdio.h>

void encode(const char *s) {
    for (int i = 0; s[i] != '\0'; ) {
        char current = s[i];
        int count = 0;

        while (s[i] == current) {
            count++;
            i++;
        }

        printf("%d%c", count, current);
    }
    printf("\n");
}

int main(void) {
    printf("Test 1: ");
    encode("AAAAAAAAAA");

    printf("Test 2: ");
    encode("AAAABBBCC");

    printf("Test 3: ");
    encode("ABCDEF");

    printf("Test 4: ");
    encode("ABABABAB");

    return 0;
}
