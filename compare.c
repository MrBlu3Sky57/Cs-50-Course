#include <stdio.h>

int main(void)
{
    int x;
    int y;

    printf("Enter two numbers:\n");
    scanf("%d %d", &x, &y);

    if (x > y)
    {
        printf("%d is greater than %d\n", x, y);
    }
    else if (x < y) {
        printf("%d is greater than %d\n", y, x);
    } else {
        printf("%d is equal to %d", x, y);
    }
}