#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	set<string> S;
	S.insert("Never gonna give you up");
	S.insert("Never gonna let you down");
	S.insert("Never gonna run around and desert you");
	S.insert("Never gonna make you cry");
	S.insert("Never gonna say goodbye");
	S.insert("Never gonna tell a lie and hurt you");
	S.insert("Never gonna stop");
	int N;
	cin >> N;
	cin.ignore();
	bool y = 1;
	for (int i = 0; i < N; i++) {
		string a;
		getline(cin, a);
		y &= S.count(a);
	}
	cout << (y ? "No" : "Yes");
}