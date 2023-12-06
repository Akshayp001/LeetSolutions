class Solution {
public:
    int totalMoney(int n) {;
        int j=1;
        int nn=n;
        int ans = 0;
        for(int i=0;i<(n/7);i++){
            int l = j+7;
            for(int k=j;k<l;k++){
                ans+=k;
                cout<<k<<endl;
                nn--;  
            }
            j=j+1;
        }
        // cout<<j<<"o"<<endl
        if(n%7!=0){
            cout<<"after"<<endl;
            int a = n%7;
            while(a--){
                cout<<j<<endl;
                ans+=j++;
            }
        }
        return ans;
        
    }
};