#include <stdio.h>

int main()
{
    const int SIZE = 10000;

    int T;
    char string[SIZE];
    scanf("%d\n", &T);

    for (int i = 0; i < T; i++)
    {
        scanf("%s\n", string);

        char even[SIZE / 2];
        char odd[SIZE / 2];

        int e = 0;
        int o = 0;
        for (int j = 0; string[j] != '\0'; j++)
        {
            if (j % 2 == 0)
            {
                even[e] = string[j];
                e++;
            }
            else
            {
                odd[o] = string[j];
                o++;
            }
        }
        even[e] = '\0';
        odd[o] = '\0';
        printf("%s %s\n", even, odd);
    }
    return 0;
}
