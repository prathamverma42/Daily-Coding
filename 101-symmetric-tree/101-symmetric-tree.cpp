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
    bool check(TreeNode* Tree1, TreeNode* Tree2){
        if(Tree1==NULL || Tree2==NULL) return Tree1==Tree2;
        if(Tree1->val!=Tree2->val) return false;
        return check(Tree1->left,Tree2->right)&&check(Tree1->right,Tree2->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left,root->right);
    }
};