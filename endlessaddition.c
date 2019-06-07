
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int ft_strcmp(char *b, char *s)
{
    while (*b && *s && *b == *s)
    {
        b++;
        s++;
    }
    return (*b - *s);
}

void biggest_first(char ** big, char ** small)
{
    char * b = *big;
    char * s = *small;
    char * tmp;

    if (*b == '-')
        b++;
    if (*s == '-')
        s++;
    
    if ((ft_strlen(b) == ft_strlen(s) && ft_strcmp(b, s) < 0) || ft_strlen(b) < ft_strlen(s))
    {
        tmp = *big;
        *big = *small;
        *small = tmp;
    }
}


char  *strinit(char * b, char *s)
{
    char * res = (char*)malloc(sizeof(char) * ft_strlen(b) + 3);
    int i = ft_strlen(b) + 3 - 1;
    
    while (i >= 0)
    {
        res[i] = '\0';
        i--;
    }
    return res;
    
}

void printRevStr(char *s)
{
    int i = 0;
    char tmp;
    int len = ft_strlen(s) - 1;
    int halflen = len/2;
    while (halflen--)
    {
        tmp = s[i];
        s[i] = s[len];
        s[len] = tmp;
        len--;
        i++;
    }
    i = 0;
    while (s[i])
    {
        write(1, &s[i], 1);
        i++;
    }
}

int myabs (int a)
{
    return (a < 0 ? -a : a);
}
void substraction(char * b, char * s, char *res)
{
    int b_len = ft_strlen(b) - 1;
    int s_len = ft_strlen(s) - 1;
    int carry = 0;
    int i = 0;
    
    while (b_len >= 0)
    {
        carry += b[b_len] - '0';
        if (s_len >= 0)
            carry -= s[s_len] - '0';
        if (carry < 0)
        {
            res[i] = 10 - (myabs(carry % 10)) + '0';
            carry -= 10;
        }
        else
            res[i] = carry % 10 + '0';
        carry = carry / 10;
        b_len--;
        s_len--;
        i++;
    }
    printRevStr(res);

}

void addition(char * b, char * s, char *res)
{
    int b_len = ft_strlen(b) - 1;
    int s_len = ft_strlen(s) - 1;
    int carry = 0;
    int i = 0;
    
    while (b_len >= 0 || carry)
    {
        carry += b[b_len] - '0';
        if (s_len >= 0)
            carry += s[s_len] - '0';
        res[i] = carry % 10 + '0';
        carry = carry / 10;
        b_len--;
        s_len--;
        i++;
    }
    printRevStr(res);
}

int check_substr_neg(char **b, char **s)
{
    int substract = 0;
    if ((**b == '-' && **s != '-') || (**b != '-' && **s == '-')) //check operation
        substract = 1;
    if ((**b == '-' && **s == '-') || (**b == '-' && **s != '-')) //check minus sign
        write(1, "-", 1);
    //skip sign if any
    if (**b == '-')
        (*b)++;
    if (**s == '-')
        (*s)++;
    return substract;
}

int        main(int ac, char **av)
{
    if (ac == 3)
    {
        biggest_first(&av[1], &av[2]);
        char * res = strinit(av[1], av[2]);
        
        if (check_substr_neg(&av[1], &av[2]) == 1)
            substraction(av[1], av[2], res);
        else
            addition(av[1], av[2], res);
        free(res);
    }
    write(1, "\n", 2);
    return 0;
}

