# QT-Traductor-Completo
Traductor morfológico, sintactico y semantico con interfaz gráfica desarrollada en QT.  

###### Instalación
El programa está en fase de despliege con las librerías básicas contenidas en QT, mediante la app para desplegar windeployqt.exe, por lo que no se requiere configuración adicional más que hacer la descarga del archivo ejecutable.

###### Desarrollo

La aplicación inicialmente fué desarrollada con Python pero, después de contemplar las limitaciónes en cuanto a la arquitectura del mismo, siendo que python es un lenguaje interpretado y no compilado, se decidió que el desarrollo se realizaría con C++ Utilizando la librería gráfica QT.

## Modulo 1: Traductir morfológico

###### Interfaz
La interfaz contiene una caja de texto en donde se pueden listar los tokens a analizar, comprobando si pertenecen a la máquina de estados planteada para el analizador léxico.

![alt text](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%201/Codigo%20fuente/Imagenes/Interfaz.png)

###### Link a la carpeta dentro del repositorio

[Modulo 1](https://github.com/JorgeA-Z/QT-Traductor-Completo/tree/main/Modulo%201)

###### Maquina de estados utilizada para el desarrollo de la aplicación

![alt text](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%201/Codigo%20fuente/Imagenes/Máquina%20de%20estados.jpeg)

## Modulo 2: Traductor sintactico
###### Interfaz
Para el módulo 2, se hicieron modificaciones respecto al analizador morfologioco, siendo que ahora es posible escribir en una caja de texto sin limitación, simulando un IDE de un lenguaje de programación.
A su vez, se agregó una pequeña consola que irá detallando las reglas gramaticales que hayan sido utilizadas para la realización de las reducciónes y los desplazamientos en la tabla de transisiones.

![alt text](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%202/Código%20fuente/Imagenes/Sintactico.jpg)
###### Reglas gramaticales

Las siguientes reglas fueron utilizadas para desarrollar el analizador sintactico del compilador, constando con un número n de reglas o símbolos no terminales.

![image](https://user-images.githubusercontent.com/74442427/194086161-058abca0-d9f0-4089-9033-13a88dffed75.png)
###### Tabla de transiciones

A su vez, la siguiente tabla de transiciones o grámatica, fue utilizada para la realización del algoritmo LR(1) de nuestro analizador sintactico.
![image](https://user-images.githubusercontent.com/74442427/194086637-18b465f0-0340-46f2-bba9-6afe0cc30b52.png)

###### Link a la carpeta dentro del repositorio

[Modulo 2](https://github.com/JorgeA-Z/QT-Traductor-Completo/tree/main/Modulo%202)

## Modulo 3: Traductor Semantico
Para la fase del analizador semantico, fue necesaria el presentar el arbol de construcción sintactica, así como la pila mostrando todas las reglas gramaticales, junto con las reducciones y desplazamientos.
En base a la pila, se enlazaron los nodos de forma que se fuera generando dicho arbol, siendo que para validar semanticamente cada expresión, solo hubo que recorrer este arbol, junto con la generación de una tabla de simbolos que agilizara el proceso de búsqueda de variables y funciones.

![image](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%202/Código%20fuente/Imagenes/Semantico.png)

###### Link a la carpeta dentro del repositorio

[Modulo 3](https://github.com/JorgeA-Z/QT-Traductor-Completo/tree/main/Modulo%203)


## Modulo 4: Código objeto
###### Interfaz
![image](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%204/Calculadora/Imagen.jpg)


Para el último módulo se realizó una calculadora cientifica con las funciones que se pueden apreciar en la captura. Esta calculadora utiliza las instrucciones embebidas de la arquitectura x86 de Intel, siendo que se inyectan con funciones en ensamblador volatiles dentro del código de C++.

Arquitectónicamente hablando, la calculadora funciona con un automata de estados finitos (que no mostraremos) que permite la asimilación de todos los componentes lexicos, sintacticos y semanticos de las operaciones matemáticas. Búscando que la jerarquia de operaciones se cumpla en todos los casos aparentes, así como funciones volatiles en ensamblador que realizarán las operaciones correspondientes.

```c++
float MainWindow::ASM_SUM(float $a, float $b)
{
    float $result;
    __asm__ __volatile__ (
        "fld %1;"
        "fld %2;"
        "faddp;"
        "fstp %0;" : "=m" ($result) : "g"($a) , "g"($b)
    );
    return $result ;
}
```
