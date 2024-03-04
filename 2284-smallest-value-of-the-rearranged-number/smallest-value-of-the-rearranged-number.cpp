#define ll long long
class Solution {
public:
    long long smallestNumber(long long num) {
        bool neg = num<0;
        ll n= abs(num);
        unordered_map<ll,ll> m;
        while(n!=0) m[n%10]++,n/=10;      
        long long ans = 0;      
        if(neg){
            for(int i=9;i>=0;i--){
                int s = m[i];
                while(s--) ans = (ans*10) + i;
            }
        }else{
            for(int i=1;i<10;i++){
                int s = m[i];
                if(s<=0) continue;
                ans = (ans*10) + i;
                
                s--;
                if(ans!=0 && m[0]>0){
                    int s = m[0];
                    while(s--) ans*=10;
                    m[0]=0;
                }
                if(s<=0) continue;
                while(s--) ans = (ans*10) + i,cout<<s<<endl;
            }
        }
        return neg?((-1)*ans):ans;
    }
};