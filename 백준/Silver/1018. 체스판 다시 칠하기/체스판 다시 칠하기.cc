#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string arr[51];
	string ch1[8] = { "WBWBWBWB","BWBWBWBW","WBWBWBWB","BWBWBWBW" ,"WBWBWBWB","BWBWBWBW" ,"WBWBWBWB","BWBWBWBW" };
	string ch2[8] = { "BWBWBWBW","WBWBWBWB","BWBWBWBW","WBWBWBWB", "BWBWBWBW","WBWBWBWB", "BWBWBWBW","WBWBWBWB" };

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int total = 64;
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			int cnt = 0;
			if (arr[i][j] == ch1[0][0]) {
				for(int k=0;k<8;k++)
					for (int g = 0; g < 8; g++) {
						if (ch1[k][g] != arr[i + k][j + g])
							cnt++;
					}
			}
			else {
				for (int k = 0; k < 8; k++)
					for (int g = 0; g < 8; g++)
						if (ch2[k][g] != arr[i + k][j + g])
							cnt++;
			}
			if (cnt > 32)
				cnt = 64 - cnt;
			total = min(cnt, total);
		}
	}
	cout << total << '\n';
}