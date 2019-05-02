#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

void check_neibours(char **tab, t_point size, t_point begin, char c);
void markTop(char **tab, t_point size, t_point begin, char c);
void markBottom(char **tab, t_point size, t_point begin, char c);
void markLeft(char **tab, t_point size, t_point begin, char c);
void markRight(char **tab, t_point size, t_point begin, char c);
void  flood_fill(char **tab, t_point size, t_point begin);



#endif