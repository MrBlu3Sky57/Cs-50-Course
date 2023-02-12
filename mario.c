#include <stdio.h>

int get_user_input(void);
void print_pyramids(int height);

int main(void)
{
    // Get user input
    int height = get_user_input();

    // Print pyramids
    print_pyramids(height);
}

int get_user_input(void)
{
    int height;

    do
    {
        printf("Height: ");
        scanf("%i", &height);
    }
    while (height < 1 || height > 8);
    return height;
}

void print_pyramids(int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (height - (i + 1)); j++)
        {
            printf(" ");
        }
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < (i + 1); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
