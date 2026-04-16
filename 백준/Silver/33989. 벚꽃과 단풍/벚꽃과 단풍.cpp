#include <bits/stdc++.h>
using namespace std;

int N;
char arr[111111]{};
int l[111111]{}, r[111111]{};

int main(){
	cin.tie(0)->sync_with_stdio(0);

	cin>>N;
    for(int i=1;i<=N;i++) cin>>arr[i];

    for(int i=1;i<=N;i++) l[i] = l[i-1] + (arr[i] == 'D');
    for(int i=N;i>=1;i--) r[i] = r[i+1] + (arr[i] == 'B');
    int ans = 111111;
    for(int i=0;i<=N;i++) ans = min(ans, l[i] + r[i+1]);
    cout<<ans;

}