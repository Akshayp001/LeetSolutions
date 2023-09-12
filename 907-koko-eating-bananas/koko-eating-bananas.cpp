class Solution {
public:

    int calcTime(vector<int>& piles,int t){
        int time=0;
        for(auto p:piles){
            if(p%t) time += p/t +1;
            else time += p/t;
            // cout<<"timee"<<time<<endl;
        }
        // cout<<"TImeEND"<<time<<endl;
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int hi) {
        sort(piles.begin(),piles.end());
        int n = piles.size();
        int l = 1;
        int h = piles[n-1];

        while(l<=h){
            int mid = l + (h-l)/2;
            cout<<mid<<"\n";

            if(calcTime(piles,mid)<=hi){
                if(mid-1>0 && calcTime(piles,mid-1)<=hi){
                    h = mid-1;
                }else{
                    return mid;
                }
            }else{
                l = mid+1;
            }
        }
        return 0;    
    }
};