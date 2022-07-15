class Solution {
public:
    void dfs(int i, int j, int m, int n, vector<vector<int>> &vis, vector<vector<int>> &grid, int &maxland, int &land){
        if(i==m || i<0 || j==n || j<0) return;
        if(grid[i][j]==0) return;
        if(!vis[i][j]){
            vis[i][j]=1;
            land+=1;
            maxland=max(maxland,land);
            dfs(i+1,j,m,n,vis,grid,maxland,land);
            dfs(i,j+1,m,n,vis,grid,maxland,land);
            dfs(i-1,j,m,n,vis,grid,maxland,land);
            dfs(i,j-1,m,n,vis,grid,maxland,land);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int maxland = 0;
        int land = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    land = 0;
                    dfs(i,j,m,n,vis,grid,maxland,land);
                }
            }
        }
        return maxland;
    }
};