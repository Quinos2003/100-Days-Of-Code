// class SeatManager {
// public:
// set<int> s;
//     SeatManager(int n) {
//         for (int i = 1; i <= n; i++) s.insert(i);
//     }
    
//     int reserve() {
//         int res = *begin(s);
//         s.erase(begin(s));
//         return res;
//     }
    
//     void unreserve(int seatNumber) {
//         s.insert(seatNumber);
//     }
// };

class SeatManager {
public:
priority_queue<int, vector<int>, greater<int>> pq;
int max_s = 0;
    SeatManager(int n) {}    
    int reserve() {

        int res = pq.empty() ? ++max_s : pq.top();

        if (!pq.empty()) pq.pop();
        return res;
    }
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */