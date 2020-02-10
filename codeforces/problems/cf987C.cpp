    #include<iostream>
    #include<algorithm>
    #include<cstdio>
    #include<cstring>
    using namespace std;
    const int maxn=3050;
    const int inf=0x3f3f3f3f;
    int f[maxn][5];
    int n,s[maxn],c[maxn];
    int main()
    {
    	cin>>n; 
    	for(int i=1;i<=n;i++) cin>>s[i];
    	for(int i=1;i<=n;i++) cin>>c[i];
    	memset(f,0x3f,sizeof(f));
    	for(int i=1;i<=n;i++)
    	{
    		f[i][1]=c[i];
    		for(int k=2;k<=3;k++)
    		{
    			for(int j=1;j<=i-1;j++)
    				if(s[i]>s[j]) f[i][k]=min(f[i][k],f[j][k-1]+c[i]);
    		}
    	}
    	int ans=inf;
    	for(int i=3;i<=n;i++) ans=min(ans,f[i][3]);
    	if(ans==inf) puts("-1");
    	else cout<<ans<<endl;
    	return 0;
    }


