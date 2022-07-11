class KthLargest {
priority_queue<int,vector<int>,greater<int>> pq;
int tar=0;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(i>=k){pq.pop();}
        }
        tar=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>tar)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */