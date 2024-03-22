#include <stdio.h>
#include <string.h>

#define N 1000

int main()
{
    int A[100][100];
    int n,m,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);

        }
    }
    
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
               
                if(A[i][j]>(A[i][k]+A[k][j]))
                {
                        A[i][j]=A[i][k]+A[k][j];
                }
            }
        }
    }//弗洛伊德主体
    int b[100][100];
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&b[i][0],&b[i][1]);
    }
    for(i=0;i<m;i++)
    {
        printf("%d\n",A[b[i][0]][b[i][1]]);
    }
    return 0;
}
