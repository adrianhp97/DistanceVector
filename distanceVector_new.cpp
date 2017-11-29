#include <iostream>

using namespace std;

struct TableRow {
    int distance;
    int nextHop;

    TableRow(): distance(-1), nextHop(-1) {}
};

bool validateInt(int n, int from, int to);

int main() {
    int n,m;
    cin >> n >> m;

    if (validateInt(n,1,1000) && validateInt(m, 0, n*(n-1)/2)) {
        TableRow rTable[n][n];
        int s;

        //Set self node distance 0 and nexthop to self 
        for(int i=0; i<n;i++){
            rTable[i][i].distance = 0;
            rTable[i][i].nextHop = i+1;
        }

        //Set edge
        for(int i=0; i < m; i++) {
            int u,v;
            cin >> u >> v;
            if (validateInt(u,1,n) && validateInt(v,1,n)) {
                rTable[u-1][v-1].distance = rTable[v-1][u-1].distance = 1;
                rTable[u-1][v-1].nextHop = v;
                rTable[v-1][u-1].nextHop = u;
            }
        }

        //Get number of scenario
        cin >> s;
        if (validateInt(s,0,100000)) {
            //Get scenario
            for(int i=0; i < s;i++) {
                int x,y;
                cin >> x >> y;
                if (validateInt(x,1,n) && validateInt(y,1,n) && rTable[x-1][y-1].distance == 1) {
                    for(int j=0; j<n; j++) {
                        if (rTable[x-1][j].distance != -1 && (j != y-1 || j != x-1)) {
                            if (rTable[y-1][j].distance == -1) {
                                rTable[y-1][j].distance = rTable[x-1][j].distance + 1;
                                rTable[y-1][j].nextHop = x;
                            } else if (rTable[x-1][j].distance < rTable[y-1][j].distance) {
                                rTable[y-1][j].distance = rTable[x-1][j].distance + 1;
                                rTable[y-1][j].nextHop = x;
                            }
                        }
                    }
                }
            }
        }

        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                cout << rTable[i][j].distance << ' ' << rTable[i][j].nextHop << endl;
            }
        }
    }
}

bool validateInt(int n, int from, int to) {
    return (n >= from && n <= to);
}