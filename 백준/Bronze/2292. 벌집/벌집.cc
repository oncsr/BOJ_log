#include <stdio.h>

int main(void)
{
  int n; scanf("%d", &n);

  int sum = 1;
  int result = 1;
  for(int i=1;n>sum;)
    {
      sum += 6*i;
      i++;
      result = i;
    }      
  printf("%d\n", result);
  return 0;
}