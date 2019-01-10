#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long long credit;
    int digit;
    int n;
    int total=0;
    int m;
    
    //ask for credit card number
    do
    {
    credit=get_long_long("Input Credit Card Number:");
    }
    while (credit <=0);

    digit= ceil(log10(credit));
    //identify 'up' for upper bound for j (odd digit) 
    int up;
    if (digit%2==0)
    {up=digit-1;}
    else
    {up=digit;}
    
    if (digit !=13 && digit !=15 && digit !=16)
    {
        printf("number is not valid");
    }
    else
    {
        for (int i=2;i<=2*floor(digit/2);i+=2)
        {
             //multiply each "even digit" by 2
             n=2*(credit% (long long) pow(10,i)-credit% (long long) pow(10,(i-1)))/pow(10,(i-1));
             //convert for example 14 to 1 and 4
             if (n >=10)
             {
                 n=n%10+(n-n%10)/10;
             }
             total=total+n;
        }
             //add "odd digit"
        for (int j=1;j<=up ;j+=2)
        {
            m=(credit%(long long) pow(10,j)-credit% (long long) pow(10,(j-1)))/pow(10,(j-1));
            total=total+m;
        }
        //printf("total:%d/n",total); 
        if (total%10 !=0)
        {
            printf("number is not valid");
        }
        else if (digit==15 && (((long long)credit/(long long)pow(10,13)==34) || ((long long)credit/(long long)pow(10,13)==37)))
        {
            printf("AMEX");
        }
        else if(digit==16 && (((long long)credit/(long long)pow(10,14)==51) || ((long long)credit/(long long)pow(10,14)==52)|| ((long long)credit/(long long)pow(10,14)==53)|| ((long long)credit/(long long)pow(10,14)==54)|| ((long long)credit/(long long)pow(10,14)==55)))
        {
            printf("MASTERCARD");
        }
        else if((digit==13 || digit==16) && ((long long)credit/(long long)pow(10,(digit-1))==4))
        {
            printf("VISA");
        }
    }
}    