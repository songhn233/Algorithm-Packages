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
string s;
int main()
{
    cin>>s;
    int l,r;
    l=r=-1;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='[') {l=i;break;}
    }
    for(int i=(int)s.size()-1;i>=0;i--)
    {
        if(s[i]==']') {r=i;break;}
    }
    if(l==-1||r==-1||l>r) {puts("-1");return 0;}
    int L,R;
    L=R=-1;
    for(int i=l;i<=r;i++)
    {
        if(s[i]==':') {L=i;break;}
    }
    for(int i=r;i>=l;i--)
    {
        if(s[i]==':') {R=i;break;}
    }
    if(L==-1||R==-1||L==R) puts("-1");
    else
    {
        int ans=4;
        for(int i=L;i<=R;i++)
        {
            if(s[i]=='|') ans++;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}