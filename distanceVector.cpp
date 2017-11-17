#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int> > inputNode();
vector<vector<int> > inputSkenario();
vector<int> convertStringToInt(string text);
void printVector(vector<vector<int> > vectorPrint);

int main() {
	vector<vector<int> > neighbour_table(inputNode());
	vector<vector<int> > skenario_table(inputSkenario());

	return 0;
}

vector<vector<int> > inputNode() {
	int n_node;
	vector<vector<int> > node;

	cin >> n_node;
	for (int idx = 0; idx < n_node; idx++) {
		string neighbour_node;

		cin >> neighbour_node;
		node.push_back(convertStringToInt(neighbour_node));
	}
	return node;
}

vector<vector<int> > inputSkenario() {
	int n_skenario;
	vector<vector<int> > skenario;

	cin >> n_skenario;
	for (int idx = 0; idx < n_skenario; idx++) {
		string skenario_text;

		cin >> skenario_text;
		skenario.push_back(convertStringToInt(skenario_text));
	}
	return skenario;
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

void printVector(vector<vector<int> > vectorPrint) {
	for(vector<vector<int> >::iterator iit = vectorPrint.begin(); iit != vectorPrint.end(); iit++) {
		for(vector<int>::iterator jit = (*iit).begin(); jit != (*iit).end(); jit++) {
			cout << *jit << ' ';
		}
		cout << endl;		
	}
}