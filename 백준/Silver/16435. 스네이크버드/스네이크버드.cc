#include<iostream>
#include<algorithm>
main(){int n,a[1000],l;std::cin>>n>>l;for(int i=0;i<n;i++)std::cin>>a[i];std::sort(a,a+n);for(int i=0;i<n;i++)if(a[i]<=l)l++;std::cout<<l;}