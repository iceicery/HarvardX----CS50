#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n; //n is number of height
    do 
    {
        n=get_int("Height: ");
    }
    while(n<0 || n>23);

    for ( int i=0;i<n;i++)
    {for (int space=n-i-1;space>0;space--)
      { printf(" ");}
     for (int p=1;p<i+2;p++)
      { printf("#");}
      printf("  ");
     for (int b=1;b<i+2;b++)
      { printf("#");}
      printf("\n");
    }
}    
