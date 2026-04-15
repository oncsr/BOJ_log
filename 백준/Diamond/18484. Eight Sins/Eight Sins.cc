#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, K;
	cin >> N >> K;
	int T = K / N;

	int e = T, s = 1;
	char res;
	for (int i = 1; i <= N; i++) {
		bool ed = 0;
		while (1) {
			cout << e << endl;
			cin >> res;
			if (res == '=') { ed = 1; s = e + 1; e = min(e + T, K); break; }
			if (res == '<')	break;
			s = e + 1;
			e = min(e + T, K);
		}
		if (ed)	continue;
		int ee = e, m = (s + ee) >> 1;
		while (s < ee) {
			cout << m << endl;
			cin >> res;
			if (res == '=')	break;
			if (res == '<')	ee = m;
			else	s = m + 1;
			m = (s + ee) >> 1;
		}
	}

}