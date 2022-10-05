# QT-Traductor-Completo
Traductor morfológico, sintactico y semantico con interfaz gráfica desarrollada en QT.  

###### Instalación
El programa está en fase de despliege con las librerías básicas contenidas en QT, mediante la app para desplegar windeployqt.exe, por lo que no se requiere configuración adicional más que hacer la descarga del archivo ejecutable.

###### Desarrollo

La aplicación inicialmente fué desarrollada con Python pero, después de contemplar las limitaciónes en cuanto a la arquitectura del mismo, siendo que python es un lenguaje interpretado y no compilado, se decidió que el desarrollo se realizaría con C++ Utilizando la librería gráfica QT.

## Traductir morfológico

###### Interfaz
La interfaz contiene una caja de texto en donde se pueden listar los tokens a analizar, comprobando si pertenecen a la máquina de estados planteada para el analizador léxico.

![alt text](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%201/Codigo%20fuente/Imagenes/Interfaz.png)

###### Maquina de estados utilizada para el desarrollo de la aplicación

![alt text](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%201/Codigo%20fuente/Imagenes/Máquina%20de%20estados.jpeg)

## Traductor sintactico
Para el módulo 2, se hicieron modificaciones respecto al analizador morfologioco, siendo que ahora es posible escribir en una caja de texto sin limitación, simulando un IDE de un lenguaje de programación.
A su vez, se agregó una pequeña consola que irá detallando las reglas gramaticales que hayan sido utilizadas para la realización de las reducciónes y los desplazamientos en la tabla de transisiones.
![alt text]([https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%201/Codigo%20fuente/Imagenes/Máquina%20de%20estados.jpeg](https://github.com/JorgeA-Z/QT-Traductor-Completo/tree/main/Modulo%202/Código%20fuente/Imagenes))
