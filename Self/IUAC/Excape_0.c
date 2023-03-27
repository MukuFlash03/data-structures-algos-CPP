#include <stdio.h>

int main()
{
    char ch1=' ', ch2=' ';

    while (1)
    {   
        scanf("%c", &ch1);
        if (ch1 == '*' && ch2 == '*')
        {
            printf("Repeated character -> Escape sequence initiated...\n");
            break;
        }
        //printf("%c",ch1);
        ch2 = ch1;
    }

    return 0;
}