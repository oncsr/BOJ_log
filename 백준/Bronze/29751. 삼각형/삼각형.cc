#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int w, h;
	cin >> w >> h;
	if (w * h % 2)	cout << w * h / 2 + 0.5;
	else	cout << w * h / 2 << ".0";

}