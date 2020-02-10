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
const int maxn=30;
string s;
int a[maxn];
int fa[maxn];
int get(int x){if(fa[x]!=x) return get(fa[x]); else return fa[x];}
void merge(int a,int b)
{
	a=get(a),b=get(b);
	if(a==b) return ;
	fa[a]=b;
}
bool find(int a)
{
	int t=a;
	while(fa[t]!=t)
	{
		t=fa[t];
	}
	if(t==12) return true;
	return false;
}
int main()
{
	while(cin>>s)
	{
		if(s=="0") break;
		for(int i=1;i<=26;i++) fa[i]=i;
		merge(s[0]-'a',s[(int)s.size()-1]-'a');
		while(cin>>s)
		{
			if(s=="0") break;
			merge(s[0]-'a',s[s.size()-1]-'a');
		}
		if(find(1)) puts("Yes.");
		else puts("No.");
	}
	return 0;
}

