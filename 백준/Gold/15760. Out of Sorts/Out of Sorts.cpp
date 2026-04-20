#include <iostream>
#include <algorithm>
using namespace std;
using ii=pair<int,int>;

int seg[262145]{};
ii arr[100001]{};

int find(int s, int e, int l, int r, int n){
	if(l>r||l>e||r<s) return 0;
	if(l<=s&&e<=r) return seg[n];
	int m=(s+e)>>1;
	return find(s,m,l,r,n*2)+find(m+1,e,l,r,n*2+1);
}

void upt(int s, int e, int i, int n){
	if(s==e){
		seg[n]=1;
		return;
	}
	int m=(s+e)>>1;
	if(i<=m) upt(s,m,i,n*2);
	else upt(m+1,e,i,n*2+1);
	seg[n]=seg[n*2]+seg[n*2+1];
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i].first, arr[i].second=i;
	
	sort(arr+1, arr+n+1, greater<>());
	
	int mx=0;
	for(int i=1;i<=n;i++){
		mx = max(mx, find(1,n,1,arr[i].second-1,1));
		upt(1,n,arr[i].second,1);
	}
	cout<<mx+1;
}