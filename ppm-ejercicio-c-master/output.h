#ifndef OUTPUT_H
	#define OUTPUT_H
	#include "ppm.h"
	#include "myerrorsandflags.h"
	#include "ppm-operations.h"

void print_help();
int make_output(char output_filename[],char option,char *argv[],t_ppm p,int index);


#endif
