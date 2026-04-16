#include <bits/stdc++.h>
using namespace std;

string mx, mn;
int N, p = -1, q = 100001;
bitset<100001> e;
int cnt[100001]{};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    for(int i=2;i*i<=100000;i++) if(!e[i]) for(int j=i*i;j<=100000;j+=i) e[j] = 1;
    for(int i=2;i<=100000;i++) cnt[i] = cnt[i-1] + (e[i] ? 0 : 1);
    for(cin>>N;N--;) {
        string name, num;
        cin>>name>>num;
        int X = stoi(num.substr(0,5));
        int Y = stoi(num.substr(5,5));
        int score = cnt[max(X,Y)] - cnt[min(X,Y)-1];
        if(score > p || (score == p && name < mx)) mx = name, p = score;
        if(score < q || (score == q && name < mn)) mn = name, q = score;
    }
    cout<<mx<<'\n'<<mn;

}