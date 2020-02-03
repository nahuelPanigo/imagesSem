#ifndef __PPM_OPERATIONS_H
#define __PPM_OPERATIONS_H

t_ppm ppm_operation_rotate90(t_ppm );
t_ppm ppm_operation_flip_horizontal(t_ppm );
t_ppm ppm_operation_flip_vertical(t_ppm );
t_ppm ppm_operation_negative(t_ppm );
t_ppm ppm_operation_sum(t_ppm p,char *str);
t_ppm ppm_operation_sub(t_ppm p,char *str);
t_ppm ppm_operation_blur(t_ppm , unsigned char);
t_ppmG ppm_operation_make_grey_scale(t_ppm p);
t_ppm  ppm_operation_copy(t_ppm);

#endif

