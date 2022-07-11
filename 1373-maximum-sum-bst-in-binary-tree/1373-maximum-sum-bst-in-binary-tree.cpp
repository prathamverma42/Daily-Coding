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
    int sum=0;
    vector <int>  maxSum(TreeNode *root) {
        if(root == NULL) 
            return {INT_MAX, INT_MIN, 0};
        
        vector <int> l = maxSum(root->left);
        vector <int> r = maxSum(root->right);
        
        if(l.size() == 0 || r.size() == 0|| root->val <= l[1] || root->val >= r[0])
            return {} ;
        
        vector <int> ans(3);
        ans[0] = min(root->val, l[0]);
        ans[1] = max(root->val, r[1]);
        ans[2] = root->val + l[2] + r[2];
        sum = max(sum, ans[2]);
        return ans;        
    }
    
    int maxSumBST(TreeNode* root) {
       maxSum(root);
        return sum;
    }
};