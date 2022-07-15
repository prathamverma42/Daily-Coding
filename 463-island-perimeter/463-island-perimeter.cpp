class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid){
        if(i<0 || i==grid.size() || j<0 || j==grid[0].size()){
            return true;
        }
        return false;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int dx[4]={1,-1,0,0};
        int dy[4]={0,0,1,-1};
        int cnt = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    for(int k=0;k<4;k++){
                        int x=i+dx[k];
                        int y=j+dy[k];
                        if(check(x,y,grid) || !grid[x][y]){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};