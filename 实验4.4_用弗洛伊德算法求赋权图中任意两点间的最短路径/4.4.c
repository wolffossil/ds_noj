#include <stdio.h>
#include <string.h>

#define MAX 10000

typedef struct{
    int a[100][100];
    int nextvex[100][100];
}ShortPath;



void Search(int x,int y,ShortPath ppath)
{
    int a,b;
    if(ppath.nextvex[x][y]!=y)
    {
       a=ppath.nextvex[x][y];
       printf("%d\n",a);
       Search(a,y,ppath);

    }
    else
    {
        return ;
    }
}

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
    ShortPath ppath;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(A[i][j]!=MAX&&A[i][j]!=0)
        {
            ppath.nextvex[i][j]=j;
        }
        else
        {
            ppath.nextvex[i][j]=-1;
        }
        ppath.a[i][j]=A[i][j];
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
                        ppath.nextvex[i][j]=ppath.nextvex[i][k];
                }
            }
        }
    }//弗洛伊德算法主体
    int b[100][100];
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&b[i][0],&b[i][1]);
    }
    for(i=0;i<m;i++)
    {
        printf("%d\n",b[i][0]);
        Search(b[i][0],b[i][1],ppath);
        printf("%d\n",b[i][1]);
    }
    return 0;
}  