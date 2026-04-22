#include <stdio.h>
#include <math.h>
main(){int N,i=0,j;scanf("%d",&N);double a[N],b[N],s=0;for(;i<N;i++){scanf("%lf%lf",a+i,b+i);for(j=0;j<i;j++){s+=sqrt((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));}}printf("%.9f",2./N*s);}