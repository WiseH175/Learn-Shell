#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int word_count = 0, line_count = 0, char_count = 0;

    // open the file
    file = fopen("filename.txt", "r");

    // check if file exists
    if (file == NULL) {
        printf("File does not exist.");
        return 0;
    }

    // loop through file and count words, lines, and characters
    while ((ch = fgetc(file)) != EOF) 
    {
        char_count++;
        if (ch == ' ' || ch == '\n') {
            word_count++;
        }
        if (ch == '\n') {
            line_count++;
        }
    }

    // close the file
    fclose(file);

    // print the count of words, lines, and characters
    printf("The number of words in the file is %d.\n", word_count);
    printf("The number of lines in the file is %d.\n", line_count);
    printf("The number of characters in the file is %d.", char_count);

    return 0;
}

