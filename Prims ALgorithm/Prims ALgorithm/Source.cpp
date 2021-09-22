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

void Prims(int graph[][column], int n_vertices, int edges, int source) {
		
	//qq.push(pair<int, pair<int, int>>(w, make_pair(u, v)));
	int flag = 0;

	qq.push(pair<int, pair<int, int>>(graph[source][0], make_pair(source, 0)));

	while (!qq.empty()) {

		for (int i = 0; i < n_vertices; i++) {
			if (set_check(source, i) == false) {
				if (graph[source][i] != -1)
					qq.push(pair<int, pair<int, int>>(graph[source][i], make_pair(source, i)));
			}
		}

		int u = qq.top().second.first;
		int v = qq.top().second.second;
		int w = qq.top().first;

		set[u] = 1;
		set[v] = 1;

		qq.pop();
		source = v;

		if (set_check(u, v) == true && graph[u][v] != -1)
			cout << u << "\t" << v << "\t" << w << endl;
		
		
		
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
	}

	int source = 0;
	//cout << "Enter Source: ";
	//cin >> source;
	Prims(graph, n_vertices, n_edges, source);

	//print_graph(graph, n_vertices);

	return 0;
}