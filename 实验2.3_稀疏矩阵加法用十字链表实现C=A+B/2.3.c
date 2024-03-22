#include <stdio.h>
#include <stdlib.h>

# define N 1000


typedef struct OLink
{
    int x,y;
    int data;
    struct OLink *right,*down;
}*Olink,OLink;

typedef struct
{
    Olink *rhead,*chead;
    int mu,nu,tu;
}CrossLink;

CrossLink creat(int m,int n,int t){
    CrossLink M;
    M.rhead=M.chead=NULL;
    M.mu=M.nu=M.tu=0;
    int i,j,a,b,e;
    Olink p,q;
    M.mu=m,M.nu=n,M.tu=t;
    M.rhead=(Olink*)malloc(sizeof(Olink)*(m+1));//确保足够的空间存储行头结点
    M.chead=(Olink*)malloc(sizeof(Olink)*(n+1));//确保足够的空间存储列头结点
    for(i=1;i<=m;i++)
        {M.rhead[i]=NULL;}//确保初始头节点均为空
    for(i=1;i<=n;i++)
        {M.chead[i]=NULL;}
    for(i=0;i<t;i++)
    {
        scanf("%d%d%d",&a,&b,&e);
        p=(Olink)malloc(sizeof(OLink));
        p->x=a,p->y=b,p->data=e;
        if(M.rhead[a]==NULL||M.rhead[a]->y>b)//如果头结点为空活头结点的元素的列大于要插入元素的列
        {
            p->right=M.rhead[a];
            M.rhead[a]=p;
        }
        else
        {
            for(q=M.rhead[a];(q->right)&&q->right->y<b;q=q->right);//先找到最后一个比插入元素的列的小的元素，把他插入到这个元素之后
            p->right=q->right;
            q->right=p;
        }
        if(M.chead[b]==NULL||M.chead[b]->x>a)//向下构建同理
        {
            p->down=M.chead[b];
            M.chead[b]=p;
        }
        else
        {
            for(q=M.chead[b];(q->down)&&q->down->x<a;q=q->down);
            p->down=q->down;
            q->down=p;
        }
    }
    return M;//返回构建好的十字链表
} 

 void charu(CrossLink M,Olink p)//作为add()函数的一部分，插入元素并对其进行相关的加法
{
    int x,y,c=0,d=0;//c和d是一种标识。
    x=p->x,y=p->y;
    
    //先是行节点
    if(M.rhead[x]==NULL)//如果第一个矩阵的与插入元素的行相同的头结点为空，二话不说直接插入。
    {
        M.rhead[x]=p;
        M.tu++;
    }
    else//如果不为空，只好慢慢找了。
    {
        Olink q=M.rhead[x];//先来一个q来等效头结点
        Olink s;//s一般是q的前一个节点
        s=q;
        while(q&&(q->y<p->y))//进行遍历
        {
            s=q;
            q=q->right;
        }
        if(q!=NULL&&(q->y==p->y))//遍历结束后恰好第一个矩阵的对应元素的列和插入元素相同，则进行加法运算
        {
            q->data+=p->data;
            if(q->data==0)//若计算结果为0，则要计划删除改节点
            {
                if(s==q)//若这个节点就是头结点，直接把头结点给下一个节点。
                {
                    M.rhead[x]=q->right;
                }
                else//若不是，s作为q的上一个节点进行删除运算
                {
                    s->right=q->right;
                }
                M.tu--;//减一个非零元素（好像没啥用）
                d=-1;//同时对d标识赋值，为下一步down链表的连接做简化准备

            }
            else//如果不等于0
            {
                c=-1;//经过加法运算直接存到第一个矩阵中
            }
        }
        if(c==0&&d==0)//这行矩阵中没有和p的列相同的元素即没有经过加法运算
        {
            if(s==q)//若插入的元素的列比原头结点的列大
            {
                M.rhead[x]=p;
                p->right=q;
            }
            else
            {
                s->right=p;
                p->right=q;
            }
            M.tu++;//加一个非零元素
        }
    }
    //然后是列节点
    if(M.chead[y]==NULL)//同理行
    {
        M.chead[y]=p;
    }
    else
    {
        Olink q=M.chead[y];
        Olink s;
        s=q;
        while(q&&(q->x<p->x))
        {
            s=q;
            q=q->down;
        }
        if(d==-1)//若相加后的元素为0
        {
            if(q!=NULL)
            {
                if(s==q)//如果是头结点
                {
                    M.chead[y]=q->down;
                }
                else
                {
                    s->down=q->down;
                }
            }
        }
        if(c==0)//若没有经过加法
        {
            if(s==q)
            {
                M.chead[y]=p;
                p->down=q;

            }
            else
            {
                s->down=p;
                p->down=q;
            }
        }
    }
}

void add(CrossLink A,CrossLink B)
{
    Olink p,q;
    p=(Olink)malloc(sizeof(OLink));
    int i=1;
    for(;i<=B.mu;i++)//遍历第二个矩阵中的非零元素
    {
        p=B.rhead[i];
        while(p)
        {
            q=(Olink)malloc(sizeof(OLink));

            q->down=p->down;//这里我很奇怪，直接写q=p会出错，所以就一个个写了。
            q->right=p->right;
            q->data=p->data;
            q->x=p->x;
            q->y=p->y;
            charu(A,q);
            p=p->right;
        }
    }
}


void show(CrossLink A)//输出加法后的非零元素
{
    int k,t;
    k=1;
    t=1;
    for(k=1;k<A.mu;k++)
    {
        Olink p=A.rhead[k];
        for(t=1;t<A.nu;t++)
        {
            if(p!=NULL&&p->y==t)
            {
                printf("%d %d %d\n",p->x,p->y,p->data);
                p=p->right;
            }
        }
    }
}

int main()
{
    CrossLink A,B;
    int m,n,t1,t2;
    scanf("%d%d%d%d",&m,&n,&t1,&t2);//行列非零元素
    A=creat(m,n,t1);
    B=creat(m,n,t2);
    add(A,B);
    show(A);
    return 0;
}