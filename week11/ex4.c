#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>

int main(void) {
    char *src;
    char *dest;
    int src_file;
    int dest_file;
    src_file = open("/home/dariya/innopolisuniversityOS/week11/ex1.txt", O_RDONLY);
    if (src_file < 0) { printf("Error in opening src file"); } //print "Error" if there is some problems
    struct stat filestat = {};
    if (fstat(src_file, &filestat)) { printf("Error in meta-data"); } //print "Error" if there is some problems
    off_t size = filestat.st_size;
    src = mmap(NULL, size, PROT_READ, MAP_PRIVATE, src_file, 0);
    if (src == MAP_FAILED) { printf("Error in mmap "); } //print "Error" if there is some problems
    dest_file = open("/home/dariya/innopolisuniversityOS/week11/ex1.memcpy.txt", O_RDWR);
    if (dest_file < 0) { printf("Error in opening dest file"); }//print "Error" if there is some problems
    if (ftruncate(dest_file, size) == -1) { printf("Error"); }//print "Error" if there is some problems
    dest = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, dest_file, 0);
    if (dest == MAP_FAILED) { printf("Error"); }
    memcpy(dest, src, size);
    return 0;
}