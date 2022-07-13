class Solution {
public:
    bool detectcycle(int i, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[]){
        vis[i]=1;
        dfsvis[i]=1;
        
        for(auto x:adj[i]){
            if(!vis[x]){
                if(detectcycle(x,vis,dfsvis,adj))
                    return true;
            }else if(dfsvis[x]){
                return true;
            }
        }
        dfsvis[i]=0;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        for(auto x: prerequisites){
            adj[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,0);
        vector<int> dfsvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(detectcycle(i,vis,dfsvis,adj)) return false;
            }
        }
        return true;
    }
};