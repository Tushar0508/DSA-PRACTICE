class MyCalendarTwo {
public:
    vector<pair<int, int>> calendar;    
    vector<pair<int, int>> overlaps;   

    MyCalendarTwo() { }

    bool book(int start, int end) {
        for (const auto& o : overlaps) {
            if (max(o.first, start) < min(o.second, end)) {
                return false;  
            }
        }

        for (const auto& c : calendar) {
            if (max(c.first, start) < min(c.second, end)) {
                overlaps.push_back({max(c.first, start), min(c.second, end)});
            }
        }

        calendar.push_back({start, end});
        return true;
    }
};