#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
bool compare(const pair<int, int> a, const pair<int, int> b) { return a.second < b.second; }

int main() {
	int n;	cin >> n;
	ii arr[200001]{};
	for (int i = 0; i < n; i++)	cin >> arr[i].first;
	for (int i = 0; i < n; i++)	cin >> arr[i].second;
	sort(arr, arr + n, compare);
	ll s = arr[0].first;
	priority_queue<int, vector<int>, less<> > Q;
	int i = 1;
	while (i < n - 2) {
		Q.push(arr[i++].first);
		Q.push(arr[i++].first);
		s += Q.top();
		Q.pop();
	}
	cout << s;
}