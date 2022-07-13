class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls = 0, rs= 0;
        for(auto x:nums){rs+=x;}
        rs=rs-nums[0];
        for(int i=0;i<nums.size();i++){
            if(ls==rs)return i;
            else{
                ls+=nums[i];
                if(i+1<nums.size())
                    rs-=nums[i+1];
            }
        }
        return -1;
    }
};