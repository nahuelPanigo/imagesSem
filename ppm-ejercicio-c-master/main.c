#include <error.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm.h"
#include "mygetopt.h"
#include "output.h"

extern int errno;

/* Sample main program */


int main(int argc,char * argv[]) {
  FILE *f;
  char output_filename[1024];
  t_ppm p;
  int err;
  char str_err[1024];
  char option;
  int index;
	

  if((err=obtainParam(argv,argc,"i:o:?hvrnb:ga:s:",output_filename,str_err,&option,&index))>0){
     errno = err;
     fprintf(stderr,"ERROR: %s\n",str_err);
     exit errno;
  }
  if(option == '?'){
    print_help();
    return 0;
  }
  f = fopen(argv[2], "rb");
  p=ppm_from_file(f);
  if((err=make_output(output_filename,option,argv,p,index)!=0)){
    fprintf(stderr,"cant open output_file");
  }
  ppm_free(p);
  fclose(f);
  exit(EXIT_SUCCESS);
}
