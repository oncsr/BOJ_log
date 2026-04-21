#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int e[1000001]{};
vector<ll> sosu;

vector<string> dib(ll n) {
	if (n == 1)	return { "1" };
	vector<string> prm;
	for (ll i : sosu) {
		if (i * i > n)	break;
		while (n % i == 0) {
			n /= i;
			prm.push_back(to_string(i));
		}
	}
	if (n > 1)	prm.push_back(to_string(n));
	return prm;
}

bool cmp(string a, string b) { return a + b > b + a; }

int main() {

	for (int i = 2; i * i <= 1000000; i++)
		if (!e[i])
			for (int j = i * i; j <= 1000000; j += i)
				e[j] = 1;

	for (int i = 2; i <= 1000000; i++)
		if (!e[i])
			sosu.push_back(i);


	ll N;
	cin >> N;
	bitset<70> S = N - 1;
	int last = 0;
	for (int i = 0; i < 70; i++) {
		if (S[i] == 1)	last = i;
	}
	ll M;
	if (last == 0)	M = 1;
	else {
		if (S[last - 1] == 1)	for (int i = last - 2; i >= 0; i--)	S[i] = 0;
		else	for (int i = last - 1; i >= 0; i--)	S[i] = 0;
		M = S.to_ullong();
	}

	vector<string> d1 = dib(N), d2 = dib(M);

	sort(d1.begin(), d1.end(), cmp);
	sort(d2.begin(), d2.end(), cmp);

	string A = "", B = "";
	for (auto i : d1)	A += i;
	for (auto i : d2)	B += i;
	
	string C = "";
	int p1 = A.size() - 1, p2 = B.size() - 1;
	int add = 0;
	while (p1 >= 0 && p2 >= 0) {
		int a = A[p1] - '0', b = B[p2] - '0';
		int g = a + b + add;
		if (g > 9)	add = 1;
		else	add = 0;
		g %= 10;
		C += (g + '0');
		p1--, p2--;
	}
	while (p1 >= 0) {
		int a = A[p1] - '0', g = a + add;
		if (g > 9)	add = 1;
		else	add = 0;
		g %= 10;
		C += (g + '0');
		p1--;
	}
	while (p2 >= 0) {
		int b = B[p2] - '0', g = b + add;
		if (g > 9)	add = 1;
		else	add = 0;
		g %= 10;
		C += (g + '0');
		p2--;
	}
	reverse(C.begin(), C.end());
	cout << C;
	
}