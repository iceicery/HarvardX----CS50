// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: copy infile outfile\n");
        return 1;
    }

    // crearte size factor n and filenames
    int n=atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];
    
    // n must be a positive integer less or equal to 100
    if (n<0 ||n >100)
    {
        fprintf(stderr, "size factor must be a positive integer less or equal to 100");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    //set new width and height size
    BITMAPINFOHEADER new_bi=bi;
    new_bi.biWidth=bi.biWidth*n;
    new_bi.biHeight=bi.biHeight*n;
    
    // determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    //set the new padding
    int new_padding = (4- (new_bi.biWidth* sizeof(RGBTRIPLE))%4) %4;
    
    //set new file size(includes pixels, padding and headers)
    BITMAPFILEHEADER new_bf=bf;
    new_bf.bfSize= 54 + (new_bi.biWidth* sizeof(RGBTRIPLE) + new_padding) * abs(new_bi.biHeight);
    new_bi.biSizeImage= new_bf.bfSize-54;
    

    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {    
        int times=0;
        while (times<n) // write each row n times
        {
            // iterate over pixels in scanline
            for (int j = 0; j < bi.biWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                // write RGB triple to outfile n times
                int t=0;
                while (t<n) //write each pixels n times
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                    t++;
                }
                
            }
            //write outfile's new padding to each row
            for (int k=0;k<new_padding;k++)
            {
                fputc(0x00,outptr);
            }
            //seek back to the beginning of row of input file
            if (times <(n-1))
            {
                fseek(inptr,-(bi.biWidth*sizeof(RGBTRIPLE)), SEEK_CUR);
            }
            times++;
        }
        //skip over padding 
        fseek(inptr, padding, SEEK_CUR);
    }
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
