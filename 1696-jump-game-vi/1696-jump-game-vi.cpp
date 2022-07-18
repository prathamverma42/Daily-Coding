class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if(nums.size()==1) return nums[0];
        priority_queue<pair<int,int>> pq;
        vector<int> dp(nums.size());
        pq.push({nums[0],0});
        for(int i=1;i<nums.size();i++){
            
            while(pq.top().second<i-k)pq.pop();
            
            dp[i]=nums[i]+pq.top().first;
            pq.push({dp[i],i});
        }
        return dp[nums.size()-1];
    }
};