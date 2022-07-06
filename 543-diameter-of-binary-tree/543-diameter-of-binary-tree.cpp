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
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        int ans = max(left,right) +1 ;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int leftHeight =  maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        return max(leftHeight+rightHeight,max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right)));
    }
};