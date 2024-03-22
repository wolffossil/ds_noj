#include <stdio.h>
#include <stdlib.h>
# define N 1000
typedef struct
{
    int a;
    int b;
    int data;
}Ju;

int main()
{
    int m,n,i,j,c,a,b,data;
    Ju A[N],t;
    scanf("%d%d",&m,&n);
    i=0;

    while(1)//创造三元组表
    {
        scanf("%d%d%d",&a,&b,&data);
        if(a==0&&b==0&&data==0) break;
        A[i].a=a,A[i].b=b;A[i].data=data;
        i++;
    }
    c=i;
    for(j=0;j<c-1;j++)//冒泡排序
    {
        for(i=0;i<c-1-j;i++)
        {
            if(A[i].b>A[i+1].b)
            {
                A[i]=t;A[i]=A[i+1],A[i+1]=t;
            }
        }
    }
    for(i=0;i<c;i++)//输出
    {
        printf("%d %d %d\n",A[i].b,A[i].a,A[i].data);
    }
    return 0;
}

/*
4 4
1 1 1
2 1 2
3 2 3
0 0 0
*/