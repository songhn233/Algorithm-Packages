#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<map>
#include<set> 
using namespace std;
const int maxn=100050;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
int n,a[maxn];
map<int,bool>vis;
set<int> t;
int cnt,ans[maxn];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
	{
		if(vis[a[i]])
		{
			puts("-1");
			return 0;
		}
		vis[a[i]]=true;
		if(a[i]<0)
		{
			if(t.find(-a[i])==t.end())
			{
				puts("-1");
				return 0;
			}
			else t.erase(-a[i]);
		}
		else t.insert(a[i]);
		
		if(t.size()==0)
		{
			ans[++cnt]=vis.size();
			vis.clear();
		}
	}
	if(t.size())
	{
		puts("-1");
		return 0;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
	puts("");
	return 0;
}
