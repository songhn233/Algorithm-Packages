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
int T,n,m,maxx;
int tire[maxn][30],cnt[maxn],num;
string s,temp;
char ans[maxn],t[maxn];
void insert(string s,int x)
{
	int p=0;
	for(int i=0;i<s.size();i++)
	{
		if(tire[p][s[i]-'a']) p=tire[p][s[i]-'a'];
		else
		{
			tire[p][s[i]-'a']=++num;
			p=num;
		}
		cnt[p]+=x;
	}
}
void dfs(int d,int ed,int sum,int p)
{
	if(d==ed)
	{
		if(sum>maxx)
		{
			maxx=sum;
			memset(ans,0,sizeof(ans));
			for(int i=0;i<ed;i++) ans[i]=t[i];
		}
		return ;
	}
	int tt=temp[d]-'0'-1,q;
	if(tt==6) tt=(tt-1)*3,q=4;
	else if(tt==7) tt=19,q=3;
	else if(tt==8) tt=22,q=4;
	else tt=(tt-1)*3,q=3;
	for(int i=tt;i<tt+q;i++)
	{
		if(tire[p][i])
		{
			t[d]='a'+i;
			dfs(d+1,ed,cnt[tire[p][i]],tire[p][i]);
			t[d]=0;
		}
		else continue;
	}
	return ;
}
int main()
{
	cin>>T;
	for(int tim=1;tim<=T;tim++)
	{
		cout<<"Scenario #"<<tim<<":"<<endl;
		memset(tire,0,sizeof(tire));
		memset(cnt,0,sizeof(cnt));num=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>s>>x;
			insert(s,x);
		}
		cin>>m;
		while(m--)
		{
			cin>>s;
			for(int i=0;s[i]!='1';i++)
			{
				memset(t,0,sizeof(t));maxx=0;
				memset(ans,0,sizeof(ans));
				temp=s.substr(0,i+1);
				dfs(0,i+1,0,0);
				if(!maxx) cout<<"MANUALLY"<<endl;
				else
				{
					for(int j=0;j<i+1;j++) cout<<ans[j];
					cout<<endl;
				}
			}
			if(m!=0) cout<<endl;
		}
		cout<<endl<<endl;
	}
	return 0;
}

