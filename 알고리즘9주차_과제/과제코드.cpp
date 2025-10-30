#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10
#define INF 1000

struct Edge {
	int start, end, weight;
};

typedef struct KruskalGraph {
	int n;
	struct Edge edges[2 * MAX_VERTICES];
} KruskalGraph;

int parent[MAX_VERTICES];

void set_init(int n) {
	for (int i = 0; i < n; i++)
		parent[i] = -1;
}

int set_find(int curr) {
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1) curr = parent[curr];
	return curr;
}

void set_union(int a, int b) {
	int root1 = set_find(a);
	int root2 = set_find(b);
	if (root1 != root2)
		parent[root1] = root2;
}

void kruskal_graph_init(KruskalGraph* g) {
	g->n = 0;
	for (int i = 0; i < 2 * MAX_VERTICES; i++) {
		g->edges[i].start = 0;
		g->edges[i].end = 0;
		g->edges[i].weight = INF;
	}
}

void kruskal_insert_edge(KruskalGraph* g, int start, int end, int weight) {
	g->edges[g->n].start = start;
	g->edges[g->n].end = end;
	g->edges[g->n].weight = weight;
	g->n++;
}

int compare(const void* a, const void* b) {
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(KruskalGraph* g, int v_count) {
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;

	set_init(v_count);

	qsort(g->edges, g->n, sizeof(struct Edge), compare);

	printf("--- Kruskal MST �˰��� ---\n");

	int i = 0;
	while (edge_accepted < (v_count - 1)) {
		if (i >= g->n) {
			printf("����: MST�� �����ϱ⿡ ������ �����մϴ�.\n");
			break;
		}

		e = g->edges[i];
		uset = set_find(e.start);
		vset = set_find(e.end);

		if (uset != vset) {
			printf("���� (%d, %d) %d ����\n", e.start, e.end, e.weight);
			edge_accepted++;
			set_union(uset, vset);
		}
		i++;
	}
	printf("\n");
}

typedef struct PrimGraph {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
} PrimGraph;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n) {
	int v = -1;

	for (int i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;
		}
	}

	if (v == -1) return -1;

	for (int i = 0; i < n; i++) {
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;
	}
	return v;
}

void prim(PrimGraph* g, int s) {
	for (int u = 0; u < g->n; u++) {
		distance[u] = INF;
		selected[u] = FALSE;
	}

	distance[s] = 0;

	printf("--- Prim MST �˰��� (����: %d) ---\n", s);

	int u;
	for (int i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);

		if (u == -1 || distance[u] == INF) break;

		selected[u] = TRUE;
		printf("���� %d �߰� (���: %d)\n", u, distance[u]);

		for (int v = 0; v < g->n; v++) {
			if (g->weight[u][v] != INF) {
				if (!selected[v] && g->weight[u][v] < distance[v])
					distance[v] = g->weight[u][v];
			}
		}
	}
	printf("\n");
}

int main() {
	int vertex_count = 7;
	int choice = -1;

	printf("--------�ּ� ���� Ʈ�� �˰����� �����غ���!--------\n");

	while (1) {
		printf("\n-------------1, 2, 3���� �����ϼ���!-------------\n");
		printf("1��: Kruskal �˰���\n");
		printf("2��: Prim �˰���\n");
		printf("3��: ���α׷� ����\n");
		printf("����: ");

		int result = scanf("%d", &choice);

		while (getchar() != '\n');

		if (result != 1) {
			choice = -1;
		}

		switch (choice) {
		case 1: {
			printf("1���� �����߽��ϴ�!\n");
			printf("Kruskal �˰������� �׷����� ����մϴ�\n");

			KruskalGraph* g_kruskal;
			g_kruskal = (KruskalGraph*)malloc(sizeof(KruskalGraph));
			kruskal_graph_init(g_kruskal);

			kruskal_insert_edge(g_kruskal, 0, 1, 29);
			kruskal_insert_edge(g_kruskal, 1, 2, 16);
			kruskal_insert_edge(g_kruskal, 2, 3, 12);
			kruskal_insert_edge(g_kruskal, 3, 4, 22);
			kruskal_insert_edge(g_kruskal, 4, 5, 27);
			kruskal_insert_edge(g_kruskal, 5, 0, 10);
			kruskal_insert_edge(g_kruskal, 6, 1, 15);
			kruskal_insert_edge(g_kruskal, 6, 3, 18);
			kruskal_insert_edge(g_kruskal, 6, 4, 25);

			kruskal(g_kruskal, vertex_count);

			free(g_kruskal);
			break;
		}

		case 2: {
			printf("2���� �����߽��ϴ�!\n");
			printf("Prim �˰������� �׷����� ����մϴ�\n");

			PrimGraph g_prim = { 7,
				{ {0, 29, INF, INF, INF, 10, INF},
				  {29, 0, 16, INF, INF, INF, 15},
				  {INF, 16, 0, 12, INF, INF, INF},
				  {INF, INF, 12, 0, 22, INF, 18},
				  {INF, INF, INF, 22, 0, 27, 25},
				  {10, INF, INF, INF, 27, 0, INF},
				  {INF, 15, INF, 18, 25, INF, 0},
				}
			};

			prim(&g_prim, 0);
			break;
		}

		case 3:
			printf("���α׷��� �����մϴ�!\n");
			return 0;

		default:
			printf("!! �߸� �Է��߽��ϴ�! 1, 2, 3���� �������ּ���!\n");
			break;
		}
	}
}