#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    int scores[100]{};
    for(int i=0;i<N;i++)    cin>>scores[i];
    vector<pair<int,int>> tester(M);
    for(auto &[a,b]:tester){
        cin>>b;
        for(int i=0;i<N;i++){
            char res;
            cin>>res;
            if(res == 'O')  a += scores[i];
        }
    }
    sort(tester.begin(), tester.end(), [](auto a, auto b) -> bool {
       if(a.first == b.first)   return a.second < b.second;
       return a.first > b.first;
    });
    cout<<tester[0].second<< ' '<<tester[0].first;
}