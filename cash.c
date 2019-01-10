#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float n;
    do
    {
    n=get_float("Enter how much the customer is owed:");
    }
    while (n<0 ||n>=1);
    
    int a=n*100;
    int b=a%25;
    int c=b%10;
    int d=c%5; //d is also number of 1 cent
    int n_quater=(a-b)/25;
    int n_dime=(b-c)/10;
    int n_five=(c-d)/5;
    int total_coins=n_quater+n_dime+n_five+d;
    printf ("total coins:%d\n",total_coins);
     
}