#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main (int argc, string argv[])
{
    if (argc !=2)
    {
        printf("Error!");
        return 1;
    }
    else
    {
      int key=atoi(argv[1]);            // string to interger
      string plaintext=get_string("Enter text: "); //prompt plain text
      int new_ascii[strlen(plaintext)]; 
      char ciphertext[strlen(plaintext)];
      for (int i=0;i<strlen(plaintext);i++)
      {
          if (isupper(plaintext[i])) //for upper letters
          {
              new_ascii[i]=(((int)plaintext[i]-65+key)%26)+65;
              ciphertext[i]=(char)new_ascii[i];
           
          }
          else if (islower(plaintext[i])) //for non alphabet
          {
              new_ascii[i]=(((int)plaintext[i]-97+key)%26)+97;
              ciphertext[i]=(char)new_ascii[i];
          }
          else
          {
            ciphertext[i]=plaintext[i];
          }
      }
      printf("plaintext:%s\n",plaintext);
      printf("ciphertext:%s\n",ciphertext);
    }  
}
