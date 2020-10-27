#include <stdio.h>
#include <unistd.h>

int main() {
    fprintf(stdout, "H");
    sleep(1);
    fprintf(stdout, "e");
    sleep(1);
    fprintf(stdout, "l");
    sleep(1);
    fprintf(stdout, "l");
    sleep(1);
    fprintf(stdout, "o");
    fflush(stdout);
    return 0;
}