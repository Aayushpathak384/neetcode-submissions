class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int j = 0;
        for(int i = 0 ; i< 2*n ; i++)
        {
            if(i>=n)
            {
                ans.push_back(nums[j]);
                j++;
            }
            else
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};