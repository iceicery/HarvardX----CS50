#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>



int main(int argc, char* argv[])
{
    //check if proper use
    if (argc !=2)
    {
        fprintf(stderr,"usage: recover infile\n");
        return 1;
    }
    
    char *infile=argv[1];
    
    //open input file
    FILE *inptr=fopen(infile,"r");
    
    //check if file could be opened
    if(inptr == NULL)
    {
        fprintf(stderr,"file cannot be opened");
        return 2; 
    }
    
    //create buffer, count, outfile of picture and filename arrays
    unsigned char buffer[512];
    int count=0;    //count is for nowing which img file and for naming 
    FILE *img=NULL; //img is image file 
    char filename[8]; // 001.jpg\0 ....
    bool flag=false; //flag is for close now and start reading next
    
    //read files
    while (fread(buffer,512,1,inptr) == 1)
    {
        //find beginning of JPEG
        // first 3 bytes:0xff 0xd8 0xff;last byte:0xe0,0xe1....,0xef
        if(buffer[0]==0xff && buffer[1]==0xd8 && buffer[2]==0xff &&
          (buffer[3]&0xf0)==0xe0)
        {
            //making a new JPEG
            sprintf(filename,"%03i.jpg",count);
            img=fopen(filename,"w");
            count++;
        
            //writing files 
            
            fwrite(&buffer,512,1,img);
                
        }
    }
    //close all files
    fclose(inptr);
    fclose(img);
    
    return 0;
}



 