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
int n,a[150],vis[150];
vector<int> ans[150];
int main()
{
	cin>>n;
	int flag=1;
	int pan=n,pos=0;
	for(int i=1;i<=n;i++) read(a[i]),a[i]*=10;
	while(flag)
	{
		if(!pan) break;
		int last;
		for(int i=1;i<=n;i++)
		{
			if(pan==1) break;
			if(a[i]==0) 
			{
				if(!vis[i]) pan--;
				vis[i]=1;
				continue;
			}
			a[i]--;
			last=i;
			if(pan!=1) pos++;
			ans[i].push_back(pos);
		}
		if(pan==1)
		{
			int temp;
			for(int i=1;i<=n;i++) 
			{
				if(a[i])
				{
					temp=i;
					break;
				}
			}
			if(last==temp) pos+=2;
			else pos+=1;
			for(int i=1;i<=a[temp];i++)
			{
				ans[temp].push_back(pos);
				pos+=2;
			}
			pan=0;	
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		printf("#%d\n",i);
		for(int j=0;j<ans[i].size();j++)
		{
			if((j+1)%10==0) cout<<ans[i][j]<<endl;
			else cout<<ans[i][j]<<" ";
		}
	}
	return 0;
}
