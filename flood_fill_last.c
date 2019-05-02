eft(char **tab, t_point size, t_point begin, char c)
{
    begin.y = begin.y;
    begin.x = begin.x - 1;
    check_neibours(tab, size, begin, c);
}
flood_fill.c                                                                                                 1,23           Top
    begin.x = begin.x + 1;
	begin.x = begin.x + 1;
	check_neibours(tab, size, begin, c);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.y][begin.x];
	check_neibours(tab, size, begin, c);
}

#include <stdio.h>

int main(void)
{
	t_point size = {8, 5};
	t_point begin = {2, 2};

	char p0[]	= "11111111";
	char p1[] = 	"10001001";
	char p2[]	= "10010001";
	char p3[]	= "10110001";
	char p4[] = 	"11100001";
	char * tab[] = {p0, p1, p2, p3, p4};

	flood_fill(tab, size, begin);
	printf("%s\n", p0);
	printf("%s\n", p1);
	printf("%s\n", p2);
	printf("%s\n", p3);
	printf("%s\n", p4);


}