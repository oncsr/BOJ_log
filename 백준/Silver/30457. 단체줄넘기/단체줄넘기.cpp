#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	int ans=0;
	int arr[1000]{};
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr, arr+n);
	int t=0;
	int vis[1000]{};
	for(int i=0;i<n;i++){
		if(arr[i]>t) ans++, vis[i]++;
		t=arr[i];
	}
	t=0;
	for(int i=0;i<n;i++){
		if(vis[i]) continue;
		if(arr[i]>t) ans++, vis[i]++;
		t=arr[i];
	}
	cout<<ans;
}