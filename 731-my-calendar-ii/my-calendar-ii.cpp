pair<int,int> d = {INT_MIN,INT_MAX};
class MyCalendarTwo {
public:
    vector<pair<int,int>> overlaps;
    vector<pair<int,int>> bookings;

    MyCalendarTwo() {   
    }

    pair<int,int> overlap(pair<int,int> a,pair<int,int> b){
        if (a.second <= b.first || b.second <= a.first) return d;
        return {max(a.first,b.first),min(a.second,b.second)};
    }
    
    bool book(int start, int end) {
        if (!bookings.size()) {
            bookings.push_back({start,end});
            return true;
        } 

        for(auto p : overlaps) {
            if ( d != overlap(p,{start,end})){
                return false;
            } 
        }


        for (auto p: bookings){
            pair<int,int> o = overlap(p,{start,end});
            if (o != d) overlaps.push_back(o);
        }
        bookings.push_back({start,end});
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */