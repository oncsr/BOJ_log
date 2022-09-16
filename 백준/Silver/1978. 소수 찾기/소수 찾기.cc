#include <stdio.h>
#include <stdbool.h>

bool sosu(int x)
{
  int y=2, z=0;
  if(x==1)
    return false;
  while(y<x)
    {
      if(x%y==0)
        z++;
      y++;
    }
  if(z==0)
    return true;
  else
    return false;
}

int main(void)
{
  int n; scanf("%d", &n);
  int arr[n];
  int num=0;
  for(int i=0;i<n;i++)
    {
      scanf("%d", &arr[i]);
      if(sosu(arr[i]))
        num++;
    }
  printf("%d\n", num);
}