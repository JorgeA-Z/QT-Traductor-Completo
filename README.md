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
###### Interfaz
Para el módulo 2, se hicieron modificaciones respecto al analizador morfologioco, siendo que ahora es posible escribir en una caja de texto sin limitación, simulando un IDE de un lenguaje de programación.
A su vez, se agregó una pequeña consola que irá detallando las reglas gramaticales que hayan sido utilizadas para la realización de las reducciónes y los desplazamientos en la tabla de transisiones.

![alt text](https://github.com/JorgeA-Z/QT-Traductor-Completo/blob/main/Modulo%202/Código%20fuente/Imagenes/Sintactico.jpg)
###### Reglas gramaticales

Regla	Entrada	Longitud	Formula	Columna
R1 <programa> ::= <Definiciones>	<programa>	1	2	24
R2 <Definiciones> ::= \e	<Definiciones>	0	0	25
R3 <Definiciones> ::= <Definicion> <Definiciones>		2	4	
R4 <Definicion> ::= <DefVar>	<Definicion>	1	2	26
R5 <Definicion> ::= <DefFunc>		1	2	
R6 <DefVar> ::= tipo identificador <ListaVar> ;	<DefVar>	4	8	27
R7 <ListaVar> ::= \e	<ListaVar>	0	0	28
R8 <ListaVar> ::= , identificador <ListaVar>		3	6	
R9 <DefFunc> ::= tipo identificador ( <Parametros> ) <BloqFunc>	<DefFunc>	6	12	29
R10 <Parametros> ::= \e	 <Parametros>	0	0	30
R11 <Parametros> ::= tipo identificador <ListaParam>		3	6	
R12 <ListaParam> ::= \e	<ListaParam>	0	0	31
R13 <ListaParam> ::= , tipo identificador <ListaParam>		4	8	
R14 <BloqFunc> ::= { <DefLocales> }	<BloqFunc> 	3	6	32
R15 <DefLocales> ::= \e	 <DefLocales>	0	0	33
R16 <DefLocales> ::= <DefLocal> <DefLocales>		2	4	
R17 <DefLocal> ::= <DefVar>	 <DefLocal>	1	2	34
R18 <DefLocal> ::= <Sentencia>		1	2	
R19 <Sentencias> ::= \e	<Sentencias>	0	0	35
R20 <Sentencias> ::= <Sentencia> <Sentencias>		2	4	36
R21 <Sentencia> ::= identificador = <Expresion> ;	 <Sentencia>	4	8	
R22 <Sentencia> ::= if ( <Expresion> ) <SentenciaBloque> <Otro>		6	12	
R23 <Sentencia> ::= while ( <Expresion> ) <Bloque>		5	10	
R24 <Sentencia> ::= return <ValorRegresa> ;		3	6	
R25 <Sentencia> ::= <LlamadaFunc> ;		2	4	
R26 <Otro> ::= \e	<Otro>	0	0	37
R27 <Otro> ::= else <SentenciaBloque>		2	4	
R28 <Bloque> ::= { <Sentencias> }	<Bloque>	3	6	38
R29 <ValorRegresa> ::= \e	<ValorRegresa>	0	0	39
R30 <ValorRegresa> ::= <Expresion>		1	2	
R31 <Argumentos> ::= \e	<Argumentos>	0	0	40
R32 <Argumentos> ::= <Expresion> <ListaArgumentos>		2	4	
R33 <ListaArgumentos> ::= \e	<ListaArgumentos>	0	0	41
R34 <ListaArgumentos> ::= , <Expresion> <ListaArgumentos>		3	6	
R35 <Termino> ::= <LlamadaFunc>	<Termino>	1	2	42
R36 <Termino> ::= identificador		1	2	
R37 <Termino> ::= entero		1	2	
R38 <Termino> ::= real		1	2	
R39 <Termino> ::= cadena		1	2	
R40 <LlamadaFunc> ::= identificador ( <Argumentos> )	<LlamadaFunc>	4	8	43
R41 <SentenciaBloque> ::= <Sentencia>	<SentenciaBloque>	1	2	44
R42 <SentenciaBloque> ::= <Bloque>		1	2	
R43 <Expresion> ::= ( <Expresion> )	 <Expresion>	3	6	45
R44 <Expresion> ::= opSuma <Expresion>		2	4	
R45 <Expresion> ::= opNot <Expresion>		2	4	
R46 <Expresion> ::= <Expresion> opMul <Expresion>		3	6	
R47 <Expresion> ::= <Expresion> opSuma <Expresion>		3	6	
R48 <Expresion> ::= <Expresion> opRelac <Expresion>		3	6	
R49 <Expresion> ::= <Expresion> opIgualdad <Expresion>		3	6	
R50 <Expresion> ::= <Expresion> opAnd <Expresion>		3	6	
R51 <Expresion> ::= <Expresion> opOr <Expresion>		3	6	
R52 <Expresion> ::= <Termino>		1	2	
![image](https://user-images.githubusercontent.com/74442427/194086161-058abca0-d9f0-4089-9033-13a88dffed75.png)
