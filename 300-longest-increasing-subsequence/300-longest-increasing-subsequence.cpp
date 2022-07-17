class Solution {
public:
    int dp[2501];
    int lis(int i,vector<int>& nums){
        int len = 1;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j>=0;j--){
            if(nums[i]>nums[j])
                len = max(len, lis(j,nums)+1);
        }
        return dp[i]=len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int ans = INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            ans = max(ans,lis(i,nums));
        }
        return ans;
    }
};