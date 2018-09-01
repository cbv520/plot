/*
 * **********************************************************************
 * File          : copy.c
 * **********************************************************************
 * Project       : Prac 5
 * Author        : Christopher Villegas - 18359884
 * File Created  : Wednesday, 15th August 2018 10:35:38 pm
 * Last Modified : Friday, 17th August 2018 5:33:12 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Copy binary and text files.
 * **********************************************************************
 */


#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* file_in;
    FILE* file_out;

    char ch;

    if(argc != 3)
    {
        printf("Incorrect number of arguments\n");
    }

    file_in = fopen(argv[1], "rb");
    file_out = fopen(argv[2], "wb");
    
    if(file_in == NULL)
    {
        printf("Error opening %s\n", argv[1]);
    }
    else if(file_out == NULL)
    {
        printf("Error opening %s\n", argv[2]);
    }

    ch = fgetc(file_in);
    while(!feof(file_in))
    {
        fputc(ch, file_out);
        ch = fgetc(file_in);
    }

    fclose(file_in);
    fclose(file_out);

    return 0;
}
