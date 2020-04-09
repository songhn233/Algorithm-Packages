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
int temp;
int a[]={4,8,15,16,23,42};
map<int,bool> mp;
int ans[10];
int main()
{

    mp[4]=true;mp[8]=true;mp[15]=true;
    mp[16]=true;mp[23]=true;mp[42]=true;
    rep(i,1,4)
    {
        cout<<"?"<<" "<<1<<" "<<i+1<<endl;
        fflush(stdout);
        int x;cin>>x;
        if(i==1) temp=x;
        else if(i==2)
        {
            rep(j,0,5)
            {
                if(temp%a[j]==0&&x%a[j]==0)
                {
                    if(mp[temp/a[j]]&&mp[x/a[j]]&&(temp/a[j]!=x/a[j])&&(temp/a[j]!=a[j])&&(x/a[j]!=a[j]))
                    {
                        ans[1]=a[j];
                        ans[2]=temp/a[j];
                        ans[3]=x/a[j];
                        break;
                    }
                }
            }
        }
        else
        {
            ans[i+1]=x/ans[1];
        }
    }
    int vis[100];
    mst(vis,0);
    rep(i,1,5) vis[ans[i]]=1;
    rep(i,0,5)
    {
        if(!vis[a[i]])
        {
            ans[6]=a[i];
            break;
        }
    }
    cout<<"! ";
    rep(i,1,6) cout<<ans[i]<<" ";
    cout<<endl;
    fflush(stdout);
    return 0;
}