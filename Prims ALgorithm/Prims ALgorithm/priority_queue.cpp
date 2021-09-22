#include<iostream>
#include<queue>
#include<functional>
using namespace std;

int main1() {
	priority_queue <int, vector<int>, greater <int>> q;
	priority_queue < pair <int, int>, vector<pair <int, int> >, greater <pair < int, int > > > q1;

	priority_queue <pair <int, pair <int, int> >, vector <pair<int, pair <int, int>> >, greater <pair <int, pair<int, int>> > > q2;
	
	/*q.push(5);
	q.push(12);
	q.push(3);
	q.push(2);
	q.push(7);*/

	/*q1.push(pair<int, int>(2, 5));
	q1.push(pair<int, int>(1, 3));
	q1.push(pair<int, int>(4, 8));
	q1.push(pair<int, int>(3, 1));
	q1.push(pair<int, int>(20, 10));*/

	q2.push(pair<int, pair<int, int>>(1, make_pair(2, 5)));
	q2.push(pair<int, pair<int, int>>(10, make_pair(1, 5)));
	q2.push(pair<int, pair<int, int>>(3, make_pair(2, 3)));
	q2.push(pair<int, pair<int, int>>(7, make_pair(7, 8)));
	q2.push(pair<int, pair<int, int>>(2, make_pair(4, 9)));

	while ( !q2.empty() ) {
		cout << q2.top().first << "\t" << q2.top().second.first << "\t" << q2.top().second.second << endl;

		q2.pop();
	}


	return 0;
}