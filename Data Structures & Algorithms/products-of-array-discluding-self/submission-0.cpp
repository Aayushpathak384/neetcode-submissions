class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>arr;
        int n = nums.size();
        int pre_m[n] , suf_m[n];
        suf_m[n-1] = nums[n-1];
        pre_m[0] = nums[0];
        for(int i = n-2 ; i>=0 ; i--)
        {
            suf_m[i] = nums[i] * suf_m[i + 1];
        }
        arr.push_back(suf_m[1]);
        for(int i = 1; i<n - 1 ; i++)
        {
            pre_m[i] = nums[i] * pre_m[i - 1];
            arr.push_back(pre_m[i-1] * suf_m[i + 1]);
        }
        arr.push_back(pre_m[n-2]);
        return arr;
    }
};
