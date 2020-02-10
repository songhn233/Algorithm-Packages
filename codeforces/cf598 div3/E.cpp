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
const int maxn=200050;
ll n,pre[maxn],f[maxn];
struct node{
	int val,id,cnt;
	bool operator<(const node&t) const{
		return val<t.val;
	}
}a[maxn];
bool cmp(node t1,node t2){return t1.id<t2.id;}
int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i].val),a[i].id=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) f[i]=inf;
	f[0]=0;
	for(int i=3;i<=n;i++)
	{
		if(i>=3) 
		{
			if(f[i-3]+a[i].val-a[i-2].val<f[i])
			{
				f[i]=f[i-3]+a[i].val-a[i-2].val;
				pre[i]=i-2;
			}
		}
		if(i>=4) 
		{
			if(f[i-4]+a[i].val-a[i-3].val<f[i])
			{
				f[i]=f[i-4]+a[i].val-a[i-3].val;
				pre[i]=i-3;
			}
		}
		if(i>=5) 
		{
			if(f[i-5]+a[i].val-a[i-4].val<f[i])
			{
				f[i]=f[i-5]+a[i].val-a[i-4].val;
				pre[i]=i-4;
			}
		}
	}
	int pos=n,tot=0;
	while(pos>1)
	{
		int temp=pre[pos];
		//cout<<temp<<"---"<<endl;
		tot++;
		for(int i=temp;i<=pos;i++) a[i].cnt=tot;
		pos=temp-1;
	}
	sort(a+1,a+n+1,cmp);
	cout<<f[n]<<" "<<tot<<endl;
	for(int i=1;i<=n;i++) cout<<a[i].cnt<<" ";
	puts("");
	return 0;
}

