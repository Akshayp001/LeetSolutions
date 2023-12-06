class Solution {
public:
    int totalMoney(int n) {;
        // int j=1;
        // int nn=n;
        // int ans = 0;
        // for(int i=0;i<(n/7);i++){
        //     int l = j+7;
        //     for(int k=j;k<l;k++){
        //         ans+=k;
        //         cout<<k<<endl;
        //         nn--;  
        //     }
        //     j=j+1;
        // }
        // // cout<<j<<"o"<<endl
        // if(n%7!=0){
        //     cout<<"after"<<endl;
        //     int a = n%7;
        //     while(a--){
        //         cout<<j<<endl;
        //         ans+=j++;
        //     }
        // }

        int comp = n / 7;
        int rem = n % 7;
        int ans = 0;
        // Add complete weeks
        for(int i=0;i<comp;i++) ans += 28+(7*i);
        
        // Add incomplete days
        int baseMoney = comp + 1;  
        for(int i = 0; i < rem; i++) {
            ans += baseMoney + i;
        }
        return ans;
        
    }
};