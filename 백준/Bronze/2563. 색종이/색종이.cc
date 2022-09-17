#include <stdio.h>

int main(void)
{
	int board[100][100] = {0};
	int arr[100][3];
	int n, S = 0;
	scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	for(int j=0;j<n;j++)
		for(int k=arr[j][0]-1;k<arr[j][0]+9;k++)
			for(int l=arr[j][1]-1;l<arr[j][1]+9;l++)
			{
				if(board[k][l] == 0)
				{
					S += 1;
					board[k][l] = 1;
				}
				else
					continue;
			}
	printf("%d\n", S);
	return 0;
}