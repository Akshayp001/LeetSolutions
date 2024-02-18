class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        if(n==1) return 0;
        sort(meetings.begin(),meetings.end());
        priority_queue<long,vector<long>,greater<long> > freeRooms;
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<pair<long,long>> > rooms;
        for(int i=0;i<n;i++) freeRooms.push(i);
        vector<int> counts(n,0);
        long t = 0;
        for(int i=0;i<meetings.size();i++){
            while(!rooms.empty() && rooms.top().first <= meetings[i][0]){
                auto p = rooms.top(); rooms.pop();
                t = p.first;
                int room = p.second;
                freeRooms.push(room);
            }
            if(!freeRooms.empty()){
                int room = freeRooms.top(); freeRooms.pop();
                rooms.push({meetings[i][1],room});
                counts[room]++;
                continue;
            }
            else {
                auto p = rooms.top(); rooms.pop();
                t = p.first;
                int room = p.second;
                rooms.push({t+meetings[i][1]-meetings[i][0],room});
                counts[room]++;
            }
        }
        int data = INT_MIN;
        int ans;
        for(int i=0;i<n;i++) {
            if(data < counts[i]){
                ans = i;
                data = counts[i];
            }
        }
        return ans;
    }
};