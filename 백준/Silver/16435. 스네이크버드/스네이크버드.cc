#include<iostream>
#include<algorithm>
main(){int n,a[1000],i,l;std::cin>>n>>l;for(i=n;i--;)std::cin>>a[i];std::sort(a,a+n);for(i=0;i<n;i++)if(a[i]<=l)l++;std::cout<<l;}