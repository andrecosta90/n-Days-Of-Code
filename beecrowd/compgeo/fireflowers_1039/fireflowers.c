#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char *is_circle_inside_circle(int r1, int x1, int y1, int r2, int x2, int y2);
float compute_distance(int xc, int yc, int xp, int yp);

int main()
{
    int n1, n2, n3, n4, n5, n6;
    char row[1024];

    while (fgets(row, sizeof(row), stdin) != NULL)
    {

        sscanf(row, "%d %d %d %d %d %d\n", &n1, &n2, &n3, &n4, &n5, &n6);

        printf("%s\n", is_circle_inside_circle(n1, n2, n3, n4, n5, n6));
    }
}

float compute_distance(int xc, int yc, int xp, int yp)
{
    return sqrt(pow(xp - xc, 2) + pow(yp - yc, 2));
}

char *is_circle_inside_circle(int r1, int x1, int y1, int r2, int x2, int y2)
{

    float dist = compute_distance(x1, y1, x2, y2);
    int diff = r1 - r2;

    if (dist <= diff) 
    {
        return "RICO";
    }

    return "MORTO";
}