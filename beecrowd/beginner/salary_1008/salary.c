#include <stdio.h>
 
int main() {
    
    int employee_number;
    int worked_hours;
    double amount_per_hour;

    
    scanf("%d\n", &employee_number);
    scanf("%d\n", &worked_hours);
    scanf("%lf\n", &amount_per_hour);
    
    printf("NUMBER = %d\n", employee_number);
    printf("SALARY = U$ %.2lf\n", worked_hours*amount_per_hour);
 
    return 0;
}