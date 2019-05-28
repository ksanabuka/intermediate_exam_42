#include <stdio.h>
#include <stdlib.h>

int mylen (char *s)
{
    int i = 0;
    while (s[i])
    {
        i++;
    }
    return i;
}

int smallestString(int * arr, int len)
{
    int i = 0;
    int tmp = arr[i];
    int smallest;
    while (i < len)
    {
        if (arr[i] < tmp)
        {
            tmp = arr[i];
            smallest = i; 
        }
        i++;
    }
    return smallest; 
}

char *strDup(char *s, int len)
{
    if (!s)
        return 0;
    char *res = (char*)malloc(sizeof(char)*len + 1);
    res[len] = '\0';
    int i = 0;

    while (len--)
    {
        res[i] = s[i];
        i++;
    }

    return res;
}

void createSubstrings(char *s, char **substrings, int qtySubstings)
{
    int strLen = mylen(s);
    int i = 0;
    int j = 0;
    int length = 1;

    while (j < qtySubstings)
    {
        while (j < qtySubstings && i < strLen && i + length - j < strLen)
        {
            // if (mylen(s + i) + length < strLen)
            // {
                substrings[j] =  strDup(s + i, length);
                printf("%s\n", substrings[j]);
                length++;
                j++;
        }
        i++; 
        length = 1;
    }

}

int findSub(char *sub, char*s)
{
    int i = 0;
    int j = 0;
    int p = 0;

    while (s[i])
    {
        while (s[i] && s[i] == sub[j])
        {
            i++;
            j++;
        }
        if (!sub[j])
            return 1;
        else 
        {
            p++;
            i = p;
            j= 0;
        }
    }
    if (!sub[j])
        return 1;
    else 
        return 0;
}

int main (int ac, char **av)
{
    int i = 1;
    int j = 0; 
    int *lens = (int*)malloc(sizeof(int) * (ac - 1));
    while(i < ac)
    {
        lens[j] = mylen(av[i]);
        i++;
        j++;
    }

    i = 0;
    int index = smallestString(lens, ac - 1);
    int lenSmallest = lens[index];


    int qtySubstrings = lenSmallest * (lenSmallest + 1) / 2;

    char ** substrings = (char**)malloc(sizeof(char*) * qtySubstrings);

    createSubstrings(av[index + 1] , substrings, qtySubstrings);
    
    i = 0; 
    j = 1; 
    
    while (i < qtySubstrings && j < ac)
    {

        while (findSub(substrings[i], av[j]) && j < ac)
        {
            j++; 
            if (j == ac)
            {
                printf("!!!%s\n", substrings[i]);
                free(lens);
                i = 0;
                while (i < qtySubstrings)
                {
                    free(substrings[i]);
                    i++;
                }
                free(substrings);
                exit(0);
            }
        }
        i++;
        j = 1; 
    }
}