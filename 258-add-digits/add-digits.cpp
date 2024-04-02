class Solution {
public:
    int addDigits(int num){
        int n=num;
        while(true){
            int t=0;
            while(n){
                t+= n%10;
                n=n/10;
            }      
            if(t/10==0) return t;
            n=t;     
        }  
        return 0;              
    }
};