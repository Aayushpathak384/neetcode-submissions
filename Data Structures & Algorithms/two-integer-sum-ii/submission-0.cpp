class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        vector<int>res;
        int start = 0; 
        int end = arr.size() - 1;
        int sum = 0;
        while(start<end)
        {
            sum = arr[start] + arr[end];
            if(sum == target)
            {
                res.push_back(start + 1);
                res.push_back(end + 1);
                break;
            }
            else if(sum> target)
            end--;
            else 
            start++;
        }
        return res;
    }
};
