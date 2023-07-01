#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <utime.h>
#include <errno.h>

int main() {
    const char *src_file = "filename.txt";
    const char *dest_file = "hello.sh";

    // Get the last access and modification times of the source file
    struct stat src_stat;
    
    stat(src_file, &src_stat);

    // Set the last access and modification times of the destination file
    struct utimbuf new_times = {src_stat.st_atime, src_stat.st_mtime};
    
    utime(dest_file, &new_times);

    printf("File time stamps have been updated successfully.\n");

    return 0;
}

