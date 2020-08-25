#include <stdio.h>
#include<limits.h>
#include <float.h>

int main() {
    int var1;
    float var2;
    double var3;
    var1 = INT_MAX; //assign maximum for integer
    var2 = FLT_MAX; //assign maximum for float
    var3 = DBL_MAX; //assign maximum for double
    printf("%u\n", sizeof(var1)); //prints the size of integer
    printf("%u\n", sizeof(var2)); //prints the size of float
    printf("%u\n", sizeof(var3)); //prints the size of double
    printf("%d\n", var1); //prints the value of integer
    printf("%f\n", var2); //prints the value of float
    printf("%lf", var3); //prints the value of double
    return 0;
}
