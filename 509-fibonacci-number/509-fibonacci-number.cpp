class Solution {
public:
    //Iterative Solution
    int fib(int n) {
        if(n==0||n==1) return n;
        int a=0,b=1,c=0;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
    //Recursive Solution
    // int fib(int n) {
    //     if(n==1 || n==0) return n;
    //     return fib(n-1) + fib(n-2);
    // }
};