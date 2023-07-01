#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int count = 0;

    file = fopen("14_blanks.c", "r");
    
    if (file == NULL) {
        printf("File does not exist.");
        return 0;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ') count++;
    }

    fclose(file);

    printf("The number of blanks in the file is %d.", count);

    return 0;
}

