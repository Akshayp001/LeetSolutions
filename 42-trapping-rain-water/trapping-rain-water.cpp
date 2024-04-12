class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sm=0,em=0;
        int sum=0,s=0,e=n-1;
        while(s<=e){
            if(height[s]<=height[e]){
                if(height[s]>=sm){
                sm =height[s];
                s++;
                }else{
                    sum+=sm-height[s];
                    s++;
                }
            }else{
                if(height[e]>=em){
                    em=height[e];
                    e--;
                }else{
                    sum+= em-height[e];
                    e--;
                }
            }
        }
        return sum;
        
    }
};