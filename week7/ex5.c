#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char **s = malloc(sizeof(char));
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n", *s); //smth was wrong with closing quotes and bracket
    memcpy(*s, foo, strlen((foo)));// we use memcpy to copy strings;
    printf("s[0] is %s\n", s[0]);
    return (0);
}
/**
    output:

s is Hello World
s[0] is Hello World

 */