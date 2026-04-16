#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    
    int h, a[1025]{}, s = 0;
    cin>>h;
    for(int i=1;i<(1<<h);i++)   cin>>a[i];
    for(int x=(1<<(h-1));x<(1<<h);x++)for(int y=x+1;y<(1<<h);y++){
        vector<int> L, R;
        int p = x, q = y, ss = 0;
        while(p != q){
            if(p>q){
                L.push_back(a[p]);
                ss += a[p];
                p>>=1;
            }
            else{
                R.push_back(a[q]);
                ss += a[q];
                q>>=1;
            }
        }
        L.push_back(a[p]);
        for(int i=R.size()-1;i>=0;i--)  L.push_back(R[i]);
        ss += a[p];
        int sss = 0, g = 0;
        for(int i=0;i<L.size();i++){
            sss += L[i];
            if(i != L.size() - 1){
                if(sss * 2 == ss){g=1;break;}
                int ssss = 0;
                for(int j=i;j>0;j--){
                    ssss += L[j];
                    if(sss - ssss == ss - sss){g=1;break;}
                }
            }
            if(g)   break;
        }
        s+=g;
    }
    cout<<s;

}