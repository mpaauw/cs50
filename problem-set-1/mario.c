#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramids(int height);

int main(void)
{
    print_pyramids(get_height());
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

void print_pyramids(int height)
{
    for(int i = 1; i <= height; i++)
    {
        // print left side of pyramid:
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
        
        // print center gap:
        printf("  ");
        
        // print right side of pyramid:
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        
        // finally, print line break:
        printf("\n");
    }
}
