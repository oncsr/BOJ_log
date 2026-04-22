#include <iostream>
#include <map>
#include <string>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin >> T;
	map<string, int> M;
	int s = 0;
	for (int i = 0; i < T; i++) {
		string a;
		cin >> a;
		if (a.size() < 6)	continue;
		if (a.substr(a.size() - 6, 6) == "Cheese" && !M[a]) {
			M[a]++;
			s++;
		}
	}
	if (s >= 4)	cout << "yummy";
	else	cout << "sad";
}