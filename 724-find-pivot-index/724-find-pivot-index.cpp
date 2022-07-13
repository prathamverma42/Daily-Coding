class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftsum = 0;
        for (int x: nums) sum += x;
        for (int i = 0; i < nums.size(); ++i) {
            if (leftsum == sum - leftsum - nums[i]) return i;
            leftsum += nums[i];
        }
        return -1;
        
        // vector<int> left,right;
        // int ls =0,rs =0;
        // int n =nums.size();
        // for(int i=0,j=n-1; i<n; i++,j--){
        //     ls+=nums[i];
        //     rs+=nums[j];
        //     left.push_back(ls);
        //     right.push_back(rs);
        // }
        // for(int i=0, j=right.size()-1;i<left.size();i++,j--){
        //     if(left[i]==right[j]) return i;
        // }
        // return -1;
        
        // int ls = 0, rs= 0;
        // int n=nums.size();
        // for(int i=1;i<n;i++){
        //     rs+=nums[i];
        // }
        // for(int i=0;i<n;i++){
        //     if(ls==rs)return i;
        //     else{
        //         ls+=nums[i];
        //         if(i+1<n)
        //             rs-=nums[i+1];
        //     }
        // }
        // return -1;
    }
};