# Tp Numero 2 : Fases de la Traducción y Errores

## 1. Preprocesador:

a. Generar hello2.c
```c
#include <stdio.h>
int/*medio*/main(void){
int i=42;
 prontf("La respuesta es %d\n");
```

b. Preprocesar y generar hello2.i:
Para esto utilizamos la opcion -e (solamente va a preprocesar y no compilar o vincular):
```
gcc -E hello2.c -o hello2.i
```

Observacion: Esto genera un archivo .i, que incluyo el contenido de stdio y remplaza los cometarios.

c. Modificamos hello2.c para generar hello3.c
```c
int printf(const char * restrict s, ...);
int main(void){
int i=42;
 prontf("La respuesta es %d\n")
```

d. Semantica de primera linea: Describe una funcion llamada printf, que retorna un valor de tipo entero y recibe una cantidad indeterminada de valores, con la condicion de que como minimo recibe un puntero a char constante.

e. Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i:

```
gcc -E hello3.c -o hello3.i
```

Diferencias: En este caso, al no existir includes o comentario, los cambios entre el codigo y el archivo proprocesado no son tantos.


## 2. Compilacion:

a. Compilar el resultado y generar hello3.s, no ensamblar:

Ahora tenemos que compialr el .i obetenido anteriormente, para esto utilizaremos la opcion -S:
```
gcc -S hello3.c -o hello3.s
```

--- ERROR ---

Como a la hora de compilar, el codigo que escribimos en C pasa a ser lenguaje maquina, los errores sintacticos del lenguaje van a evitar que podamos compilar el archivo. En este caso falto cerrar la llave del main.

## 3. Vinculación:


## 4. Corrección de Bug:



## 5. Remoción de prototipo:



## 6. Compilación Separada: Contratos y Módulos:



