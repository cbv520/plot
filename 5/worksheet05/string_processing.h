/*
 * **********************************************************************
 * File          : string_processing.h
 * **********************************************************************
 * Project       : Prac 5
 * Author        : Christopher Villegas - 18359884
 * File Created  : Friday, 17th August 2018 9:15:12 pm
 * Last Modified : Friday, 17th August 2018 9:42:52 pm
 * Standard      : ANSI C
 * **********************************************************************
 * Description   : 
 * **********************************************************************
 */


#ifndef STRING_PROCESSING_H
#define STRING_PROCESSING_H

#define CHAR_TO_INT(tens, ones) (((tens) - '0') * 10 + (ones - '0'))

void process_line(char*);
int time_str_to_sec(char*);

#endif