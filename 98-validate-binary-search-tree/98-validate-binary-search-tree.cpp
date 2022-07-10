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
    
    bool isValidBSTHelper (TreeNode* currentNode, TreeNode* min, TreeNode* max) {
        if (currentNode==NULL) return true;               
        if (min && currentNode->val <= min->val) return false;
        if (max && currentNode->val >= max->val) return false;

        return isValidBSTHelper (currentNode->left, min, currentNode) && isValidBSTHelper (currentNode->right, currentNode, max);
    }
    
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper (root, NULL, NULL);
    }
//     bool check(TreeNode *root,long MIN,long MAX){
//         if(root==NULL) return true;
//         if(root->val<=MIN || root->val>=MAX) return false;
        
//         return (root->left,MIN,root->val)&&(root->right,root->val,MAX);
//     }
//     bool isValidBST(TreeNode* root) {
//         return check(root,INT_MIN,INT_MAX);
//     }
    
    // void inorder(TreeNode* root, vector<int>&ans){
    //     if(root==NULL) return;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }
    // bool isValidBST(TreeNode* root) {
    //     vector<int> ans;
    //     inorder(root,ans);
    //     int n= ans.size();
    //     for(int i=0;i<n-1;i++){
    //         if(ans[i]>=ans[i+1]) return false;
    //     }
    //     return true;
    // }
};