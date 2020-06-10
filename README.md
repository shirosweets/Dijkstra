# Dijkstra
			*** COMANDOS PARA CORRER  EL PROGRAMA CON MAKEFILE***

make
valgrind --show-reachable=yes --leak-check=full ./dijkstra input/example_graph_1.in

		   *** COMANDOS PARA CORRER  EL PROGRAMA (MEMORY LEAKS CON MAKEFILE)***

make
valgrind --show-reachable=yes --leak-check=full ./dijkstra input/example_graph_1.in
