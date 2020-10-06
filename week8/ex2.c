#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//10 MB = 1024*1024

int main() {
    for (int i = 0; i < 100; i++) {
        void *ptr = malloc(10 * 1024 * 1024);
        memset(ptr, 0, 10 * 1024 * 1024);  // set to 0
        sleep(1);
    }
    return 0;
}
/** My findings: si and so is equal to 0 */
