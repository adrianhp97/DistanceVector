#include <stdlib.h>

typedef struct $
{
	int nextHop;
	int distance;
} distanceVector;

bool isNNodeValid(int n_node);
bool isMEdgeValid(int n_edge, int n_node);
bool isNSkenarioValid(int n_skenario);
bool isNodeValid(int n_node, int n1, int n2);
bool isSkenarioValid(int n_node, int s1, int s2);

int main() {
	int n, m;
	int node, edge;
	int s;
	int from, to;
	distanceVector** distance;


	scanf("%d %d", &n, &m);
	if (isNNodeValid(n) && isMEdgeValid(m)) {
		for (int idx = 0; idx < ; idx++) {
			for (int jdx = 0; jdx < ; jdx++) {

			}
		}
	}


	return 0;
}

bool isNNodeValid(int n_node) {
	return ((n_node > 0) && (n_node <= 1000));
}

bool isMEdgeValid(int n_edge, int n_node) {
	return ((n_edge >= 0) && (n_edge <= (n_node * (n_node - 1) / 2)));
}

bool isNSkenarioValid(int n_skenario) {
	return ((n_skenario >= 0) && (n_skenario <= 100000));
}

bool isNodeValid(int n_node, int n1, int n2) {
	return ((1 <= n1) && (n2 <= n_node) && (n1 != n2));
}

bool isSkenarioValid(int n_node, int s1, int s2) {
	return ((1 <= s1) && (s2 <= n_node) && (s1 != s2));
}