/*
 * **********************************************************************
 * File          : string_processing.c
 * **********************************************************************
 * Project       : Prac 5
 * Author        : Christopher Villegas - 18359884
 * File Created  : Friday, 17th August 2018 9:14:33 pm
 * Last Modified : Friday, 17th August 2018 10:20:13 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_processing.h"

void process_line(char* str)
{
   char* time_str = (char*)malloc(20 * sizeof(char));
   char* message;
   int time_secs;
   int i;

   time_str = str;
   for(i = 0; i < 2; i++)
   {
      time_str = strstr(time_str, " ");
      time_str++;
   }
   printf("d\n");
   time_str[8] = '\0';
   printf("b\n");
   message = str;
   printf("x\n");
   /*for(i = 0; i < 4; i++)
   {
      message = strstr(message, " ");
      message++;
   }*/
   printf("2\n");
   time_secs = time_str_to_sec(time_str);
   printf("a\n");
   for(i = 0; i < 8;i++)
   {
      printf("%c\n",time_str[i]);
   }
   
   printf("%s: %s", time_str, message);
   printf("y\n");
}

int time_str_to_sec(char* str)
{
   int hours = CHAR_TO_INT(str[0], str[1]);
   int minutes = CHAR_TO_INT(str[3], str[4]);
   int seconds = CHAR_TO_INT(str[6], str[7]);

   hours = hours * 60 * 60;
   minutes = minutes * 60;

   return hours + minutes + seconds;
}