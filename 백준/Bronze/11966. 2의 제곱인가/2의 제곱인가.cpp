#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    cout<<(__builtin_popcount(n)-1 ? 0 : 1);

}