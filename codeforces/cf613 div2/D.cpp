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
const int maxn=100050;
int n;
vector<int> a;
int calc(vector<int> t,int d)
{
	if(t.size()==0||d<0) return 0;
	vector<int> t1,t2;
	t1.clear(),t2.clear();
	for(int i=0;i<t.size();i++)
	{
		if(t[i]>>d&1) t1.push_back(t[i]);
		else t2.push_back(t[i]);
	}
	if(t1.size()==0) return calc(t2,d-1);
	else if(t2.size()==0) return calc(t1,d-1);
	else return min(calc(t1,d-1),calc(t2,d-1))+(1<<d);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		int x;read(x);
		a.push_back(x);
	}
	cout<<calc(a,30)<<endl;
	return 0;
}

