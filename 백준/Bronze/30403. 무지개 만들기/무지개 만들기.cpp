#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin>>n;
    int small[7]{}, large[7]{};
    char list1[7] = {'r', 'o', 'y', 'g', 'b', 'i', 'v'};
    char list2[7] = {'R', 'O', 'Y', 'G', 'B', 'I', 'V'};
    for(int i=0;i<n;i++){
        char a;
        cin>>a;
        for(int j=0;j<7;j++){
            if(a == list1[j])   small[j]++;
            if(a == list2[j])   large[j]++;
        }
    }
    int S = 0, L = 0;
    for(int j=0;j<7;j++){
        if(small[j])    S++;
        if(large[j])    L++;
    }
    if(S == 7 && L == 7)  cout<<"YeS";
    else if(S == 7)  cout<<"yes";
    else if(L == 7)  cout<<"YES";
    else    cout<<"NO!";
}