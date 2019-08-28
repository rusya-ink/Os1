#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("%d %d\n", sizeof(a), a);
    printf("%d %f\n", sizeof(b), b);
    printf("%d %lf\n", sizeof(c), c);
    return 0;

}