class Solution {
bool solve(vector<int> &nums, vector<int> &matchs, int i){
    if(i==nums.size()){
        for(auto x:matchs){
            if(x!=0) return false;
        }
        return true;
    }
    for(int j=0;j<4;j++){
        if(matchs[j]>=nums[i]){
            matchs[j]-=nums[i];
            if(solve(nums,matchs,i+1)) return true;
            matchs[j]+=nums[i];
        }
    }
    return false;
}
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto x: matchsticks){sum+=x;}
        if(sum%4!=0) return false;
        int sumsize = sum / 4;
        vector<int> matchs(4,sumsize);
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks,matchs,0);
    }
};