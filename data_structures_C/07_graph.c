#include <stdio.h>
#include <stdlib.h>

/*
 * Définition:
 *   - Vertex,
 *   - Edge,
 *   - Adjacency,
 *   - Path
 *
 * Opérations:
 *  - Add Vertex,
 *  - Add Edge,
 *  - Display Vertex
 *
 */

typedef struct Vertex{
    char value;
} Vertex;

typedef struct Edge{
    Vertex *a;
    Vertex *b;
} Edge;

typedef struct Graph{
    Vertex** verticles;
    int Vcapacity;
    int Vallocated;
    Edge** edges;
    int Ecapacity;
    int Eallocated;
} Graph;

Graph* createGraph(int size){
    Graph* g = malloc(sizeof(Graph));
    g->verticles = malloc(sizeof(Vertex*) * size * 2);
    g->edges = malloc(sizeof(Edge*) * size);
    g->Vallocated = 0;
    g->Eallocated = 0;
    g->Vcapacity= size;
    g->Ecapacity= size;
    return g;
}

Vertex* addVertex(Graph *g, int value){
    if (g->Vallocated == g->Vcapacity){
        return NULL;
    }
    Vertex* v = malloc(sizeof(Vertex));
    v->value = value;
    g->verticles[g->Vallocated] = v;
    g->Vallocated++;
    return v;
}

void addEdge(Graph *g, Vertex *a, Vertex *b){
    if (g->Eallocated == g->Ecapacity){
    }
    else{
        Edge* e = malloc(sizeof(Edge));
        e->a = a;
        e->b = b;
        g->edges[g->Eallocated] = e;
    }
    g->Eallocated++;
}

Edge* findEdge(Graph *g, Vertex* value){
    int i;
    for(i = 0; i < g->Eallocated; i++){
        if ((g->edges[i]->a == value) || (g->edges[i]->b == value)){
                return g->edges[i];
        }
    }
    return (Edge*)-1;
}

int findEdgeIndex(Graph *g, Vertex* value){
    int i;
    for(i = 0; i < g->Eallocated; i++){
        if ((g->edges[i]->a == value) || (g->edges[i]->b == value)){
                return i;
        }
    }
    return -1;
}

void displayGraph(Graph *g){
    int i;
    printf("Verticles : {");
    for(i=0;i < g->Vallocated; i++){
        printf("%x:%c", g->verticles[i], g->verticles[i]->value);
        if(i < g->Vallocated-1){
            printf(", ");
        }else{
            printf("}\n");
        }
    }
    printf("Edges : {\n");
    for(i=0;i < g->Eallocated; i++){
        printf("[%d] : ", i);
        printf("%x----%x", g->edges[i]->a, g->edges[i]->b);
        printf("\n");
    }
    printf("}\n");
}

//DFS
void DepthFirstSearch(Graph *graph){
    Vertex** visited;
    visited = malloc(sizeof(Vertex*) * graph->Vallocated);
    int visitedNum = 0;

    Vertex** stackVisited;
    stackVisited = malloc(sizeof(Vertex*) * graph->Vallocated);
    int stackTop = graph->Vallocated-1;

    visited[visitedNum] = graph->verticles[0];
    visited++;
    stackVisited[stackTop] = graph->verticles[0];
    stackTop--;
}

//BFS
void BreadthFirstSearch(Graph *graph){
}

int main(){
    Graph* g = createGraph(16);
    Vertex* s = addVertex(g, 's');
    Vertex* a = addVertex(g, 'a');
    Vertex* b = addVertex(g, 'b');
    Vertex* c = addVertex(g, 'c');
    Vertex* d = addVertex(g, 'd');
    addEdge(g, s, a);
    addEdge(g, a, d);
    addEdge(g, d, b);
    addEdge(g, b, s);
    addEdge(g, d, c);
    addEdge(g, s, c);
    displayGraph(g);
    return 0;
}
