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
int n,a,b,t[55];
string ma[55],mb[55],p[55];
map<string,int> vis;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;string s;
		cin>>x>>s;
		if(x==0) mb[++b]=s;
		else ma[++a]=s;
		p[i]=s;
		t[i]=x;
	}
	int t1=a,t2=b;
	for(int i=1;i<=n;i++)
	{
		string s=p[i];
		if(vis[s]) continue;
		if(t[i]==0)
		{
			cout<<p[i]<<" "<<ma[t1]<<endl;
			vis[p[i]]=1;
			vis[ma[t1]]=1;
			t1--;
		}
		else
		{
			cout<<p[i]<<" "<<mb[t2]<<endl;
			vis[p[i]]=1;
			vis[mb[t2]]=1;
			t2--;
		}
	}
	return 0;
}

