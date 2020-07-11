class Solution {
public:
    bool winnerSquareGame(int n) {
        int sg[100050];
        bool hash[100050];
        memset(sg,0,sizeof(sg));
        memset(hash,0,sizeof(hash));
        int i,j;
        for(i=0;i<=n;++i)
        {
            memset(hash,0,sizeof(hash));
            int temp=1;
            while(temp*temp<=i) hash[sg[i-temp*temp]]=1,temp++;
            for(j=0;j<=n;++j)
            {
                if(!hash[j])
                   break;
            }
            sg[i]=j;
        }
        if(sg[n]) return true;
        return false;
    }
};