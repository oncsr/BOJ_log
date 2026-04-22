#include <iostream>
#include <vector>
using namespace std;

int K;
vector<int> arr(1 << 10);		// 방문 순서 저장
vector<vector<int> > Level(11);	// 각 레벨에 속한 노드들을 저장

int pos = 0;	// 몇 번째에 방문하고 있는 지

// 중위 순회 구현
// depth : 현재 노드의 깊이
void inorder(int depth) {

	// 현재 있는 노드가 왼쪽 자식을 가지고 있지 않는 경우
	if (depth == K) {
		Level[depth].push_back(arr[pos]);
		pos++;
		return;
	}

	inorder(depth + 1);

	Level[depth].push_back(arr[pos]);
	pos++;

	inorder(depth + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	for (int i = 0; i < (1 << K) - 1; i++)
		cin >> arr[i];

	inorder(1);

	for (int i = 1; i <= K; i++) {
		for (int j : Level[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}
}