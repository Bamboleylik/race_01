#include "../inc/header.h"

char *mx_strcpy(char *dst, const char *src){ 
   char *destination = dst;
   while (*src)
   {
    *dst = *src;

    dst++;
    src++;
   }
   *dst='\0';

   return destination;
}
