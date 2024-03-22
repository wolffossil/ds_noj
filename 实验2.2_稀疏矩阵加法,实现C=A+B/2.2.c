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
    data T1[N];
    data T2[N];
    int t1,t2;
}juzhen;



void Add(juzhen A)
{
    int i,j,k=0;
    juzhen B,C;
    data t;
    B.t1=0;
    for(i=0;i<A.t1;i++)//对相关元素相加
    {
        for(j=0;j<A.t2;j++)
        {
            if(A.T2[j].col!=-1)
            {

            if(A.T1[i].col==A.T2[j].col&&A.T1[i].row==A.T2[j].row)
            {
                if(A.T1[i].number+A.T2[j].number!=0)
                {
                B.T1[k].col=A.T1[i].col;
                B.T1[k].row=A.T1[i].row;
                B.T1[k].number=A.T1[i].number+A.T2[j].number;
                A.T1[i].col=A.T1[i].row=-1;
                A.T2[j].col=A.T2[j].row=-1;
                B.t1++;
                k++;}
                if(A.T1[i].number+A.T2[j].number==0)
                {
                    A.T1[i].col=A.T1[i].row=-1;
                A.T2[j].col=A.T2[j].row=-1;
                }
            }
            }

        }
    }
    k=0;
    for(i=0;i<A.t1;i++)//填充为完整矩阵三元组表
    {
       if(A.T1[i].col!=-1)
       {
           C.T1[k]=A.T1[i];
           k++;
       }
    }
    for(i=0;i<A.t2;i++)
    {
        if(A.T2[i].col!=-1)
        {
            C.T1[k]=A.T2[i];
            k++;
        }
    }
    for(i=0;i<B.t1;i++)
    {
        C.T1[i+k]=B.T1[i];
    }
    for(i=0;i<k+B.t1-1;i++)//冒泡排序
    {
        for(j=0;j<k+B.t1-1-i;j++)
        {
            if(C.T1[j].col>C.T1[j+1].col)
            {
                    t=C.T1[j],C.T1[j]=C.T1[j+1],C.T1[j+1]=t;
                }
            else if(C.T1[j].col==C.T1[j+1].col)
            {if(C.T1[j].row>C.T1[j+1].row)
                {t=C.T1[j],C.T1[j]=C.T1[j+1],C.T1[j+1]=t;}
            }
            }
        }
    for(i=0;i<k+B.t1;i++)//输出
    {
        printf("%d %d %d\n",C.T1[i].col,C.T1[i].row,C.T1[i].number);
    }
    return ;

}

int main()//程序主要框架
{
    int i,m,n;
    juzhen A;
    scanf("%d%d%d%d",&m,&n,&A.t1,&A.t2);
    for(i=0;i<A.t1;i++)
    {
        scanf("%d%d%d",&A.T1[i].col,&A.T1[i].row,&A.T1[i].number);
    }
    for(i=0;i<A.t2;i++)
    {
        scanf("%d%d%d",&A.T2[i].col,&A.T2[i].row,&A.T2[i].number);
    }

    Add(A);
    return 0;
}