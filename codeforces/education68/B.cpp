#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int maxn=400050;
const int inf=0x3f3f3f3f;
int q,n,m,ro[maxn],co[maxn];
char c[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin>>q;
	while(q--)
	{
		cin>>n>>m;
		for(int i=0;i<n*m;i++) 
		{
			cin>>c[i];
		}
		for(int i=0;i<n;i++)
		{
			int temp=0;
			for(int j=0;j<m;j++)
			{
				if(c[i*m+j]=='.') temp++;
			}
			ro[i]=temp;
		}
		for(int i=0;i<m;i++)
		{
			int temp=0;
			for(int j=0;j<n;j++)
			{
				if(c[j*m+i]=='.') temp++;
			}
			co[i]=temp;
		}
		int ans=inf;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
                int temp=0;
				if(c[i*m+j]=='.') temp=ro[i]+co[j]-1;
				else temp=ro[i]+co[j];
                ans=min(ans,temp);
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

