#include <stdio.h>
#include <string.h>

#define N 1000

int path[N];

void Search(int vs,int v0)
{
    if(path[vs]==-1)
    {
        return ;
    }
    else
    {
        Search(path[vs],v0);
        printf("%d\n",path[vs]);
    }
}
int main()
{
    int a[100][100]; //邻接矩阵
    int w[100]; //源点到各节点的最短路径
    int s[100]; //节点是否已经判断过，1代表已经运算过
    int n; //节点数
    int v0,vs;
    //int path[100];

	scanf("%d",&n);
	//输入邻接矩阵
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d%d",&v0,&vs);
	int i,j,k;
	int m;
	for(i=0;i<n;i++)
    {
        w[i]=a[v0][i];
        s[i]=0;
        if(i!=v0&&w[i]<N)
            {path[i]=v0;}
            else {path[i]=-1;}
    }
	
	w[0] = 0;
	s[0] = 1;
	path[v0]=-1;
	//主循环
	for(int i = 1;i < n;i++)
	{
		m = N;
		//选出权值最小的点
		for(k = 0;k < n;k++)
		{
			if(s[k] == 0&&w[k]!=0) //k尚未进行处理
			{
				if(w[k] < m)
				{
					j = k;
					m = w[k];
				}
			}
		}
		s[j] = 1;
		//表示已经处理过，加入集合s
		for(k = 0;k < n;k++)
		{
			if(s[k] == 0 && (m+a[j][k] )< w[k]&&w[k]!=0)
			{
				w[k] = m + a[j][k];
				path[k]=j;
			}
		}
	}//迪杰斯特拉算法主体
	Search(vs,v0);;
	printf("%d\n",vs);
	//printf("%d",path[v0]);

}