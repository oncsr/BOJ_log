#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

struct group {
	// no : 그룹 번호, sum : 그룹의 크기 합, att : 그룹의 전투력
	ll sum, att;
};

int root[200001]{};
group arr[200001]{};

pair<int, group> find(int x) {
	if (root[x] == x)	return { x, {arr[x].sum, arr[x].att} };
	pair<int, group> p = find(root[x]);
	root[x] = p.first, arr[x].sum = p.second.sum, arr[x].att = p.second.att;
	return p;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q;
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		arr[i].sum = a;
		root[i] = i;
	}

	for (; Q--;) {
		int a, b;
		cin >> a >> b;
		pair<int, group> fir = find(a), sec = find(b);
		a = fir.first, b = sec.first;
		/*
		cout << "Group number : " << a << ',' << b << '\n';
		cout << "Group sum : " << arr[a].sum << ',' << arr[b].sum << '\n';
		cout << "Group att : " << arr[a].att << ',' << arr[b].att << '\n';
		*/
		if (a == b) {
			cout << arr[a].att << '\n';
		}
		else {
			ll s = fir.second.sum + sec.second.sum;
			ll t = fir.second.att + sec.second.att + fir.second.sum * sec.second.sum;
			arr[a].sum = arr[b].sum = s;
			arr[a].att = arr[b].att = t;
			root[a] = b;
			cout << arr[a].att << '\n';
		}
	}
}