#include <bits/stdc++.h>
using namespace std;

int seg[524289]{}, arr[200000]{};

void init(int s, int e, int n){
   if(s==e){
      seg[n] = 1;
      return;
   }
   int m=(s+e)>>1;
   init(s,m,n*2);   init(m+1,e,n*2+1);
   seg[n] = seg[n*2] + seg[n*2+1];
}

int find(int s, int e, int l, int r, int n){
   if(l>r || l>e || r<s)   return 0;
   if(l <= s && e <= r)   return seg[n];
   int m=(s+e)>>1;
   return find(s,m,l,r,n*2)+find(m+1,e,l,r,n*2+1);
}

void upt(int s, int e, int i, int n){
   if(s==e){
      seg[n] = 0;
      return;
   }
   int m=(s+e)>>1;
   if(i <= m)   upt(s,m,i,n*2);
   else    upt(m+1,e,i,n*2+1);
   seg[n] = seg[n*2] + seg[n*2+1];
}

int main() {
   cin.tie(0)->sync_with_stdio(0);

   int n;
   cin>>n;
   for(int i=0;i<n;i++)   cin>>arr[i];
   int g = arr[n-1] % (n-1);
   swap(arr[0], arr[g]);

   init(0,n-1,1);
   int id = 0, ans[200000]{};
   for(int i=0;i<n;i++){
      upt(0,n-1,id,1);
      ans[id] = arr[i];
      if(i == n-1)   break;
      int k = arr[i] % (n-i-1);
      int F = find(0,n-1,id+1,n-1,1), s, e;
      if(k == 0)   k = n-i-1;
      if(k > F){
         k -= F;
         s = 0, e = id-1;
      }
      else    s = id+1, e = n-1;
      int m=(s+e)>>1;
      while(s<e){
         F = find(0,n-1,s,m,1);
         if(k > F){
            k -= F;
            s = m+1;
         }
         else    e = m;
         m = (s+e)>>1;
      }
      id = m;
   }
   for(int i=0;i<n;i++)   cout<<ans[i]<<' ';

}