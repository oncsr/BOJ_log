#include <bits/stdc++.h>
using namespace std;

//	구조체를 이용한 trie
//	정수 삽입, 삭제 가능 (비트 단위로 저장)

//	BOJ 16903 AC Code

struct node {
	int cnt;	// 현재 노드의 개수
	struct node* L;
	struct node* R;
};

node* create(int val, int h) {
	node* temp = (node*)malloc(sizeof(node));
	temp->cnt = 1;
	temp->L = NULL;
	temp->R = NULL;
	return temp;
}

// 정수 x를 트라이에 삽입
void insert(node* root, int x) {
	int H = 30;
	node* temp = root;
	while (H >= 0) {
		int bit = (x & (1 << H)) ? 1 : 0;
		if (bit) {
			if (temp->R != NULL) {
				temp = temp->R;
				temp->cnt++;
			}
			else {
				temp->R = create(1, H);
				temp = temp->R;
			}
		}
		else {
			if (temp->L != NULL) {
				temp = temp->L;
				temp->cnt++;
			}
			else {
				temp->L = create(0, H);
				temp = temp->L;
			}
		}
		H--;
	}
}

void node_free(node* tar) {
	if (tar->L != NULL)	node_free(tar->L);
	if (tar->R != NULL)	node_free(tar->R);
	free(tar);
}

// 정수 x와 xor한 가장 큰 값 찾기
int find(node* root, int x) {
	int H = 30;
	int res = 0;
	node* temp = root;
	while (H >= 0) {
		int rbit = (x & (1 << H)) ? 0 : 1;
		if (rbit) {
			if (temp->R != NULL)	res += (1 << H), temp = temp->R;
			else	temp = temp->L;
		}
		else {
			if (temp->L != NULL)	res += (1 << H), temp = temp->L;
			else	temp = temp->R;
		}
		H--;
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	node* root = (node*)malloc(sizeof(node));
	root->cnt = 1;
	root->L = NULL, root->R = NULL;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		insert(root, a);
	}
	int Q;
	for (cin >> Q; Q--;) {
		int x;
		cin >> x;
		cout << (find(root, x) ^ x) << ' ';
	}
	node_free(root);

}
