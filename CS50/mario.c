#include <cs50.h>
#include <stdio.h>

void print_pattern(int number, string c);
void print_line(int iter, int height);

int main(void)
{
    //Get height
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
    
    //print each line
    for (int i = 0; i < height; i++)
    {
        print_line(i, height);
    }
}

//prints single line based on the height and iteration
void print_line(int iter, int height)
{
    print_pattern(height - iter - 1, " ");
    print_pattern(iter + 1, "#");
    printf("  ");
    print_pattern(iter + 1, "#");
    printf("\n");
}

//Prints the same character given number of times
void print_pattern(int number, string c)
{
    for (int i = 0; i < number; i++)
    {
        printf("%s", c);
    }
}
