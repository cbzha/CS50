#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int input = get_int("enter the height of the pyramid:");
    while (input < 1 || input > 8)
    {
        input = get_int("enter the height of the pyramid:");
    }
    int ip = input;
    for (int i = 0; i < input; i++)
    {
        for (int m = 0; m < ip - 1 ; m++)
        {
            printf(" ");
        }
        -- ip;
        for (int j = 0; j <= i ; j++)
        {
            printf("#");
        }
        printf("  ") ;       
        for (int n = 0; n <= i ; n++)
        {
            printf("#");
        }
        printf("\n");        
    }
}
