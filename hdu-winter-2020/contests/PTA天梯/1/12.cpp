#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
int T,n,m;
vector<int> a[55];
set<int> p[55];
int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;cin>>x;
			a[t].push_back(x);
			p[t].insert(x);
		}
	}
	cin>>m;
	while(m--)
	{
		int x,y;
		read(x),read(y);
		int t2=0;
		map<int,int> vis;
		vis.clear();
		for(int i=0;i<a[y].size();i++)
		{
			if(p[x].find(a[y][i])!=p[x].end()&&vis[a[y][i]]==0) 
			{
				t2++;
				vis[a[y][i]]=1;
			}
		}
		int t1=p[x].size()+p[y].size()-t2;
		double res=(double)t2/(double)t1;
		res*=100;
		printf("%.2lf%\n",res);
	}
	return 0;
}

