#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, M;
   cin>>N>>M;
   int a;
   string b;
   vector<pair<int, string>> odd, even;
   int cnt[11]{};
   for(cin>>a>>b;a;cin>>a>>b){
      if(++cnt[a] > M) continue;
      if(a&1)  odd.emplace_back(a,b);
      else  even.emplace_back(a,b);
   }
   
   auto cmp = [&](pair<int, string> a, pair<int, string> b) -> bool {
      if(a.first != b.first)  return a.first < b.first;
      string p = a.second, q = b.second;
      if(p.size() != q.size())   return p.size() < q.size();
      return p<q;
   };

   sort(odd.begin(), odd.end(), cmp);
   sort(even.begin(), even.end(), cmp);

   for(auto [a,b]:odd)  cout<<a<<' '<<b<<'\n';
   for(auto [a,b]:even)  cout<<a<<' '<<b<<'\n';

}