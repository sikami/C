 
    
    
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
        printf("Usage: ./copy n infile outfile\n");
        return 1;
    }
    if(atoi(argv[1]) < 1 || atoi(argv[1]) > 100 )
    {
        printf("Usage: ./copy n infile outfile\n       Please insert n between 1 to 100\n");
    }
   
    
    //remember n
    int resize_num = atoi(argv[1]);
    

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
    
    
     // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    
    
    //update header info
    BITMAPFILEHEADER newbf;
    newbf = bf;
    BITMAPINFOHEADER newbi;
    newbi = bi;
    
    newbi.biWidth *= resize_num;
    newbi.biHeight *= resize_num;
    
    int newpadding = (4 - (newbi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    newbi.biSizeImage = ((newbi.biWidth * sizeof(RGBTRIPLE)) + newpadding) * abs(newbi.biHeight);
    newbf.bfSize = (newbi.biSizeImage - bi.biSizeImage) + bf.bfSize;
    
   
    // write outfile's BITMAPFILEHEADER
    fwrite(&newbf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&newbi, sizeof(BITMAPINFOHEADER), 1, outptr);

   
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline n times
      for (int a= 0; a < resize_num; a++)
      {    
        
        for (int j = 0; j < bi.biWidth; j++)
        {
            
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
           for(int b = 0; b < resize_num; b++)
           {// write RGB triple to outfile
             fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
           }
        }

         for (int k = 0; k < newpadding; k++)
         {
           fputc(0x00, outptr);
         }
         
         fseek(inptr, padding, SEEK_CUR);
         fseek(inptr, -(bi.biWidth*sizeof(RGBTRIPLE) + padding), SEEK_CUR);    
        
      }
      
      fseek(inptr,(bi.biWidth*sizeof(RGBTRIPLE) + padding), SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
