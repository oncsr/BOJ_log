#include <iostream>
main(){
    int n;
    std::cin>>n;
    for(int i=0;i<2*n-1;i++)    std::cout<<(int)(i<n);
}