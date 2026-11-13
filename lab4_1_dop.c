 #define USE_TEST 
 
 #include <stdio.h>
 #include <math.h>

 #define MAX_DATA 11

 int main() {
    #ifdef USE_TEST
        double a[MAX_DATA] = {0.3, 0.7, 0.9, 1.3, 1.7, 1.9, 2.3, 2.7, 2.9, 3.3, 3.7};
    #else
        double a[MAX_DATA] = {0};
    #endif
    double sumLog, sumDen;
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
            printf("Cannot calculate log(0) for a[%d]\n", i + 1);
            return 1;
        }
        sumLog += log(logArg);
        sumDen += cos(fabs(1.0 - s));
    }
    if (sumDen == 0.0) {
        printf("The denominator is zero\n");
        return 1;
    }
    double S3 = sin(sumLog) * sin(sumLog) / sumDen;
    printf("S3 = %lf\n", S3);
    return 0;
 }
