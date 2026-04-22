#include <iostream>
using namespace std;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, a[1000001]{};
	cin>>n;
	for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        a[i]=c=='S';
        a[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++){
        int id=0, s=0;
        while(id<n&&i-a[id]>0&&n-id+a[id]>=i){
            id+=i-a[id];
            s++;
        }
        cout<<s<<' ';
    }
}