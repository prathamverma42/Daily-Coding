class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls = 0, rs= 0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            rs+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(ls==rs)return i;
            else{
                ls+=nums[i];
                if(i+1<n)
                    rs-=nums[i+1];
            }
        }
        return -1;
    }
};