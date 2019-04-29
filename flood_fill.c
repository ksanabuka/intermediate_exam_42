 #include "flood_fill.h"
#include <stdio.h>

void check5(char **tab, t_point size, t_point begin, char c)
{
  if ((begin.y >= 0 && begin.y < size.y && begin.x >= 0 && begin.x < size.x) && tab[begin.y][begin.x] == c)
  {
 //   printf("%c\n", tab[begin.y][begin.x]);
    tab[begin.y][begin.x] = 'F';
    mark_top_neibour(tab, size, begin, c);
    mark_bottom_neibour(tab, size, begin, c);
    mark_left_neibour(tab, size, begin, c);
    mark_right_neibour(tab, size, begin, c);
  }
}

void mark_top_neibour(char **tab, t_point size, t_point begin, char c)
{
    t_point tmp; 
    tmp.x = begin.x;
    tmp.y = begin.y - 1;
    check5(tab, size, tmp, c); 
}

void mark_bottom_neibour(char **tab, t_point size, t_point begin, char c)
{
    t_point tmp; 
    tmp.x = begin.x;
    tmp.y = begin.y + 1;
    check5(tab, size, tmp, c);
}

void mark_left_neibour(char **tab, t_point size, t_point begin, char c)
{
    t_point tmp; 
    tmp.x = begin.x - 1;
    tmp.y = begin.y;
    check5(tab, size, tmp, c); 
}

void mark_right_neibour(char **tab, t_point size, t_point begin, char c)
{
    t_point tmp; 
    tmp.x = begin.x + 1;
    tmp.y = begin.y;
    check5(tab, size, tmp, c); 
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
  char c = tab[begin.y][begin.x];
  check5(tab, size, begin, c);
}

int main(void)
{
  t_point size = {8, 5};
	t_point begin = {0, 0};
	
  char r0[] = "11111111";
  char r1[] = "10001001";
  char r2[] = "10010001";
  char r3[] = "10110001";
  char r4[] = "11100001";

  char *tab[] = {r0, r1, r2, r3, r4};

  flood_fill(tab, size, begin);

  printf("%s\n", tab[0]);
  printf("%s\n", tab[1]);
  printf("%s\n", tab[2]);
  printf("%s\n", tab[3]);
  printf("%s\n", tab[4]);
	return (0);
}