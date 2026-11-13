 #include <stdio.h>                                       /// Імпортування бібліотек0.3
 #include <math.h>

 #define MAX_DATA 11                                      /// Визначення константи MAX_DATA для розміру масиву

 int main() {
    double a[MAX_DATA] = {0};
    double sumLog = 0;
    double sumDen = 0;

    for (int i=0; i<MAX_DATA; i++) {                      /// Цикл для введення значень масиву a
        printf("Enter a[%d]: ", i+1);
        fflush(stdout);
        scanf("%lf", &a[i]);
    }

    for (int i = 0; i < MAX_DATA; i++) {                 /// Цикл для обчислення суми логарифмів та суми знаменників
        double s = sin(a[i]);
        double c = cos(a[i]);
        double logArg = fabs(1.0 - c * c);

        if (logArg == 0.0) {                            /// Перевірка на нульовий аргумент логарифму
            printf("Cannot calculate log(0) for a[%d]\n", i + 1);
            return 1;
        }

        sumLog += log(logArg);
        sumDen += cos(fabs(1.0 - s));
    }

    if (sumDen == 0.0) {                               /// Перевірка на нульовий знаменник
        printf("The denominator is zero\n");
        return 1;
    }

    double S3 = sin(sumLog) * sin(sumLog) / sumDen;   /// Обчислення значення S3
    printf("S3 = %lf\n", S3);

    return 0;
 }