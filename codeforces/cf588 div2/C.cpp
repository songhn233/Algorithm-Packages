#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=20;
int n,m,a[maxn][maxn];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		a[x][y]=a[y][x]=1;
	}
	if(n<=6) cout<<m<<endl;
	else 
	{
		int res=n;
		for(int i=1;i<=7;i++)
		{
			for(int j=i+1;j<=7;j++)
			{
				int cnt=0;
				for(int k=1;k<=7;k++)
				{
					if(a[i][k]&&a[j][k]) cnt++;
				}
				res=min(res,cnt);
			}
		}
		cout<<m-res<<endl;
	}
	
	return 0;
}
