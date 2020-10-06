#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdio.h>

//10 MB = 1024*1024

int main() {
    struct rusage resource_usage;
    for (int i = 0; i < 100; i++) {
        void *ptr = malloc(10 * 1024 * 1024);
        memset(ptr, 0, 10 * 1024 * 1024);  // set to 0
        getrusage(RUSAGE_SELF, &resource_usage);
        printf("Memory usage = %ld\n", resource_usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}
/** My findings:
Memory usage = 11284
Memory usage = 21676
Memory usage = 31972
Memory usage = 42268
Memory usage = 52564
Memory usage = 62860
Memory usage = 72892
Memory usage = 83188
Memory usage = 93484
Memory usage = 103780
Memory usage = 114076
Memory usage = 124108
Memory usage = 134404
Memory usage = 144700
Memory usage = 154996
Memory usage = 165292
Memory usage = 175324
Memory usage = 185620
Memory usage = 195916
 * */
