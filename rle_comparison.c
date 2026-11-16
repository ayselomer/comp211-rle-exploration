
#include <stdio.h>
#include <string.h>

int encode(const char *s) {
    int compressed_size = 0;

    for (int i = 0; s[i] != '\0'; ) {
        char current = s[i];
        int count = 0;

        while (s[i] == current) {
            count++;
            i++;
        }

        compressed_size += printf("%d%c", count, current);
    }

    return compressed_size;
}

int main(void) {
    const char *tests[] = {
        "AAAAAAAAAA",
        "AAAABBBCC",
        "ABCDEF",
        "ABABABAB"
    };

    int num_tests = sizeof(tests) / sizeof(tests[0]);

    for (int t = 0; t < num_tests; t++) {
        const char *str = tests[t];
        int original_size = (int)strlen(str);

        printf("Test %d\n", t + 1);
        printf("Original: %s\n", str);
        printf("Encoded: ");

        int compressed_size = encode(str);

        double ratio = (double)original_size / compressed_size;
        double percent_change =
            ((double)(compressed_size - original_size)
             / original_size) * 100;

        printf("\nOriginal size: %d\n", original_size);
        printf("Encoded size: %d\n", compressed_size);
        printf("Compression ratio: %.2f:1\n", ratio);
        printf("Percentage change: %.2f%%\n\n", percent_change);
    }

    return 0;
}
