#include <stdio.h>
#include <string.h>

#define N 10000;


int main()
{
    int a[100][100]; //邻接矩阵
    int w[100]; //源点到各节点的最短路径
    int s[100]; //节点是否已经判断过，1代表已经运算过
    int n; //节点数

	scanf("%d",&n);
	//输入邻接矩阵
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int j, k;
	int m;
	for(j = 1;j < n;j++) //初始化
	{
		s[j] = 0;
		w[j] = a[0][j];
	}
	w[0] = 0;
	s[0] = 1;
	//主要程序
	for(int i = 1;i < n;i++)
	{
		m = N;
		//选出权值最小的点
		for(k = 0;k < n;k++)
		{
			if(s[k] == 0) //检测k是否被处理
			{
				if(w[k] < m)
				{
					j = k;
					m = w[k];//为比较做准备
				}
			}
		}
		s[j] = 1;
		//表示已经处理过，加入集合s
		for(k = 0;k < n;k++)
		{
			if(s[k] == 0 && ((m+a[j][k] )< w[k]))
			{
				w[k] = m + a[j][k];//重新储存后，为下次循环和最后的输出做准备。

			}

		}

	}
	for(int i = 0;i < n;i++)
	{
		printf("%d\n",w[i]);
	}
	return 0;
}