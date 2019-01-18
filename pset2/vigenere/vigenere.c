#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    string s=argv[1];
    //printf("string:%s\n",s);
    int key[strlen(s)];
    int keynum=strlen(s);  //keynum is how many keys
    string plaintext=get_string("plaintext: "); //prompt plain text
    for(int i=0;i<strlen(s);i++)
   {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))     //transfer alphabet key to integer
            {
                key[i]=(int)s[i]-65;
            }
            else 
            {
                key[i]=(int)s[i]-97;
            }
        }
        else                       //ciphertext remain the same as plaintext if key is not alphabet     
        {
            printf("ciphertext:%s\n",plaintext);
            printf("key should be alphabet!");
            break;
        }
    }
    int new_ascii[strlen(plaintext)]; 
    char ciphertext[strlen(plaintext)];
    int x=0;   //x is for applying group to next if not alphabet
    for (int j=0;j<strlen(plaintext);j++)
    {
        int group=(j-x)%keynum;
        if (isupper(plaintext[j]))
        {
            new_ascii[j]=(plaintext[j]-65+key[group])%26+65;
            ciphertext[j]=(char)new_ascii[j];
        }
        else if (islower(plaintext[j]))
        {
            new_ascii[j]=(plaintext[j]-97+key[group])%26+97;
            ciphertext[j]=(char)new_ascii[j];
        }
        else
        {
            ciphertext[j]=plaintext[j];
            x++;
        }
    }
    printf("ciphertext:%s",ciphertext);
}


