class Solution {
public:
    int dp[101][101][601];
   vector<int> cal(string s){
        int one = 0;
        int zero= 0;
        int i = 0;
        while(s[i]!='\0'){
            if(s[i]=='0'){zero++;}
            else one++;
            i++;
        }
        return {zero,one};
    }
    int solve(vector<string> &str, int m, int n, int indx){
        if(indx==str.size()){return 0;}
        if(m<=0 && n<=0){return 0;}
        if(dp[m][n][indx]!=-1) return dp[m][n][indx];
        vector<int> len=cal(str[indx]);
        if(len[0]<=m && len[1]<=n){
            return dp[m][n][indx]=max(1+solve(str,m-len[0],n-len[1],indx+1),solve(str,m,n,indx+1));
        }
        return dp[m][n][indx]=solve(str,m,n,indx+1);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(strs,m,n,0);
    }
};