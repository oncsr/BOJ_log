#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N;
	cin >> N;
	if (N == 1)	return cout << 1, 0;

	string ans1 = to_string(N);
	int len1 = ans1.size();

	bool trig1 = 0;

	string ans2 = "";
	int len2 = 0;
	for (int i = 2; i * i <= N; i++) {
		if (N % i)	continue;
		int g = 0, M = N;
		while (M % i == 0) {
			g++;
			M /= i;
		}
		if (M != 1)	continue;
		// i^g

		ans2 = to_string(i);
		len2 = ans2.size();
		if (g > 1)	ans2 += " " + to_string(g) + " ^ ", len2 += to_string(g).size() + 1;

		vector<int> V;
		for (int j = 2; j < g; j++) {
			if (g % j == 0)	V.push_back(j);
		}

		for (int j : V) {
			// (i^j)^(g/j)
			int a = 1;
			for (int k = 0; k < j; k++)	a *= i;
			string temp = to_string(a) + " " + to_string(g/j) + " ^ ";
			int len = temp.size() - 3;
			if (len < len2)	ans2 = temp, len2 = len;
		}
		if (len2 < len1)	ans1 = ans2, len1 = len2;
	}

	for (int i = 2; i * i < N; i++) {
		if (N % i)	continue;
		int a = i, b = N / i;
		int A = a, B = b;
		int x = -1, y = -1;
		int p = 0, q = 0;
		for (int j = 2; j * j <= a; j++) {
			if (a % j)	continue;
			while (a % j == 0) {
				a /= j;
				p++;
			}
			if (a != 1) {
				p = 0, a = A;
				continue;
			}
			x = j;
		}
		for (int j = 2; j * j <= b; j++) {
			if (b % j)	continue;
			while (b % j == 0) {
				b /= j;
				q++;
			}
			if (b != 1) {
				q = 0, b = B;
				continue;
			}
			y = j;
		}
		// x가 -1이면 a, 아니면 x^p

		string temp = "";
		int len = 0;

		string temp1 = to_string(A) + " ";
		len += to_string(A).size();
		
		if (x != -1) {
			string tmp = to_string(x) + " " + to_string(p) + " ^ ";
			int tmp_len = tmp.size() - 3;
			if (tmp_len < len)	temp1 = tmp, len = tmp_len;

			// x^p를 더 줄일 수 있는지?
			vector<int> V;
			for (int j = 2; j < p; j++) {
				if (p % j == 0)	V.push_back(j);
			}

			for (int j : V) {
				// (i^j)^(g/j)
				int aa = 1;
				for (int k = 0; k < j; k++)	aa *= x;
				string temp3 = to_string(aa) + " " + to_string(p / j) + " ^ ";
				int len3 = temp3.size() - 3;
				if (len3 < len)	temp1 = temp3, len = len3;
			}
		}


		string temp4 = to_string(B) + " ";
		int len4 = to_string(B).size();
		if (y != -1) {
			string tmp = to_string(y) + " " + to_string(q) + " ^ ";
			int tmp_len = tmp.size() - 3;
			if (tmp_len < len4)	temp4 = tmp, len4 = tmp_len;

			vector<int> V;
			for (int j = 2; j < q; j++) {
				if (q % j == 0)	V.push_back(j);
			}

			for (int j : V) {
				// (i^j)^(g/j)
				int aa = 1;
				for (int k = 0; k < j; k++)	aa *= y;
				string temp3 = to_string(aa) + " " + to_string(q / j) + " ^ ";
				int len3 = temp3.size() - 3;
				if (len3 < len4)	temp4 = temp3, len4 = len3;
			}
		}
		temp = temp1 + temp4 + "*";
		len += len4 + 1;
		if (len < len1)	ans1 = temp, len1 = len;
	}

	cout << ans1;


}