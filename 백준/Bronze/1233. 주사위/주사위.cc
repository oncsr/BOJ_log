#include <iostream>
using namespace std;
int main(){
    int arr[81]{};
    int a,b,c,d=0;
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            for(int k=1;k<=c;k++){
                arr[i+j+k]++;
                if((arr[i+j+k]>arr[d])||(arr[i+j+k]==arr[d]&&i+j+k<d)) d=i+j+k;
            }
        }
    }
    cout<<d;
}