class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int res = 0;
        int pre_min = arr[0];
        for(int i = 0; i< arr.size() ; i++)
        {
            if(pre_min>arr[i])
            pre_min = arr[i];
            int cal = arr[i] - pre_min;
            if(cal>0)
            res = max(res , cal);
            else
            continue;
        }
        return res;
    }
};
