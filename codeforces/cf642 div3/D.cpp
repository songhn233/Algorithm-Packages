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
const int maxn=200050;
int T,n;
struct node{
    int l,r,len;
    bool operator<(const node&t) const{
        if(len==t.len) return l>t.l;
        return len<t.len;
    }
};
priority_queue<node> q;
int ans[maxn];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        q.push({1,n,n});
        int s=1;
        while(!q.empty())
        {
            node t=q.top();q.pop();
            ans[(t.l+t.r)/2]=s;
            if(s==n) break;
            s++;
            if(t.l<=(t.l+t.r)/2-1) q.push({t.l,(t.l+t.r)/2-1,(t.l+t.r)/2-1-t.l+1});
            if(t.r>=(t.l+t.r)/2+1) q.push({(t.l+t.r)/2+1,t.r,t.r-((t.l+t.r)/2+1)+1});
        }
        rep(i,1,n) printf("%d ",ans[i]);
        cout<<endl;
    }
    return 0;
}