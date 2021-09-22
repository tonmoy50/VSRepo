#include<iostream>
#include<queue>
#include<limits>
#include<limits.h>

using namespace std;

const int row = 100, column = 100;
int set[100] = { 0 };
int visited[100] = { 0 };
priority_queue <pair <int, pair <int, int> >, vector <pair<int, pair <int, int>> >, greater <pair <int, pair<int, int>> > > qq;

void print_graph(int graph[][column], int n_vertices) {
	cout << "u" << "\t" << "v" << "\t" << "w" << endl;

	for (int u = 0; u < n_vertices; u++) {
		for (int v = 0; v < n_vertices; v++) {
			cout << u << "\t" << v << "\t" << graph[u][v] << endl;
		}
		//cout << endl;
	}
}

bool set_check(int u, int v) {
	if (set[u] == 1) {
		if (set[v] == 1)
			return true;
		else
			return false;
	}
	else
		return false;
}

void Kruskals(int graph[][column], int n_vertices, int edges, int source) {

	//qq.push(pair<int, pair<int, int>>(w, make_pair(u, v)));
	
	while (!qq.empty()) {
		int u = qq.top().second.first;
		int v = qq.top().second.second;
		int w = qq.top().first;

		if (set_check(u, v) == false) {
			cout << u << "\t" << v << "\t" << w << endl;
			set[u] = 1;
			set[v] = 1;
		}
		qq.pop();
	}


}

int main() {
	int graph[row][column] = { -1 };
	int n_edges = 0, n_vertices = 0;
	int u, v, w;

	cout << "Enter number of vertices and edges: ";
	cin >> n_vertices >> n_edges;
	cout << "Enter the connection and weight of the edges: " << endl;

	for (int i = 0; i < n_edges; i++) {
		cin >> u >> v >> w;
		graph[u][v] = w;
		qq.push(pair<int, pair<int, int>>(w, make_pair(u, v)));
	}

	int source = 0;
	Kruskals(graph, n_vertices, n_edges, source);

	//print_graph(graph, n_vertices);

	return 0;
}