#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	string s = "WelcomeToSMUPC";
	cin >> N;
	cout << s[(N - 1) % 14];

}