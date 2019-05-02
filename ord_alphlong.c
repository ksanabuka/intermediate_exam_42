#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


typedef struct  s_words
  {
    int                 len;
    char *              pnt;
  }                     t_words;


int isS(char c)
{
    return (c == 32 || (c >= 9 && c <= 13)) ? 1 : 0;
}

int cW(char * s)
{
    int i = 0;
    int c = 0;
    while (s[i])
    {
        while (isS(s[i]))
            i++;
        if (s[i] && !isS(s[i]))
            c++;
        while (s[i] && !isS(s[i]))
            i++;
    }
    return c;
}

int comp(t_words fw, t_words sw)
{
    int newlen;
    int i = 0;

    if (fw.len > sw.len)
        return 0;
    else if (fw.len < sw.len)
        return 1;
    else
    {
        newlen = fw.len;
        while(newlen--)
        {
            if ((fw.pnt[i] >= 65 &&  fw.pnt[i] <= 90) && (sw.pnt[i] >= 97 &&  sw.pnt[i] <= 122) && (fw.pnt[i] == sw.pnt[i] - 32))
                i++;
            else if ((fw.pnt[i] >= 97 &&  fw.pnt[i] <= 122) && (sw.pnt[i] >= 65 &&  sw.pnt[i] <= 90) && (fw.pnt[i] == sw.pnt[i] + 32))
                i++;
            else if (fw.pnt[i] < sw.pnt[i])
                return 1;
            else if (fw.pnt[i] > sw.pnt[i])
                return 0;
            else
            {
                i++;
            }
        }
        return 1;
    }
}

void swap(t_words *fw, t_words *sw)
{
    t_words tmp;
    tmp = *fw;
    *fw = *sw;
    *sw = tmp; 
}

void bubbleSort(int size, t_words *allWords)
{
    int i = 0;
    int swp = 1;

    while (swp == 1)
    {
        swp = 0;
        i = 0;
        while (i < size)
        {
            if (i + 1 < size && !comp(allWords[i], allWords[i + 1]))
            {
                swap(&allWords[i], &allWords[i + 1]);
                swp = 1; 
            }
            i++;
        }
        size--;
    }
}

void print1w(t_words w)
    {
        int i = w.len;
        int j = 0;
        char c;

        while (j < i)
        {
            c = w.pnt[j];
            write(1, &c, 1);
            j++;
        }
    }

void print1lenWords(int size, t_words *allWords)
{
    int i = 0;
    while (i < size)
    {
        print1w(allWords[i]);
        i++;
        if (allWords[i].len == allWords[i - 1].len)
            write(1, " ", 1);
        else 
            write(1, "\n", 1);
        
    }
}

void ord_alphlong(char * s)
{
    int countW = cW(s);
    t_words *allWords = (t_words*)malloc(sizeof(t_words) * countW);

    int i = 0;
    int wl;
    int j = 0;
    int flag;

//complete the structure 

    while (s[i])
    {
        wl = 0;
        while (isS(s[i]))
            i++;
        if (s[i] && !isS(s[i]))
        {
            allWords[j].pnt =  s + i;
            flag = 1;
        }
        while (s[i] && !isS(s[i]))
        {
            wl++;
            i++;
        }
        if (flag == 1)
        {
            allWords[j].len = wl;
            j++;
            flag = 0;
        }
    }

    bubbleSort(countW, allWords);
    print1lenWords(countW, allWords);


    free(allWords);
}


int main (int ac, char ** av)
{
    if (ac != 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    ord_alphlong(av[1]);
    return 0;
}