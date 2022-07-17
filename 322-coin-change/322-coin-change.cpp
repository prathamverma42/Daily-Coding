class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int MAX = 1e5;
        int n = coins.size();
        int t[n+1][amount+1];
        for(int i=0;i<=n;i++){
            t[i][0]=0;
        }
        for(int i=0;i<=amount;i++){
            t[0][i]=MAX-1;
        }
        for(int i=1;i<=amount;i++){
            if(i%coins[0]==0){
                t[1][i]=i/coins[0];
            }else{
                t[1][i]=MAX-1;
            }
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i-1]<=j){
                    t[i][j]=min(1+t[i][j-coins[i-1]],t[i-1][j]);
                }else{
                    t[i][j]=t[i-1][j];
                }
            }
        }
        
        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=amount;j++){
        //         cout<<t[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return t[n][amount]==99999?-1:t[n][amount];
    }
};