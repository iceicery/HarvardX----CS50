#define _XOPEN_SOURCE
#include <unistd.h>

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//////////////////////////////////////////////////////////
//Some assumptions of this problem
//  each password has been hashed with C’s DES-based (not MD5-based) crypt function.
//  each password is no longer than five (5) characters.
//  each password is composed entirely of alphabetical characters (uppercase and/or lowercase).
////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//introduce new function
//  strnpy:Copies up to n characters from the string pointed to, by src to dest::char *strncpy(char *dest, const char *src, size_t n)
//  strcmp: Compares the C string str1 to the C string str2 :: int strcmp ( const char * str1, const char * str2 );//
//  crypt:string encoding function ::#include <unistd.h> char *crypt(const char *key, const char *salt); 
//  key:string to be encoded;salt:string chosen from the set {a b c ....A B C...0 1 ..9 ./}, in this case it is first two char 
////////////////////////////////////////////////////

int main (int argc, string argv[])
{
    if (argc!=2)
    {
        printf("Usage: ./crack hash");
        return 1;
    }
    else
    {
        string hash=argv[1];
        char salt[3];
        for (int i=0;i<2;i++)  //get salt from hashed passward
        {
            salt[i]=hash[i];
        }
        char guesspw[5]="\0\0\0\0\0"; 
        
        //store all ASCII alphabet in an array
        char arr[52];
        for (int j=0;j<26;j++) 
        {
            arr[j]=(char)(65+j);
            arr[j+26]=(char)(97+j);
        }

        
        // check each possible password 
        for(int e=0;e<52;e++)
        {
            for(int d=0; d<52;d++)
            {
                for(int c=0;c<52;c++)
                {
                    for(int b=0;b<52;b++)
                    {
                        for(int a=0;a<52;a++)
                        {
                            guesspw[0]=(char)arr[a];
                            guesspw[1]=(char)arr[b];
                            guesspw[2]=(char)arr[c];
                            guesspw[3]=(char)arr[d];
                            guesspw[4]=(char)arr[e];
                            
                            //get all different length password from guess password
                            char pw[6]={};
                            for(int f=5;f>0;f--) 
                            {
                                strncpy(pw,guesspw,f);
                                //printf("trypw:%s\n",pw); //each try-password until password fouond could be see in this line.
                                pw[f]='\0';
                                if (strcmp(crypt(pw,salt),hash)==0)
                                {
                                    printf("password:%s/n",pw);
                                    return 0;
                                }
                            }
                            
                        }
                    }
                }
            }
        }
        //if not found 
        printf("Password can't be found!");
        return 0;
        
        
    }
}