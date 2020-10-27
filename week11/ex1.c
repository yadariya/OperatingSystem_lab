#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

/* initial string in ex1.txt : I love cinnabons
 * final string in ex1.txt : Have a nice day */
int main() {
    
    int file = open("/home/dariya/innopolisuniversityOS/week11/ex1.txt", O_RDWR); // I open file for R&W
    if (file < 0) { printf("Error in file open "); } //print "Error" if there is some problems

    struct stat filestat = {};
    if (fstat(file, &filestat)) { printf("Error in meta-data"); } //print "Error" if there is some problems

    off_t size = filestat.st_size;

    char *add;
    add = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    if (add == MAP_FAILED) { printf("Error in mmap "); } //print "Error" if there is some problems
    add[0] = 'H';
    add[1] = 'a';
    add[2] = 'v';
    add[3] = 'e';
    add[4] = ' ';
    add[5] = 'a';
    add[6] = ' ';
    add[7] = 'n';
    add[8] = 'i';
    add[9] = 'c';
    add[10] = 'e';
    add[11] = ' ';
    add[12] = 'd';
    add[13] = 'a';
    add[14] = 'y';
    return 0;
}