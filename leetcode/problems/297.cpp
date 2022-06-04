/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx=0;
        return dfs_d(data,idx);
    }
    TreeNode* dfs_d(string data,int& idx) {
        if(idx>=data.size()) return NULL;
        if(data[idx]=='n') 
        {
            idx+=5;
            return NULL;
        }
        int val=0,sign=1;
        if(data[idx]=='-') sign=-1,idx++;
        while(data[idx]>='0'&&data[idx]<='9') val=val*10+data[idx]-'0',idx++;
        idx++;
        TreeNode* root = new TreeNode(val*sign);
        root->left = dfs_d(data,idx);
        root->right = dfs_d(data,idx);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));