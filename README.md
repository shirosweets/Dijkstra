# Dijkstra
### ¿Qué es el algoritmo de Dijkstra?

 Es un algoritmo de búsqueda creado por Edsger Dijkstra que determina el camino más corto, dado un vértice origen, hacia el resto de los vértices en un grafo que tiene pesos en cada arista.

-------------------------------------------------------------------------------------------------------------------
### ¿Cómo correr el programa?
1) Descargar https://github.com/shirosweets/Dijkstra/blob/master/lab06-dijkstra.zip
2) Descomprimir.
3) Descargar https://github.com/shirosweets/Dijkstra/tree/master/Valentina_Solange_Vispo o https://github.com/shirosweets/Dijkstra/blob/master/Valentina_Solange_Vispo.zip
4) Reemplazar los archivos de Valentina_Solange_Vispo.zip en la carpeta descomprimida.
5) Ejecutar los comandos.

			  *** COMANDOS PARA CORRER  EL PROGRAMA CON MAKEFILE***
make

valgrind --show-reachable=yes --leak-check=full ./dijkstra input/example_graph_1.in

		   *** COMANDOS PARA CORRER  EL PROGRAMA (MEMORY LEAKS CON MAKEFILE)***
make

valgrind --show-reachable=yes --leak-check=full ./dijkstra input/example_graph_1.in

		       *** COMANDOS PARA BORRAR ARCHIVOS CREADOS AL COMPILAR ***
		       
make clean

-------------------------------------------------------------------------------------------------------------------

Autor: Valentina Solange, Vispo.

-------------------------------------------------------------------------------------------------------------------
