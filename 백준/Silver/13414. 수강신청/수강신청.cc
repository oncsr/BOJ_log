#include <iostream>
#include <queue>
#include <map>
using namespace std;
using pp = pair<int, string>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	map<string, int> M;
	int n, l, k = 0;
	string a;
	for (cin >> n >> l; l--;) {
		cin >> a;
		M[a] = ++k;
	}
	priority_queue<pp, vector<pp>, greater<> > Q;
	for (auto i = M.begin(); i != M.end(); i++)
		Q.push({ i->second, i->first });
	for (; !Q.empty() && n--;) {
		cout << Q.top().second << '\n';
		Q.pop();
	}
}