class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        for(int i=0;i<encoded.size();i++){
            int t=first;
            first^=encoded[i];
            encoded[i]=t;
        }
        encoded.push_back(first);
        return encoded;        
    }
};