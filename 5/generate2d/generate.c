/*
 * **********************************************************************
 * File          : generate.c
 * **********************************************************************
 * Project       : Prac 5
 * Author        : Christopher Villegas - 18359884
 * File Created  : Tuesday, 28th August 2018 8:24:00 pm
 * Last Modified : Thursday, 30th August 2018 5:23:47 am
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : Generate a 2D array with random values and save it to
 *                 a file. 
 * **********************************************************************
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "randomarray.h"

int saveArray(double** array, int rows, int cols, char* filename);

int main(int argc, char** argv)
{
   int rows, cols;
   double** array;
   int i;
   
   if(argc == 4)
   {
      rows = atoi(argv[2]);
      cols = atoi(argv[3]);
      array = (double**)malloc(rows*sizeof(double*));
      for(i = 0; i < rows; i++)
      {
         array[i] = (double*)malloc(cols*sizeof(double));
      }
      
      randomArray(array, rows, cols, 0);
      if(!saveArray(array, rows, cols, argv[1]))
      {
         printf("Error allocating memory\n");
      }

      for(i = 0; i < rows; i++)
      {
         free(array[i]);
         array[i] = NULL;
      }
      free(array);
      array = NULL;
   }
   else
   {
      printf("invalid arguments\n");
   }

   return 0;
}

/**
 * @brief save an array of double to file
 * 
 * @param array input array
 * @param rows number of rows
 * @param cols number of columns
 * @param filename name of file to save to
 * @return int 1 if successful save
 */
int saveArray(double** array, int rows, int cols, char* filename)
{
   FILE* file;
   int i, j;
   int fileOpened;

   if(!strcmp(filename, "-"))
   {
      file = stdout;
   }
   else
   {
      file = fopen(filename, "w");
   }
   fileOpened = file != NULL;
   if(fileOpened)
   {
      for(i = 0; i < rows; i++)
      {
         for(j = 0; j < cols; j++)
         {
            fprintf(file, "%f ", array[i][j]);
         }
         fprintf(file, "\n");
      }
   }
   fclose(file);

   return fileOpened;
}








