#include <stdio.h>
 
int main() {
    
    const double PI = 3.14159;
    double r;
    
    scanf("%lf\n", &r);
    
    printf("A=%.4lf\n", (PI * r * r));
 
    return 0;
}