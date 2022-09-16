#include <stdio.h>
int main()
{
  int a,b,c; scanf("%d%d%d",&a,&b,&c);
  (c-b)>0 ? printf("%d\n", a/(c-b)+1) : printf("-1\n");
}