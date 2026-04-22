#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	map<string, string> site;

	int N, M;
	cin >> N >> M;

	// site에 key=사이트, value=비밀번호의 쌍을 모두 넣어준다.
	for (int i = 0; i < N; i++)
	{
		string a, b;
		cin >> a >> b;
		site[a] = b;
	}

	// 입력으로 들어오는 사이트의 비밀번호를 출력해준다.
	for (int i = 0; i < M; i++)
	{
		string a;
		cin >> a;
		cout << site[a] << '\n';
	}

}