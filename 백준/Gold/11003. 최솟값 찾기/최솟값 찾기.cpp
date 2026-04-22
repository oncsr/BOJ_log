#include <iostream>
#include <queue>
using namespace std;

// 이제 pair<int, int> 는 ii와 같다.
using ii = pair<int, int>;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, L;
	cin >> N >> L;

	priority_queue<ii, vector<ii>, greater<ii>> Q;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		Q.push({ a,i });

		int id = Q.top().second;

		while (i - id >= L)
		{
			Q.pop();
			id = Q.top().second;
		}

		cout << Q.top().first << ' ';
	}

}