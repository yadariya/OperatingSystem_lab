#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(void) {

    FILE *output = fopen("/home/dariya/innopolisuniversityOS/week12/ex1.txt", "w");
    int inf = open("/dev/random", O_RDONLY);
    if (inf < 0) {
        fprintf(stderr, "Problem with file");
    }
    char string[20];
    size_t size = 0;
    while (size < sizeof(string)) {
        ssize_t out = read(inf, string + size, (sizeof string) - size);
        if (out < 0) {
            fprintf(stderr, "Cannot read information\n");
        }
        size += out;
    }
    close(inf);
    fprintf(output, "%s\n", string);
    fclose(output);
}