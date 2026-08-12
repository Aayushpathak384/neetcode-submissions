class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>arr;
        int n = nums.size();
        int max = INT_MIN;
            for(int j = 0 ; j< k ; j++)
            {
                if(nums[j]>max)
                max = nums[j];
                
            }
            arr.push_back(max);
        for(int i = 1 ; i< n - k +1; i++)
        {
            if(nums[i + k - 1]> max)
            {
                max = nums[i + k - 1];
            }
            else if(nums[i - 1]== max)
            {
                max = INT_MIN;
                for(int x = i ; x< i + k  ; x++)
                {
                    if(nums[x]>max)
                    max = nums[x];
                }
            }
            arr.push_back(max);
        }
        return arr;
    }
};
