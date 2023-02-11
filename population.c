#include <stdio.h>

int get_start_size(void);
int get_end_size(int start_size);
int return_years(int start_size, int end_size);

int main(void)
{

    // get start size
    int start_size = get_start_size();

    // get end size
    int end_size = get_end_size(start_size);

    // print years
    printf("Years: %i\n", return_years(start_size, end_size));
}




int get_start_size(void)
{
    int start_size;

    do
    {
        printf("Start size: ");
        scanf("%i", &start_size);
    } while (start_size < 9);
    return start_size;
}

int get_end_size(int start_size)
{
    int end_size;

    do
    {
        printf("End size: ");
        scanf("%i", &end_size);
    } while (end_size < start_size);
    return end_size;
}

int return_years(int start_size, int end_size)
{
     int i = 0;
    while (start_size < end_size)
    {
        start_size = start_size + start_size/3 - start_size/4;
        i++;
    }
    return i;
}