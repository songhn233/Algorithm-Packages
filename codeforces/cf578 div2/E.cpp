    #include<cstdio>
    #include<iostream>
    #include<algorithm>
    #include<cstring>
    using namespace std;
    const int maxn=1000050;
    int n,nex[maxn];
    char ans[maxn];
    int main()
    {
    	scanf("%d",&n);
    	scanf("%s",ans+1);
    	for(int step=2;step<=n;step++)
    	{
    		nex[0]=nex[1]=0;
    		char t[maxn];scanf("%s",t+1);
    		int m=strlen(t+1);
    		for(int i=2,j=0;i<=m;i++)
    		{
    			while(j&&t[j+1]!=t[i]) j=nex[j];
    			if(t[j+1]==t[i]) j++;
    			nex[i]=j;
    		}
    		int p=0;
    		int size=strlen(ans+1);
    		for(int i=max(1,size-m+1);i<=size;i++)
    		{
    			while(p&&t[p+1]!=ans[i]) p=nex[p];
    			if(t[p+1]==ans[i]) p++;
    		}
    		for(int i=p+1;i<=m;i++) ans[++size]=t[i];
    	}
    	puts(ans+1);
    	return 0;
    }
