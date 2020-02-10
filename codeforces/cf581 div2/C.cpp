#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const int inf=0x3f3f3f3f;
int n,a[110][110],m;
int s,t,tt[1000050];
string c[110];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];	
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		a[i][j]=c[i][j-1]-'0';
    		if(a[i][j]==0) a[i][j]=inf;
    	}
    }
    for(int i=1;i<=n;i++) a[i][i]=0;
    cin>>m;
    for(int i=1;i<=m;i++) cin>>tt[i];	
    
    for(int k=1;k<=n;k++)
    	for(int i=1;i<=n;i++)
    		for(int j=1;j<=n;j++)
    		a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    	
    vector<int> ans;
    ans.push_back(tt[1]);
    for(int pre=1;pre<m;)
    {
    	for(int i=pre+1;i<=m;i++)
    	{
    		if(a[tt[pre]][tt[i]]!=i-pre)
    		{
    			ans.push_back(tt[i-1]);
    			pre=i-1;
			}
			else if(i==m)
			{
				ans.push_back(tt[m]);
				pre=m;
			}
		}
	}
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
