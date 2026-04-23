#include <iostream>
#include <vector>
using namespace std;

/*
* 2022.11.13
* [used algorithm]
* =>
* [point]
* =>
*/
vector<int> order(1000001);

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, a, par = 0, ans[1000001]{};
	cin >> N;
	bool suc = true;
	for (int i = 0; i < N; i++) {
		cin >> a;
		if (!i) {
			if (a != 1) {
				suc = false;
				break;
			}
			else {
				par = 1;
				order[a] = i;
			}
			continue;
		}
		if (a > par + 1) {
			suc = false;
			break;
		}
		else if (a == par + 1) {
			order[a] = i;
			ans[order[a - 1]]++;
			par = a;
		}
		else if (a == 1) {
			order = vector<int>(1000001);
			par = 1;
			order[a] = i;
		}
		else {
			ans[order[a - 1]]++;
			order[a] = i;
		}
		par = a;
	}
	if (!suc)	cout << -1;
	else {
		for (int i = 0; i < N; i++)	cout << ans[i] << '\n';
	}
}