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
const int maxn=500050;
int n,fa[maxn];
struct node{
	int l,r,id;
	bool operator<(const node&t) const{
		return l<t.l;
	}
}a[maxn];
int get(int x){if(x!=fa[x]) return fa[x]=get(fa[x]); return fa[x];}
void merge(int x,int y)
{
	x=get(x),y=get(y);
	fa[x]=y;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		read(a[i].l),read(a[i].r);
		a[i].id=i;
	}
	sort(a+1,a+n+1);
	set<PII> s;
	int flag=1,pan=0;
	for(int i=1;i<=n;i++)
	{
		PII t;
		t.first=a[i].l,t.second=a[i].id;
		auto it=s.lower_bound(t);
		while(it!=s.end())
		{
			if((*it).first>a[i].r) break;
			if(get((*it).second)==get(a[i].id))
			{
				flag=0;
				break;
			}
			else merge((*it).second,a[i].id),pan++;
			it++;
		}
		PII temp;
		temp.first=a[i].r,temp.second=a[i].id;
		s.insert(temp);
	}
	if(pan!=n-1) flag=0;
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}

