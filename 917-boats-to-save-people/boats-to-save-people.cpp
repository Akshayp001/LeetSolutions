class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n= people.size();
        int i=0,j=n-1;
        int ctr=0;
        int temp = limit;
        int carry=0;
        while(i<=j){
            if(temp>=people[j] && carry<2){
                temp-=people[j]; j--;
                carry++;
            }else if(temp>=people[i] && carry<2){
                temp-=people[i]; i++;
                carry++;
            }else{
                temp=limit;
                ctr++;
                carry=0;
            }
        }
        if(temp<limit) ctr++;
        return ctr;        
    }
};