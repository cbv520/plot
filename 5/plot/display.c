/*
 * **********************************************************************
 * File          : display.c
 * **********************************************************************
 * Project       : Prac 5
 * Author        : Christopher Villegas - 18359884
 * File Created  : Tuesday, 28th August 2018 4:59:02 am
 * Last Modified : Thursday, 30th August 2018 5:33:49 am
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : reads data from a text file into a 2D array,
                   then passes the array to the plot() function 
                   (declared in plot.h)
 * **********************************************************************
 */


#include "plot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double** readVals(int rows, int cols, FILE* file);

int main(int argc, char** argv)
{ 
   char* filename;
   FILE* file;
   int rows, cols;
   double** array;
   int i;
   if(argc > 1)
   {
      filename = argv[1];
      if(!strcmp(filename, "-"))
      {
         file = stdin;
      }
      else
      {
         file = fopen(filename, "r");
      }
      fscanf(file, "%d %d", &rows, &cols);
      array = readVals(rows, cols, file);
      fclose(file);
      plot(array, rows, cols);

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

double** readVals(int rows, int cols, FILE* file)
{
   int i, j;
   char* str;
   char buffer[1000];
   double** array = (double**)malloc(rows*sizeof(double*));
   for(i = 0; i < rows; i++)
   {
      array[i] = (double*)malloc(cols*sizeof(double));
   }
   
   i = 0;
   while(i < rows)
   {
      if(fgets(buffer, 1000, file) != NULL)
      {
         j = 0;
         str = strtok(buffer, " ");
         while(str != NULL)
         {
            array[i][j] = atof(str);
            str = strtok(NULL, " ");
            j++;
         }
         if(j == cols + 1)
         {
            i++;
         }
      }      
   }
   return array;
}
