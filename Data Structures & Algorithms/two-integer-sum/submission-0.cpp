class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int>s;
        vector<int>arr;
        bool flag = false;
        int n = nums.size();
        int i;
        for( i = 0 ; i< n ; i++)
        {
            if(s.count(target - nums[i]))
            {
                flag = true;
                break;
            }
            else
            s.insert(nums[i]);
        }
        if(flag == true)
        {
            for(int j = 0 ;j< n ; j++)
            {
                if(target - nums[i] == nums[j] && i!=j)
                arr.push_back(j);
            }
             arr.push_back(i);
        }
        return arr;
        
        
    }
};
