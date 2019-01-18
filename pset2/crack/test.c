#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string guesspw="ABCDE";

    char pw[6]={};
    for (int f=5;f<0;f--) 
    {
        strncpy(pw,guesspw,f);
        printf("trypw:%s\n",pw);
    
        if (strcmp(pw,"ABC")==0)
        {
            printf("password:%s/n",pw);
            return 0;
        }
        
        pw[f]='\0';    
    }

}