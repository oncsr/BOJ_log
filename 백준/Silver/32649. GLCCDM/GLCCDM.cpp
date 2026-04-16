#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int A, B, K;
	cin >> A >> B >> K;
 
	if (B % A || (B / A) < K)	return cout << -1, 0;
 
	vector<int> ans;
	for (int i = A; i < B; i += A) {
		if (B % i)	continue;
		ans.push_back(i);
		if (ans.size() == K - 1)	break;
	}
	ans.push_back(B);
	if (ans.size() != K)	cout << -1;
	else	for (int i : ans)	cout << i << ' ';
 
}