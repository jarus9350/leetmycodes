class Router {
public:
    int size = 0;
    unordered_map<int,deque<int>> destTime;
    unordered_map<int,set<pair<int,int>>> timeSD;
    queue<vector<int>> q;
    Router(int memoryLimit) {
        size = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (timeSD[timestamp].find({source,destination}) == timeSD[timestamp].end()) {
            if (q.size() == size) auto f = forwardPacket();
            q.push({source,destination,timestamp});
            destTime[destination].push_back(timestamp);
            timeSD[timestamp].insert({source,destination});
            return true;
        } 
        return false;
    }
    
    vector<int> forwardPacket() {
        if (!q.size()) return {};
        auto front = q.front();
        

        int src = front[0];
        int dest = front[1];
        int t = front[2];

        q.pop();

        destTime[dest].pop_front();
        timeSD[t].erase({src,dest});
        return front;
    }

    
    int getCount(int destination, int startTime, int endTime) {
        auto& v = destTime[destination];

        int l = 0;
        int h = v.size() -1;
        int lIndex = -1;
        int hIndex = - 1;
        while (l <= h){
            int m = l + (h - l)/2;
            if (startTime < v[m]) {
                h = m - 1;
                lIndex = m;
            } else if ( v[m] < startTime){
                l = m + 1;
            } else {
                lIndex = m;
                h = m - 1;
            }
        }

        l = 0;
        h = v.size() -1;
        while (l <= h){
            int m = l + (h - l)/2;
            if (endTime < v[m]) {
                h = m - 1;
            } else if ( v[m] < endTime){
                hIndex = m;
                l = m + 1;
            } else {
                hIndex = m;
                l = m + 1;
            }
        }

        if (hIndex == -1 && lIndex == -1) return 0;
        if (lIndex == -1 || hIndex == -1) return 0;
        return hIndex - lIndex + 1;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */