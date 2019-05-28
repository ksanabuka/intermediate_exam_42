typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void mark4(char **tab, t_point size, t_point begin, char c);
void markTop(char **tab, t_point size, t_point begin, char c);


void markTop(char **tab, t_point size, t_point begin, char c)
{
	if (begin.y - 1 >= 0 && tab[begin.y - 1][begin.x] == c)
	{
	tab[begin.y-1][begin.x] = 'F';
	begin.y = begin.y - 1;
	mark4(tab, size, begin, c);
	}
	return ;
}


void markBottom(char **tab, t_point size, t_point begin, char c)
{
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == c)
	{
	tab[begin.y+1][begin.x] = 'F';
	begin.y = begin.y + 1;
	mark4(tab, size, begin, c);
	}
	return ;
}


void markLeft(char **tab, t_point size, t_point begin, char c)
{
	if (begin.x - 1 >= 0 && tab[begin.y][begin.x - 1] == c)
	{
	tab[begin.y][begin.x - 1] = 'F';
	begin.x = begin.x - 1;
	mark4(tab, size, begin, c);
	}
	return ;
}


void markRight(char **tab, t_point size, t_point begin, char c)
{
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == c)
	{
	tab[begin.y][begin.x + 1] = 'F';
	begin.x = begin.x + 1;
	mark4(tab, size, begin, c);
	}
	return ;
}
void mark4(char **tab, t_point size, t_point begin, char c)
{
	tab[begin.y][begin.x] = 'F';
	markTop(tab, size, begin, c);
	markBottom(tab, size, begin, c);
	markLeft(tab, size, begin, c);
	markRight(tab, size, begin, c);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.y][begin.x];
	mark4(tab, size, begin, c);

}


//
//#include <stdio.h>
//
//int  main(void)
//{
//	t_point size = {8, 5};
//	t_point begin = {2, 2};
//	
//	char p1[9] = "11111111";
//	char p2[9] = "10001001";
//	char p3[9] = "10010001";
//	char p4[9] = "10110001";
//	char p5[9] = "11100001";
//
//	char * tab[5] = {p1, p2, p3, p4, p5};
//
//	flood_fill(tab, size, begin);
//	printf("%s\n%s\n%s\n%s\n%s\n", p1, p2, p3, p4, p5);
//	return 0;
//
//}
//

