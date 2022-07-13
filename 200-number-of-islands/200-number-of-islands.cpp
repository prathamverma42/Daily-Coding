class Solution {
public:
    void dfs(int i, int j, int vis[301][301], vector<vector<char>>& grid, int m,int n){
        if(i<0 || j<0 || i>=m || j>=n) return;
        if(grid[i][j]=='0') return;
        if(!vis[i][j]){
            vis[i][j]=1;
            dfs(i+1,j,vis,grid,m,n);
            dfs(i,j+1,vis,grid,m,n);
            dfs(i-1,j,vis,grid,m,n);
            dfs(i,j-1,vis,grid,m,n);
        } 
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int vis[301][301];
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,vis,grid,m,n);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};