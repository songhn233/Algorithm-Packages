#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=150;
inline int read()
{
	int x=0,t=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')t=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*t;
}
char c[maxn];
int f[maxn][maxn],n;
int main()
{
	while(~scanf("%s",c+1))
	{
		if(c[1]=='e'&&c[2]=='n'&&c[3]=='d') break;
		memset(f,0,sizeof(f));
		n=strlen(c+1);
		for(int len=2;len<=n;len++)
		{
			for(int l=1;l<=n-len+1;l++)
			{
				int r=l+len-1;
				if((c[l]=='('&&c[r]==')')||(c[l]=='['&&c[r]==']')) f[l][r]=2+f[l+1][r-1];
				else f[l][r]=f[l+1][r-1];
				for(int k=l;k<r;k++)
				{
					f[l][r]=max(f[l][r],f[l][k]+f[k+1][r]);
				}
			}
		}
		cout<<f[1][n]<<endl;
	}
	return 0;
}

