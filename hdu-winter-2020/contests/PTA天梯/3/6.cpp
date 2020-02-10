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
string a;
int x,t=1;
vector<int> A;
vector<int> div(vector<int> &A,int b,int &r)
{
    vector<int> C;
    r=0;
    for(int i=A.size()-1;i>=0;i--)
    {
        r=r*10+A[i];
        C.push_back(r/b);
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}
int main()
{
    cin>>x;
    while(1)
    {
    	vector<int> A;
    	A.clear();
    	for(int i=t-1;i>=0;i--) A.push_back(1);
    	int r;
    	vector<int> C=div(A,x,r);
    	if(r==0)
    	{
    		for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    		printf(" ");
    		printf("%d\n",t);
    		break;
		}
    	t++;
	}
    
    return 0;
}
