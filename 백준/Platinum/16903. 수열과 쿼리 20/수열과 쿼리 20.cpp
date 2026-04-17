#include <bits/stdc++.h>
using namespace std;

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

// 정수 x를 트라이에서 삭제
void remove(node* root, int x) {
	int H = 30;
	node* temp = root;
	while (H >= 0) {
		int bit = (x & (1 << H)) ? 1 : 0;
		if (bit) {
			temp->R->cnt--;
			if (temp->R->cnt == 0) {
				node_free(temp->R);
				temp->R = NULL;
				break;
			}
			temp = temp->R;
		}
		else {
			temp->L->cnt--;
			if (temp->L->cnt == 0) {
				node_free(temp->L);
				temp->L = NULL;
				break;
			}
			temp = temp->L;
		}
		H--;
	}
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
	insert(root, 0);
	int Q;
	for (cin >> Q; Q--;) {
		int o, x;
		cin >> o >> x;
		if (o == 1)	insert(root, x);
		else if (o == 2)	remove(root, x);
		else	cout << find(root, x) << '\n';
	}
	node_free(root);

}
