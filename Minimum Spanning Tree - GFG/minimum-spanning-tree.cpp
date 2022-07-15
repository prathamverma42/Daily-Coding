// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int prims(int V, vector<vector<int>> adj[]){
	    vector<bool> vis(V,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});//weight,vertex
        
        int ans=0;
        
        while(!pq.empty()){
            int vertex = pq.top().second;
            int weight = pq.top().first;
            
            pq.pop();
            if(vis[vertex]) continue;
            ans+=weight;
            vis[vertex] = true; 
            
            for(int i=0;i<adj[vertex].size();i++){
                int curr = adj[vertex][i][0];
                int wt = adj[vertex][i][1];
                if(!vis[curr]){
                    pq.push({wt,curr});
                }
            }
        }
      return ans;
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
         return prims(V,adj);
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends