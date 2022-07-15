// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dis(V,INT_MAX);
        pq.push({0,S});
        dis[S]=0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int prevdis = p.first;
            int node = p.second;
            for(auto x: adj[node]){
                int adjnode = x[0];
                int weight = x[1];
                if(dis[adjnode]>dis[node]+weight){
                    dis[adjnode]=dis[node]+weight;
                    pq.push({dis[node]+weight,adjnode});
                }
            }
        }
        return dis;
        
        
        // // Code here
        // vector<int> dis(V,INT_MAX);
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // pq.push({0,S});
        // dis[S]=0;
        
        // while(!pq.empty()) {
        //   //  int dis = pq.top().first;
        //     int node = pq.top().second;
        //     pq.pop();
            
        //     for(auto i: adj[node]) {
        //         int next  = i[0];
        //         int weight = i[1];
        //         if(weight+dis[node]<dis[next]) {
        //             dis[next] = weight+dis[node];
        //             pq.push({dis[next],next});
        //         }
        //     }
            
        // }
        // return dis;

        
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends