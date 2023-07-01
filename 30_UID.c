#include <stdio.h>
#include <unistd.h>

int main() {
    char *filename = "f2.txt";
    uid_t uid = getuid();
    gid_t gid = getgid();

    if (access(filename, R_OK) == 0) {
        printf("User %d with group %d has read access to file %s.\n", uid, gid, filename);
    } else {
        printf("User %d with group %d does not have read access to file %s.\n", uid, gid, filename);
    }

    if (access(filename, W_OK) == 0) {
        printf("User %d with group %d has write access to file %s.\n", uid, gid, filename);
    } else {
        printf("User %d with group %d does not have write access to file %s.\n", uid, gid, filename);
    }

    if (access(filename, X_OK) == 0) {
        printf("User %d with group %d has execute access to file %s.\n", uid, gid, filename);
    } else {
        printf("User %d with group %d does not have execute access to file %s.\n", uid, gid, filename);
    }

    return 0;
}

