#include <stdio.h>

int isAlpha(char c)
{
    return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)) ? 1 : 0;
}

void addChValue(char c, int * arr)
{
    int index;
    if ((c >= 97 && c <= 122))
    {
        index = c - 97;
        arr[index]+= 1;
    }
    else if (c >= 65 && c <= 90)
    {
        index = c - 65;
        arr[index]+= 1;
    }
    else 
        return ; 

}

int giveValue(char c, int * arr)
{
    int index;
     if ((c >= 97 && c <= 122))
    {
        index = c - 97;
    }
    else if (c >= 65 && c <= 90)
    {
        index = c - 65;
    }
    else 
        return 0;
    int tmp = arr[index];
    arr[index] = -1; 
    return (tmp);
}

int main(int ac, char ** av)
{
    if (ac != 2)
   { 
        printf("\n");
        return 0;
    }

    int arr[26] = {0};

    int i = 0;
    while (av[1][i] != '\0')
    {
        addChValue(av[1][i], arr);
        i++;
    }

    i = 0;
    int value;
    int flag = 0;
    char c; 

    while (av[1][i] != '\0')
    {
        value = giveValue(av[1][i], arr);
        if (value != 0 && value != -1)
        {
            if (flag == 1)
            {
                printf(", ");
            }
            c = ((av[1][i] >= 97 && c <= 122))? av[1][i] : av[1][i] + 32;
            printf("%d%c", value, c);
            flag = 1;
        }
        i++;
    }
    printf("\n");

    return 0;
}