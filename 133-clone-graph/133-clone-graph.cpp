/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    //using DFS traversal
    
    void dfs(Node* node, map<Node*,Node*> &mp){
        if(mp.find(node)==mp.end()){
            mp[node]=new Node(node->val,{});
        }
        for(auto it: node->neighbors){
            if(mp.find(it)==mp.end()){
                dfs(it,mp);
            }
            mp[node]->neighbors.push_back(mp[it]);
        }
    }
    Node* cloneGraph(Node* node){
        if(!node) return NULL;
        map<Node*,Node*> mp;
        dfs(node,mp);
        return mp[node];
    }
    
    
    //using BFS traversal
    
    // Node* cloneGraph(Node* node) {
    //     if(node==NULL){
    //         return NULL;
    //     }
    //     map<Node*,Node*> mp;
    //     Node*temp = new Node(node->val,{});
    //     mp[node]=temp;
    //     queue<Node*> q;
    //     q.push(node);
    //     while(!q.empty()){
    //         auto p = q.front();
    //         q.pop();
    //         for(auto x: p->neighbors){
    //             if(mp.find(x)==mp.end()){
    //                 mp[x]= new Node(x->val,{});
    //                 q.push(x);
    //             }
    //             mp[p]->neighbors.push_back(mp[x]);
    //         }
    //     }
    //     return mp[node];
    // }
};