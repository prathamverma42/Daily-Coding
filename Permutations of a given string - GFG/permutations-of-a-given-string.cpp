// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void solve(string s, set<string>&ans, vector<int>&vis, string temp){
	        if(temp.length()==s.length()){
	            ans.insert(temp);
	            return ;
	        }
	        for(int i=0;i<s.length();i++){
	            if(vis[i]==-1){
	                vis[i]=0;
	                temp.push_back(s[i]);
	                solve(s,ans,vis,temp);
	                vis[i]=-1;
	                temp.pop_back();
	            }
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    sort(S.begin(),S.end());
		    set<string> ans;
		    vector<int> vis(S.length(),-1);
		    solve(S,ans,vis,"");
		    vector<string>res;
		    for(auto x:ans){
		        res.push_back(x);
		    }
		    return res;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends