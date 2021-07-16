#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    double max=32767;
    for(i=1;i<=10;i++)
        printf("%f\n", rand()/RAND_MAX);
    return 0;
}

