#include <stdio.h>

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);
	int arr1[100][100];
	int arr2[100][100];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d", &arr1[i][j]);
	for(int k=0;k<n;k++)
		for(int l=0;l<m;l++)
			scanf("%d", &arr2[k][l]);
	for(int a=0;a<n;a++)
	{
		for(int b=0;b<m;b++)
			printf("%d ", arr1[a][b]+arr2[a][b]);
		printf("\n");
	}
	return 0;
}