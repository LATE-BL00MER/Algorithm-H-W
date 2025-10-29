/*
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define INF 1000

struct Edge {
	int start, end, weight;
};

typedef struct GraphType {
	int n; // ������ ��
	struct Edge edges[2 * MAX_VERTICES];
}GraphType;

int parent[MAX_VERTICES];

void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

void graph_init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void insert_edge(GraphType* g, int start, int end, int weight) {
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = weight;
	g->n++;
}

int compare(const void* a, const void* b) { // ����Ƽ �˻�
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

int set_find(int curr) {
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1) curr = parent[curr]; // ���迡 ������ ���� �� �ڵ� ����!
	return curr; // ���迡 ������ ���� �� �ڵ� ����!
}

void set_union(int a, int b) {
	int root1 = set_find(a); // 5
	int root2 = set_find(b); // 0
	if (root1 != root2)
		parent[root1] = root2;
}

void kruskal(GraphType* g, int n) { // ����Ƽ �˻�
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;

	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("---kruskal MST �˰���---\n");

	int i = 0;
	while (edge_accepted < (g->n - 1)) {
		e = g->edges[i];
		uset = set_find(e.start); // 5
		vset = set_find(e.end); // 0

		if (uset != vset) {
			printf("����(%d, %d) %d ����\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));

	int v = 7; // ������ ����

	set_init(v);
	graph_init(g);

	insert_edge(g, 0, 1, 29);
	insert_edge(g, 1, 2, 16);
	insert_edge(g, 2, 3, 12);
	insert_edge(g, 3, 4, 22);
	insert_edge(g, 4, 5, 27);
	insert_edge(g, 5, 0, 10);
	insert_edge(g, 6, 1, 15);
	insert_edge(g, 6, 3, 18);
	insert_edge(g, 6, 4, 25);

	kruskal(g, v);
}
*/

//Prim �˰���
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10
#define INF 1000L

typedef struct GraphType {
	int n; // ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES]; // ����ġ ������� 
}GraphType;

int selected[MAX_VERTICES]; // �湮 ���� ǥ�� �迭(������ ������ŭ �ʿ�)
int distance[MAX_VERTICES]; // �Ÿ��� �����ϴ� �迭(������ ������ŭ �ʿ�)

int get_min_vertex(int n) {
	int v;
	for (int i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	return v;
}

void prim(GraphType* g, int s) {
	for (int u = 0; u < g->n; u++) 
		distance[u] = INF;
	distance[s] = 0;

	int u;
	for (int i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("���� %d �߰�\n", u);

		for (int v = 0; v < g->n; v++)
			if (g->weight[u][v] != INF)
				if (!selected[v] && g->weight[u][v] <distance[v])
					distance[v] = g->weight[u][v];
	}
}

int main() {
	GraphType g = { 7,
		{ {0, 29, INF, INF, INF, 10, INF},
		  {29, 0, 16, INF, INF, INF, 15},
		  {INF, 16, 0, 12, INF, INF, INF},
		  {INF, INF, 12, 0, 22, INF, 18},
		  {INF, INF, INF, 22, 0, 27, 25},
		  {10, INF, INF, INF, 27, 0, INF},
		  {INF, 15, INF, 18, 25, INF, 0},
		}
	};
	prim(&g, 0);
} 