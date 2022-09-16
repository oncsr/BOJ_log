#include <stdio.h>
#include <string.h>

int main(void)
{
    int i = 0, j = 0, k = 0;
    int N, len;
    char w[100][100];
    int num;

    scanf("%d", &N);
    num = N;

    for (i = 0; i < N; i++)
    {
        scanf("%s", w[i]);
        len = strlen(w[i]);

        for (j = 0; j < len - 1; j++)
        {
            for (k = 0; k < len - 2; k++)
            {
                if (w[i][j] != w[i][j + 1] && w[i][j] == w[i][j + 2 + k])
                {
                    num -= 1;
                    j = len;
                    break;
                }
            }
        }
    }
    printf("%d", num);
    return 0;
}