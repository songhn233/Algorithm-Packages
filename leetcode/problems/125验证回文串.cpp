class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string temp="";
        for(int i=0;i<n;i++) 
        {
            s[i]=tolower(s[i]);
            if(isdigit(s[i])||isalpha(s[i])) temp+=s[i];
        }
        n=temp.size();
        int t=n-1,flag=0;
        for(int i=0;i<n/2;i++)
        {
            if(temp[i]==temp[t])
            {
                t--;
                continue;
            }
            else 
            {
                flag=1;
                break;
            }
        }
        if(flag) return false;
        else return true;
    }
};