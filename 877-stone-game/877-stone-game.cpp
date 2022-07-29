class Solution {
public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int sum1 = arr[i] + solve(arr,i+1,j,dp);
        int sum2 = arr[j] + solve(arr,i,j-1,dp);
        return dp[i][j]=max(sum1,sum2);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int ans = solve(piles,0,piles.size()-1,dp);
        int totsum = 0;
        for(auto x:piles){
            totsum+=x;
        }
        return ans>totsum-ans;
    }
};