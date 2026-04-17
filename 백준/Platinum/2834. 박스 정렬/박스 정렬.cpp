#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	int arr[1001]{};
	int arr2[1001]{};
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		arr2[i] = a;
	}

	vector<vector<int>> OP;
	auto comp = [&]() {
		for (int j = 1; j <= N; j++)	if (arr[j] != j)	return 0;
		return 1;
	};
	if (comp()) { cout << 0; return 0; }
	while (!comp()) {
		vector<int> Q;
		int vis[1001]{};
		for (int i = 1; i <= N; i++) {
			if (arr[i] == i)	continue;
			Q.push_back(i);
			vis[i]++;
			break;
		}
		int g = Q[0];
		while (!vis[arr[g]]) {
			Q.push_back(arr[g]);
			g = arr[g];
		}
		for (int i : Q)	arr[i] = i;
		OP.push_back(Q);
	}


	
	vector<vector<int>> ans;
	vector<int> st;
	for (int i = 0; i < OP.size(); i++) {
		for (int j : OP[i]) {
			st.push_back(j);
		}
	}
	if (!st.empty()) {
		ans.push_back(st);
		int temp = arr2[st[0]];
		arr2[st[0]] = arr2[st.back()];
		for (int i = st.size() - 1; i > 0; i--)	arr2[st[i]] = arr2[st[i - 1]];
		arr2[st[1]] = temp;
	}



	vector<int> Q;
	int vis[1001]{};
	for (int i = 1; i <= N; i++) {
		if (arr2[i] == i)	continue;
		Q.push_back(i);
		vis[i]++;
		break;
	}
	if (!Q.empty()) {
		int g = Q[0];
		while (!vis[arr2[g]]) {
			Q.push_back(arr2[g]);
			g = arr2[g];
		}
	
		ans.push_back(Q);
		int temp = arr2[Q[0]];
		arr2[Q[0]] = arr2[Q.back()];
		for (int i = Q.size() - 1; i > 0; i--)	arr2[Q[i]] = arr2[Q[i - 1]];
		arr2[Q[1]] = temp;

	}

	cout << ans.size() << '\n';
	for (auto i : ans) {
		cout << i.size() << ": ";
		for (int j : i)	cout << j << ' ';
		cout << '\n';
	}

}