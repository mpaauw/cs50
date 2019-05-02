#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid_half(int height);

int main(void)
{
    print_pyramid_half(get_height());
}

int get_height(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    } while(num < 1 || num > 8);
    return num;
}

void print_pyramid_half(int height)
{
    // print left half of pyramid:
    for(int i = 1; i <= height; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(j < (height - i))
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
    }
}
