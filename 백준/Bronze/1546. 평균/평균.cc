#include <stdio.h>

int main()
{
	int n;	scanf("%d", &n);
	
	int arr[n], max = 0;
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		if(arr[i]>max)	max = arr[i];
	}
	
	double arr2[n], sum = 0.0;
	for(int j=0;j<n;j++){
		arr2[j] = (double)arr[j] / (double)max * 100.0;
		sum += arr2[j];
	}
	printf("%f\n", sum/(double)n);
}