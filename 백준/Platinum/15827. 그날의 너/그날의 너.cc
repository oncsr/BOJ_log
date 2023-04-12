#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
using ll = long long;
using pl = pair<ll, ll>;

ll gcd(ll a, ll b) {
	if (a < b)	swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int cnt = 0;
string factor_list[1000]{};
map<string, bool> visit;
map<string, pair<char, pair<string, string> > > comp_factor;
map<string, pl> factor_value;
pair<string, pl> ans[1000]{};

pl ADD(pl res1, pl res2) {
	pl res;
	pl temp = res1;
	res1.first *= res2.second;
	res1.second *= res2.second;
	res2.first *= temp.second;
	res2.second *= temp.second;
	res.first = res1.first + res2.first;
	if (res.first == 0)	res.second = 1;
	else {
		res.second = res1.second;
		ll g = gcd(abs(res.first), abs(res.second));
		res.first /= g;
		res.second /= g;
	}
	return res;
}

pl SUB(pl res1, pl res2) {
	pl res;
	pl temp = res1;
	res1.first *= res2.second;
	res1.second *= res2.second;
	res2.first *= temp.second;
	res2.second *= temp.second;
	res.first = res1.first - res2.first;
	if (res.first == 0)	res.second = 1;
	else {
		res.second = res1.second;
		ll g = gcd(abs(res.first), abs(res.second));
		res.first /= g;
		res.second /= g;
	}
	return res;
}

pl MUL(pl res1, pl res2) {
	pl res;
	res.first = res1.first * res2.first;
	res.second = res1.second * res2.second;
	if (res.first == 0)	res.second = 1;
	else {
		ll g = gcd(abs(res.first), abs(res.second));
		res.first /= g;
		res.second /= g;
	}
	return res;
}

pl DIV(pl res1, pl res2) {
	pl res;
	res.first = res1.first * res2.second;
	res.second = res1.second * res2.first;
	if (res.first == 0)	res.second = 1;
	else {
		ll g = gcd(abs(res.first), abs(res.second));
		res.first /= g;
		res.second /= g;
		if (res.second < 0) {
			res.second = abs(res.second);
			res.first *= -1;
		}
	}
	return res;
}

pl cal(string a) {
	if (factor_value[a].second)	return factor_value[a];
	string A = comp_factor[a].second.first;
	string B = comp_factor[a].second.second;
	char op = comp_factor[a].first;
	pl res1 = cal(A);
	pl res2 = cal(B);
	pl res;
	if (op == 'A')	res = ADD(res1, res2);
	if (op == 'S')	res = SUB(res1, res2);
	if (op == 'M')	res = MUL(res1, res2);
	if (op == 'D')	res = DIV(res1, res2);
	return factor_value[a] = res;
}

void solve(string a, pl val) {
	if (!comp_factor[a].first)	return;
	string A = comp_factor[a].second.first;
	string B = comp_factor[a].second.second;
	visit[A] = visit[B] = 1;
	pl Aval = factor_value[A];
	pl Bval = factor_value[B];
	char op = comp_factor[a].first;
	if (op == 'A') {
		ans[cnt++] = { A,val };
		solve(A, val);
		ans[cnt++] = { B,val };
		solve(B, val);
	}
	if (op == 'S') {
		ans[cnt++] = { A,val };
		solve(A, val);
		ans[cnt++] = { B,{-val.first,val.second} };
		solve(B, { -val.first,val.second });
	}
	if (op == 'M') {
		pl temp1 = MUL(val, Bval);
		pl temp2 = MUL(val, Aval);
		ans[cnt++] = { A,temp1 };
		solve(A, temp1);
		ans[cnt++] = { B,temp2 };
		solve(B, temp2);
	}
	if (op == 'D') {
		pl temp1 = DIV(val, Bval);
		pl temp2 = MUL(val, Aval);
		temp2 = { -temp2.first,temp2.second };
		temp2 = DIV(temp2, MUL(Bval, Bval));
		ans[cnt++] = { A,temp1 };
		solve(A, temp1);
		ans[cnt++] = { B,temp2 };
		solve(B, temp2);
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string a, c, d;
		char b;
		cin >> a >> b;
		factor_list[i] = a;
		if (b == 'E') {
			int e;
			cin >> e;
			factor_value[a] = { e,1 };
		}
		else {
			cin >> c >> d;
			comp_factor[a] = { b,{c,d} };
		}
	}
	cal("HAPPY");
	visit["HAPPY"] = 1;
	ans[cnt++] = { "HAPPY",{1,1} };
	solve("HAPPY", { 1,1 });
	
	for (int i = 0; i < N; i++) {
		if (visit[factor_list[i]])	continue;
		ans[cnt++] = { factor_list[i],{0,1} };
	}
	sort(ans, ans + N);
	for (int i = 0; i < N; i++) {
		cout << ans[i].first << ' ' << ans[i].second.first << '/' << ans[i].second.second << '\n';
	}
}