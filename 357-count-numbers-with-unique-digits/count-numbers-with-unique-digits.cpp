class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n<=1) return pow(10,n);
        int temp =9,res=10,j=n-1;

        for(int i=9;i>=0;i--){
            if(j>0){
                temp*=i;
                res+=temp;
                j-=1;
            }   
        }
        return res;     
    }
};