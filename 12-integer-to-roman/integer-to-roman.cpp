class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> m;
        m[1]="I";
        m[4]="IV";
        m[5]="V";
        m[9]="IX";
        m[10]="X";
        m[40]="XL";
        m[50]="L";
        m[90]="XC";
        m[100]="C";
        m[400] ="CD";
        m[500] ="D";
        m[900]="CM";
        m[1000]="M";

        vector<int> nms = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string s = "";

        while(num){
            int i=0;
            while(nms[i]>num){
                i++;
            }
            cout<<i<<endl;
            cout<<"v"<<nms[i]<<endl;
            s+=m[nms[i]];
            num = num-nms[i];
        }
        return s;



        
    }
};