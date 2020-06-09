#include <assert.h>
#include <stdlib.h>

#include <stdio.h> /* printf()...           */

#include "cost.h"
#include "graph.h"
#include "set.h"

/*	Costo mínimo
@param costo1 primer costo 
@param costo2 segundo costo 

@return Devuelve un cost_t que es el costo mínimo entre dos costos.
	En caso de ser iguales devuelve el primero.
*/
cost_t cost_min(cost_t costo1, cost_t costo2){
	cost_t costo_min_;
	if(cost_lt(costo2, costo1)){ // costo2 < costo1
		costo_min_ = costo2;
	}
	else if(cost_le(costo1, costo2)){ // costo1 <= costo2
		// Si son iguales puedo tomar cualquiera
		costo_min_ = costo1;
	}
	return costo_min_;
}

/* Vértice mínimo
@param s_vertices set Conjunto de vértices
@param cost0 cost_t Costo

@return Devuelve el vértice de costo mínimo
*/
vertex_t v_min(set s_vertices, cost_t *costos){
	set s_copy = set_copy(s_vertices); // Copio 's_vertices' en 's_copy'
	vertex_t min_vertice = set_get(s_copy); // Vértice de retorno, inicializado en 0
	cost_t min_cost0 = costos[min_vertice]; 
	while(!set_is_empty(s_copy)){ // Mientras el conjunto NO sea vacío
		vertex_t v_comp = set_get(s_copy); // Vértice auxiliar para comparar
		if(cost_le(costos[v_comp], min_cost0)){
			min_vertice = v_comp;
			min_cost0 = costos[v_comp];
		}
		s_copy = set_elim(s_copy, v_comp);
	}
	s_copy = set_destroy(s_copy);
	return min_vertice; // Retorna el vértice del costo
}

cost_t *dijkstra(graph_t graph, vertex_t init){
	// Arreglo de costos del grafo. D
	cost_t *costo_min = calloc(graph_max_size(graph), (sizeof(cost_t)));
	// Conjunto de los vértices hacia los que todavía desconocemos cuál es el camino de menor costo. C
	set s_vertices = set_empty(); 
	// Agrego todos los vértices al conjunto de vértices
	for(unsigned int i=0u; i<graph_max_size(graph); i++){
		s_vertices = set_add(s_vertices, i);
		// No debo añadir aún los costos porque este incluirá al inicial (que debe ser 0 su costo)
	}
	// Elimino el vértice 'v' porque va a ser costo 0 ya que es el inicial
	s_vertices = set_elim(s_vertices, init);
	// Actualizo el resultado para decir cuál es el costo de ir desde v hacia cada j. Anoto solo el valor de la arista
	for(unsigned int j=0u; j<graph_max_size(graph); j++){
		// Añade todos los costos de los vértices
		costo_min[j] = graph_get_cost(graph, init, j);
	}
	// En este punto, s_vertices incluye todos los vértices exceptuando el incial (ya que sé su costo).
	// Costo del Vértice inicial = 0

	// Luego, costo_min incluye todos los costos de los vértices restantes.
	while(!set_is_empty(s_vertices)){ // Mientras el conjunto NO sea vacío, aprendo el camino
		vertex_t c = v_min(s_vertices, costo_min);
		// Actualizo todos los valores de los vértices para ver si tenía antes era el mínimo
		for(unsigned int m=0u; m<graph_max_size(graph); m++){
			cost_t costo_aux = cost_sum(costo_min[c], graph_get_cost(graph, c, m));
			costo_min[m] = cost_min(costo_min[m], costo_aux);
		}
		s_vertices = set_elim(s_vertices, c); // Elimino 'c' de 's_vertices'
	}
	s_vertices = set_destroy(s_vertices); // Libero 's_vertices'
	return costo_min;
}