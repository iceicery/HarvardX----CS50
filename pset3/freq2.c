
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"


// Calculates frequency (in Hz) of a note
int frequency(string note)
{
        int octave;
        int freq;
        int power;
        if (strlen(note)==2)
        {
            octave=note[1]-'0';
        }
        if (strlen(note)==3)
        {
            octave=note[2]-'0';
        }
        
        power=octave-4;
        
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
            freq=freq*pow(2,1./12);
        }
        if (note[1]=='b')
        {
            freq=freq/pow(2,1./12);
        }
        return freq;
}

//test
int main(void)
{
    string note=get_string("enter note:");
    printf("frequency:%d\n",frequency(note));
    //printf("power:%d\n",power);
    //printf("octave:%d\n",octave);
}