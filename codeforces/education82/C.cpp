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
int T,flag;
string s;
map<int,int> mp[30];
int vis[30];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<=26;i++) mp[i].clear();
		vis[s[0]-'a']=1;
		int flag=0;
		if(s.size()==1)
		{
			puts("YES");
			cout<<s[0];
			for(int i=0;i<26;i++)
			{
				if(i!=s[0]-'a') cout<<char('a'+i);
			}
			cout<<endl;
			continue;
		} 
		for(int i=1;i<s.size();i++)
		{
			if(s[i]==s[i-1])
			{
				flag=1;
				break;
			}
			mp[s[i-1]-'a'][s[i]-'a']=1;
			mp[s[i]-'a'][s[i-1]-'a']=1;
			vis[s[i]-'a']=1;
		}
		int t1,t2;t1=t2=-1; 
		for(int i=0;i<26;i++)
		{
			if(mp[i].size()==0) continue;
			if(mp[i].size()>2)
			{
				flag=1;
				break;
			}
			else if(mp[i].size()==2) continue;
			else if(mp[i].size()==1)
			{
				if(t1!=-1&&t2!=-1)
				{
					flag=1;
					break;
				}
				else if(t1!=-1) 
				{
					t2=i;
				}
				else t1=i;
			}
		}
		if(flag) puts("NO");
		else if(t1==-1||t2==-1) puts("NO");
		else
		{
			puts("YES");
			int x=t1,last;
			cout<<char('a'+x);
			int pp;
			for(auto y:mp[x])
			{
				pp=y.first;
			}
			cout<<char('a'+pp);
			last=t1;
			if(pp!=t2)
			{
				while(pp!=t2)
				{
					int p1,p2;
					p1=p2=-1;
					for(auto y:mp[pp])
					{
						if(p1!=-1&&p2!=-1) break;
						if(p1==-1) p1=y.first;
						else p2=y.first;
					}
					int temp=p1^p2^last;
					cout<<char('a'+temp);
					last=pp;
					pp=temp;
				}
			}
			for(int i=0;i<26;i++)
			{
				if(!vis[i]) cout<<char('a'+i);
			}
			cout<<endl;
		}
	}
	return 0;
}

