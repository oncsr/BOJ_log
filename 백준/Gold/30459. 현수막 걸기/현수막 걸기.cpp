#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	
	int n, m, r;
	cin>>n>>m>>r;
	
	vector<int> v;
	int a[2000]{};
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<i;j++) v.emplace_back(abs(a[i]-a[j]));
	}
	sort(v.begin(), v.end());
	int x=0;
	for(int i=0;i<m;i++){
		int g; cin>>g;
		int s=0, e=v.size()-1, k=(s+1+e)>>1;
		while(s<e){
			if(v[k]*g<=2*r) s=k;
			else e=k-1;
			k=(s+1+e)>>1;
		}
			
		if(k==0 && v[k]*g>2*r)continue;
		if(v[k]*g>2*r) k--;
		x=max(x, v[k]*g);
	}
	
	if(x==0) cout<<-1;
	else{
		cout<<x/2<<'.';
		cout<<((x&1)?5:0);
	}
}