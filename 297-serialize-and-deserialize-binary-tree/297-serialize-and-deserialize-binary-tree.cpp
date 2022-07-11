/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       if(!root) return "";
        queue<TreeNode*> q;
        q.push(root);
        string ans = "";
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p==NULL){
                ans+="#,";
                continue;
            }else{
                ans=ans+to_string(p->val)+",";
            } 
            q.push(p->left);
            q.push(p->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* left;
            TreeNode* right;
            getline(s, str, ',');
            str=="#"?left=NULL:left = new TreeNode(stoi(str));
            getline(s, str, ',');
            str=="#"?right=NULL:right = new TreeNode(stoi(str));
            if(left!=NULL) q.push(left);
            if(right!=NULL)q.push(right);
            p->left=left;
            p->right=right;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));