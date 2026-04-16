#include <bits/stdc++.h>
using namespace std;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, M, K, S[100001]{};
   cin>>N>>M>>K;
   for(int i=1;i<=N;i++)   cin>>S[i], S[i] += S[i-1];
   vector<pair<int, int>> V;
   int a;
   cin>>a;
   for(int i=1;i<K;i++){
      int b;
      cin>>b;
      V.emplace_back(S[b-1] - S[a-1], -a);
      a = b;
   }
   V.emplace_back(S[N] - S[a-1], -a);

   sort(V.begin(), V.end());
   vector<int> ans;
   for(int i=K-M;i<V.size();i++)   ans.push_back(-V[i].second);
   sort(ans.begin(), ans.end());
   for(int i:ans) cout<<i<<'\n';

}