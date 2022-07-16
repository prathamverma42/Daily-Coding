class Solution {
public:
    
      // declare a dp table
    
    int dp[55][55][55];
    
    long long mod = 1e9 + 7;
    
    int dfs(int i, int j, int n, int m, int moves)
    {
        // base case, if we reached out of grid
        
        if(i < 0 || i >= n || j < 0 || j >= m)
            return 1;
        
        // if no moves are remaining
        
        if(moves <= 0)
            return 0;
        
        // if already calculated
        
        if(dp[i][j][moves] != -1)
            return dp[i][j][moves];
        
        // call for upper side
        
        int up = dfs(i - 1, j, n, m, moves - 1);
        
        // call for down side
        
        int down = dfs(i + 1, j, n, m, moves - 1);
        
        // call for left side
        
        int left = dfs(i, j - 1, n, m, moves - 1);
        
        // call for right side
        
        int right = dfs(i, j + 1, n, m, moves - 1);
        
        // total paths will be sum of all the paths from all four directions
        
        // store the result and return it
        
        return dp[i][j][moves] = (up % mod + down % mod + left % mod + right % mod) % mod;
    }
    
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        
        // initialize the dp with -1
        
        memset(dp, -1, sizeof(dp));
        
        return dfs(startRow, startColumn, n, m, maxMove);
    }
    
    // I tried
    
    // void dfs(int m, int n, vector<vector<int>> &grid, int move, int i, int j, int &ans, int dx[], int dy[]){
    //     if(i<0 || j<0 || i>=m || j>=n){
    //         ans+=1;
    //         return;
    //     }
    //     if(move<0) return;
    //     grid[i][j]=1;
    //      for(int k=0;k<4;i++){
    //          int x=i+dx[k];
    //          int y=j+dy[k];
    //          if(!grid[x][y]){
    //              dfs(m,n,grid,move-1,x,y,ans,dx,dy);
    //          }
    //     }
    //     grid[i][j]=0;
    // }
    // int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    //     int ans = 0;
    //     vector<vector<int>> grid(m,vector<int>(n,0));
    //     int dx[4]={1,-1,0,0};
    //     int dy[4]={0,0,1,-1};
    //     dfs(m,n,grid,maxMove,startRow,startColumn,ans,dx,dy);
    //     return ans;
    // }
};