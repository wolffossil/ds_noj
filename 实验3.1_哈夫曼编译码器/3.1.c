#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 1000
typedef struct HtNode
{
    int weight;
    int parent,lchild,rchild;
}HtNode;

typedef struct HtTree
{
    struct HtNode ht[N];
    int root;
    char HC[N][N];
}HtTree,*PHtTree;

PHtTree TraverseHuffman(PHtTree T,int n)//译码过程
{
    static int codeLen=0;
    static char cd[N];

    if(T->ht[n].rchild==0)
    {
        cd[codeLen]='\0';
        strcpy(T->HC[n],cd);
    }
    else
    {
        cd[codeLen++]='0';
        TraverseHuffman(T,T->ht[n].lchild);
        codeLen--;
        cd[codeLen++]='1';
        TraverseHuffman(T,T->ht[n].rchild);
        codeLen--;
    }
    return T;
}

int main()
{
    PHtTree pht;//初始参数
    int i,j,n,m,w[N];
    char data[N];
    int A[N];
    char string[100];
    scanf("%d",&n);//输入相关的数据
    for(i=1;i<=n;i++)
    {
    scanf("%s",&data[i]);
    A[data[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
    }
    scanf("%s",string);
    m=strlen(string);
    int m1,m2;
    pht=(PHtTree)malloc(sizeof( HtTree));//开始构建哈夫曼树
    for(i=1;i<=2*n-1;i++)
    {
        pht->ht[i].lchild=0;
        pht->ht[i].rchild=0;
        pht->ht[i].parent=0;
        if(i<=n)
        {
            pht->ht[i].weight=w[i];
        }
        else
        {
            pht->ht[i].weight=0;
        }
    }
    for(i=1;i<n;i++)
    {
         int a[2];//从中挑选权值相加最小的两个前置数。
         int j,m1=N,m2=N;
         for(j=1;j<n+i;j++)
    {
      if(pht->ht[j].weight<m1&&pht->ht[j].parent==0)
      {
          m2=m1;
          a[1]=a[0];
          m1=pht->ht[j].weight;
          a[0]=j;
      }
      else if(pht->ht[j].weight<m2&&pht->ht[j].parent==0)
      {
          m2=pht->ht[j].weight;
          a[1]=j;
      }
   }
        pht->ht[a[0]].parent=n+i;
        pht->ht[a[1]].parent=n+i;
        pht->ht[n+i].weight=pht->ht[a[0]].weight+pht->ht[a[1]].weight;
        //printf("%d+%d=%d\n",pht->ht[a[0]].weight,pht->ht[a[1]].weight,pht->ht[n+i].weight);
        pht->ht[n+i].lchild=a[0];
        pht->ht[n+i].rchild=a[1];
        pht->root=n+i;
    }
    pht=TraverseHuffman(pht,pht->root);//引用函数
    for(i=0;i<m;i++)
    {
        printf(pht->HC[A[string[i]]]);
    }
    printf("\n");
    printf("%s",string);
    printf("\n");
    return 0;
}