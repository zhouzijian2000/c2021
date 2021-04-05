//此程序的地图是用深度优先搜素算法（dfs）随机生成的！
#include<bits/stdc++.h>
#include <conio.h>
using namespace std;
int xx[]={1,-1,0,0},yy[]={0,0,1,-1},v[44][44],mp[44][44];
struct Node
{
	int nx,ny;
}nod;
void dfs(int x,int y)
{
	mp[x][y]=1;
	if(x==1 && y==1) return;
	int s=rand()%4;
	for(int i=s;i<s+4;i++)
	{
		int dx=x+xx[i%4];
		int dy=y+yy[i%4];
		if(mp[dx][dy]==0 && dx>0 && dy>0 && dx<43 && dy<43 && v[dx][dy]==0)
		{
			int flag=0;
			for(int k=0;k<4;k++)
			{
				int ddx=dx+xx[k];
				int ddy=dy+yy[k];
				if(mp[ddx][ddy]==1) flag++;
			}
			if(flag==1)//保证不和别的路挖穿，增加迷宫难度； 
			{
				v[dx][dy]=1;
				dfs(dx,dy);
			}
		}
		else v[dx][dy]=1;
	}
}
int main()
{
	for(int i=0;i<44;i++)
	{
		for(int j=0;j<44;j++) mp[i][j]=0;
	}
	dfs(42,42);
	mp[1][0]=2;
	mp[42][43]=1; 
	for(int i=0;i<44;i++)
	{
		for(int j=0;j<44;j++) 
		{
			if(mp[i][j]==1) cout<<"  ";
			else if(mp[i][j]==0) cout<<"口";
			else if(mp[i][j]==2) cout<<"人"; 
		}
		cout<<endl; 
	}
	nod.nx=1;
	nod.ny=0;
	while(1)
	{
		int x0=nod.nx;
		int y0=nod.ny;
		if(x0==42 && y0==43)
		{
			cout<<"恭喜你，通关了！"<<endl;
			system("pause"); 
			break;
		}
		int x1,y1;
		char t=_getch();
		if(t=='w')
		{
			x1=x0-1;
			y1=y0;
		}
		else if(t=='s')
		{
			x1=x0+1;
			y1=y0;
		}
		else if(t=='a')
		{
			x1=x0;
			y1=y0-1;
		}
		else if(t=='d')
		{
			x1=x0;
			y1=y0+1;
		}
		if(mp[x1][y1]==1)
		{
			nod.nx=x1;
			nod.ny=y1;
			mp[x0][y0]=1;
			mp[x1][y1]=2;
			system("cls");
			for(int i=0;i<44;i++)
			{
				for(int j=0;j<44;j++) 
				{
					if(mp[i][j]==1) cout<<"  ";
					else if(mp[i][j]==0) cout<<"口";
					else if(mp[i][j]==2) cout<<"人"; 
				}
				cout<<endl; 
			}
		}
	}
	return 0;
} 
