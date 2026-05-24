class TimeMap {
private: unordered_map<string, pair<vector<string>, vector<int>>> m;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        auto& p = m[key]; 
        p.first.push_back(value);
        p.second.push_back(timestamp);
        return;
    }
    
    string get(string key, int timestamp) 
    {
        if(m.find(key) == m.end())
        return "";
        auto& p = m[key];
        const vector<int>& time = p.second;
        const vector<string>& values = p.first;
        if(time[0] > timestamp)
        return "";
        auto it = upper_bound(time.begin(),time.end(), timestamp);
        int index = it - time.begin();
        if(index > 0)
        index -= 1;
        return values[index];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */