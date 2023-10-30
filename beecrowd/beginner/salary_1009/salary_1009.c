#include <stdio.h>

int main()
{

    char employee_name[100];
    double salary;
    double total_sold;

    scanf("%s\n", employee_name);
    scanf("%lf\n", &salary);
    scanf("%lf\n", &total_sold);

    printf("TOTAL = R$ %.2lf\n", salary + total_sold * .15);

    return 0;
}