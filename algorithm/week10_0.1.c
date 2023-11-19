#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _crt_secure_no_warnings
#pragma warning(disable:4996)

typedef struct Vertex {
	int data;
	struct Vertex* next;
	struct Edge* adjacencyList;
}VERTEX;

typedef struct Edge {
	int weight;
	VERTEX* from;
	VERTEX* target;
	struct Edge* next;
}EDGE;

typedef struct Graph {
	VERTEX* vertices;
	int vertexCount;
}GRAPH;

GRAPH* createGraph() {
	GRAPH* graph = (GRAPH*)malloc(sizeof(GRAPH));
	graph->vertices = NULL;
	graph->vertexCount = 0;
	return graph;
}

VERTEX* createVertex(int data) {
	VERTEX* v = (VERTEX*)malloc(sizeof(VERTEX));
	v->data = data;
	v->next = NULL;
	v->adjacencyList = NULL;
	
	return v;
}

void addVertex(GRAPH* g, VERTEX* v) {
	VERTEX* vertexList = g->vertices;

	if (vertexList == NULL) {
		g->vertices = v;
	}
	else {
		while (vertexList->next != NULL) {
			vertexList = vertexList->next;
		}
		vertexList->next = v;
	}
	g->vertexCount++;
}

void addEdge(VERTEX* v, EDGE* e) {
	if (v->adjacencyList == NULL) {
		v->adjacencyList = e;
	}
	else {
		EDGE* adjacencyList = v->adjacencyList;

		while (adjacencyList->next != NULL) {

			if ((adjacencyList->target->data) > (e->target->data)) {
				e->next = adjacencyList->next;

			}


		}
	}
}

EDGE* createEdge(VERTEX* from, VERTEX* target, int weight) {
	EDGE* newEdge = (EDGE*)malloc(sizeof(EDGE));
	newEdge->from = from;
	newEdge->target = target;
	newEdge->weight = weight;
	newEdge->next = NULL;
	return newEdge;
}

int main() {
	GRAPH* graph = createGraph();
	
	VERTEX* v1 = createVertex(1); VERTEX* v2 = createVertex(2); VERTEX* v3 = createVertex(3);
	VERTEX* v4 = createVertex(4); VERTEX* v5 = createVertex(5); VERTEX* v6 = createVertex(6);

	addVertex(graph,v1); addVertex(graph, v2); addVertex(graph, v3);
	addVertex(graph,v4); addVertex(graph, v5); addVertex(graph, v6);

	addEdge(v1, createEdge(v1, v2, 1));
	


	return 0;
}
