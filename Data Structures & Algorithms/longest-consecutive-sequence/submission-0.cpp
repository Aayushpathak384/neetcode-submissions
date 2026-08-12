class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>arr , pro;
        int n  = nums.size();
        int res = 0;
        for(int i = 0 ; i< n ; i++)
        arr.insert(nums[i]);
        for(int i = 0 ; i< n ; i++)
        {
            if(pro.count(nums[i]))
            continue;
            else
            {
                int x = nums[i];
                int y = nums[i];
                int count = 1;
                pro.insert(x);
                while(arr.count(x + 1) || arr.count(y - 1))
                {
                    if(arr.count(x + 1))
                    {
                        count++;
                        x +=1;
                        pro.insert(x);
                    }
                    if(arr.count(y - 1))
                    {
                        count++;
                        y  = y-1;
                        pro.insert(y);
                    }
                }
                res = max(res , count);
            }
        }
        return res;
    }
};
