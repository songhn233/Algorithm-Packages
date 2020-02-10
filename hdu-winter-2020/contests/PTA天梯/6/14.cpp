#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#define ll long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define mst(a,b) memset((a),(b),sizeof(a))
#define PII pair<int,int>
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=20050;
int n,tot;
map<string,int> mp;
map<int,string> mmp;
map<PII,int> ee;
int head[maxn],num,k,pre[maxn];
int dis[maxn],vis[maxn];
struct node{
	int v,nex,co;
}e[maxn];
void add(int u,int v,int co)
{
	e[++num].nex=head[u];
	e[num].v=v;e[num].co=co;
	head[u]=num;
}
void dij(int st,int ed)
{
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    memset(pre,0,sizeof(pre)); 
    priority_queue<PII,vector<PII>,greater<PII> > q;
    bitset<150> vv[maxn];
    dis[st]=0;
    q.push(make_pair(0,st));
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+1)
            {
                dis[v]=dis[u]+1;
                bitset<150> temp;
                temp=vv[u];
                temp.set(e[i].co);
                vv[v]=temp;
                q.push(make_pair(dis[v],v));
                pre[v]=u;
            }
            else if(dis[v]==dis[u]+1)
            {
            	bitset<150> temp;
            	temp=vv[u];
            	temp.set(e[i].co);
            	if(temp.count()<vv[v].count())
            	{
            		vv[v]=temp;
            		q.push(make_pair(dis[v],v));
            		pre[v]=u;
				}
			}
        }
    }
    if(dis[ed]==inf) puts("Sorry, no line is available.");
    else
    {
    	cout<<dis[ed]<<endl;
    	vector<int> res;res.clear();
    	for(int i=ed;i;i=pre[i]) res.push_back(i);
    	int last=-1;
    	int t=res.back();
    	for(int i=(int)res.size()-1;i>=1;i--)
    	{
    		if(last==-1) last=ee[make_pair(res[i-1],res[i])];
    		else
    		{
    			if(ee[make_pair(res[i-1],res[i])]!=last)
    			{
    				cout<<"Go by the line of company #"<<last<<" from "<<mmp[t]<<" to "<<mmp[res[i]]<<"."<<endl;
    				last=ee[make_pair(res[i-1],res[i])];
    				t=res[i];
				}
			}
		}
		cout<<"Go by the line of company #"<<last<<" from "<<mmp[t]<<" to "<<mmp[res[0]]<<"."<<endl;
	} 
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		string x,y;
		cin>>x;
		int u,v;
		if(mp[x]) u=mp[x],mmp[u]=x;
		else mp[x]=++tot,u=tot,mmp[tot]=x;
		for(int j=1;j<k;j++)
		{
			cin>>y;
			if(mp[y]) v=mp[y],mmp[v]=y;
			else mp[y]=++tot,v=tot,mmp[tot]=y;
			ee[make_pair(u,v)]=i;
			ee[make_pair(v,u)]=i;
			add(u,v,i);add(v,u,i);
			u=v;
		}
	}
	cin>>k;
	while(k--)
	{
		string s,e;
		cin>>s>>e;
		int st=mp[s],ed=mp[e];
		if((!st)||(!ed)) puts("Sorry, no line is available.");
		else
		{
			dij(st,ed);
		}
	}
	return 0;
}
