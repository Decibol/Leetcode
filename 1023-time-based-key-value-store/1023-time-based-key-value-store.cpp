class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> timemap;

public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (timemap.find(key) == timemap.end()) return "";
        
        int startTime = 0;
        int endTime = timemap[key].size() - 1;
        int result = -1;        

        while (startTime <= endTime){
            int mid = (startTime + endTime) / 2;

            if (timemap[key][mid].first == timestamp){
                result = mid;
                break;
            }
            
            else if (timemap[key][mid].first <= timestamp){
                result = mid;
                startTime = mid + 1;
            }

            else {
                endTime = mid - 1;
            }
        }

        return result == -1 ? "" : timemap[key][result].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */