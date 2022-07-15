class Solution {
public:
     
    void dfs(vector<vector<int>> &grid,int row,int col,int color ) {
        if(row<0 || col<0 || row>=grid.size() || col>=grid[0].size() || grid[row][col] !=color ) return;
        grid[row][col]=-color;
        dfs(grid,row-1,col,color);
        dfs(grid,row+1,col,color);
        dfs(grid,row,col-1,color);
        dfs(grid,row,col+1,color);
        if(row>0 && col>0 && row<grid.size()-1 && col<grid[0].size()-1 && 
           abs(grid[row-1][col]) == color && 
           abs(grid[row+1][col]) == color && 
           abs(grid[row][col-1]) == color && 
           abs(grid[row][col+1]) == color ){
                    grid[row][col] = color;
            }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int coll = grid[row][col];
        dfs(grid,row,col,coll);
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]<0) {
                    grid[i][j]=color;
                }
            }
        }
        return grid;
    }
};