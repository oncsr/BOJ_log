#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> res;

ll gcd(ll a, ll b) {
	if (!a)  return b;
	if (!b)  return a;
	if (a < b)   swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

ll power(ll n, ll p, ll m) {
	if (p == 0)  return 1;
	if (p == 1)  return n;
	__int128 r = power(n, p >> 1, m);
	return (p & 1) ? r * r % m * n % m : r * r % m;
}

bool miller_rabin(ll n) {
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (!(n & 1))  return false;

	for (auto& a : { 2,3,5,7,11,13,17,19,23,29,31,37 }) {
		if (n == a)    return true;
		if (a >= n - 1)  return true;
		ll T = (n - 1) >> 1;

		bool may_prime = 0;
		while (!(T & 1)) {
			if (power(a, T, n) == n - 1) { may_prime = 1; break; }
			T >>= 1;
		}
		ll v = power(a, T, n);
		if (v == n - 1 || v == 1)  may_prime = 1;

		if (!may_prime)  return false;
	}
	return true;

}

void rho(ll n) {
	if (n == 1)  return;
	if (!(n & 1)) { res.push_back(2); rho(n >> 1); return; }

	if (miller_rabin(n)) { res.push_back(n); return; }

	ll c, x, y, v;
	c = rand() % 20 + 1;
	x = y = rand() % (n - 2) + 2;

	auto f = [&](ll g) {return ((__int128)g * g + c) % n; };
	do x = f(x), y = f(f(y)), v = gcd(abs(y - x), n);
	while (v == 1);

	rho(v);

	rho(n / v);

}

vector<pair<ll, int>> V;
bool ans = 0;

int cnt[10]{};
ll N;

bool chk_len(ll D) {
	if (to_string(D).size() * 2 != to_string(N).size())	return false;
	if (to_string(N / D).size() * 2 != to_string(N).size())	return false;
	return true;
}

bool chk_num(ll D) {
	int temp_cnt[10]{};
	for (char i : to_string(D))	temp_cnt[i - '0']++;
	for (char i : to_string(N / D))	temp_cnt[i - '0']++;
	for (int i = 0; i < 10; i++)	if (temp_cnt[i] != cnt[i])	return false;
	return true;
}

bool chk_zero(ll D) {
	string a = to_string(D), b = to_string(N / D);
	char prev = ' ';
	for (char i : a) {
		if (prev == '0' && i == '0')	return false;
		prev = i;
	}
	prev = ' ';
	for (char i : b) {
		if (prev == '0' && i == '0')	return false;
		prev = i;
	}
	return true;
}

void chk(int pos, ll D) {
	if (pos == V.size()) {
		if (!chk_len(D))	return;
		if (!chk_num(D))	return;
		if (!chk_zero(D))	return;
		ans = 1;
		return;
	}
	for (int i = 0; i <= V[pos].second; i++) {
		chk(pos + 1, D);
		if (D * D > N / (V[pos].first * V[pos].first))	return;
		D *= V[pos].first;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	for (cin >> N; N; cin >> N) {
		string s = to_string(N);
		if (s.size() % 2) {
			cout << N << ": no\n";
			continue;
		}

		for (int i = 0; i < 10; i++)	cnt[i] = 0;
		for (char i : s)   cnt[i - '0']++;
		res = vector<ll>();
		rho(N);

		sort(res.begin(), res.end());

		V = vector<pair<ll, int>>();
		for (int i = 0; i < res.size(); i++) {
			int j = i;
			for (; j < res.size() && res[i] == res[j]; j++);
			V.emplace_back(res[i], j - i);
			i = j - 1;
		}

		ans = 0;
		chk(0, 1);

		cout << N << ": " << (ans ? "yes\n" : "no\n");

	}

}