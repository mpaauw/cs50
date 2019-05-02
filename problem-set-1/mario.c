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
        // build output string:
        char output[height];
        for(int j = 0; j < height; j++)
        {
            if(j < (height - i))
            {
                output[j] = ' ';
            }
            else
            {
                output[j] = '#';    
            }
        }
        
        // print left side of pyramid:
        for(int j = 0; j < height; j++)
        {
            printf("%c", output[j]);
        }
        
        // print center gap:
        printf("  ");
        
        // print right side of pyramid:
        for(int j = height - 1; j >= 0; j--)
        {
            printf("%c", output[j]);
        }
        
        // finally, print line break:
        printf("\n");
    }
}
