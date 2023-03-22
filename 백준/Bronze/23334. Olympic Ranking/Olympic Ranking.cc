#include <iostream>
#include <string>
#include <queue>
using namespace std;
using node = pair<pair<int, int>, pair<int, string> >;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, b, c;
	priority_queue<node, vector<node>, less<> > Q;
	for (cin >> N; N--;) {
		cin >> a >> b >> c;
		string s;
		getline(cin, s);
		node A = { {a,b},{c,s} };
		Q.push(A);
	}
	cout << Q.top().second.second.substr(1);
}