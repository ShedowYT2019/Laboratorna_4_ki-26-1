 #include <stdio.h>
 #include <math.h>

 #define MAX_DATA 11

 int main() {
    double a[MAX_DATA] = {0};
    double S3 = 0;

    for (int i=0; i<MAX_DATA; i++) {
        printf("Enter a[%d]: ", i+1);
        fflush(stdout);
        scanf("%lf", &a[i]);
    }

    for (int i = 0; i < MAX_DATA; i++) S3 += sin(a[i]*a[i]);
    printf("S3 = %lf\n", S3);

    return 0;
 }
