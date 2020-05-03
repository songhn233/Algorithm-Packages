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
const int maxn=100050;
int T,n,k,a[maxn];
string s,t;
string ans;
int main()
{
    cin>>T;
    while(T--)
    {
        ans.clear();
        rd(n),rd(k);
        cin>>s;
        for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
        sort(a+1,a+n+1);
        t=s;
        ans="a";
        for(int i=1;i<=n;i++) t[i-1]=char('0'+a[i]);
        int rest=k;
        while(rest)
        {
            if(rest==1)
            {
                ans=max(ans,t);
                break;
            }
            else if(t.size()<=rest)
            {
                string temp;temp.resize(1);     
                for(int i=0;i<rest;i++) 
                {
                    temp[0]=t[i];
                    ans=max(ans,temp);
                }
                break;
            }
            else if(rest==2)
            {
                if(t.size()==3||(t[1]==t.back())||(t[0]==t[1]&&t[2]==t.back()))
                {
                    string temp;temp.resize(2);
                    temp[0]=t[0];
                    temp[1]=t.back();
                    ans=max(ans,temp);
                    t=t.substr(1);
                    int tt=(int)t.size()-1;
                    t=t.substr(0,tt);
                    ans=max(ans,t);
                }
                else
                {
                    ans=max(ans,t.substr(0,1));
                    ans=max(ans,t.substr(1));
                }
                break;
            }
            else
            {
                string temp;temp.resize(2);
                temp[0]=t[0];
                temp[1]=t.back();
                ans=max(ans,temp);
                t=t.substr(1);
                int tt=(int)t.size()-1;
                t=t.substr(0,tt);
                rest--;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}