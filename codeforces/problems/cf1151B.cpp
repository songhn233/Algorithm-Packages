#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=550;
int n,m;
int a[maxn][maxn];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	int temp=0;
	for(int i=1;i<=n;i++) temp^=a[i][1];
	if(temp) 
	{
		puts("TAK");
		for(int i=1;i<=n;i++) cout<<1<<" ";
		puts("");
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				if(a[i][j]!=a[i][1])
				{
					puts("TAK");
					for(int k=1;k<=n;k++)
					{
						if(k==i) cout<<j<<" ";
						else cout<<1<<" ";
					}
					puts("");
					return 0;
				}
			}
		}
	}
	puts("NIE");
	return 0;
}
