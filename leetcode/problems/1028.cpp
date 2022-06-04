/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        stack<pair<TreeNode*,int> > sta;
        int i=0,dep=0;
        while(i<S.size())
        {
            if(S[i]=='-')
            {
                dep++;
                i++;
            }
            else
            {
                int val = 0;
                while(S[i]>='0'&&S[i]<='9')
                {
                    val=val*10+S[i]-'0';
                    i++;
                }
                while(sta.size()&&sta.top().second>=dep) sta.pop();
                TreeNode* temp=new TreeNode(val);
                if(sta.size()&&sta.top().first->left==NULL) {
                    sta.top().first->left=temp;
                }
                else if(sta.size()&&sta.top().first->right==NULL) {
                    sta.top().first->right=temp;
                }
                sta.push(make_pair(temp,dep));
                dep=0;
            }
        }
        while(sta.size()>1) sta.pop();
        return sta.top().first;
    }
};