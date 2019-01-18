
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include "helpers.h"


// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    if (strlen(note)==2)
    {
        int octave=note[1]-'0';
        int power=octave-4;
        if (note[0]=='A')  //A0-A7
        {
            if (0<=octave && octave<8)
            {
                return 440*pow(2,power);
            }
            else 
            {
                return 0;
            }

        }
        else if (note[0]=='B')//B0-B7
        {
            
            if (0<=octave && octave<8)
            {
                return round(440*pow(2,2./12)*pow(2,power)); 
            }
            else
            {
                return 0;
            }
        }
        else if (note[0]=='C')//C1-C8
        {
            
            if (0< octave && octave<=8)
            {
                return round(440*pow(2,-9./12)*pow(2,power)); 
            }
            else
            {
                return 0;
            }
        }
        else if (note[0]=='D')//D1-D7
        {
            
            if (0< octave && octave<8)
            {
                return round(440*pow(2,-7./12)*pow(2,power)); 
            }
            else
            {
                return 0;
            }
        } 
        else if (note[0]=='E')//E1-E7
        {
            
            if (0< octave && octave<8)
            {
                return round(440*pow(2,-5./12)*pow(2,power)); 
            }
            else
            {
                return 0;
            }
        } 
        else if (note[0]=='F')//F1-F7
        {
            
            if (0< octave && octave<8)
            {
                return round(440*pow(2,-4./12)*pow(2,power)); 
            }
            else
            {
                return 0;
            }
        }
        else if (note[0]=='G')//G1-G7
        {
            
            if (0< octave && octave<8)
            {
                return round(440*pow(2,-2./12)*pow(2,power)); 
            }
            else
            {
                return 0;
            }
        }  
        else
        {
            return 0;
        }
    }
    else
    {
        int octave=note[2]-'0';
        int power=octave-4;
        if (octave>0 && octave<8)
        {
            if (note[1]=='#')    //do all #
            {
                if(note[0]=='A')
                {
                    return round(frequency("A4")*pow(2,1./12)*pow(2,power));
                }
                else if (note[0]=='B')
                {
                    return round(frequency("B4")*pow(2,1./12)*pow(2,power));
                }
                else if (note[0]=='C')
                {
                    return round(frequency("C4")*pow(2,1./12)*pow(2,power));
                }
                else if (note[0]=='D')
                {
                    return round(frequency("D4")*pow(2,1./12)*pow(2,power));
                }
                else if (note[0]=='E')
                {
                    return round(frequency("E4")*pow(2,1./12)*pow(2,power));
                }
                else if (note[0]=='F')
                {
                    return round(frequency("F4")*pow(2,1./12)*pow(2,power));
                }
                else if (note[0]=='G')
                {
                    return round(frequency("G4")*pow(2,1./12)*pow(2,power));
                }
                else
                {
                    return 0;
                }
            }
            else if (note[1]=='b') //do all b
            {
                if(note[0]=='A')
                {
                    return round(frequency("A4")*pow(2,-1./12)*pow(2,power));
                }
                else if (note[0]=='B')
                {
                    return round(frequency("B4")*pow(2,-1./12)*pow(2,power));
                }
                else if (note[0]=='C')
                {
                    return round(frequency("C4")*pow(2,-1./12)*pow(2,power));
                }
                else if (note[0]=='D')
                {
                    return round(frequency("D4")*pow(2,-1./12)*pow(2,power));
                }
                else if (note[0]=='E')
                {
                    return round(frequency("E4")*pow(2,-1./12)*pow(2,power));
                }
                else if (note[0]=='F')
                {
                    return round(frequency("F4")*pow(2,-1./12)*pow(2,power));
                }
                else if (note[0]=='G')
                {
                    return round(frequency("G4")*pow(2,-1./12)*pow(2,power));
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
            
    }
}

//test
int main(void)
{
    string note=get_string("enter note:");
    printf("frequency:%d\n",frequency(note));
}