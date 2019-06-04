

if ++ ->addition 

if -- ->addition 

if - & + 
    if -  bigger= --> - (bigger - smaller);
    if +  bigger --> + (bigger - smaller); 

void printsign(char *a, char *b)
{
    if (a[0] == '-' && b[0] == '-')
    {
        write(1, "-", 1);
        return ; 
    }
    if (a[0] != '-' && b[0] != '-')
    {
        return ; 
    }
    if (setModuleBigger(a, b) == 0)
        return ; 
    char * moduleBigger = (setModuleBigger(a, b) == 1) ? a : b; 
    (moduleBigger[0] == '-') ? write(1, "-", 1) : 0;
    return ;
}

int setModuleBigger(char * a, char *b)
{
    a = (a[0] == '-') ? a + 1 : a; 
    b = (b[0] == '-') ? b + 1 : b;
    while (a && b && *a == *b)
    {
        a++;
        b++; 
    }
    if (!*a && !*b)
        return 0; 
    if (!*a && *b)
        return 2; 
    if (*a && !*b)
        return 1; 
    if ((a - b) > 0)
        return 1;
    else 
        return 2;
}
int toValue(char a, char b, int sign, int * rank)
{
   int d1 =  a - '0';
   int d2 =  b - '0';
   int res = 0; 
   if (sign == '-')
   {
       if (d1 < d2)
    {   
        if (*rank < 0)
        {
            *rank++; 
            d1 += 10; 
        }
        
        res = d1 - d2; 
    } 

       a - b 
       
   }

}
void rec_addition(char * bigger, char *smaller)
{
    int rank = 0; 

}

rec_substraction


