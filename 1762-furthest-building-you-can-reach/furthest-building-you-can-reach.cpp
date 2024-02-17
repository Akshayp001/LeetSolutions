class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        int i;
        priority_queue<int> pq;
        for(i=0;i<h.size()-1;i++){
            if((h[i+1]-h[i])<=0) continue;
            b-= (h[i+1]-h[i]);
            pq.push((h[i+1]-h[i]));
            if(b<0){
                b+=pq.top();
                pq.pop();
                l--;
            }  
            if(l<0) break;               
        }  
        return i;      
    }
};