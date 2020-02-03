#include "ppm.h"
#include <stdio.h>




/*
Desenfoque: cada pixel en la posición [i,j] con un radio r especificado como argumento se calcula como el promedio de los pixeles
 en las posiciones que van desde [max(i-r,0),max(j-r,0)] hasta [min(i+r,height-1),min(j+r,width-1)]
*/

t_ppm  ppm_operation_copy(t_ppm p){
  unsigned row,col;
  t_ppm new = ppm_create(p.height, p.width, p.depth); 
  for(row=0; row < new.height; row++) 
    for(col=0; col < new.width ; col++){
      new.pixels[row][col] = p.pixels[row][col];
  }
  return new;
}


t_ppm ppm_operation_sum(t_ppm p,char *str){
  unsigned col,row,minC,minR;
  FILE *f;
  t_ppm p2;
  if ((f = fopen(str, "rb")));
  p2 = ppm_from_file(f);
  minC = (p2.width < p.width ? p2.width : (p.width));
  minR = (p2.height < p.height ? p2.height : (p.height));
  t_ppm new = ppm_create(minR, minC, p.depth);
  for(row=0; row < minR; row++){ 
  	for(col=0; col < minC ; col++){
    	new.pixels[row][col].red = (p.pixels[row][col].red +p2.pixels[row][col].red < 255 ? (p.pixels[row][col].red +p2.pixels[row][col].red) : (255));
    	new.pixels[row][col].green = (p.pixels[row][col].green +p2.pixels[row][col].green < 255 ? (p.pixels[row][col].green +p2.pixels[row][col].green):(255)); 
    	new.pixels[row][col].blue = (p.pixels[row][col].blue +p2.pixels[row][col].blue < 255 ? (p.pixels[row][col].blue +p2.pixels[row][col].blue) : (255));
 	 }
   }
  fclose(f);
  ppm_free(p2);
  return new;
}



t_ppm ppm_operation_sub(t_ppm p,char *str){
  unsigned col,row,minC,minR;
  FILE *f;
  t_ppm p2;
  if ((f = fopen(str, "rb")));
  p2 = ppm_from_file(f);
  minC = (p2.width < p.width ? p2.width : (p.width));
  minR = (p2.height < p.height ? p2.height : (p.height));
  t_ppm new = ppm_create(minR, minC, p.depth);
  for(row=0; row < minR; row++){ 
  	for(col=0; col < minC ; col++){
    	new.pixels[row][col].red = p.pixels[row][col].red -p2.pixels[row][col].red ;
    	new.pixels[row][col].green = p.pixels[row][col].green - p2.pixels[row][col].green;  
    	new.pixels[row][col].blue = p.pixels[row][col].blue +p2.pixels[row][col].blue ;
 	 }
   }
  fclose(f);
  ppm_free(p2);
  return new;
}

t_ppm ppm_operation_blur(t_ppm p, unsigned char ratio){
	unsigned minR,maxR,minC,maxC;
	long red,green,blue;
	int col,row,colu,ro;
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  for(row=0; row < new.height; row++) {
  	for(col=0; col < new.width ; col++){
    		maxC  = (col+ratio < p.width-1 ? col+ratio : (p.width-1));
    		minC  =	((col-ratio) > 0 ? col-ratio : (0));
    		maxR  = (row+ratio < p.height-1 ?  row + ratio : (p.height-1));
    		minR  =  (row-ratio > 0 ? row-ratio : (0));
    		red=0;	green=0;	blue=0;
    		for (colu=minC; colu<maxC ; colu++){
    			for (ro=minR; ro<maxR ; ro++){
    				red = red +p.pixels[ro][colu].red; 
    				green= green +p.pixels[ro][colu].green;
    				blue = blue+ p.pixels[ro][colu].blue;
    			}
  			}
  			new.pixels[row][colu].red= red/((maxC-minC) * (maxR-minR));
    		new.pixels[row][colu].green= green/((maxC-minC )* (maxR-minR));
    		new.pixels[row][colu].blue= blue/((maxC-minC) * (maxR -minR));
	}
}
  return new;
}


t_ppm ppm_operation_rotate90(t_ppm p){
	unsigned col,row;
  t_ppm new = ppm_create(p.width, p.height, p.depth);
  for(row=0; row < new.height; row++) 
  	for(col=0; col < new.width ; col++){
    	new.pixels[row][col] = p.pixels[col][row];
  }
  return new;
}



t_ppm ppm_operation_flip_horizontal(t_ppm p){
		unsigned col,row;
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  for(row=0; row < new.height; row++) 
  	for(col=0; col < new.width ; col++){
    	new.pixels[row][col] = p.pixels[row][p.width-col-1];
  }
  return new;
}



t_ppm ppm_operation_flip_vertical(t_ppm p){
			unsigned col,row;
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  for(row=0; row < new.height; row++) 
  	for(col=0; col < new.width ; col++){
    	new.pixels[row][col] = p.pixels[p.height-row-1][col];
  }
  return new;
}


t_ppmG ppm_operation_make_grey_scale(t_ppm p){
  unsigned col,row;
  t_ppmG new = ppm_createG(p.height, p.width, p.depth);
  for(row=0; row < new.height; row++) 
  	for(col=0; col < new.width ; col++){
    	new.pixels[row][col].grey = (p.pixels[row][col].green*0.587)+(p.pixels[row][col].red*0.299)+(p.pixels[row][col].blue*0.114);
  }
  return new;
}

void ppm_invert_colours(t_ppm_pixel *p){
  p->red=255-p->red;
  p->green=255-p->green;
  p->blue=255-p->blue;
}

t_ppm ppm_operation_negative(t_ppm p){
  unsigned int row,col; 
  t_ppm new = ppm_create(p.height, p.width, p.depth);
  for(row=0; row < p.height; row++) for(col=0; col < p.width ; col++){
    new.pixels[row][col] = p.pixels[row][col];
    ppm_invert_colours(&new.pixels[row][col]);
  }
  return new;
}

