class Solution {
public:
    string toBin(int num){
        return bitset<sizeof(int) * 8>(num).to_string();
    }
    int minBitFlips(int start, int goal) {
        bitset<32> a(toBin(start));
        bitset<32> b(toBin(goal));
        bitset<32> c=a^b;
        return c.count();
    }
};