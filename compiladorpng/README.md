# Compilador png
Este programa hace uso de pilas y la notacion posfija de una expresion regular para poder hacer un automata finito no determinista plasmado en una imagen mediante graphviz, para usar graphviz se tiene que instalar a continuacion el siguiente comando para instalar

`sudo apt install graphviz`
Para compilar y generar el programa el siguiente comando:

`gcc compiladorpng.c -o ejecutables/nombreejecutable`

Para correr el programa usar el siguiente comando (las comillas no se quitan):

`./ejecutables/nombreejecutable "suexpresionregular"`
