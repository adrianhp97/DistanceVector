/*
	STRUKTUR VECTOR(MATRIX)

	VECTOR DISTANCE
	NODE | DISTANCE | NEXTHOP

	NEIGHBOUR TABLE
	NODE | list of NEIGHBOUR NODE

	SKENARIO TABLE
	FROM | TO

	SKENARIO IDX = 0 => SKENARIO[0][0]
	NODE IDX = 1 => NODE[1][1]
	DISTANCE VECTOR IDX = 1 DISTANCEVECTOR[1][1][0]
*/


#include <stdio.h>
#include <stdlib.h>

void nodeAllocation(short** node, int n_node);
void nodeDeallocation(short** skenario);
void skenarioAllocation(short** skenario, int n_skenario);
void skenarioDeallocation(short** node);
void distanceVectorAllocation(short*** node, int n_node);
void distanceVectorDeallocation(short*** node);
void edgeAllocation(short** edge, int n_edge);
void edgeDeallocation(short** edge);
int countIntegerInArray(short* array, int number);
int searchMark(short* array);

bool isNNodeValid(int n_node);
bool isMEdgeValid(int n_edge, int n_node);
bool isNSkenarioValid(int n_skenario);
bool isNodeValid(int n_node, int n1, int n2);
bool isSkenarioValid(int n_node, int s1, int s2);

void inputNode(short** node);
void inputSkenario(short** skenario);
void makeDistanceVector(short** node);
void initiateDistanceVector(short*** node, short** neighbour);
void printTable(short** node);
void printRoutingTable(short** node);
void updateDistanceVector(short** from, short** to, int node_from);

int main() {
	short** neighbour_table;
	short** skenario_table;
	short*** distanceVector;

	inputNode(neighbour_table);
	inputSkenario(skenario_table);
	initiateDistanceVector(distanceVector, neighbour_table);
	// nodeDeallocation(neighbour_table);

	// if (neighbour_table.size() != 0) {
	// 	for(int idx = 0; idx < skenario_table.size(); idx++) {
	// 		int from = skenario_table[idx][0] - 1;
	// 		int to = skenario_table[idx][1] - 1;
	// 		updateDistanceVector(distanceVector[from], &distanceVector[to], from + 1);
	// 	}
	// 	skenarioDeallocation(skenario_table);
	
	// 	for(int idx = 0; idx < distanceVector.size(); idx++) {
	// 		printRoutingTable2(distanceVector[idx]);
	// 	}
	// 	distanceVectorDeallocation(distanceVector);
	// }

	return 0;
}

void nodeDeallocation(short** node) {
	for (int idx = 0; idx <= sizeof(node); idx++) {
		delete [] node[idx];
	}
	delete [] node;
}

void skenarioAllocation(short** skenario, int n_skenario) {
	skenario = (short**) malloc(n_skenario * sizeof(short*));
	for (int idx = 0; idx <= sizeof(skenario); idx++) {
		skenario[idx] = (short*) malloc(2 * sizeof(short));
	}
}

void skenarioDeallocation(short** skenario) {
	for (int idx = 0; idx <= sizeof(skenario); idx++) {
		delete [] skenario[idx];
	}
	delete [] skenario;
}

void distanceVectorAllocation(short*** node, int n_node) {
	node = (short***) malloc(n_node+1 * sizeof(short**));
	for (int idx = 1; idx <= n_node; idx++) {
		node[idx] = (short**) malloc(n_node+1 * sizeof(short*));
		for(int jdx = 0; jdx < 3; jdx++) {
			node[idx][jdx] = (short*) malloc(2 * sizeof(short));
		}
	}
}

void distanceVectorDeallocation(short*** node) {
	for (int idx = 0; idx <= sizeof(node); idx++) {
		for (int jdx = 0; jdx <= 3; jdx++) {
			delete [] node[idx][jdx];
		}
		delete [] node[idx];
	}
	delete [] node;
}

void edgeDeallocation(short** edge) {
	for (int idx = 0; idx <= sizeof(edge); idx++) {
		delete [] edge[idx];
	}
	delete [] edge;
}

int countIntegerInArray(short* array, int number) {
	int count = 0;
	for (int idx = 0; idx < sizeof(array); idx++) {
		if (array[idx] == number) {
			count++;
		}
	}
	return count;
}

int searchMark(short* array) {
	int idx = 1;
	while (idx != sizeof(array) && array[idx] != -1 ) {
		idx++;
	}
	return idx;
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

void inputNode(short** node) {
	int n_node, n_edge;
	short** edge;

	scanf("%d %d", &n_node, &n_edge);
	if (isNNodeValid(n_node) && isMEdgeValid(n_edge, n_node)) {
		node = (short**) malloc(n_node + 1 * sizeof(short*));
		edge = (short**) malloc(n_edge * sizeof(short*));
		for (int idx = 0; idx < n_edge; idx++) {
			edge[idx] = (short*) malloc(2 * sizeof(short));
		}
		for (int idx = 0; idx < n_edge; idx++) {
			int from, to;
	
			scanf("%d %d", &from, &to);
			if (isNodeValid(n_node, from, to)) {
				edge[idx][0] = from; 
				edge[idx][1] = to;
			}
		}

		for (int idx = 1; idx <= n_node; idx++) {
			int counter = countIntegerInArray(edge[0], idx) + countIntegerInArray(edge[1], idx);
			node[idx] = (short*) malloc(counter+1 * sizeof(short*));
			node[idx][1] = -1;

			printf("%d\n", counter);
		}

		for (int idx = 0; idx < n_edge; idx++) {
			// int from = searchMark(node[edge[idx][0]]);
			// int to = searchMark(node[edge[idx][1]]);
			// node[edge[idx][0]][from] = edge[idx][1];
			// node[edge[idx][1]][to] = edge[idx][0];
			// if (from+1 != sizeof(node[edge[idx][0]])) {
			// 	node[edge[idx][0]][from + 1] = -1;	
			// }
			// if (to+1 != sizeof(node[edge[idx][0]])) {
			// 	node[edge[idx][1]][to + 1] = -1;	
			// }
		}

		// edgeDeallocation(edge);
	}
}

void inputSkenario(short** skenario) {

}

void makeDistanceVector(short** node) {

}

void initiateDistanceVector(short*** node, short** neighbour) {

}

void printTable(short** node) {

}

void printRoutingTable(short** node) {

}

void updateDistanceVector(short** from, short** to, int node_from) {

}
