#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *d = opendir("/home/dariya/innopolisuniversityOS/week10/tmp");
    struct dirent *file;
    struct stat stat;
    if (d == NULL) {
        printf("Error");
        return 0;
    }
    chdir("/home/dariya/innopolisuniversityOS/week10/tmp");
    while ((file = readdir(d)) != NULL) {
        lstat(file->d_name, &stat);
        if (strcmp(".", file->d_name) == 0 || strcmp("..", file->d_name) == 0) {
            continue;
        }
        if (stat.st_nlink >= 2) {
            printf("%s\n", file->d_name);
        }
    }
    chdir("..");
    closedir(d);
    return 0;
}
