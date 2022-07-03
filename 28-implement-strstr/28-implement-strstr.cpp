class Solution {
public:
    int strStr(string haystack, string needle) {
        
       // same approach with good variables and method 
        int C = 0, pos = -1;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[0]) {
                pos = i;
                C++;
                for (int j = 1; j < needle.size(); j++) {
                    if (haystack[i + j] == needle[j]) C++;
                    else { C = 0; pos = -1; break; }
                }
            }
            if (C == needle.size()) break;
        }
        return pos;
        
        // int s = haystack.length();
        // int p = needle.length();
        // for(int i=0;i<s;i++){
        //     if(haystack[i]==needle[0]){
        //         int k=1;
        //         int r=i+1;
        //         while(k<p){
        //             if(haystack[r]==needle[k]){
        //                 r++;
        //                 k++;
        //             }else{
        //                 break;
        //             }
        //         }
        //         if(k==p){
        //             return r-p;
        //         }
        //     }
        // }
        // return -1;
    }
};