#include <iostream>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int arr[11]{};
	for (int i = 0; i < 2047; i++)
		for (int j = 0; j < 11; j++){
            int a;
            cin>>a;
            arr[j] ^= a;
        }
    for(int i=0;i<11;i++)    cout<<arr[i]<<' ';
}