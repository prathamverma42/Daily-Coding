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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*,TreeNode*>> q;
        q.push({NULL,root});
        TreeNode*parentx=NULL;
        int depthx=0;
        TreeNode*parenty=NULL;
        int depthy=0;
        int depth=0;
        while(!q.empty()){
            int cnt = q.size();
            for(int i=0;i<cnt;i++){
                auto p=q.front();
                q.pop();
                TreeNode*parent = p.first;
                TreeNode*child = p.second;
                if(child->val==x){
                    parentx=parent;
                    depthx=depth;
                }
                if(child->val==y){
                    parenty=parent;
                    depthy=depth;
                }
                if(child->left) q.push({child,child->left});
                if(child->right) q.push({child,child->right});
            }
            depth++;
        }
        return parentx!=parenty && depthx==depthy;
    }
};