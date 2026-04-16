#include <bits/stdc++.h>
using namespace std;

int main(){
  cin.tie(0)->sync_with_stdio(0);
  int TC;
  for(cin>>TC;TC--;){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int &i:a)cin>>i;
    for(int &i:b)cin>>i;
    int poss=1;
    for(int i=0;i<n-3;i++)if(!(poss=a[i]==b[i]))break;
    if(!poss){cout<<"NO\n";continue;}
    bitset<1000> D;
    D[a[n-3]*100+a[n-2]*10+a[n-1]]=1;
    for(int i=n-3;i<m-3;i++){
      bitset<1000> ND;
      for(int j=111;j<1000;j++)if(D[j])for(int k=1;k<10;k++){
      	int A=j/100,B=(j/10)%10,C=j%10;
      	if(k&1){
      	  if(A==b[i])ND[B*100+C*10+k]=1;
      	}
      	else{
      	  int tm[3]={A,B,C};
      	  sort(tm,tm+3);
      	  if(tm[0]==b[i])ND[tm[1]*100+tm[2]*10+k]=1;
      	}
      }
      D=ND;
    }
    cout<<(D[b[m-3]*100+b[m-2]*10+b[m-1]]?"YES\n":"NO\n");
  }
}