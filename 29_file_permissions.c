#include <stdio.h>
#include <sys/stat.h>

int main() {
    // File name
    char *file_name = "f2.txt";

    // Get file permissions
    struct stat file_stat;
    stat(file_name, &file_stat);
    mode_t file_perms = file_stat.st_mode;

    // Print each permission bit
    printf("Owner permissions: %c%c%c\n", 
           (file_perms & S_IRUSR) ? 'r' : '-',
           (file_perms & S_IWUSR) ? 'w' : '-',
           (file_perms & S_IXUSR) ? 'x' : '-');
    printf("Group permissions: %c%c%c\n", 
           (file_perms & S_IRGRP) ? 'r' : '-',
           (file_perms & S_IWGRP) ? 'w' : '-',
           (file_perms & S_IXGRP) ? 'x' : '-');
    printf("Others permissions: %c%c%c\n", 
           (file_perms & S_IROTH) ? 'r' : '-',
           (file_perms & S_IWOTH) ? 'w' : '-',
           (file_perms & S_IXOTH) ? 'x' : '-');

    return 0;
}

