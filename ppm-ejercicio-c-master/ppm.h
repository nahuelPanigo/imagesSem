#ifndef _PPM_H
#define _PPM_H

#include <stdio.h>

#define PPM_TYPE "P6"
#define PPM_TYPEG "P5"

/* grey pixel */
typedef struct {
  unsigned char grey;
} t_ppm_pixelG;


/* A PPM type grey : has height, width, depth and pixels */
typedef struct {
  unsigned int height;
  unsigned int width;
  unsigned short depth;
  t_ppm_pixelG* * pixels;
} t_ppmG;

/* RGB pixel */
typedef struct {
  unsigned char red;
  unsigned char green;
  unsigned char blue;
} t_ppm_pixel;

/* A PPM type: has height, width, depth and pixels */
typedef struct {
  unsigned int height;
  unsigned int width;
  unsigned short depth;
  t_ppm_pixel * * pixels;
} t_ppm;


/* initializes a new PPM of height * width pixels and depth. Its 
 * pixels are all zeros (black)
 */
t_ppm ppm_create(unsigned long height, unsigned long width, unsigned short depth);

/* initializes a new PPM grey of height * width pixels and depth. Its 
 * pixels are all zeros (black)
 */
t_ppmG ppm_createG(unsigned long height, unsigned long width, unsigned short depth);

/* Reads a PPM from an existing file. Not all stabdard formats are supported*/
t_ppm ppm_from_file(FILE *);

/* Saves to file a PPM type object */
void ppm_save(t_ppm, FILE *);


/* Saves to file a PPM type grey object */
void ppm_saveG(t_ppmG, FILE *);

/* Prints PPM header fileds */
void ppm_print_header(t_ppm p);

/* This function must be called after destroying a PPM object.
 * It frees all memory allocated for pixels \
 */
void ppm_free(t_ppm p);


/* This function must be called after destroying a PPM grey object.
 * It frees all memory allocated for pixels \
 */
void ppm_freeG(t_ppmG p);
#endif
