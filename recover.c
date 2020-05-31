#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isjpeg(unsigned char *buf);


int main(int argc, char *argv[])
{
    //check if command line argument has 2 arguments
    if (argc != 2)
    {
        printf("usage: ./recover [filename]\n");
        return 1;
    }

    //store second line argument as file
    char *file = argv[1];

    //create new file input and output variable
    FILE *fp, *newfile;

    //declare buffer
    unsigned char buffer[512];

    //create counter for the file should it be found
    int filename = 0;

    //create array to store filename as characters
    char title[8];

    //open file to read
    fp = fopen(file, "r");


    //check if file is not null
    if (fp == NULL)
    {
        printf("File is not there. Try again.\n");
        return 1;
    }
    else
    {
        //read the file
        while (fread(&buffer, 512, 1, fp) == 1)
        {
            //if jpeg file is found
            if (isjpeg(buffer))
            {
                if (filename == 0)
                {
                    //create new file, open new file then write
                    sprintf(title, "%03i.jpg", filename);
                    newfile = fopen(title, "w");
                    fwrite(&buffer, 512, 1, newfile);
                    filename += 1;

                }
                else
                {
                    //closefile
                    fclose(newfile);

                    //create new file, open new file then write
                    sprintf(title, "%03i.jpg", filename);
                    newfile = fopen(title, "w");
                    fwrite(&buffer, 512, 1, newfile);
                    filename += 1;

                }
            }
            else
            {
                if (filename != 0)
                {
                    fwrite(&buffer, 512, 1, newfile);
                }
            }

        }
    }

    //close file
    fclose(fp);
    fclose(newfile);
}



bool isjpeg(unsigned char *buf)
{
    //check if block 1st is the start of JPEG file
    if (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff && ((buf[3] & 0xf0) == 0xe0))
    {
        return true;
    }

    return false;
}