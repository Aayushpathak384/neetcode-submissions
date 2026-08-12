class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>s;
        
        for(int x: nums)
        {
             if(s.count(x) )
             {
                return true;
             }
             else
             {
                s.insert(x);
             }
        }
        return false;
    }
};