#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, s=1;
    cin>>n;
    for(long long f=n;f>n-5;f--)
        s*=f;
    for(long long f=2;f<=5;f++)
        s/=f;
    cout<<s;
}