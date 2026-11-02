#define USE_TEST

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_DATA 11

void assert_equal_double(double expected, double actual, int precision);

int main () {
    #ifdef USE_TEST
        double a[MAX_DATA] = {0.3, 0.7, 0.9, 1.3, 1.7, 1.9, 2.3, 2.7, 2.9, 3.3, 3.7};
        const double ok_result = -0.357614;
    #else 
        double a[MAX_DATA] = {0};
    #endif

        double sumLog = 0;
        double sumDen = 0;

    #ifndef USE_TEST
    
        for (int i=0; i<MAX_DATA; i++) {
            printf("Enter a[%d]: ", i+1);
            fflush(stdout);
            scanf("%lf", &a[i]);
        }
    #endif

     for (int i = 0; i < MAX_DATA; i++) {
         double s = sin(a[i]);
         double c = cos(a[i]);
         double logArg = fabs(1.0 - c * c);

         if (logArg == 0.0) {
             fprintf(stderr, "Cannot calculate log(0) for a[%d]\n", i + 1);
             return 1;
         }

         sumLog += log(logArg);
         sumDen += c * fabs(1.0 - s);
     }

     if (sumDen == 0.0) {
         fprintf(stderr, "The denominator is zero\n");
         return 1;
     }

     double S3 = pow(sin(sumLog), 2) / sumDen;

     #ifdef USE_TEST
         assert_equal_double(ok_result, S3, 6);
     #endif
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