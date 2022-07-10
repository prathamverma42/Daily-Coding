class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        
        dp[0] = cost[0], dp[1] = cost[1];
        for(int i = 2; i < n; i++)
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
        
        return min(dp[n-1], dp[n-2]);
        
        // if(cost.size()==2) return min(cost[0],cost[1]);
        // cost.push_back(0);
        // int a = cost[0], b = cost[1];
        // int temp;
        // for(int i=2;i<cost.size();i++){
        //     temp = min(a,b)+cost[i];
        //     a=b;
        //     b=temp;
        // }
        // return temp;
    }
};