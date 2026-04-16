#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string n, a, b;
	cin >> n >> a >> b;
	int x = 0, y = 0;
	auto game = [](char a, char b) -> bool {
		return (a == 'R' && b == 'S') || (a == 'S' && b == 'P') || (a == 'P' && b == 'R');
	};
	for (int i = stoi(n); i--;) {
		if (game(a[i], b[i]))	x++;
		if (game(b[i], a[i]))	y++;
	}
	cout << (x > y ? "victory" : "defeat");

}