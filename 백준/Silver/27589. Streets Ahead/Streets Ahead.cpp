#include <iostream>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int id = 1;
	int N, Q;
	cin >> N >> Q;
	map<string, int> M;
	for (; N--;) {
		string a;
		cin >> a;
		M[a] = id++;
	}
	for (; Q--;) {
		string a, b;
		cin >> a >> b;
		cout << abs(M[a] - M[b]) - 1 << '\n';
	}

}