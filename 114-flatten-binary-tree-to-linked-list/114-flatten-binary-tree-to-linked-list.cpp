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
    void flatten(TreeNode* root) {
        if(root==NULL || (root->right==NULL && root->left==NULL)){
            return ;
        }
        
        flatten(root->left);
        
        if(root->left!=NULL){
            TreeNode*temp=root->left;
            while(temp->right!=NULL){
                temp=temp->right;
            }
            temp->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        
        flatten(root->right);
        return ;
    }
};