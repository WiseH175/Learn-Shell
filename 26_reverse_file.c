#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    long int pos;
    char ch;

    fp1 = fopen("filename.txt", "r");
    fp2 = fopen("f2.txt", "w");

    // Move the file pointer to the end of the file
    fseek(fp1, 0, SEEK_END);

    // Get the current position of the file pointer
    pos = ftell(fp1);

    // Read the file character by character from the end and write to another file
    while(pos--) {
        fseek(fp1, pos, SEEK_SET);
        ch = fgetc(fp1);
        fputc(ch, fp2);
    }


    fclose(fp1);
    fclose(fp2);

    return 0;
}

