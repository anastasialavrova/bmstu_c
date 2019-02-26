#include<stdio.h>

void line(int x1, int y1, int x2, int y2, int x, int y)
{
    int v1_x = x1 - x, v1_y = y1 - y, v2_x = x2 - x, v2_y = y2 - y;
    int vect = v1_x * v2_y - v1_y * v2_x;
    int scalar = v1_x * v2_x + v1_y * v2_y;
    if (vect == 0 && scalar <= 0)
        printf("Yes");
    else
        printf("No");
}

int main()
{
    int x1, y1, x2, y2, x, y;
    printf("Enter the first end of the line: ");
    int rc1 = scanf("%d %d", &x1, &y1);
    printf("\nEnter the second end of the line: ");
    int rc2 = scanf("%d %d", &x2, &y2);
    printf("\nEnter the point: ");
    int rc = scanf("%d %d", &x, &y);
    if (rc1 == 2 && rc2 == 2 && rc == 2)
        line(x1, y1, x2, y2, x, y);
    else
        printf("Error!");
}
