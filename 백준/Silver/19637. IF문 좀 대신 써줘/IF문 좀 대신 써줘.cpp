#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	vector<int> att;
	vector<string> word;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string a;
		int b;
		cin >> a >> b;
		if (!att.empty() && att.back() == b)	continue;
		word.push_back(a);
		att.push_back(b);
	}
	for (; M--;) {
		int a;
		cin >> a;
		int pos = lower_bound(att.begin(), att.end(), a) - att.begin();
		cout << word[pos] << '\n';
	}
}