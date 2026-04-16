#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N, T;
	cin >> N >> T;
	int arr[1001][1001]{}, ans = 0;
	for (int i = 1; i <= N; i++) {
		int t;
		cin >> t;
		int temp = t;
		int cnt = 0, cnt2 = 1000000;
		while (T % temp)	temp--, cnt++;
		temp = t;
        if(temp <= T){
            cnt2 = 0;
            while (T % temp)	temp++, cnt2++;
        }
	    ans += min(cnt, cnt2);
	}
	cout << ans;
}