class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==2) return min(cost[0],cost[1]);
        cost.push_back(0);
        int a = cost[0], b = cost[1];
        int temp;
        for(int i=2;i<cost.size();i++){
            temp = min(a,b)+cost[i];
            a=b;
            b=temp;
        }
        return temp;
    }
};