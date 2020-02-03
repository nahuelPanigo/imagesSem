
### funciones agregadas

* **Escala Gris:** para pasar a escala de gris primero se debera sacar el numero de gris que tiene el pixel con la formula (green *0.587+ red*0.2999+ blue*0.114) ,ademas se debera cambiar el tipo de imagen, cambiandole en la cabezera el tipo por p5 y la estructura de los pixeles a un color.
* **suma de imagenes:** para esto primero se debe ingresar una segunda imagen, a las cuales se deberan coincidir en tamaño, min(width,height),y el valor de cada pixel se calculara como la suma de cada color, siempre y cuando no supere el 255.
* **division de imagenes:** para esto primero se debe ingresar una segunda imagen, a las cuales se deberan coincidir en tamaño, min(width,height),y el valor de cada pixel se calculara como la resta de cada color,como son unsugned los colores no hace falta preguntar si es mayor q 0.



El programa principal deberá recibir opciones y a partir de ellas operar con las
funciones antes mencionadas según se vayan procesando las opciones:

* `-i entrada.ppm`: archivo origen. Opción requerida
* `-o salida.ppm`: archivo salida. Opción requerida
* `-n`: calcula el negativo
* `-r`: rota a 90 grados
* `-h`: espejo horizontal
* `-v`: espejo vertical
* `-g`: cambia la imagen a escala de grises
* `-b NUM`: desenfoque con radio NUM
* `-a entrada2.ppm`: suma la entrada.ppm ingresada con entrada2.ppm.
* `-s entrada2.ppm`: resta a la entrada.ppm ingresada, la entrada2.ppm
* `-?`: ayuda del programa

Los argumentos se irán procesando a medida que aparecen, siendo fundamental que
la opción -i sea la primer opción para poder así procesar lo que demanda el
usuario, y que la opcion -o este siempre despues de -i Ejemplos de uso:

### compilar
	gcc -o images *.c

### Copia de una imagen

```
./images -i input.ppm -o output.ppm
```
### cambia a escala de grises

```
./images -i input.ppm -o output.ppm -g
```

### resta 2 imagenes

```
./images -i input.ppm -o output.ppm -s input2.ppm
```

### suma 2 imagenes

```
./images -i input.ppm -o output.ppm -a input2.ppm
```

### Calcula el negativo del origen

```
./images -i input.ppm -o output.ppm -n
```

### Rota una imagen, luego hace el espejo horizontal y luego el desenfoque

```
./images -i input.ppm -h -o output.ppm -b 2
```

### Ejemplos de imagenes

El directorio `./samples` tiene ejemplo de PPMs

