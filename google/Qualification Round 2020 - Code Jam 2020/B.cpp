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
    for(int tim=1;tim<=T;tim++)
    {
        cin>>s;
        printf("Case #%d: ",tim);
        rep(i,1,s[0]-'0') cout<<"(";
        cout<<s[0];
        int cnt=s[0]-'0';
        for(int i=1;i<s.size();i++)
        {
            int temp=s[i]-s[i-1];
            if(temp<0) 
            {
                for(int j=1;j<=-temp;j++) cout<<")";
                cout<<s[i];
                if(temp) cnt+=temp;
            }
            else
            {
                for(int j=1;j<=temp;j++) cout<<"(";
                cout<<s[i];
                if(temp) cnt+=temp;
            }
        }
        for(int i=1;i<=cnt;i++) cout<<")";
        cout<<endl;
    }
    return 0;
}