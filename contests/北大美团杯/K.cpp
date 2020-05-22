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
const int maxn=600010;
int T,n,vis[maxn];
char s[maxn];
vector<int> f[maxn];
int num=0;
// bool calc(int mid,int t)
// {
//     if(f[mid].size()==0) return false;
//     if(t==1)
//     {
//         if(f[mid].size()<=1&&s[f[mid].back()]=='1') return true;
//         if(f[mid].size()==4&&s[f[mid].back()]=='5') return true;
//     }
//     if(t==4&&f[mid].size()==2&&s[f[mid].back()]=='1') return true;
//     if(t==4&&f[mid].size()==5&&s[f[mid].back()]=='1') return true;
//     if(t==5&&f[mid].size()==3&&s[f[mid].back()]=='4') return true;
//     return false;

// }
int main()
{
    rd(T);
    while(T--)
    {
        scanf("%s",s+1);
        n=strlen(s+1);
        num=0;
        int t1,t2,t3;
        t1=1,t2=1,t3=1;
        for(int i=1;i<=n;i++) vis[i]=0,f[i].clear();
        for(int i=1;i<=(n-(n/6));i++)
        {
            int flag=0;
            if(s[i]=='1')
            {
                if(t1<=num)
                {
                    if(f[t1].size()<=1) f[t1].push_back(i),flag=1,vis[i]=1;
                    if(f[t1].size()>=2) t1++;
                }
            }
            if(s[i]=='4')
            {
                if(f[t2].size()==2)
                {
                    f[t2].push_back(i),flag=1;
                }
                t2++;
            }
            if(s[i]=='5')
            {
                if(f[t3].size()==3) f[t3].push_back(i),flag=1;
                t3++;
            }
            if(!flag)
            {
                if(num>=n/6) continue;
                num++;
                f[num].push_back(i);
                vis[i]=1;
            }
            // // int l=1,r=num;
            // // while(l<r)
            // // {
            // //     int mid=l+r>>1;
            // //     if(calc(mid,s[i]-'0')) r=mid;
            // //     else l=mid+1;
            // // }
            // int flag=0;
            // if(s[i]=='1')
            // {
            //     int l=1,r=num;
            //     while(l<r)
            //     {
            //         int mid=l+r>>1;
            //         if(f[mid].size()<=1) r=mid;
            //         else l=mid+1;
            //     }
            //     if(f[l].size()==1) f[l].push_back(i),flag=1,vis[i]=1;
            // }
            // else if(s[i]=='4')
            // {
            //     int l=1,r=num;
            //     while(l<r)
            //     {
            //         int mid=l+r>>1;
            //         if(f[mid].size()==2) r=mid;
            //         else l=mid+1;
            //     }
            //     if(f[l].size()==2) f[l].push_back(i),flag=1;
            // }
            // else if(s[i]=='5')
            // {
            //     int l=1,r=num;
            //     while(l<r)
            //     {
            //         int mid=l+r>>1;
            //         if(f[mid].size()==3) r=mid;
            //         else l=mid+1;
            //     }
            //     if(f[l].size()==3) f[l].push_back(i),flag=1;
            // }
            // if(!flag)
            // {
            //     if(num==n/6) continue;
            //     ++num;
            //     f[num].clear();
            //     f[num].push_back(i);
            //     if(num<=n/6) vis[i]=1;
            // }
        }
        vector<int> temp;temp.clear();
        for(int i=1;i<=n;i++) if(!vis[i]&&s[i]=='1') temp.push_back(i);
        int pos=0;
        for(int i=1;i<=num;i++)
        {
            if(f[i].size()==1) continue;
            for(int j=0;j<f[i].size();j++)
            {
                printf("%d ",f[i][j]);
            }
            if(f[i].size()==4) printf("%d %d\n",temp[pos],n-(n/6)+i),pos++;
            else printf("%d\n",n-(n/6)+i);
        }
    }
    return 0;
}