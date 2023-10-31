#include <math.h>
#include <stdio.h>

int main()
{

    double a;
    double b;
    double c;

    scanf("%lf %lf %lf\n", &a, &b, &c);

    // compute bhaskara
    double delta = b * b - 4 * a * c;

    if (a == 0 || delta < 0)
    {
        printf("Impossivel calcular\n");
        return 0;
    }
    double den = 2 * a;
    double sqrt_delta = sqrt(delta);

    double r1 = (-b + sqrt_delta) / den;
    double r2 = (-b - sqrt_delta) / den;

    printf("R1 = %.5lf\n", r1);
    printf("R2 = %.5lf\n", r2);

    return 0;
}