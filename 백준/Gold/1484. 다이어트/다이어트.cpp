#include <bits/stdc++.h>
using namespace std;

int main() {
	int s = 2, e = 1, G;
	cin >> G;
	vector<int> ans;
	while (s != e) {
		if (s * s - e * e == G)	ans.push_back(s), e++;
		else if (s * s - e * e < G)	s++;
		else	e++;
	}
	if (ans.empty())	cout << -1;
	else {
		sort(ans.begin(), ans.end());
		for (int i : ans)	cout << i << '\n';
	}
}