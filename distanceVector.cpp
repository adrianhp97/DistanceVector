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

vector<vector<int> > inputNode();
vector<vector<int> > inputSkenario();
vector<vector<int> > makeDistanceVector(int n_node, vector<int> node);
vector<vector<vector<int> > > initiateDistanceVector(vector<vector<int> > node);
vector<int> convertStringToInt(string text);
vector<int> pushVector(int idx, string text);
void printVector(vector<vector<int> > vectorPrint);
void printRoutingTable(vector<vector<int> > vectorPrint);
void updateDistanceVector(vector<vector<int> > from, vector<vector<int> > *to);

int main() {
	vector<vector<int> > neighbour_table(inputNode());
	vector<vector<int> > skenario_table(inputSkenario());
	vector<vector<vector<int> > > distanceVector(initiateDistanceVector(neighbour_table));

	for(int idx = 0; idx < skenario_table.size(); idx++) {
		updateDistanceVector(distanceVector[skenario_table[idx][0]], &distanceVector[skenario_table[idx][1]]);
		printRoutingTable(distanceVector[skenario_table[idx][1]]);
	}

	return 0;
}

vector<vector<int> > inputNode() {
	int n_node;
	vector<vector<int> > node;

	cin >> n_node;
	for (int idx = 0; idx < n_node; idx++) {
		string neighbour_node;
		vector<int> single_node;

		cin >> neighbour_node;
		single_node = pushVector(idx, neighbour_node);
		node.push_back(single_node);
	}
	return node;
}

vector<vector<int> > inputSkenario() {
	int n_skenario;
	vector<vector<int> > skenario;

	cin >> n_skenario;
	for (int idx = 0; idx < n_skenario; idx++) {
		int from, to;
		vector<int> single_skenario;

		cin >> from;
		cin >> to;
		single_skenario.push_back(from);
		single_skenario.push_back(to);
		skenario.push_back(single_skenario);
	}
	return skenario;
}

vector<vector<int> > makeDistanceVector(int n_node, vector<int> node) {
	vector<vector<int> > distanceVector;
	for(int idx = 1; idx <= n_node; idx++) {
		vector<int> single_vector;

		single_vector.push_back(idx);
		single_vector.push_back(-1);
		single_vector.push_back(-1);
		distanceVector.push_back(single_vector);
	}

	for(vector<int>::iterator iit = node.begin(); iit != node.end(); iit++) {	
		if(iit == node.begin()) {
			distanceVector[(*iit)-1][1] = (0);
		} else {
			distanceVector[(*iit)-1][1] = (1);
		}
		distanceVector[(*iit)-1][2] = (*iit);
	}

	return distanceVector;
}

vector<vector<vector<int> > > initiateDistanceVector(vector<vector<int> > node) {
	vector<vector<vector<int> > > distanceVector;
	
	for(int idx = 0; idx < node.size(); idx++) {
		distanceVector.push_back(makeDistanceVector(node.size(), node[idx]));
	}

	return distanceVector;
}

vector<int> convertStringToInt(string text) {
	vector<int> arrayOfInt;
	for(int idx = 0; idx < text.length(); idx++) {
		if(text[idx] != ',') {
			arrayOfInt.push_back(text[idx] - '0');
		}
	}
	return arrayOfInt;
}

vector<int> pushVector(int idx, string text) {
	vector<int> pushedVector;

	if(text.compare("\n") != 82) {
		vector<int>::iterator it;

		pushedVector = convertStringToInt(text);
		it = pushedVector.begin();
		pushedVector.insert(it, idx+1);
	} else {
		pushedVector.push_back(idx+1);
	}
	
	return pushedVector;
}

void printVector(vector<vector<int> > vectorPrint) {
	for(vector<vector<int> >::iterator iit = vectorPrint.begin(); iit != vectorPrint.end(); iit++) {
		if((*iit).size() != 0) {
			for(vector<int>::iterator jit = (*iit).begin(); jit != (*iit).end(); jit++) {
				cout << *jit << ' ';
			}
		}
		cout << endl;		
	}
}

void printRoutingTable(vector<vector<int> > vectorPrint) {
	for(vector<vector<int> >::iterator iit = vectorPrint.begin(); iit != vectorPrint.end(); iit++) {
		for(vector<int>::iterator jit = (*iit).begin(); jit != (*iit).end(); jit++) {
			if((*jit) != (*iit).begin()) {
				cout << *jit << ' ';
			}
		}
		cout << endl;
	}
}

void updateDistanceVector(vector<vector<int> > from, vector<vector<int> > *to) {
	
}