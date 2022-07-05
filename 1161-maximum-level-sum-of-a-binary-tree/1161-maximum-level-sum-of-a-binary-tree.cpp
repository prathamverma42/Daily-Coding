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
    int maxLevelSum(TreeNode* root) {
        long int indx = 0;
        long int sum = INT_MIN;
        // if(!root) return ans;
        queue<TreeNode*> q;        
        q.push(root);
        int i=0;
        while(!q.empty()){
            int count = q.size();
            vector<int> temp;
            long int samp=0;
            for(int i=0;i<count;i++){
                auto p=q.front();
                q.pop();
                samp+=p->val;
                // temp.push_back(p->val);
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
            // cout<<samp<<endl;
            i++;
            // ans.push_back(temp);
            if(sum<samp){
                sum=samp;
                indx=i;
            }
        }
        return indx;
    }
};