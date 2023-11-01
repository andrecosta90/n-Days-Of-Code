#include <stdio.h>

int main()
{
    float n1, n2, n3, n4;
    int w1 = 2, w2 = 3, w3 = 4, w4 = 1;

    scanf("%f %f %f %f\n", &n1, &n2, &n3, &n4);

    float average = (n1 * w1 + n2 * w2 + n3 * w3 + n4 * w4) / (w1 + w2 + w3 + w4);
    printf("Media: %.1f\n", (average));

    if (average >= 7)
    {
        printf("Aluno aprovado.\n");
    }
    else if (average < 5)
    {
        printf("Aluno reprovado.\n");
    }
    else
    {
        float n5;
        scanf("%f\n", &n5);
        printf("Aluno em exame.\n");
        printf("Nota do exame: %.1f\n", n5);

        float new_average = (average + n5) / 2;
        printf("%s\n", (new_average >= 5) ? "Aluno aprovado." : "Aluno reprovado.");
        printf("Media final: %.1f\n", new_average);
    }
}