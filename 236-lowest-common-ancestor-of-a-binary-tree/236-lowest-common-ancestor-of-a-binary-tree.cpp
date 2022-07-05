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
    bool path(TreeNode* root, TreeNode* target, vector<TreeNode*> &ans){
        if(root==NULL) return false;
        ans.push_back(root);
        if(root==target) return true;
        if(path(root->left,target,ans)||path(root->right,target,ans)) return true;
        else ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p,path_q;
        path(root,p,path_p);
        path(root,q,path_q);
        int i=0;
        // for(auto x:path_p){
        //     cout<<x->val<<" ";
        // }cout<<endl;
        // for(auto x:path_q){
        //     cout<<x->val<<" ";
        // }cout<<endl;
        while(i<path_p.size() && i<path_q.size() && path_p[i]==path_q[i])i++;
        return path_p[--i];
    }
};