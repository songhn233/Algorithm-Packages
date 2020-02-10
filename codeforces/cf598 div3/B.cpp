#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=150;
int T,n,a[maxn],vis[maxn],pos[maxn];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			pos[a[i]]=i;
		}
		vis[0]=1;
		for(int i=1;i<=n;i++)
		{
			if(!vis[pos[i]])
			{
				int temp=pos[i];
				while(temp-1&&(!vis[temp-1])&&a[temp-1]>a[temp])
				{
					swap(pos[a[temp]],pos[a[temp-1]]);
					swap(a[temp],a[temp-1]);
					vis[temp-1]=1;
					temp--;
				}
				vis[temp]=1;
			}
		}
		for(int i=1;i<=n;i++) cout<<a[i]<<" ";
		puts("");
	}
	return 0;
}

