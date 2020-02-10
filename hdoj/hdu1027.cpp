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
const int maxn=10050;
int a[4];
int main()
{
	while(cin>>a[0]>>a[1]>>a[2]>>a[3])
	{
		if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0) break;
		int flag=0,tot=1;
		do{
			if(tot%6==1&&tot!=1) puts(""),flag=0;
			if(!flag) cout<<a[0]<<a[1]<<a[2]<<a[3],flag=1;
			else cout<<" "<<a[0]<<a[1]<<a[2]<<a[3];
			tot++;
		}while(next_permutation(a,a+4));
		puts("");
	}
	return 0;
}

