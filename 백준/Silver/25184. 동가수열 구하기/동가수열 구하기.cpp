#include <bits/stdc++.h>
using namespace std;

int N;

int main(){
	cin.tie(0)->sync_with_stdio(0);

    cin>>N;
    int i = (N+1)/2, j = N, c = 0;
    while(c++ < N) {
        if(c&1) cout<<i--<<' ';
        else cout<<j--<<' ';
    }

}