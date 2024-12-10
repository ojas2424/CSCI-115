#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define V 5

bool createMST(int a, int b, vector<bool> prims) {
	if (a == b) {
		return false;
	}
	if (prims[a] == false && prims[b] == false) {
		return false;
	}
	else if (prims[a] == true && prims[b] == true) {
		return false;
	}
	return true;
}

void primsMethod(int cost[][V]) {
	vector<bool> prims(V, false);
	prims[0] = true;
	int edge = 0;
	int costmst = 0;

	while (edge < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V;i++) {
			for (int j = 0;j < V;j++) {
				if (cost[i][j] < min) {
					if (createMST(i, j, prims)) {
						min = cost[i][j];
						a = i;
						b = j;
					}
				}
			}
		}

		if (a != -1 && b != -1) {
			cout << "edge " << edge++ << " : (" << a << "," << b << "):cost =" << min << endl;
			costmst += min;
			prims[b] = prims[a] = true;
		}
	}
	cout << "cost : " << costmst;
}

//Kruskal's algorithm 
int parent[V];

int find(int i) {
	while (parent[i] != i) {
		i = parent[i];
	}
	return i;
}

void uni(int i, int j) {
	int a = find(i);
	int b = find(j);
	parent[a] = b;
}

/*void kruskalMST(int cost[][V]) {
	int MSTcost = 0;

	for (int i = 0; i < V;i++) {
		parent[i] = i;
	}

	int edge = 0;
	while (edge < V - 1) {
		int min = INT_MAX, a = -1, b = -1;

		for (int i = 0; i < V;i++) {
			for (int j = 0;j < V;j++) {
				if (find(i) != find(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}
		uni(a, b);
		cout << "Edge " << edge++ << " : (" << a << "," << b << "):cost =" << min << endl;
		MSTcost += min;
	}
	cout << "Total cost of MST: " << MSTcost << endl;
}
*/

int main() {
	int graph[][V] = {
		{INT_MAX, 20, INT_MAX, 24, INT_MAX},
		{11, INT_MAX, 13,8,10},
		{INT_MAX,11,INT_MAX,INT_MAX,17},
		{25,8,INT_MAX,INT_MAX,15},
		{INT_MAX,12,17,15,INT_MAX},
		{INT_MAX,13,15,18,INT_MAX},
	};
	cout << "Prim's algorithm: " << endl;
	primsMethod(graph);
	cout << "\n" << endl;

}