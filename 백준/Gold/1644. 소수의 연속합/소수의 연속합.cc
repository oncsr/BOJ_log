#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	int e[4000001]{};
	vector<int> V;
	cin >> N;
	for (int i = 2; i * i <= N; i++) {
		if (!e[i]) {
			for (int j = i * 2; j <= N; j += i)
				e[j] = 1;
		}
	}
	for (int i = 2; i <= N; i++)
		if (!e[i])
			V.push_back(i);
	int st = 0, ed = 0, sum = 0, cnt = 0;
	while (st <= ed) {
		if (sum == N) {
			cnt++;
			if (st == ed)	break;
			else {
				sum -= V[st++];
				if (ed == V.size())	break;
				sum += V[ed++];
			}
		}
		else if (sum < N) {
			if (ed == V.size())	break;
			sum += V[ed++];
		}
		else {
			if (st == ed)	break;
			sum -= V[st++];
		}
	}
	cout << cnt;
}