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
int n;
int main()
{
    cin>>n;
    int k=0;
    cout<<8+n*7<<endl;
    printf("%d %d\n",1,1);
    printf("%d %d\n",1,2);
    printf("%d %d\n",1,3);
    printf("%d %d\n",2,1);
    printf("%d %d\n",3,1);
    printf("%d %d\n",3,2);
    printf("%d %d\n",3,3);
    printf("%d %d\n",2,3);
    for(int i=1;i<=n;i++)
    {
        k+=2;
        printf("%d %d\n",1+k,2+k);
        printf("%d %d\n",1+k,3+k);
        printf("%d %d\n",2+k,1+k);
        printf("%d %d\n",3+k,1+k);
        printf("%d %d\n",3+k,2+k);
        printf("%d %d\n",3+k,3+k);
        printf("%d %d\n",2+k,3+k);
    }
    return 0;
}