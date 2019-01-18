// Helper functions for music

#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int num=fraction[0]-'0';
    int den=fraction[2]-'0';
    return 8*num/den;    
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
        int octave= note[strlen(note)-1]-'0';
        int power=octave-4;
        int freq=0;
        
        if (note[0]=='A' && 0<=octave && octave<8)  //A0-A7
        {
              freq=440*pow(2,power);
        }
        else if (note[0]=='B'&& 0<=octave && octave<8)//B0-B7
        {
               freq= round(440*pow(2,2./12)*pow(2,power)); 
        }
        else if (note[0]=='C' && 0< octave && octave<=8)//C1-C8
        {
                freq= round(440*pow(2,-9./12)*pow(2,power)); 
        }
            
        else if (note[0]=='D'&& 0< octave && octave<8)//D1-D7
        {
                freq= round(440*pow(2,-7./12)*pow(2,power)); 
        }
        else if (note[0]=='E' && 0< octave && octave<8)//E1-E7
        {
                freq= round(440*pow(2,-5./12)*pow(2,power)); 
        }
        else if (note[0]=='F' && 0< octave && octave<8)//F1-F7
        {
                freq= round(440*pow(2,-4./12)*pow(2,power)); 
        }
        else if (note[0]=='G' && 0< octave && octave<8)//G1-G7
        {
                freq=round(440*pow(2,-2./12)*pow(2,power)); 
        }
        //deal with # and b
        if (note[1]=='#')
        {
            freq=round(freq*pow(2,1./12));
        }
        if (note[1]=='b')
        {
            freq=round(freq/pow(2,1./12));
        }
        return freq;
}


// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (s[0]== '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*/test
int main(void)
{
    string note=get_string("enter test note:");
    string fraction="1/4";
    printf("rest:%d\n",is_rest(note)); 
    printf("fraction:%d\n",duration(fraction));
    printf("frequency:%d\n",frequency(note));
    printf("power:%f\n",pow(2,-2));
}

*/