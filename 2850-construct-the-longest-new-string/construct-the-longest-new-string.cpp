class Solution {
public:
    int longestString(int x, int y, int z) {
        return (min(x,y)*2+z+(min(x,y)!=max(x,y)))*2;  
    }
};