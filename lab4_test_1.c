#define USE_TEST

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_DATA 11

void assert_equal_double(double expected, double actual, int precision);

int main () {
    #ifdef USE_TEST
        double a[MAX_DATA] = {0.3, 0.7, 0.9, 1.3, 1.7, 1.9, 2.3, 2.7, 2.9, 3.3, 3.7};
        const double ok_result = 2.839147;
    #else 
        double a[MAX_DATA] = {0};
    #endif

        double S3 = 0;

    #ifndef USE_TEST
    
        for (int i=0; i<MAX_DATA; i++) {
            printf("Enter a[%d]: ", i+1);
            fflush(stdout);
            scanf("%lf", &a[i]);
        }
    #endif

     for (int i=0; i<MAX_DATA; i++) S3 += sin(a[i]*a[i]);

     assert_equal_double(ok_result, S3, 6);
     printf("S3 = %lf\n", S3);

     return 0;
}

void assert_equal_double(double expected, double actual, int precision)
{
    #ifdef USE_TEST
        double v = trunc(actual * pow(10, precision))/pow(10 , precision);
        if (v == expected) {
            fprintf(stderr, "Test ok! Expected == Actual == %.15g\n", expected);
            fflush(stderr);
        }    
        else {
            fprintf(stderr, "Test FAIL! Expected %.15g != Actual %.15g\n", expected, v);
            exit(1);
        }
    #endif
}