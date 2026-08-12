class TimeMap {
public:
    unordered_map<string , vector<pair<string , int>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
         mp[key].push_back({value , timestamp});
    }
    
    string get(string key, int timestamp) {
        if(mp.count(key))
        {
            auto & arr = mp[key];
            int high = arr.size() - 1;
            int low = 0;
            string str = "";
            while(low<=high)
            {
                int mid = (low + high)/2;
                if(arr[mid].second<=timestamp)
                {
                    str = arr[mid].first;
                    low = mid  +1;
                }
                else
                high = mid - 1;
            }
            return str;
        }
        else 
        return  "";
    }
};
