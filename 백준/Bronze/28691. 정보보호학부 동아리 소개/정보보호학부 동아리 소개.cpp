#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	char a;
	cin >> a;
	if (a == 'M')	cout << "MatKor";
	if (a == 'W')	cout << "WiCys";
	if (a == 'C')	cout << "CyKor";
	if (a == 'A')	cout << "AlKor";
	if (a == '$')	cout << "$clear";
}