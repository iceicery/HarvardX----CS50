#include <cs50.h>
#include <stdio.h>
//prompt the user for the half-pyramid's height
int main(void)
{
    int n;
    do
    {
        n=get_int("Height:");
    }
    while (n>23 || n<0);
    for(int i=0;i<n ;i++)
    { for(int s=n-i ;s>1;s--)
      {
          printf(" ");
          
      }
      for(int p=0;p<i+2;p++)
      {
          printf("#");
          
      }
      printf("\n");
       
    }
    
}