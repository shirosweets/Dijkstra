#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "graph.h"

struct graph_data{
    cost_t *costs;
    unsigned int max_size;
};

/** Returns an empty graph
@param max_size Amount of vertices this graph can contain
@note Vertices are zero-based: {0, 1, ..., max_size - 1}
*/
graph_t graph_empty(unsigned int max_size){
    graph_t graph = calloc(1, sizeof(struct graph_data));
    assert(graph != NULL);
    graph->max_size = max_size;
    graph->costs = calloc(max_size * max_size, sizeof(cost_t));
    for (unsigned int i = 0; i < max_size * max_size; ++i){
        graph->costs[i] = cost_inf();
    }
    assert(graph->costs != NULL);
    return graph;
}

/** Returns the amount of vertices of the given graph
@param graph A graph
*/
unsigned int graph_max_size(graph_t graph){
    assert(graph != NULL);
    return graph->max_size;
}

/** Adds an edge with the given cost to the graph
@param graph A graph
@param from A source vertex (assumed to be less than max_size)
@param to A target vertex (assumed to be less than max_size)
@param cost The cost assigned to this edge
*/
void graph_add_edge(graph_t graph, vertex_t from, vertex_t to, cost_t cost){
    assert(graph != NULL);
    assert(from < graph->max_size);
    assert(to < graph->max_size);
    graph->costs[to + graph->max_size * from] = cost;
}

/** Returns the cost assigned to the given edge
@param graph A graph
@param from The source vertex of the edge (assumed to be less than max_size)
@param to The target vertex of the edge (assumed to be less than max_size)
*/
cost_t graph_get_cost(graph_t graph, vertex_t from, vertex_t to){
    assert(graph != NULL);
    assert(from < graph->max_size);
    assert(to < graph->max_size);
    return graph->costs[to + graph->max_size * from];
}

/** Free memory resources
@param graph A graph
*/
graph_t graph_destroy(graph_t graph){
    assert(graph != NULL);
    free(graph->costs);
    free(graph);
    return NULL;
}

/** Prints a graph in stdout using the same format as graph_from_file
*/
void graph_print(graph_t graph){
    assert(graph != NULL);
    printf("%u\n", graph->max_size);
    for (unsigned int i = 0; i < graph->max_size; ++i){
        for (unsigned int j = 0; j < graph->max_size; ++j){
            const cost_t cost = graph_get_cost(graph, i, j);
            if (cost_is_inf(cost)){
                printf("# ");
            } else {
                printf("%d ", cost);
            }
        }
        printf("\n");
    }
}

/** Reads a graph from a file
@param filepath The path to the file containing the graph specification
@note Expected format has the following structure:
<N+1>
<cost_00> ... <cost_0j> ... <cost_0N>
...         
<cost_N0> ... <cost_Nj> ... <cost_NN>
where N+1 = max_size
*/
graph_t graph_from_file(const char *file_path){
    FILE *file = fopen(file_path, "r");
    if (file == NULL){
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int tam = 0;
    fscanf(file, "%u", &tam);
    char word[256];
    const graph_t graph = graph_empty(tam);
    for (unsigned int i = 0; i < tam; ++i){
        for (unsigned int j = 0; j < tam; ++j){
            cost_t cost = cost_inf();
            fscanf(file, "%s", word);
            if (word[0] != '#'){
                cost = atoi(word);
            }
            graph_add_edge(graph, i, j, cost);
        }
    }
    fclose(file);
    return graph;
}
