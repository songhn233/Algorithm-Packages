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
int T;
string s;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>s;
        int n=s.size();
        if(n==1) cout<<s<<endl;
        else
        {
            int flag=0;
            for(int i=0;i<n;i++) 
            {
                if(s[i]!=s[0])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0) cout<<s<<endl;
            else
            {
                for(int i=0;i<n;i++)
                {
                    if(i>0&&s[i]==s[i-1])
                    {
                        if(s[i]=='0') cout<<"10";
                        else cout<<"01";
                    }
                    else cout<<s[i];
                }
                cout<<endl;
            }
            
        }
        
    }
    return 0;
}