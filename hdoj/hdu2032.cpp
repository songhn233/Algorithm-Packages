#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int f[50][50];
int main()
{
	f[1][1]=1;
	for(int i=2;i<=30;i++)
	{
		for(int j=1;j<=i;j++) f[i][j]=f[i-1][j-1]+f[i-1][j];
	}
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(j!=i) cout<<f[i][j]<<" ";
				else cout<<f[i][j];
			}
			puts("");
		}
		cout<<endl;
	}
	return 0;
}
