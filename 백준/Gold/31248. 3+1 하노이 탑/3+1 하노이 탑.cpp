#include <bits/stdc++.h>
using namespace std;

char M[5] = {' ','A','B','C','D'};
vector<pair<char, char>> res;
void print(int s, int e){
    res.emplace_back(M[s], M[e]);
}

void H1(int n, int s, int e, int o){
    if(n == 1) {print(s,e);return;}
    H1(n-1,s,o,e);
    print(s,e);
    H1(n-1,o,e,s);
}

void H2(int n, int s, int e, int o1, int o2){
    if(n == 1)  {print(s,e);return;}
    if(n == 2)  {print(s,o1);print(s,e);print(o1,e);return;}
    H1(n-2,s,o1,o2);
    print(s,o2);
    print(s,4);
    print(o2,4);
    H2(n-2,o1,e,s,o2);
}

int main(){
    int N;
    cin>>N;
    if(N == 1){cout<<"1\nA D";return 0;}
    if(N == 2){cout<<"3\nA B\nA D\nB D";return 0;}
    H1(N-2,1,2,3);
    print(1,3);
    print(1,4);
    print(3,4);
    H2(N-2,2,4,1,3);

    cout<<res.size()<<'\n';
    for(auto [a,b]:res) cout<<a<<' '<<b<<'\n';

}