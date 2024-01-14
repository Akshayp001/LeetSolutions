class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr(n,1);

        int ctr=0;
        int killed = n;
        for(int i = 0; i < n; i++){
            if(killed==1) break;

            if(arr[i]==0){
                if(i==n-1){
                    i=-1;
                }
                continue;   
            }

            ctr++;

            if(ctr==k){
                arr[i]=0;
                killed--;
                ctr=0;
            }
            if(i==n-1) i=-1;
            
        }

        for(int i=0;i<n;i++){
            if(arr[i]!=0) return i+1;        
        } 
        return -1; 
    }
};