    #include<algorithm>
    #include<cstring>
    #include<iostream>
    #include<cstdio>
    using namespace std;
    int q,n;
    int main()
    {
    	cin>>q;
    	while(q--)
    	{
    		int ans=0;
    		cin>>n;
    		if(n&1)
    		{
    			if(n<9) 
    			{
    				puts("-1");
    				continue;
    			}
    			else ans=1,n-=9;
    		}
    		if(n<4&&n>0) puts("-1");
    		else
    		{
    			ans+=n/4;
    			cout<<ans<<endl;
    		}
    	}
    	return 0;
    }
