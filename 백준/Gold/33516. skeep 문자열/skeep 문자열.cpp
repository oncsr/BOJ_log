#include <iostream>
#include <string>
#include <stack>
using namespace std;

int N;
string S;
char T[5] = { 's','k','e','e','p' };

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> S;
	int ans = 0;
	stack<char> st;
	for (int i = N - 1; i >= 0; i--) {
		if (S[i] != 's' || st.size() < 4) {
			st.push(S[i]);
			continue;
		}
		bool can = 1;
		stack<char> temp;
		for (int j = 1; j < 5; j++) {
			char t = st.top();
			st.pop();
			can &= (t == T[j] || t == '?');
			temp.push(t);
		}
		if (can) st.push('?'), ans++;
		else {
			while (!temp.empty()) st.push(temp.top()), temp.pop();
			st.push(S[i]);
		}
	}
	cout << ans;
	

}