class Solution {
public:
    bool check(int node, vector<int> &color, vector<vector<int>> &graph){
        queue<int> q;
        q.push(node);
        color[node]=1;
        while(!q.empty()){
            int p = q.front();
            q.pop();
            for(auto x: graph[p]){
                if(color[x]==-1){
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
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                if(check(i,color,graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};