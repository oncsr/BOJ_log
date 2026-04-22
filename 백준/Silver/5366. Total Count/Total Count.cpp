#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string a;
	map<string, int> M;
	vector<string> V;
	for (getline(cin, a); a != "0"; getline(cin, a)) {
		if (!M[a])	V.push_back(a);
		M[a]++;
	}
	int s = 0;
	for (string i : V) {
		cout << i << ": " << M[i] << '\n';
		s += M[i];
	}
	cout << "Grand Total: " << s;
}