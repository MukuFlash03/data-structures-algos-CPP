#include <stdio.h>
#include <stdbool.h>

bool flag;

void menu()
{
    printf("1. Sensor\n");
    printf("2. Channel\n");#include <stdio.h>
#include <stdbool.h>

bool flag;

void menu()
{
    printf("1. Sensor\n");
    printf("2. Channel\n");
    printf("3. Curve\n");
    flag = false;
}

int main()
{
    char ch;
    int a1, a2;
    //scanf("%c",&ch);
    //printf("%d ASCII\n",ch);

    menu();
    while(1 && !flag)
    {
        scanf("%c",&ch);
        a1 = ch;
    switch ((int)ch)
    {
        case 48:
            printf("%d entered\n", ch-48);
            break;
        case 42:
            printf(". entered\n");
            //printf("%d\t %d\n", a1, a2);
            if (a1 == 42 && a2 == 42)
                {
                    printf("Escape...\n");
                    flag = true;
                    menu();
                }
            break;
        case 35:
            printf("ENTER pressed\n");
            break;
    }
    a2 = a1;
    }
    
    
    return 0;
}
    printf("3. Curve\n");
    flag = false;
}

int main()
{
    char ch;
    int a1, a2;
    //scanf("%c",&ch);
    //printf("%d ASCII\n",ch);

    menu();
    while(1 && !flag)
    {
        scanf("%c",&ch);
        a1 = ch;
    switch ((int)ch)
    {
        case 48:
            printf("%d entered\n", ch-48);
            break;
        case 42:
            printf(". entered\n");
            //printf("%d\t %d\n", a1, a2);
            if (a1 == 42 && a2 == 42)
                {
                    printf("Escape...\n");
                    flag = true;
                    menu();
                }
            break;
        case 35:
            printf("ENTER pressed\n");
            break;
    }
    a2 = a1;
    }
    
    
    return 0;
}