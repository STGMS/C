#include <stdio.h>

#define MAX 1000000

int main() {
    char text[MAX];

    printf("Input your text:\n");

    if (fgets(text, sizeof(text), stdin)) {
        printf("Text: %s\nHex:  ", text);

        for (int i = 0; text[i] != '\0'; i++) {
            printf("%02X ", (unsigned char)text[i]);
            //if ((i + 1) % 16 == 0) printf("\n      "); // Salto cada 16 bytes
        }
    }
    return 0;
}