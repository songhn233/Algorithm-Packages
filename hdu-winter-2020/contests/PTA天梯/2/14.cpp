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
const int maxn=10050;
int n,k,num,en[maxn];
int pre[maxn],vis[maxn],dis[maxn],cnt[maxn],tot[maxn];
int lu[maxn],lutot[maxn];
int head[maxn],Num;
map<string,int> mp;
map<int,string> mmp;
string st,ed;
struct node{
    int v,w,nex;
}e[maxn];
vector<int> ans;
void add(int u,int v,int w){
    e[++Num].nex=head[u];
    e[Num].w=w;e[Num].v=v;
    head[u]=Num;
}
void dij(int s)
{
    memset(dis,0x3f,sizeof(dis));
    priority_queue<PII,vector<PII>,greater<PII> > q;
    q.push(make_pair(0,s));
    dis[s]=0;lu[s]=1;
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=head[u];i;i=e[i].nex)
        {
            int v=e[i].v;
            if(dis[u]+e[i].w<dis[v])
            {
                dis[v]=dis[u]+e[i].w;
                cnt[v]=cnt[u]+1;
                tot[v]=tot[u]+en[v];
                pre[v]=u;
                lu[v]=lu[u];
                q.push(make_pair(dis[v],v));
            }
            else if(dis[u]+e[i].w==dis[v])
            {
            	lu[v]+=lu[u];
            	if(cnt[v]<cnt[u]+1)
            	{
            		cnt[v]=cnt[u]+1;
            		tot[v]=tot[u]+en[v];
            		pre[v]=u;
            		//q.push(make_pair(dis[v],v));
				}
				else if(cnt[v]==cnt[u]+1)
				{
					if(tot[v]<tot[u]+en[v])
					{
						tot[v]=tot[u]+en[v];
						pre[v]=u;
            			//q.push(make_pair(dis[v],v));
					}
				}
			}
        }
    }
    int t=mp[ed];
    while(t)
    {
    	ans.push_back(t);
    	t=pre[t];
	}
	for(int i=(int)ans.size()-1;i>=0;i--) 
	{
		if(i!=0) cout<<mmp[ans[i]]<<"->";
		else cout<<mmp[ans[i]]<<endl;
	}
	cout<<lu[mp[ed]]<<" "<<dis[mp[ed]]<<" "<<tot[mp[ed]]<<endl;
}
int main()
{
	cin>>n>>k;
	cin>>st>>ed;
	mp[st]=++num;
	mmp[1]=st;
	for(int i=1;i<n;i++) 
	{
		string s;cin>>s;
		mp[s]=++num;
		mmp[num]=s;
		cin>>en[num];
	}
	for(int i=1;i<=k;i++)
	{
		string u,v;int w;
		cin>>u>>v>>w;
		add(mp[u],mp[v],w);
		add(mp[v],mp[u],w);
	}
	dij(mp[st]);
	return 0;
}

