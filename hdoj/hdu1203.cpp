#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10050;
double f[maxn],w[maxn];
int v[maxn],n,m;
int main()
{
	while(cin>>m>>n)
	{
		if(m==0&&n==0) break;
		for(int i=1;i<=n;i++) cin>>v[i]>>w[i],w[i]=1.0-w[i];
		for(int i=0;i<=m;i++) f[i]=1.0;
		for(int i=1;i<=n;i++)
		{
			for(int j=m;j>=v[i];j--)
				f[j]=min(f[j],f[j-v[i]]*w[i]);
		}
		printf("%.1lf%%\n",(1.0-f[m])*100);
	}
	return 0;
}
