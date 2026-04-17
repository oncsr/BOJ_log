#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string a;
	cin >> a;
	priority_queue<int, vector<int>, greater<>> P;
	priority_queue<int, vector<int>, greater<>> K;
	if (a[0] == 'K')	P.push(1);
	else	K.push(1);
	int mx = 1;
	for (int i = 1; i < a.size(); i++) {
		char now = a[i];
		if (now == 'K') {
			if (K.empty())	P.push(++mx);
			else {
				P.push(K.top());
				K.pop();
			}
		}
		else {
			if (P.empty())	K.push(++mx);
			else {
				K.push(P.top());
				P.pop();
			}
		}
	}
	cout << mx;

}