#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=150;
const int inf=0x3f3f3f3f;
int f[maxn][5],a[maxn],n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=f[0][1]=f[0][2]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;
		if(a[i]==1) f[i][2]=min(f[i-1][0],f[i-1][1]),f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;
		if(a[i]==2) f[i][1]=min(f[i-1][0],f[i-1][2]),f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;
		if(a[i]==3) f[i][1]=min(f[i-1][0],f[i-1][2]),f[i][2]=min(f[i-1][0],f[i-1][1]),f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;
	}
	cout<<min(f[n][0],min(f[n][1],f[n][2]))<<endl;
	return 0;
}
