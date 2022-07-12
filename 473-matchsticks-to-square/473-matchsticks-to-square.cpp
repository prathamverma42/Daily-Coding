class Solution {
int a=0,b=0,c=0,d=0;
bool solve(vector<int> &nums, int i){
    if(i==nums.size()){
        if(a==0 && b==0 && c==0 && d==0) return true;
        else return false;
    }
    if(a>=nums[i]){
        a-=nums[i];
        if(solve(nums,i+1)) return true;
        a+=nums[i];
    }
    if(b>=nums[i]){
        b-=nums[i];
        if(solve(nums,i+1)) return true;
        b+=nums[i];
    }
    if(c>=nums[i]){
        c-=nums[i];
        if(solve(nums,i+1)) return true;
        c+=nums[i];
    }
    if(d>=nums[i]){
        d-=nums[i];
        if(solve(nums,i+1)) return true;
        d+=nums[i];
    }
    return false;
}
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto x: matchsticks){sum+=x;}
        if(sum%4!=0) return false;
        int sumsize = sum / 4;
        a=sumsize, b=sumsize, c=sumsize, d=sumsize;
        sort(matchsticks.rbegin(), matchsticks.rend());
        return solve(matchsticks,0);
    }
};