# include <stdio.h>
#include "output.h"
#include <stdlib.h>

void print_help(){
	printf("REQUIERED OPTIONS: \n");
  printf("-i (with argument,name input file)\n");
	printf("-o (with argument, name output file)\n");
	printf("OPTIONS TO DO (only one):\n");
  printf("-n [negative]\n");
  printf("-? [help]\n");
	printf("-h [horizontalMirror]\n");
	printf("-v [verticalMirror]\n");
	printf("-r [rotate 90]\n");
	printf("-g [change image to grey scale]\n");
	printf("-b [blur](need a radio)\n"); 
	printf("-a [sum between 2 images](need a second image)\n");
	printf("-s [sub between 2 images](need a second images)\n");
}



int make_output(char output_filename[],char option,char *argv[],t_ppm p,int index){
t_ppm p_op;
t_ppmG p_opG;
int *numb=0;
FILE *op=NULL;


if((op=fopen(output_filename,"wb"))==NULL){
  return OPENING_ERROR;
}
switch (option){
      case 'n':
            p_op = ppm_operation_negative(p);
            break;
      case 'h':
            p_op=ppm_operation_flip_horizontal(p);
            break;
      case 'v':
            p_op=ppm_operation_flip_vertical(p);
            break;  
      case 'r':
            p_op = ppm_operation_rotate90(p);
            break;
      case 'b':
            numb =malloc(sizeof(int));
            sscanf(argv[index],"%d",numb);
            p_op=ppm_operation_blur(p,*numb);
            free(numb);
            break;
      case 'g':
            p_opG=ppm_operation_make_grey_scale(p);
            break;
      case 'a':
            p_op=ppm_operation_sum(p,argv[index]);
            break;
      case 's':
            p_op=ppm_operation_sub(p,argv[index]);
            break;
      case 'c':
            p_op=ppm_operation_copy(p);
            break;
  }
  if(option == 'g'){
  		ppm_saveG(p_opG,op);
  		ppm_freeG(p_opG);
  }else{
  	ppm_save(p_op,op);
  	ppm_free(p_op);
  }
  fclose(op);
  return 0;
}
