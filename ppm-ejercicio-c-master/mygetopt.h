#ifndef MY_GET_OPT_H
#define MY_GET_OPT_H
#include "ppm.h"
#include "myerrorsandflags.h"
#include "unistd.h"
#include "string.h"

void initializeflag(int flag[]);
int onlyCopy(int flag[]);
int obtainParam(char * argv[],int argc,char *str,char outputFile[],char str_err[],char *option,int *index);
int checkRequiredOrExtra(int flag[]);
int checkRepeated(int flag[]);

#endif
