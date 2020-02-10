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
const int maxn=100050;
int nex[maxn],pre[maxn],n,num=0;
struct node{
	int id,val;
}t[maxn];
node head;
node ans[maxn];
int main()
{
	cin>>head.id>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		t[a]={a,b};
		nex[a]=c;
	}
	for(int i=head.id;i!=-1;i=nex[i])
	{
		ans[++num]={t[i].id,t[i].val};
	}
	for(int i=1;i<=num;i++)
	{
		if(i%2==1)
		{
			if(i==num) printf("%05d %d -1\n",ans[num-(i/2)].id,ans[num-(i/2)].val);
			else printf("%05d %d %05d\n",ans[num-(i/2)].id,ans[num-(i/2)].val,ans[1+(i/2)].id);
		}
		else
		{
			if(i==num) printf("%05d %d -1\n",ans[i/2].id,ans[i/2].val);
			else printf("%05d %d %05d\n",ans[i/2].id,ans[i/2].val,ans[num-(i/2)].id);
		}
	}
	return 0;
}

