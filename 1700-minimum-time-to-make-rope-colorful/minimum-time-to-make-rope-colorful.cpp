class Solution {
public:
    int minCost(string colors, vector<int>& nT) {
        int cost=0;

        for(int i=0;i<colors.length()-1;i++){
            if(colors[i]==colors[i+1]){
                if(nT[i]>nT[i+1]){
                    cost+=nT[i+1];
                    nT[i+1]=nT[i];
                }else{
                    cost+=nT[i];
                }   
            }
        }
        return cost;
        
    }
};