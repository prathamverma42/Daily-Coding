/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Traverse(TreeNode*root,int&ans){
        if(root==NULL) return;
        ans+=1;
        Traverse(root->left,ans);
        Traverse(root->right,ans);
    }
    int countNodes(TreeNode* root) {
        int ans=0;
        Traverse(root,ans);
        return ans;
    }
};