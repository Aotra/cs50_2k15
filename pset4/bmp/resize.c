/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./copy infile outfile\n");
        return 1;
    }
    int fac=atoi(argv[1]);
    if(fac<0 || fac>100)
    {
    printf("resize amount should be a positive integer less than or equal to 100");
    return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];
    

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf,of;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    of=bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi,oi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    oi=bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    oi.biWidth=bi.biWidth*fac;
    oi.biHeight=bi.biHeight*fac;
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int opadding= (4 - (oi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    oi.biSizeImage= (oi.biWidth*sizeof(RGBTRIPLE)+opadding)*abs(oi.biHeight);
    of.bfSize=bf.bfSize-bi.biSizeImage+oi.biSizeImage;
    
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&of, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&oi, sizeof(BITMAPINFOHEADER), 1, outptr);    
    

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
    fpos_t pos;
    fgetpos(inptr,&pos);
    
      for (int k = 0; k < fac; k++)
      {
        if(k<fac)
      {
        fsetpos(inptr,&pos);     
      }
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;           
            
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
            for (int a = 0; a < fac; a++)
            fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            
        }              
     
        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
        
        // then add it back (to demonstrate how)
        for (int l = 0; l < opadding; l++)
        fputc(0x00, outptr);  
   
           
      }  
   
 }        
    
    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
