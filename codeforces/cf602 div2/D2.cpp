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
#define mp make_pair
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=200050;
int n,m,pan;
int c[maxn];
struct node{
	int val,id;
}a[maxn];
struct query{
	int cnt,k,pos,res;
	bool operator<(const query t) const{
		return k<t.k;
	}
}q[maxn];
set<PII> s;
bool cmpq(query x,query y){return x.cnt<y.cnt;}
int lowbit(int x){return x&-x;}
int sum(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
void add(int x,int p)
{
	while(x<=n)
	{
		c[x]+=p;
		x+=lowbit(x);
	}
}
bool calc(int mid)
{
	if(sum(mid)>=pan) return true;
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		read(a[i].val),a[i].id=i;
		s.insert(mp(-a[i].val,i));
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		read(q[i].k);read(q[i].pos);
		q[i].cnt=i;
	}
	sort(q+1,q+m+1);
	int p=0;
	for(int i=1;i<=m;i++)
	{
		while(q[i].k>p)
		{
			p++;
			PII tt=*s.begin();
			add(tt.second,1);
			s.erase(tt);
		}
		int l=1,r=n;
		pan=q[i].pos;
		while(l<r)
		{
			int mid=l+r>>1;
			if(calc(mid)) r=mid;
			else l=mid+1;
		}
		q[i].res=a[l].val;
	}
	sort(q+1,q+m+1,cmpq);
	for(int i=1;i<=m;i++) cout<<q[i].res<<endl;
	return 0;
}

