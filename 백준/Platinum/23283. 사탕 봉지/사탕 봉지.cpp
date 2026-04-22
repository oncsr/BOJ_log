#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using pl = pair<pair<ll, ll>, int>;

/*
* 민식이가 처음에 모든 사탕 봉지를 가진 채로 시작하고,
* 영식이에게 K개의 사탕 봉지를 주는 것으로 치환할 수 있다.
* 
* 사탕 봉지를 주는 기준으로 쉽게 생각할 수 있는 것이
* 1. 사과맛 사탕이 적은 순
* 2. 포도맛 사탕이 적은 순
* 이지만, 이렇게 하면 반례가 생길 수 있다.
* 
* 정렬 기준
* => 각각의 총 사탕 개수 중 사과맛 사탕의 비율, 포도맛 사탕의 비율의 최댓값이
* 가장 작은 순으로 주면 된다.
* 
* 증명?
* 
* 솔직히 모르겠다.
* 
*/

ll ta, tb;

bool cmp(pl a, pl b) {
	double paf = a.first.first * 100. / ta;
	double pas = a.first.second * 100. / tb;
	double pbf = b.first.first * 100. / ta;
	double pbs = b.first.second * 100. / tb;
	if (max(paf, pas) == max(pbf, pbs)) {
		return paf + pas < pbf + pbs;
	}
	return max(paf, pas) < max(pbf, pbs);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T = 2;
	while (T--) {
		int N;
		cin >> N;
		ll suma = 0, sumb = 0;
		pl arr[500000]{};
		for (int i = 0; i < N; i++) {
			ll a, b;
			cin >> a >> b;
			suma += a, sumb += b;
			arr[i] = { {a,b},i + 1 };
		}
		ta = suma, tb = sumb;
		sort(arr, arr + N, cmp);
		int ans[500000]{};
		for (int i = 0; i < N / 2; i++) {
			suma -= arr[i].first.first;
			sumb -= arr[i].first.second;
			ans[arr[i].second]++;
		}
		if (suma <= ta / 2 || sumb <= tb / 2) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= N; i++) {
			if (!ans[i])	cout << i << ' ';
		}
		cout << '\n';
		
	}

}