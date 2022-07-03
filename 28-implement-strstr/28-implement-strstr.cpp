class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = haystack.length();
        int p = needle.length();
        for(int i=0;i<s;i++){
            if(haystack[i]==needle[0]){
                int k=1;
                int r=i+1;
                while(k<p){
                    if(haystack[r]==needle[k]){
                        r++;
                        k++;
                    }else{
                        break;
                    }
                }
                if(k==p){
                    return r-p;
                }
            }
        }
        return -1;
    }
};