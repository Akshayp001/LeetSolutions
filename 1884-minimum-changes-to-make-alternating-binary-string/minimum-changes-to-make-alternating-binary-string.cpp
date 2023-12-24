class Solution {
public:
    int minOperations(string s) {
        int a=0,b=1;
        int n = s.length();
        int x=0,y=0;

        for(auto si:s){
            if((si-'0')==a){
                x++;
            }
            if((si-'0')==b){
                y++;
            }
            a=!a;
            b=!b;
            cout<<a<<" "<<b<<endl;
        }
        return min(x,y);
    }
};