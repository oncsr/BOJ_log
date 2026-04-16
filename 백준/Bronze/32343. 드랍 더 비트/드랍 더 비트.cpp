#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);

    int n, a, b;
    cin>>n>>a>>b;
    int x = max(0, a+b-n), arr[10]{}, g = 1, res = 0;

    for(int i=0;i<a-x;i++)  arr[i] = 1;
    for(int i=a-x;i<a-x+b-x;i++)    arr[i] = 1;
    for(int i=n-1;i>=0;i--) res += arr[i] * g, g <<= 1;
    cout<<res;

}