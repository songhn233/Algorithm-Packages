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
const int maxn=1050;
int n,ans,in[maxn];
vector<int> e[maxn];
vector<int> t;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;read(x),read(y);
		e[x].push_back(y);
		e[y].push_back(x);
		in[x]++,in[y]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i].size()==1) t.push_back(i);
	}
	while(t.size()>1)
	{
		int t1=t[0],t2=t[1];
		cout<<"? "<<t1<<" "<<t2<<endl;
		cout.flush();
		int temp;cin>>temp;
		if(temp==t1||temp==t2)
		{
			cout<<"! "<<temp<<endl;
			return 0;
		}
		else
		{
			for(int i=0;i<e[t1].size();i++)
			{
				int v=e[t1][i];
				in[v]--;
				if(in[v]==1) t.push_back(v);
			}
			for(int i=0;i<e[t2].size();i++)
			{
				int v=e[t2][i];
				in[v]--;
				if(in[v]==1) t.push_back(v);
			}
			t.erase(t.begin());t.erase(t.begin());
		}
	}
	cout<<"! "<<t[0]<<endl;
	return 0;
}

