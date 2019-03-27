/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

 
unsigned char buffer [512];

int main(int argc, char* argv[])
{
    //open file
    FILE* inptr = fopen("card.raw", "r");
    
    if(inptr == NULL)
    {
        printf("Error. File can't be opened.");
        return 1;
    }
    
   
    int jpegfiles = 0;
    int open = 0;
    FILE* outptr;
    char title [8];
    //repeat process, while not the end of file
    while(fread(&buffer, 512, 1, inptr) == 1)
    {
      //if found jpeg
      if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
      { 
              
             //set open to 1
              open = 1;     
             //if jpeg files is open then write
            
              if(jpegfiles != 0)
              {
                  fclose(outptr);
                  sprintf(title, "%03d.jpg", jpegfiles);
                  outptr = fopen(title, "a");
                  fwrite(&buffer, 512, 1, outptr);
                  jpegfiles++;
                  
              }
              if(jpegfiles == 0)
              {
                  sprintf(title, "%03d.jpg", jpegfiles);
                  outptr = fopen(title, "a");
                  fwrite(&buffer, 512, 1, outptr);
                  jpegfiles++;
              }
            
              
      }
      else //if jpeg signature is not found do nothing
      {
          //write to already found jpeg file
          if(open == 1)
          {
            fwrite(&buffer, 512, 1, outptr);
          }
          
           
      }
     
    }
    
    fclose(outptr);
    fclose(inptr);
    //return 0;
}


