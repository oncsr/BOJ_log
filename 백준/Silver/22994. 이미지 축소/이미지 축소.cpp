#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(a<b)swap(a,b);
    return a%b?gcd(b, a%b):b;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    char arr[1000][1000]{};
    for(int i=0;i<n;i++)    for(int j=0;j<m;j++)    cin>>arr[i][j];

    int garo = 1, sero = 1;
    int cont = 1;
    for(int j=1;j<m;j++){
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(arr[i][j] == arr[i][j-1])    cnt++;
        }
        if(cnt == n)    cont++;
        else{
            if(garo == 1)garo = cont;
            else if(garo != cont)   garo = gcd(garo, cont);
            cont = 1;
        }
    }
    if(cont != garo)    garo = gcd(garo, cont);
    if(cont == m)   garo = m;

    cont = 1;
    for(int i=1;i<n;i++){
        int cnt = 0;
        for(int j=0;j<m;j++){
            if(arr[i][j] == arr[i-1][j])    cnt++;
        }
        if(cnt == m)    cont++;
        else{
            if(sero == 1)   sero = cont;
            else if(sero != cont)   sero = gcd(sero, cont);
            cont = 1;
        }
    }
    if(cont != sero)    sero = gcd(sero, cont);
    if(cont == n)   sero = n;

    cout<<n/sero<<' '<<m/garo<<'\n';
    for(int i=0;i<n;i+=sero){
        for(int j=0;j<m;j+=garo)    cout<<arr[i][j];
        cout<<'\n';
    }

}