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
int T;
string s,t;
map<char,bool> mp;
vector<int>p[30];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		mp.clear();
		for(int i=0;i<s.size();i++) mp[s[i]]=true;
		int flag=1;
		for(int i=0;i<t.size();i++)
		{
			if(mp[t[i]]==0) flag=0;
		}
		if(!flag) puts("-1");
		else
		{
			for(int i=0;i<30;i++) p[i].clear();
			for(int i=0;i<s.size();i++) p[s[i]-'a'].push_back(i);
			int pre=-1,ans=1;
			for(int i=0;i<t.size();i++)
			{
				if(upper_bound(p[t[i]-'a'].begin(),p[t[i]-'a'].end(),pre)!=p[t[i]-'a'].end())
				{
					pre=p[t[i]-'a'][upper_bound(p[t[i]-'a'].begin(),p[t[i]-'a'].end(),pre)-p[t[i]-'a'].begin()];
				}
				else
				{
					ans++;
					pre=p[t[i]-'a'][upper_bound(p[t[i]-'a'].begin(),p[t[i]-'a'].end(),-1)-p[t[i]-'a'].begin()];
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

