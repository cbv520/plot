/*
 * **********************************************************************
 * File          : logreader.c
 * **********************************************************************
 * Project       : Prac 5
 * Author        : Christopher Villegas - 18359884
 * File Created  : Friday, 17th August 2018 5:38:32 pm
 * Last Modified : Friday, 17th August 2018 9:55:41 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Reads logfiles and reports the seconds since midnight
 *                 of logs matching a specified term
 * **********************************************************************
 */


#include <stdio.h>
#include <string.h>
#include "string_processing.h"

#define BUFFER_SIZE 1000
#define SEARCH_WORD "fail"

int main(int argc, char** argv)
{
   FILE* file;
   char buffer[BUFFER_SIZE];

   file = fopen(argv[1], "r");

   if(file == NULL)
   {
      printf("Error opening file\n");
   }
   else
   {
      while(fgets(buffer, BUFFER_SIZE, file) != NULL)
      {
         if(strstr(buffer, SEARCH_WORD) != NULL)
         {
            process_line(buffer);
         }
      }
   }

   fclose(file);
}

