#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int n, i = 0;
	cin >> n;
	stack<int> st;

	vector<char> answer;

	for (int j = 0; j < n; j++) {
		int num;
		cin >> num;
		while (num > i) {
			st.push(i + 1);
			answer.push_back('+');
			i++;
		}
		if (st.top() != num) {
			cout << "NO";
			return 0;
		}
		st.pop();
		answer.push_back('-');
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << '\n';
	}

}