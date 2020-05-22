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
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T;
string a,b;
vector<int> A,B;
vector<int> add(vector<int> A,vector<int> B)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<max(A.size(),B.size());i++)
    {
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(1);
    return C;
}
int main()
{
    cin>>T;
    while(T--)
    {
        A.clear();B.clear();
        cin>>a;
        for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
        B.push_back(1);
        vector<int> C=add(A,B);
        if(a.size()>=21&&a!="100000000000000000000") puts("Zhang San will never have girlfriend!");
        else
        {
            for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
            cout<<endl;
        }
    }
    return 0;
}