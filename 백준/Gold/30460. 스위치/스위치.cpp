#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int n;
	cin>>n;
	ll dp[200001][4]{}, arr[200001]{};
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	dp[1][3]=arr[1]*2, dp[1][0]=arr[1];
	dp[2][3]=dp[1][0]+2*arr[2];
	dp[2][2]=dp[1][3]+2*arr[2];
	dp[2][0]=dp[1][0]+arr[2];
	dp[3][3]=dp[2][0]+2*arr[3];
	dp[3][2]=dp[2][3]+2*arr[3];
	dp[3][1]=dp[1][3]+2*arr[2]+2*arr[3];
	dp[3][0]=dp[2][0]+arr[3];
	for(int i=4;i<=n;i++){
		
		dp[i][3]=max(dp[i-1][0], dp[i-1][1])+2*arr[i];
		dp[i][2]=dp[i-1][3]+2*arr[i];
		dp[i][1]=dp[i-1][2]+2*arr[i];
		dp[i][0]=max(dp[i-1][0],dp[i-1][1])+arr[i];
		
	}
	cout<<max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
}