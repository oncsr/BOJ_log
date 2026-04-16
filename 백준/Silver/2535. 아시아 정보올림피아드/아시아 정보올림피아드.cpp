#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, cnt[101]{};
   cin>>N;
   vector<tuple<int, int, int>> arr(N);
   for(auto &[c,a,b]:arr)  cin>>a>>b>>c;
   sort(arr.begin(), arr.end(), greater<>());

   int s = 0;
   for(auto &[c,a,b]:arr){
      if(cnt[a] > 1) continue;
      cout<<a<<' '<<b<<'\n';
      cnt[a]++;
      if(++s == 3)   return 0;
   }

}