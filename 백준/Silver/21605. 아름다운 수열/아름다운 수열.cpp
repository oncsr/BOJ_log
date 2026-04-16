#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N;
	cin >> N;
	if (N == 1)	cout << "-1 1";
	else if (N == 2)	cout << "1 -1 -1 1";
	else {
		cout << "1 1 -1 -1 ";
		N -= 2;
		for (int i = 1; i < N; i++)	cout << "1 -1 ";
		cout << "-1 1";
	}

}