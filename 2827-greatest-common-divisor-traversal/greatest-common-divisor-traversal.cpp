class Disjoint {
public:
    vector<int> parent,rank;
    int n;
    Disjoint(int size): parent(size), rank(size, 1), n(size){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if(x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void adds() {
        parent.push_back(n);
        rank.push_back(1);
        n++;
    }
    void uni(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px == py) return;
        if(rank[px] > rank[py]) {
            rank[px] += rank[py];
            parent[py] = px;
        } else {
            rank[py] += rank[px];
            parent[px] = py;
        }
        return;
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int ind = nums.size();
        Disjoint uf(nums.size());
        for(int j = 0; j < nums.size(); j++) {
            int temp = nums[j];
            if(temp % 2 == 0) {
                while(temp % 2 == 0) temp /= 2;
                if(m.count(2) == 0) {
                    m[2] = ind;
                    uf.adds();
                    ind++;
                }
                uf.uni(j, m[2]);
            }
            for(int i = 3; i <= sqrt(temp); i += 2) {
                if(temp % i == 0) {
                    while(temp % i == 0) temp /= i;
                    if(m.count(i) == 0) {
                        m[i] = ind;
                        uf.adds();
                        ind++;
                    }
                    uf.uni(j, m[i]);
                }
            }
            if(temp != 1) {
                if(m.count(temp) == 0) {
                    m[temp] = ind;
                    uf.adds();
                    ind++;
                }
                uf.uni(j, m[temp]);
            }
        }
        return uf.rank[uf.find(0)] == ind;
    }
};