#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define V 6 

int minimum_dist(int a[], bool y[]) {
	int minimum = INT_MAX, idxMin; 

	for (int v = 0; v < V; v++) {
		if (y[v] == false && a[v] <= minimum) {
			minimum = a[v], idxMin = v;
		}
	}
	return idxMin;
}

void print(int s[]) {
	cout << "Vertex:          from source: " << endl;
	for (int i = 0;i < V;i++) {
		cout << i << "                   " << s[i] << endl;
	}
}

void dijkstra(int graph[V][V], int source) {
	int s[V]; 
	bool y[V]; 

	for (int i = 0; i < V;i++) {
		s[i] = INT_MAX; 
		y[i] = false;  
	}
	s[source] = 0;

	for (int key = 0; key < V - 1;key++) {
		int z = minimum_dist(s, y); 
		y[z] = true; 

		for (int v = 0; v < V; v++) { 
			if (!y[v] && graph[z][v] && s[z] != INT_MAX && s[z] + graph[z][v] < s[v]) {
				s[v] = s[z] + graph[z][v];
			} 
		}
	}
	print(s);
}

int main() {
	int graph[V][V] = {
		{0,4,0,1,3,0},
		{4,0,3,2,0,0},
		{0,0,2,0,1,5},
		{1,0,4,3,5,0},
		{5,0,0,1,0,2},
		{0,5,0,2,0,1}
	};
	dijkstra(graph, 0);
}