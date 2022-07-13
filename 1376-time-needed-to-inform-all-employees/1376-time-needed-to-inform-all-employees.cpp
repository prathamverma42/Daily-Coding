class Solution {
public:
     int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int ans = 0;
        vector<int> adj[n];
        for(int i=0;i<n;++i)
        {
            if(manager[i] == -1) continue;
            else
            {
                adj[manager[i]].push_back(i);
            }
                
        }
        vector<int> vis(n, 0);
        queue<int> qu;
        qu.push(headID);
        vis[headID] = 0;
        while(!qu.empty())
        {
            int size = qu.size();
            while(size--)
            {
            int u = qu.front();
            qu.pop();
            for(auto v: adj[u])
            {
                vis[v]+=informTime[u] + vis[u];
                qu.push(v);
            }
            }
           
        }
        ans = *max_element(vis.begin(), vis.end());
        return ans;
    }
};