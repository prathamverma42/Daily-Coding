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
    TreeNode* LCA(TreeNode* root, int val1, int val2){
        
        if(root == NULL) return NULL;
        if(root->val == val1 or root->val == val2){
            return root;
        }
        TreeNode* left = LCA(root->left, val1, val2);
        TreeNode* right = LCA(root->right, val1, val2);

        if(left != NULL and right != NULL){
            return root;
        }
        
        else if(left) return left;
        else if(right) return right;

        return NULL;
    }
    
    bool ltos(TreeNode* root, int val, string &s){
        
        if(root == NULL) return false;

        if(root->val == val) return true;

        bool left = ltos(root->left, val, s);
        bool right = ltos(root->right, val, s);

        if(left or right){
            s += 'U';
            return true;
        }

        return false;
    }

    bool ltod(TreeNode* root, int val, string &s){

        if(root == NULL) return false;

        if(root->val == val) return true;

        s += 'L';
        bool left = ltod(root->left, val, s);
        if(left) return true;
        s.pop_back();

        s += 'R';
        bool right = ltod(root->right, val, s);
        if(right) return true;
        s.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {   
        
        TreeNode* lca = LCA(root, startValue, destValue);
        
        string s1 = "";
        ltos(lca, startValue, s1);
        
        string s2 = "";
        ltod(lca, destValue, s2);
        
        string res = s1 + s2;
        
        return res;
    }
};