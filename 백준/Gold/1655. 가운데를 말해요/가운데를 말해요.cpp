#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> upper;
	priority_queue<int, vector<int>, less<int>> lower;

	// 수들의 중앙값이 항상 lower의 top이 되도록 한다.
	// =>
	// lower에 들어있는 수의 개수는 upper에 들어있는 수의 개수보다 1 크거나 같아야 한다.


	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		// 두 원소의 개수가 같을 때
		// lower의 개수를 하나 늘려야 한다.
		if (lower.size() == upper.size())
		{
			if (!upper.empty() && x >= upper.top())
			{
				lower.push(upper.top());
				upper.pop();
				upper.push(x);
			}
			else
			{
				lower.push(x);
			}
		}
		else
		{
			if (!lower.empty() && x <= lower.top())
			{
				upper.push(lower.top());
				lower.pop();
				lower.push(x);
			}
			else
			{
				upper.push(x);
			}
		}

		cout << lower.top() << '\n';

	}
}