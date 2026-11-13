#define USE_TEST                                                                             /// Створення макроса USE_TEST для включення тестування

#include <stdio.h>                                                                           /// Імпортування бібліотек 
#include <math.h>
#include <stdlib.h>
 
#define MAX_DATA 11                                                                         /// Визначення константи MAX_DATA для розміру масиву
void assert_equal_double(double expected, double actual, int precision);                    /// Прототип функції assert_equal_double для перевірки рівності чисел з плаваючою комоюй

int main () {
    #ifdef USE_TEST                                                                         /// Якщо макрос USE_TEST визначений, то використовується тестовий масив a та очікуваний результат ok_result
        double a[MAX_DATA] = {0.3, 0.7, 0.9, 1.3, 1.7, 1.9, 2.3, 2.7, 2.9, 3.3, 3.7};
        const double ok_result = 0.115584;                                                 /// ВІдповідь що повинна бути отримана при використанні тестових даних
    #else                                                                                   /// Якщо макрос USE_TEST не визначений, то використовується масив a, який заповнюється користувачем
        double a[MAX_DATA] = {0};
    #endif                                                                                  /// Завершення умовного оператора

        double sumLog = 0;
        double sumDen = 0;
    
    #ifndef USE_TEST                                                                        /// Якщо макрос USE_TEST не визначений, то користувач вводить значення масиву a
    
        for (int i=0; i<MAX_DATA; i++) {
            printf("Enter a[%d]: ", i+1);
            fflush(stdout);
            scanf("%lf", &a[i]);
        }
    #endif

     for (int i = 0; i < MAX_DATA; i++) {                                                   /// Цикл для обчислення суми логарифмів та суми знаменників
         double s = sin(a[i]);
         double c = cos(a[i]);
         double logArg = fabs(1.0 - c * c);

         if (logArg == 0.0) {                                                               /// Перевірка на нульовий аргумент логарифму
             fprintf(stderr, "Cannot calculate log(0) for a[%d]\n", i + 1);
             return 1;
         }

         sumLog += log(logArg);                                                             /// Додавання логарифму до суми логарифмів
         sumDen += cos(fabs(1.0 - s));                                                       /// Додавання до суми знаменників
     }

     if (sumDen == 0.0) {                                                                   /// Перевірка на нульовий знаменник
         fprintf(stderr, "The denominator is zero\n");
         return 1;
     }

     double S3 = pow(sin(sumLog), 2) / sumDen;                                             /// Обчислення значення S3

     #ifdef USE_TEST                                                                       /// Якщо макрос USE_TEST визначений, то перевіряється рівність обчисленого значення S3 з очікуваним результатом ok_result
         assert_equal_double(ok_result, S3, 6);                                            /// Виклик функції assert_equal_double для перевірки рівності обчисленого значення S3 з очікуваним результатом ok_result з точністю до 6 знаків після коми
     #endif

     printf("S3 = %lf\n", S3);                                                             /// Виведення обчисленого значення S3 на екран

     return 0;
}

void assert_equal_double(double expected, double actual, int precision)                    /// Функція для перевірки рівності двох чисел з плаваючою комою з заданою точністю
{
#ifdef USE_TEST                                                                            /// Якщо макрос USE_TEST визначений, то виконується перевірка рівності двох чисел з плаваючою комою з заданою точністю
    double factor = pow(10.0, precision);
    double rounded_actual = round(actual * factor) / factor;
    double rounded_expected = round(expected * factor) / factor;

    if (rounded_actual == rounded_expected) {                                             /// Якщо обчислене значення S3 дорівнює очікуваному результату ok_result з точністю до 6 знаків після коми, то виводиться повідомлення про успішне проходження тесту
        fprintf(stderr, "Test ok! Expected == Actual == %.6f\n", rounded_actual);         /// Виведення повідомлення про успішне проходження тесту
    } else {
        fprintf(stderr, "Test FAIL! Expected %.6f != Actual %.6f\n",                      /// Виведення повідомлення про невідповідність очікуваного та фактичного результатів
                rounded_expected, rounded_actual);
        exit(1);
    }
#endif
}