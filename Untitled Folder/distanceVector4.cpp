/*
	STRUKTUR VECTOR(MATRIX)

	VECTOR DISTANCE
	NODE | DISTANCE | NEXTHOP

	NEIGHBOUR TABLE
	NODE | list of NEIGHBOUR NODE

	SKENARIO TABLE
	FROM | TO
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<short> > inputNode();
void inputNodeVoid(vector<vector<short> > *node);
vector<vector<short> > inputSkenario();
void inputSkenarioVoid(vector<vector<short> > *skenario);
vector<vector<short> > makeDistanceVector(int n_node, vector<short> &node);
void makeDistanceVectorVoid(int n_node, vector<short> &node, vector<vector<short> > *distanceVector);
vector<vector<vector<short> > > initiateDistanceVector(vector<vector<short> > &node);
void initiateDistanceVectorVoid(vector<vector<short> > &node, vector<vector<vector<short> > > *distanceVector);
void printVector(vector<vector<short> > &vectorPrint);
void printRoutingTable(vector<vector<short> > &vectorPrint);
void printRoutingTable2(vector<vector<short> > &vectorPrint);
void updateDistanceVector(vector<vector<short> > &from, vector<vector<short> > *to, int node_from);

int main() {
	vector<vector<short> > neighbour_table;
	vector<vector<short> > skenario_table;
	vector<vector<vector<short> > > distanceVector;

	inputNodeVoid(&neighbour_table);
	inputSkenarioVoid(&skenario_table);
	initiateDistanceVectorVoid(neighbour_table, &distanceVector);

	for(int idx = 0; idx < skenario_table.size(); idx++) {
		int from = skenario_table[idx][0] - 1;
		int to = skenario_table[idx][1] - 1;
		updateDistanceVector(distanceVector[from], &distanceVector[to], from + 1);
	}

	for(int idx = 0; idx < distanceVector.size(); idx++) {
		printRoutingTable2(distanceVector[idx]);
	}
    
	return 0;
}

vector<vector<short> > inputNode() {
	int n_node, n_edge;
	vector<vector<short> > node;

    cin >> n_node;
    cin >> n_edge;
    for (int idx = 0; idx < n_node; idx++) {
		vector<short> single_node;
        single_node.push_back(idx+1);
		node.push_back(single_node);
	}
	for (int idx = 0; idx < n_edge; idx++) {
        int from, to;

        cin >> from;
        cin >> to;
        node[from-1].push_back(to);
        node[to-1].push_back(from);
	}
	return node;
}

void inputNodeVoid(vector<vector<short> > *node) {
	int n_node, n_edge;


    cin >> n_node;
    cin >> n_edge;
    for (int idx = 0; idx < n_node; idx++) {
		vector<short> single_node;
        single_node.push_back(idx+1);
		(*node).push_back(single_node);
	}
	for (int idx = 0; idx < n_edge; idx++) {
        int from, to;

        cin >> from;
        cin >> to;
        (*node)[from-1].push_back(to);
        (*node)[to-1].push_back(from);
	}
}

vector<vector<short> > inputSkenario() {
	int n_skenario;
	vector<vector<short> > skenario;

	cin >> n_skenario;
	for (int idx = 0; idx < n_skenario; idx++) {
		int from, to;
		vector<short> single_skenario;

		cin >> from;
		cin >> to;
		single_skenario.push_back(from);
        single_skenario.push_back(to);
		skenario.push_back(single_skenario);
	}
	return skenario;
}

void inputSkenarioVoid(vector<vector<short> > *skenario) {
	int n_skenario;

	cin >> n_skenario;
	for (int idx = 0; idx < n_skenario; idx++) {
		int from, to;
		vector<short> single_skenario;

		cin >> from;
		cin >> to;
		single_skenario.push_back(from);
        single_skenario.push_back(to);
		(*skenario).push_back(single_skenario);
	}
}

vector<vector<short> > makeDistanceVector(int n_node, vector<short> &node) {
	vector<vector<short> > distanceVector;
	for(int idx = 1; idx <= n_node; idx++) {
		vector<short> single_vector;

		single_vector.push_back(idx);
		single_vector.push_back(-1);
		single_vector.push_back(-1);
		distanceVector.push_back(single_vector);
	}

	for(vector<short>::iterator iit = node.begin(); iit != node.end(); iit++) {	
		if(iit == node.begin()) {
			distanceVector[(*iit)-1][1] = (0);
		} else {
			distanceVector[(*iit)-1][1] = (1);
		}
		distanceVector[(*iit)-1][2] = (*iit);
	}

	return distanceVector;
}


void makeDistanceVectorVoid(int n_node, vector<short> &node, vector<vector<short> > *distanceVector) {
	for(int idx = 1; idx <= n_node; idx++) {
		vector<short> single_vector;

		single_vector.push_back(idx);
		single_vector.push_back(-1);
		single_vector.push_back(-1);
		(*distanceVector).push_back(single_vector);
	}

	for(vector<short>::iterator iit = node.begin(); iit != node.end(); iit++) {	
		if(iit == node.begin()) {
			(*distanceVector)[(*iit)-1][1] = (0);
		} else {
			(*distanceVector)[(*iit)-1][1] = (1);
		}
		(*distanceVector)[(*iit)-1][2] = (*iit);
	}
}

vector<vector<vector<short> > > initiateDistanceVector(vector<vector<short> > &node) {
	vector<vector<vector<short> > > distanceVector;
	
	for(int idx = 0; idx < node.size(); idx++) {
		distanceVector.push_back(makeDistanceVector(node.size(), node[idx]));
	}

	return distanceVector;
}


void initiateDistanceVectorVoid(vector<vector<short> > &node, vector<vector<vector<short> > > *distanceVector) {
	for(int idx = 0; idx < node.size(); idx++) {
		(*distanceVector).push_back(makeDistanceVector(node.size(), node[idx]));
	}
}

void printVector(vector<vector<short> > &vectorPrint) {
	for(vector<vector<short> >::iterator iit = vectorPrint.begin(); iit != vectorPrint.end(); iit++) {
		if((*iit).size() != 0) {
			for(vector<short>::iterator jit = (*iit).begin(); jit != (*iit).end(); jit++) {
                if(jit != (*iit).end()) {
                    cout << *jit << ' ';    
                }
			}
		}
		cout << endl;		
	}
}

void printRoutingTable(vector<vector<short> > &vectorPrint) {
	for(vector<vector<short> >::iterator iit = vectorPrint.begin(); iit != vectorPrint.end(); iit++) {
		for(vector<short>::iterator jit = (*iit).begin(); jit != (*iit).end(); jit++) {
			if(jit != (*iit).begin()) {
                if(jit != (*iit).end()) {
                    cout << *jit << ' ';
                }
			}
		}
		cout << endl;
	}
}

void printRoutingTable2(vector<vector<short> > &vectorPrint) {
	for(int iit = 0; iit < vectorPrint.size(); iit++) {
		for(int jit = 1; jit < vectorPrint[iit].size(); jit++) {
            if(jit+1 != vectorPrint[iit].size()) {
                cout << vectorPrint[iit][jit] << ' ';
            }
            else {
                cout << vectorPrint[iit][jit];
            }
		}
		cout << endl;
	}
}

void updateDistanceVector(vector<vector<short> > &from, vector<vector<short> > *to, int node_from) {
	for(int idx = 0; idx < from.size(); idx++) {
		if((*to)[idx][1] < 0) {
			if(from[idx][1] != (*to)[idx][1]) {
				(*to)[idx][1] = from[idx][1] + 1;
				(*to)[idx][2] = node_from;
			}
		}
	}
}