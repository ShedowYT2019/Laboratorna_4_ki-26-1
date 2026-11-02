 #include <stdio.h>
 #include <math.h>

 #define MAX_DATA 10

 int main() {
    double a[MAX_DATA] = {0};
    double sumLog = 0;
    double sumDen = 0;

    for (int i=0; i<MAX_DATA; i++) {
        printf("Enter a[%d]: ", i+1);
        fflush(stdout);
        scanf("%lf", &a[i]);
    }

    for (int i = 0; i < MAX_DATA; i++) {
        double s = sin(a[i]);
        double c = cos(a[i]);
        double logArg = fabs(1.0 - c * c);

        if (logArg == 0.0) {
            printf("Cannot calculate log(0) for a[%d]\n", i + 1);
            return 1;
        }

        sumLog += log(logArg);
        sumDen += c * fabs(1.0 - s);
    }

    if (sumDen == 0.0) {
        printf("The denominator is zero\n");
        return 1;
    }

    double S3 = sin(sumLog) * sin(sumLog) / sumDen;
    printf("S3 = %lf\n", S3);

    return 0;
 }
