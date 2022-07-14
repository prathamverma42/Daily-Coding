class Solution {
public:
    bool check(int node, vector<int> &vis, vector<int> &color, vector<vector<int>> &graph){
        queue<int> q;
        q.push(node);
        vis[node]=1;
        color[node]=1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto x: graph[p]){
                if(vis[x]==-1){
                    vis[x]=1;
                    color[x]=1-color[p];
                    q.push(x);
                }else if(color[x]==color[p]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        if(v==1) return true;
        vector<int> vis(v,-1);
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(vis[i]==-1){
                if(check(i,vis,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};