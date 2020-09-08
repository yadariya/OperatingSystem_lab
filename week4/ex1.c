#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int n = 30;
  pid_t pid = fork();
  for (int i = 0; i < n; i += 1) {
    if (pid != 0) {
      printf("Hello from parent %d %d\n", getpid(), i);
    } else {
      printf("Hello from child %d %d\n", getpid(), i);
    }
  }
}
