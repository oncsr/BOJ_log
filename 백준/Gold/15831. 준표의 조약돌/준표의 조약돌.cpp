#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N, B, W;
    cin>>N>>B>>W;
    int arr1[300001]{}, arr2[300001]{};
    int idx1[300001]{}, idx2[300001]{};
    int ans = 0, b = 0, w = 0;
    for(int i=1;i<=N;i++){
        char a;
        cin>>a;
        arr1[i] += arr1[i-1];
        arr2[i] += arr2[i-1];
        if(a == 'B'){
            arr1[i]++;
            idx1[++b] = i;
        }
        else{
            arr2[i]++;
            idx2[++w] = i;
        }
    }

    for(int i=1;i<=N;i++){
        int pos;
        if(arr1[i-1] + B + 1 > b)   pos = N;
        else    pos = idx1[arr1[i-1] + B + 1] - 1;
        if(arr2[pos] - arr2[i-1] < W)   continue;
        ans = max(ans, pos - i + 1);
    }
    cout<<ans;

}