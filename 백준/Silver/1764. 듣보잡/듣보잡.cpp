#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	set<string> A;
	set<string> B;
	
	int N, M;
	cin >> N >> M;

	// 듣도 못한 사람들을 모두 A에 넣어준다.
	for (int i = 0; i < N; i++)
	{
		string a;
		cin >> a;
		A.insert(a);
	}

	// 보도 못한 사람 중 듣도 못한 사람이 있다면 B에 넣어준다.
	// => B에는 듣도 보도 못한 사람만 들어가게 된다.
	for (int i = 0; i < M; i++)
	{
		string a;
		cin >> a;
		if (A.count(a) == 1)
		{
			B.insert(a);
		}
	}

	cout << B.size() << '\n';
	for (auto it = B.begin(); it != B.end(); it++)
	{
		cout << *it << '\n';
	}
}