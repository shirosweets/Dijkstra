#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "set.h" // 
#include "graph.h"

/*	Costo mínimo
@param costo1 primer costo 
@param costo2 segundo costo 

@return Devuelve un cost_t que es el costo mínimo entre dos costos.
	En caso de ser iguales devuelve el primero.
*/
cost_t cost_min(cost_t costo1, cost_t costo2);

/* Vértice mínimo
@param saux set Conjunto de vértices
@param cost0 cost_t Costo

@return Devuelve el vértice de costo mínimo
*/
vertex_t v_min(set saux, cost_t *costos);

/** Dijkstra Algorithm
@param graph A graph represented as a cost matrix (@see graph.h)
@param init The initial vertex

@return An array of costs that contains
	for each position 'v' such that 0 <= 'v' < graph_max_size('graph'),
	the minimum cost of a path from 'init' to 'v' in the 'graph'.

@note The returned array must be freed by the user.
*/
cost_t *dijkstra(graph_t graph, vertex_t init);

#endif
