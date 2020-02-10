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
int T,n;
string s;
map<PII,int> mp;
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		cin>>s;
		mp.clear();
		mp[make_pair(0,0)]=0;
		int x=0,y=0;
		int ans=inf,al,ar;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='L') x--;
			if(s[i]=='R') x++;
			if(s[i]=='U') y++;
			if(s[i]=='D') y--;
			if(mp.count(make_pair(x,y)))
			{
				if(ans>i-mp[make_pair(x,y)])
				{
					ans=i-mp[make_pair(x,y)];
					al=mp[make_pair(x,y)];
					ar=i;
				}
				mp[make_pair(x,y)]=i+1;
			}
			else mp[make_pair(x,y)]=i+1;
		}
		if(ans==inf) puts("-1");
		else cout<<al+1<<" "<<ar+1<<endl;
	}
	return 0;
}
