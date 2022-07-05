class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(auto x: nums){
            mp[x]=1;
        }        
        int len = 1;
        for(auto x: mp){
            if(mp.find(x.first+1)!=mp.end()){
                len++;
            }else{
                len=1;
            }
            ans=max(len,ans);
        }
        return ans;
    }
};