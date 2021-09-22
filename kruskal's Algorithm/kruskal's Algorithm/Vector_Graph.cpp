#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void printGraph(vector <pair <int, int> > adj[], int V) {
	int v, w;

	for (int u = 0; u < V; u++) {
		cout << "Node " << u << " Makes an edge with " << endl;

		for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
			v = i->first;
			w = i->second;

			cout << "\n Node " << v << " with the weight = " << w << endl;

		}

		cout << endl;

	}


}

void addEdge(vector <pair<int, int> > adj[], int u, int v, int weight) {

	adj[u].push_back(make_pair(v, weight));
	adj[v].push_back(make_pair(u, weight));
}

int main1() {
	const int V = 5;
	int u, v, w, edge = 0;
	vector <pair < int, pair < int, int> >  > graph ;

	cout << "How many Edges: ";
	cin >> edge;
	cout << "Enter the Connections\n";

	for (int i = 0; i < edge; i++) {
		cin >> u;
		cin >> v;
		cin >> w;

		graph.push_back(make_pair(w, make_pair(u, v)));
	}

	cout << "Unsorted\n";

	for (int i = 0; i < graph.size(); i++) {
		cout << graph[i].second.first << ' ' << graph[i].second.second << ' ' <<  graph[i].first << endl;
	}

	cout << "Sorted\n";
	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++) {
		cout << graph[i].second.first << ' ' << graph[i].second.second <<  ' ' <<  graph[i].first << endl;
	}



	




	return 0;
}

