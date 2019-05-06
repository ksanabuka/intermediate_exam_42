#include <stdlib.h>

typedef struct  s_Heights
  {
    int           height;
    int           index;
  }               t_heights;

void sortHeights(int *his, int size, t_heights *all_heights)
{
    int i = 0;
    int j = 0; 
    while (i < size)
    {
        while(i < size && his[i] == 0)
        {
            i++;
        }
        if (i < size && his[i] > 0)
        {
            all_heights[j].height = his[i];
            all_heights[j].index = i; 
            j++; 
            i++;
        }
    }

    while (j < size)
    {
        all_heights[j].index = -1;
        all_heights[j].height = -1;
        j++;
    }

    i = 0;
    j = 0;
    int tmp;
    int tmp1;
    int swap = 1;

    while (swap == 1)
    {
        swap = 0;
        i = 0; 
        while( i < size && i + 1 < size && all_heights[i].index != -1)
        {
            if (all_heights[i].height < all_heights[i + 1].height)
            {
                tmp = all_heights[i].height;
                tmp1 = all_heights[i].index;
                all_heights[i].height = all_heights[i + 1].height;
                all_heights[i].index = all_heights[i + 1].index;
                all_heights[i + 1].height = tmp;
                all_heights[i + 1].index = tmp1;
                swap = 1;
            }
            i++;
        }
        size--;
    }
}

int find_bars_in_sq(int *his, int size, int pos1, int pos2)
{
    int i = pos1 + 1;
    int bars_to_del = 0; 
    while (i < size && i < pos2)
    {
        if (his[i] != 0)
            bars_to_del += his[i];
        i++;
    }
    return bars_to_del;
}

int calculateVolumeBetweenTwoBars(int *his, int size, int pos1, int pos2)
{
    if (pos1 < 0 || pos2 < 0)
        return -1;
    if (pos1 == pos2 + 1)
        return 0;
    int index_diff_length_sq = (pos1 > pos2) ? pos1 - pos2 - 1: pos2 - pos1 - 1;
    int height_sq = (his[pos1] < his[pos2]) ? his[pos1] : his[pos2];
    int volume = index_diff_length_sq * height_sq - find_bars_in_sq(his, size, pos1, pos2);
    return volume;
}

int findNextBar(int *his, int size, int start)
{
    if (start >= size || start < 0)
    {
        return -1;
    }
    int i = start; 
    while (i < size)
    {
        while (i < size && his[i] == 0)
            i++;
        if (i < size && his[i] > 0)
            return i;
        else 
            return -1;
    }
    return -1;
}

int findHighestPair(int *his, int size, int curIndex, t_heights *all_heights)
{
    int i = 0; 
    int tmp = findNextBar(his, size, curIndex + 1);
    
    if (tmp == -1)
        return -1;

    if (his[tmp] > his[curIndex])
        return tmp; 
    else
    {
        while (i < size)
        {
            if (his[curIndex] == all_heights[i].height)
            {
                while (i < size && all_heights[i].index <= curIndex)
                    i++;
                if (all_heights[i].index > curIndex)
                    return (all_heights[i].index);
            }
            else 
                i++;
        }
        return tmp;
    }
}

int    volume_histogram(int *his, int size)
{
    t_heights *all_heights = (t_heights *)malloc(sizeof(t_heights) * size);
    int curIndex;
    int HIghestPairIndex;
    int volume = 0;
    sortHeights(his, size, all_heights);
    
    curIndex = findNextBar(his, size, 0);
    if (curIndex < 0)
        return 0;

    while (curIndex < size)
    {
        HIghestPairIndex = findHighestPair(his, size, curIndex, all_heights);
        if (HIghestPairIndex < 0)
            return volume;
        volume += calculateVolumeBetweenTwoBars(his, size, curIndex, HIghestPairIndex);
        curIndex = HIghestPairIndex;
    }
    return volume;
}

// all_heights[].height
// all_heights[].index


#include <stdio.h>

int main(void)
{
   int    histogram[] = {0, 0, 2, 0, 0};
    int    size = 5;
    int res = volume_histogram(histogram, size);
    printf("%d\n", res);
}