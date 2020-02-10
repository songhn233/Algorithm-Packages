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
int n,k;
map<int,int> mp;
int main()
{
	cin>>n>>k;
	int pan=0;
	for(int i=1;i<=k+1;i++)
	{
		printf("?");
		for(int j=1;j<=k+1;j++)
		{
			if(j!=i) printf(" %d",j);
		}
		printf("\n");
		fflush(stdout);
		int pos,val;
		cin>>pos>>val;
		mp[val]++;
		pan=max(pan,val); 
	}
	cout<<"! "<<mp[pan]<<endl;
	return 0;
}

