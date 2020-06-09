#include <stdio.h>
#include <stdlib.h>

#include "dijkstra.h"

int main(int argc, char *argv[]){
    printf(" ********* Inicio programa *********\n");

    if (argc < 2) {
        printf("Usage: ./dijkstra input/example_graph_1.in\n");
        exit(EXIT_FAILURE);
    }
    printf("\n Se abre el grafo desde el archivo\n");
    graph_t graph = graph_from_file(argv[1]);
    vertex_t init = 0;
    printf("\n Se ingresa el algoritmo\n\n");
    cost_t *costs = dijkstra(graph, init);
    printf("Dijkstra Shortest Path Algorithm\n");
    for (unsigned int v = 0; v < graph_max_size(graph); v++){
        printf("Minimum cost from %d to %d: ", init, v);
        cost_print(costs[v]);
        printf("\n");
    }
    free(costs);
    graph = graph_destroy(graph);
    
    printf("\n ********* Fin programa *********\n");
}
