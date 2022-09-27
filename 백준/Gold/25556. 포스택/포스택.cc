#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, a;
	bool suc = true;
	cin >> n;
	vector<vector<int> > V(4);
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (V[0].empty())	V[0].push_back(a);
		else if(a > V[0][V[0].size() - 1]) V[0].push_back(a);
		else {
			if (V[1].empty())	V[1].push_back(a);
			else if (a > V[1][V[1].size() - 1])	V[1].push_back(a);
			else {
				if (V[2].empty())	V[2].push_back(a);
				else if (a > V[2][V[2].size() - 1])	V[2].push_back(a);
				else {
					if (V[3].empty())	V[3].push_back(a);
					else if (a > V[3][V[3].size() - 1])	V[3].push_back(a);
					else {
						suc = false;
						break;
					}
				}
			}
		}
	}
	cout << (suc ? "YES" : "NO");
}