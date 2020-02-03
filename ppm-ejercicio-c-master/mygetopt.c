#include "mygetopt.h"
#include <stdlib.h>
#include <string.h>


int obtainParam(char * argv[],int argc,char *str,char outputFile[],char str_err[],char *option,int *index){
	int opt=0;
	FILE *faux,*f;
	int flag[11];
	int error=1;
	int *r;
	extern char *optarg;
	extern int optind;
	initializeflag(flag);
	while((opt=getopt(argc,argv,str))!=-1){
		switch (opt){
			case 'i':
						flag[inputFile]++;
						break;
			case 'o':
						outputFile=strcpy(outputFile,optarg);
						flag[outFile]++;
						break;
			case 'n':
						*option='n';
						flag[negative]++;
						break;
			case 'h':
						*option='h';
						flag[horizontalMirror]++;
						break;
			case 'v':
						*option='v';
						flag[verticalMirror]++;
						break;
			case '?':
						flag[help]++;	
						*option='?';
						str_err=strcpy(str_err,"help");
						return 0;
						break;	
			case 'r':
						*option='r';
						flag[rotate]++;
						break;
			case 'b':
						r=malloc(sizeof(int));
						*option='b';
						*index=optind-1;
						error=(sscanf(optarg,"%d",r));
						if(error != 1){
							str_err=strcpy(str_err,"Error having de blur number");
							free(r);
							return ERROR_CONVERT_NUMBER;
						}
						free(r);
						flag[blur]++;
						break;
			case 'g':
					*option='g';
					flag[grey]++;
					break;
			case 'a':
					*option='a';
					*index=optind-1;
					flag[add]++;
					if ((faux = fopen(optarg, "rb")) == NULL) {
							str_err=strcpy(str_err,"Error opening file");
   							return OPENING_ERROR;
   					 }
   					 fclose(faux);
					break;
			case 's':
					*option='s';
					*index=optind-1;
					flag[sub]++;
					if ((faux = fopen(optarg, "rb")) == NULL) {
   							str_err=strcpy(str_err,"Error opening file");
   							return OPENING_ERROR;
   					 }
   					 fclose(faux);
					break;
			default:
						str_err=strcpy(str_err,"Error argument unknow");
						return ARG_UNKNOW;
						break;
		}
	}
	if (argc<4){
			str_err=strcpy(str_err,"Error few arguments");
			return REQUIRED_ARGUMENT;
	}
	if((strcmp(argv[1],"-i"))|(flag[outFile] != 1)){
		str_err=strcpy(str_err,"Error missing requiered arguments");
		return REQUIRED_ARGUMENT;
	};
	if ((f = fopen(argv[2], "rb")) == NULL) {
		str_err=strcpy(str_err,"Error opening file");
   		return OPENING_ERROR;
    	}
	error=checkRepeated(flag);
	if(error==ARG_REPEATED){
		fclose(f);
		str_err=strcpy(str_err,"argument Repeated");
		return error;
	}
	error=checkRequiredOrExtra(flag);
	if (error==ARG_MISSING_EXTRA){
		fclose(f);
		str_err=strcpy(str_err,"more o few arguments");
		return error;
	}
	if(onlyCopy(flag)){
		*option='c';
	}
	fclose(f);

	return 0;	
}



void initializeflag(int flag[]){
	for (int i = 0; i < 11; ++i)
	{
		flag[i]=0;
	}
}


int onlyCopy(int flag[]){
	int count =0;

	for (int i = 0; i < 11; ++i)
	{
		if(flag[i]>0){
			count++;
		}
	}
	if(count==2) return 1;

	return	0;
}

int checkRequiredOrExtra(int flag[]){
	int count=0;
	for (int i =0; i<11; ++i){
		if(flag[i]>0)
			count++;
	}
	if((count>3)|(count<2)){
		return ARG_MISSING_EXTRA;
	}
	return 0;
}

int checkRepeated(int flag[]){
int i=0;
	while(i<11){
		if(flag[i]>1){
			return ARG_REPEATED;
		}
		i++;
	}
	return 0;
}
