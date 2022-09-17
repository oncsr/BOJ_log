#include <stdio.h>
int gcd(int a,int b){
	if(a%b==0)
		return b;
	else
		return gcd(b, a % b);
}
int lcm(int a,int b){
	return a*b/gcd(a,b);
}
int main(){
	int m,n;
	scanf("%d%d",&m,&n);
	printf("%d\n%d",gcd(m,n),lcm(m,n));
	return 0;
}