class Solution {
public:
    TreeNode * solve(vector<int>& preorder, vector<int>& inorder,int &preStart,int inStart,int inEnd,map<int,int> &mp) {
        if(preStart>inorder.size()|| inStart>inEnd) return NULL;
        TreeNode *root= new TreeNode(preorder[preStart++]);
        int ans = mp[root->val];
        int n = ans-inStart;
        root->left = solve(preorder,inorder,preStart,inStart,ans-1,mp);
        root->right = solve(preorder,inorder,preStart,ans+1,inEnd,mp);  
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        int preStart=0,preEnd= preorder.size()-1;
        int inStart=0,inEnd=inorder.size()-1;
        for(int i=0;i<inorder.size();i++) {
            mp[inorder[i]]=i;
        }
        return solve(preorder,inorder,preStart,inStart,inEnd,mp);
        
    }
};