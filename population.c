#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variables
    int startsize, endsize, year = 0;
    // TODO: Prompt for start size
    do
    {
        startsize = get_int("Enter the start size of llamas: ");
    }
    while ((startsize < 9));
    // TODO: Prompt for end size
    do
    {
        endsize = get_int("\nEnter the end size of llamas: ");
    }
    while (endsize < startsize);
    // TODO: Calculate number of years until we reach threshold
    int llamas = startsize;
    while (llamas < endsize)
    {
        llamas = llamas + (llamas / 3) - (llamas / 4);
        year++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", year);

}
