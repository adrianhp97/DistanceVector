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
vector<vector<short> > inputSkenario();
vector<vector<short> > makeDistanceVector(int n_node, vector<short> &node);
vector<vector<vector<short> > > initiateDistanceVector(vector<vector<short> > &node);
void printVector(vector<vector<short> > &vectorPrint);
void printRoutingTable(vector<vector<short> > &vectorPrint);
void printRoutingTable2(vector<vector<short> > &vectorPrint);
void updateDistanceVector(vector<vector<short> > &from, vector<vector<short> > *to, int node_from);

int main() {
	vector<vector<short> > neighbour_table;
	vector<vector<short> > skenario_table;
    vector<vector<vector<short> > > distanceVector;
    
    int n_node, n_edge;

    cin >> n_node;
    cin >> n_edge;
    for (int idx = 0; idx < n_node; idx++) {
		vector<short> single_node;
        single_node.push_back(idx+1);
		neighbour_table.push_back(single_node);
	}
	for (int idx = 0; idx < n_edge; idx++) {
        int from, to;

        cin >> from;
        cin >> to;
        neighbour_table[from-1].push_back(to);
        neighbour_table[to-1].push_back(from);
    }
    
    int n_skenario;

	cin >> n_skenario;
	for (int idx = 0; idx < n_skenario; idx++) {
		int from, to;
		vector<short> single_skenario;

		cin >> from;
		cin >> to;
		single_skenario.push_back(from);
        single_skenario.push_back(to);
		skenario_table.push_back(single_skenario);
    }
    
    for(int idx = 0; idx < neighbour_table.size(); idx++) {
        vector<vector<short> > tempDistanceVector;
        for(int jdx = 1; jdx <= neighbour_table.size(); jdx++) {
            vector<short> single_vector;
    
            single_vector.push_back(jdx);
            single_vector.push_back(-1);
            single_vector.push_back(-1);
            tempDistanceVector.push_back(single_vector);
        }
    
        for(vector<short>::iterator iit = neighbour_table.begin(); iit != neighbour_table.end(); iit++) {	
            if(iit == neighbour_table.begin()) {
                tempDistanceVector[(*iit)-1][1] = (0);
            } else {
                tempDistanceVector[(*iit)-1][1] = (1);
            }
            tempDistanceVector[(*iit)-1][2] = (*iit);
        }
        
		distanceVector.push_back(tempDistanceVector);
	}

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

vector<vector<vector<short> > > initiateDistanceVector(vector<vector<short> > &node) {
	vector<vector<vector<short> > > distanceVector;
	
	for(int idx = 0; idx < node.size(); idx++) {
		distanceVector.push_back(makeDistanceVector(node.size(), node[idx]));
	}

	return distanceVector;
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