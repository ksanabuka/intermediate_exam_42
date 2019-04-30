#include <stdio.h>

void    print_doublon(int *a, int na, int *b, int nb)
{
    int tmp; 
    int i = 0;
    int j = 0;
    int flag = 0; 

    while (i < na && j < nb)
    {
        if (a[i] < b[j])
        {
            tmp = a[i];
            i++;
        }
        else if (a[i] > b[j])
        {
            tmp = b[j];
            j++;
        }
         else if (a[i] == b[j])
        {
            if (flag == 1)
                 printf(" ");
            tmp = b[j];
            printf("%d", tmp);

            j++;
            i++;
            flag = 1;

        }
        else if (i < na && tmp == a[i])
        {
            if (flag == 1)
                printf(" ");
            printf("%d", tmp);
            i++;
            flag = 1;

        }
        else if (j < nb && tmp == b[j])
        {
            if (flag == 1)
                printf(" ");
            printf("%d", tmp);
            j++;
            flag = 1;

        }
    }
    printf("\n");

}

int main (void)
{
   int  a[3] = { 100,  200, 300 };
   int na = 3;
   int  b[4] = { 1,    2,   3, 4};
   int nb = 4;
   print_doublon(a, na, b, nb);
   return 0;
}