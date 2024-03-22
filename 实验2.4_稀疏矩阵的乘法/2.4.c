#include <stdio.h>
#include <stdlib.h>

# define N 1000

typedef struct

{
    int row;
    int col;
    int number;
}data;

typedef struct
{

    data T[N];
    int t;
    int m,n;
}juzhen;


void Multiply(juzhen A,juzhen B)
{
    int s[N];//设置一个数组去储存稀疏矩阵中一行的元素
    int i=0,j=0,a,b,c,d,e;
    juzhen C,D;
    e=0;
    for(a=1;a<=A.n;a++)
    {
        for(i=1;i<=N;i++)//每次循环前清空为0，为下次存储做准备
    {
        s[i]=0;
    }
        j=0;i=0;
       for(i=0;i<A.t;i++)
        {
        if(A.T[i].row==a)
        {
            C.T[j]=A.T[i];
            j++;
        }
        }
        for(b=0;b<j;b++)
        {
            for(c=0;c<B.t;c++)
            {
                if(C.T[b].col==B.T[c].row)
                {
                    s[B.T[c].col]+=C.T[b].number*B.T[c].number;//运算结果存储
                }
            }
        }
        for(d=1;d<=B.n;d++)//以计算完成的第一行相关元素的三元组存储
        {
            if(s[d]!=0)
            {
                D.T[e].row=a,D.T[e].col=d,D.T[e].number=s[d];
                e++;
            }
        }
    }
    for(i=0;i<e;i++)//输出
    {
        printf("%d %d %d\n",D.T[i].row,D.T[i].col,D.T[i].number);
    }
}
//寻找合适的算法去计算相关的稀疏矩阵元素并存储同时输出


int main()
{
    int i;
    juzhen A,B;
    printf("输入第一组矩阵的行列数:\n");
    scanf("%d%d",&A.m,&A.n);
    i=0;
    int a,b,c;
    printf("输入第一组稀疏矩阵的相关数据:\n");
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==0&&b==0&&c==0)
        {
            break;
        }
        A.T[i].row=a,A.T[i].col=b,A.T[i].number=c;
        i++;
    }
    A.t=i;
    i=0;
    printf("输入第二组矩阵的行列数:\n");
    scanf("%d%d",&B.m,&B.n);
    printf("输入第二组稀疏矩阵的相关数据:\n");
    while(1)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(a==0&&b==0&&c==0)
        {
            break;
        }
        B.T[i].row=a,B.T[i].col=b,B.T[i].number=c;
        i++;
    }
    B.t=i;
    Multiply(A,B);
    return 0;
}//通过main函数来玩出输入步骤并引用Multiply来完成题目要求