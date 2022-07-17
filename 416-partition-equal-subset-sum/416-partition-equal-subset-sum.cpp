class Solution {
public:
    bool t[201][10001];
    int subset(vector<int>& nums, int sum){
        int n = nums.size();
        for(int i=0;i<=n;i++){
            t[i][0]=true;
        }
        for(int i=1;i<=sum;i++){
            t[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j-nums[i-1]] || t[i-1][j];
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        return subset(nums,sum/2);
    }
};