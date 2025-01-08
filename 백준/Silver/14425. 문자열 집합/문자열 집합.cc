#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<string> S;

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		S.insert(a);
	}
	
	int answer = 0;
	for (int i = 0; i < M; i++)
	{
		string a;
		cin >> a;
		if (S.count(a) == 1)
		{
			answer++;
		}
	}

	cout << answer;
}