#include <iostream>
#include <set>
using namespace std;

struct cmp {
	bool operator()(string a, string b) const {
		return a > b;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	set<string, cmp> S;
	for (cin >> n; n--;) {
		string a, b;
		cin >> a >> b;
		if (b == "enter")	S.insert(a);
		else	S.erase(a);
	}
	for (string i : S)	cout << i << '\n';
}