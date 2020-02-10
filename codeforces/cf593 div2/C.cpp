#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=350;
int n,a[maxn][maxn];
int main()
{
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		
		if(flag==0) 
		{
			for(int j=1;j<=n;j++) a[i][j]=j+(i-1)*n;
			flag=1;
		}
		else if(flag==1)
		{
			for(int j=1;j<=n;j++) a[i][j]=i*n-j+1;
			flag=0;
		}
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++) cout<<a[j][i]<<" ";
		puts("");
	}
	return 0;
}

