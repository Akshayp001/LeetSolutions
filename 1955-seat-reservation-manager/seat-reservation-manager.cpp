class SeatManager {
    priority_queue<int, vector<int>, greater<int>> avail;

public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i) {
            avail.push(i);
        }
    }

    int reserve() {
        int seat = avail.top();
        avail.pop();
        return seat;
    }

    void unreserve(int seat) {
        avail.push(seat);
    }
};
