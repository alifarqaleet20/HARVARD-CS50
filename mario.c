#include <cs50.h>
#include <stdio.h>

int main(void)
//condition of input
{
    int n;
    do
    {

        n = get_int("height= ");

    }
    while ((n < 1) || (n > 8));

//the iteration of #
    //rows
    for (int i = 0; i < n; i++)
    {
        //columns
        for (int j = i; j < n - 1; j++)
        {
            printf(" ");
        }

        for (int k = n; k > n - 1 - i; k--)
        {
            printf("#");
        }
        printf("\n");
    }


}