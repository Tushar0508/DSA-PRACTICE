class AllOne {
public:

    unordered_map<string, int> count;
    set<pair<int, string>> st; 

    void inc(string key) {
       int n = count[key];

       count[key]++;

       st.erase({n, key});
       st.insert({n+1, key});
        
    }
    
    void dec(string key) {
        int n = count[key];
        count[key]--;
        st.erase({n, key});

        if(count[key]>0) st.insert({n-1, key});
        else count.erase(key);
    }
    
    string getMaxKey() {
        if(!st.empty()) return st.rbegin()->second;
        else return "";

    }
    
    string getMinKey() {
        if(!st.empty()) return st.begin()->second;
        else return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */