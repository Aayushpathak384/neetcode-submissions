class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int>freq;
        unordered_set<int>help;
        vector<int>arr , temp;
        int n = nums.size();
        int m ;
        for(int i = 0 ; i< n; i++)
        {
            freq[nums[i]]++;
        }
        for(auto x: freq)
        {
            temp.push_back(x.second);
        }
        m = temp.size();
        sort(temp.begin() , temp.end() );
        temp.erase(temp.begin() , temp.begin() + (m - k));
        for(int x: temp)
        {
            help.insert(x);
        }
        for(auto x: freq)
        {
             if(k == 0)
             break;
             else
             {
                if(help.count(x.second))
                {
                    arr.push_back(x.first);
                    k--;
                }
             }
        }
        
        return arr;
    }
};
