#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
   cin.tie(0)->sync_with_stdio(0);

   int N, M, T;
   cin>>N>>M>>T;
   int A[200001]{}, B[200001]{};
   ll S[200001]{};
   for(int i=1;i<=N;i++)   cin>>A[i]>>B[i];

   for(;M--;){
      int a,b;
      cin>>a>>b;
      int s1 = A[a], e1 = B[a];
      int s2 = A[b], e2 = B[b];
      vector<pair<int, int>> V;
      V.emplace_back(s1, e1);
      V.emplace_back(s2, e2);
      sort(V.begin(), V.end());
      if(V[1].first >= V[0].second) continue;
      S[V[1].first]++;
      S[min(V[1].second, V[0].second)]--;
   }

   ll s = 0;
   for(int i=0;i<T;i++){
      s += S[i];
      cout<<s<<'\n';
   }

}