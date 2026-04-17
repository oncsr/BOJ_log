#include <bits/stdc++.h>
using namespace std;

int main(){
    long long s;
    cin>>s;
    long long g = sqrt(2*s);
    cout<<(g*g+g <= 2*s ? g:g-1);
}