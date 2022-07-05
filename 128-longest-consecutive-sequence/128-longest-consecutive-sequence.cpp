class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        map<int,int> mp;
        for(auto x: nums)
        {
            mp[x]=1;
        }        
        int n = mp.size();
        int len = 1;
        for(auto x: mp){
            if(mp.find(x.first+1)!=mp.end()){
                len++;
            }else{
                len=1;
            }
            ans=max(len,ans);
        }
        // int num = mp.begin()?->first;
        // cout<<num;
        // for(int i=1;i<n;i++){
        //     if(mp.find(num+1)!=mp.end()){
        //         num=num+1;
        //         len++;
        //     }else{
        //         num=mp
        //     }
        // }
        
        
        return ans;
       //  unordered<int,int> mp;
       //  for(auto x: nums){
       //      mp.insert({x,1});
       //  }
       //  int ans = 0;
       //  int curr = nums[0];
       //  int cnt = 0;
       // for(auto x: mp)
       // {
       //     if(mp.find){
       //          cnt++;
       //      }else{
       //          curr=mp
       //      }
       //  }

    }
};