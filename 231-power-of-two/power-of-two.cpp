class Solution {
public:
    //recursion 
    
    // bool isPowerOfTwo(int n) {
    //     if(n==1) return true;

    //     if(n>1){
    //         if(n%2==0) return isPowerOfTwo(n/2);
    //         else return false;  
    //     }
    //     return false;
    // }

    //optimised
    bool isPowerOfTwo(int n) {
        if(n<1) return false;

        while(n%2==0 || n==1){
            if(n==1) return true;
            n=n/2;
        }
        return false;
    }
};