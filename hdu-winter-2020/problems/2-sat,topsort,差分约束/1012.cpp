#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
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
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
template<class T>inline void rd(T &x) {
  x=0; int ch=getchar(),f=0;
  while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
  while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
  if(f)x=-x;
}
const int inf=0x3f3f3f3f;
const int maxn=20050;
int n,m,in[maxn],num;
int fa[maxn];
int get(int x){if(x!=fa[x]) fa[x]=get(fa[x]); return fa[x];}
vector<int> e[maxn];
vector<PII> g;
queue<int> q;
void merge(int x,int y)
{
  x=get(x),y=get(y);
  if(x==y) return ;
  fa[x]=y;
}
int getnum(string s)
{
  int res=0;
  rep(i,0,(int)s.size()-1)
  {
    if(s[i]>='0'&&s[i]<='9') res=res*10+s[i]-'0';
    else continue;
  }
  return res;
}
int main()
{
  while(~scanf("%d%d",&n,&m))
  {
    num=0;g.clear();
    mst(in,0);rep(i,0,n-1) e[i].clear();
    rep(i,0,n-1) fa[i]=i;
    while(!q.empty()) q.pop();
    getchar();
    rep(i,1,m)
    {
      string opt;getline(cin,opt);
      if(opt.find('>')!=string::npos)
      {
        string t1=opt.substr(0,opt.find('>'));
        string t2=opt.substr(opt.find('>')+1);
        int u=getnum(t1),v=getnum(t2);
        g.push_back(make_pair(u,v));
      }
      else if(opt.find('<')!=string::npos)
      {
        string t1=opt.substr(0,opt.find('<'));
        string t2=opt.substr(opt.find('<')+1);
        int u=getnum(t1),v=getnum(t2);
        g.push_back(make_pair(v,u));
      }
      else
      {
        string t1=opt.substr(0,opt.find('='));
        string t2=opt.substr(opt.find('=')+1);
        int u=getnum(t1),v=getnum(t2);
        merge(u,v);
      }
    }
    rep(i,0,(int)g.size()-1)
    {
      int u=g[i].first,v=g[i].second;
      e[get(u)].push_back(get(v));in[get(v)]++;
    }
    int pan=0;
    int flag1,flag2;flag1=flag2=0;
    rep(i,0,n-1) if(!in[i]&&get(i)==i) q.push(i),pan++;
    if(pan>1) flag1=1;
    int cnt=0;
    rep(i,0,n-1) if(get(i)==i) cnt++;
    while(!q.empty())
    {
      int u=q.front();q.pop();
      cnt--;
      int tot=0;
      rep(i,0,(int)e[u].size()-1)
      {
        int v=e[u][i];in[v]--;
        if(!in[v]) q.push(v),tot++;
      }
      if(tot>1) flag1=1;
    }
    if(cnt!=0) flag2=1;
    if(flag2) puts("CONFLICT");
    else if(flag1) puts("UNCERTAIN");
    else puts("OK");
  }
  return 0;
}