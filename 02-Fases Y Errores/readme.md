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

b. Corregimos el error agregando la llave faltante:

```c
int printf(const char * restrict s, ...);
int main(void){
 int i=42;
 prontf("La respuesta es %d\n")
}
```
c. Leer hello4.s, investigar sobrelenguajeensamblador,eindicardeformar sintética cual es el objetivo de ese código:

El archivo hello4.s es el resultado de compilar hello4, por lo tanto el compilador se encargo de traducir el codigo en c a un lenguaje de maquina, que nuestro procesador es capaz de entender. Al tratarse de una traduccion, la funcion del codigo sigue siendo la misma, solo que ahora, al estar en ensablador, (un lenguaje de menor nivel) ya no esta hecho para que nosotros lo leeamos, sino que para que lo lea el procesador.

d. Ensamblar hello4.s en hello4.o, no vincular:

Ensanblaremos hello4.s usando el siguiente comando:
```
gcc -c hello4.c -o hello4.o
```
## 3. Vinculación:

**a. Vincular hello4.o con la biblioteca estándar y generar el ejecutable.**

vincularemos hello4.o a la biblioteca estandar usando el siguiente comando:
```
gcc hello4.o -o hello4.exe
```

```
error
```
Al usar una funcion que no se encuentra (prontf) en nuestro codigo o en la libreria estandar, la vinculacion nos produjo un error, ya que este es el ultimo paso en el cual puede buscar una referencia a esta funcion.

**b. Corregir en hello5.c y generar el ejecutable. Solo corregir lo necesario para que vincule.**

Para corregir este error, lo que podemos hacer es cambiar el llamado de prontf, a printf (tambien podriamos crear la funcion prontf)
Ensamblaremos y vincularemos esta nueva version:

```c
int printf(const char * restrict s, ...);
int main(void){
 int i=42;
 prontf("La respuesta es %d\n")
}
```


**c. Ejecutar y analizar el resultado.**

Luego de este cambio, el .exe se genera sin mas problemas, pero al momento de ejecutar, el resultado no fue el que esperabamos (error pragmatico) debido a que la funcion printf esta esperando un parametro mas del que le pasmaos (en este caso un entero, que quermos que sea el valor de la variable i). Al no encontrar este valor, trae de memoria un numero desconocido.

## 4. Corrección de Bug:

**a. Corregir en hello6.c y empezar de nuevo; verificar que funciona como se espera**

```c
int printf(const char * restrict s, ...);
int main(void){
 int i=42;
 prontf("La respuesta es %d\n",i)
}
```

La correccion de este bug implica agregar el parametro faltante (variable i) a la funcion printf. Luego ensamblamos y vincualamos hello6.

Con este cambio el resultado es el esperado.



## 5. Remoción de prototipo:

a. Escribir hello7.c, una nueva variante:
```c
int main(void){
 int i=42;
 printf("La respuesta es %d\n", i);
}
```
Ensamblamos y vincualamos hello7.

Al ejecutar estos comandos, se presentara un warning, debido a la declaracion implicita de printf (tener en cunta que esto puede variar segun el compilador,ya que cada uno maneja esto de formas diferentes, en este caso es gcc).

```
WARNING
```
**b. Explicar porqué funciona.**

En el caso del compilador gcc, esto no genera un error (solo warning, que no impide el funcionamiento) debido a al printf ser una funcion utilizando con mucha frecuencia, gcc opto por tratarla como una funcion built in del lenguaje, por lo que se puede usar sin la necesidad de tener un prototipo o declaracion explicita.

## 6. Compilación Separada: Contratos y Módulos:

**a. Escribir studio1.c (sí, studio1, no stdio) y hello8.c**

studio1.c:
```c
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
```
hello8.c:
```c
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
```

**b. Investigar como en su entorno de desarrollo puede generar un programa ejecutable que se base en las dos unidades de traducción (i.e., archivos fuente, archivos con extensión .c). Luego generar ese ejecutable y probarlo.**

A partir de estos 2 archivos fuente, podemos realizar un ejecutable de una forma muy sencilla: 

```
gcc studio 1.c hello8.c -o hello8
```

Al no tener un contrato entre studi1.c y hello8.c, y al usar la funcion printf sin el include de studi.h, apareceran 2 warnings, pero el .exe se generara correctamente

Resultado:
```
La respuesta es 42
```
**c. Responder ¿qué ocurre si eliminamos o agregamos argumentos a la invocación de prontf? Justifique.**

Dado que nuestra declaracion de prontf espera exactamente 2 parametros, cualquier otra cantidad hara que la compilacion falle 


**d. Revisitar el punto anterior, esta vez utilizando un contrato de interfaz en un archivo header.**

i. Escribir el contrato en studio.h.
```c
#ifndef _STUDIO_H_INCULDED_
#define _STUDIO_H_INCULDED_
void prontf(const char*, int);
#endif
```

ii. Escribir hello9.c, un cliente que sí incluye el contrato.
```c
#include "studio.h" // Interfaz que importa
int main(void){
int i=42;
 prontf("La respuesta es %d\n", i);
}
```

iii. Escribir studio2.c, el proveedor que sí incluye el contrato.
```c
#include "studio.h" // Interfaz que exporta
#include <stdio.h> // Interfaz que importa
void prontf(const char* s, int i){
 printf("La respuesta es %d\n", i);
}
```

iv. Responder: ¿Qué ventaja da incluir el contrato en los clientes y en el proveedor.

Incluir el contrato nos da varias ventajas, nos quita los warnings declarar las funciones de forma implicita (esto puede ser muy importante si nuestro compilador falla en lugar de darnos warning), podemos encontrar errores en la libreria antes de compilar, y principalmete facilita el crecimiento del proyecto ya que los contratos se encargan del correcto uso de las librerias
