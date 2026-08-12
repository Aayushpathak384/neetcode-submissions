class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int pre_max[n];
        int suf_max[n];
        int res = 0;
        pre_max[0] = arr[0];
        suf_max[n-1] = arr[n-1];
        for(int i = n - 2 ; i>=0 ; i--)
        {
            if(arr[i]>suf_max[i+1])
            suf_max[i] = arr[i];
            else
            suf_max[i] = suf_max[i+1];
        }
        for(int i  = 1 ; i< n; i++)
        {
            if(arr[i]>pre_max[i -1])
            pre_max[i] = arr[i];
            else
            pre_max[i] = pre_max[i-1];
            int cal = min(pre_max[i] , suf_max[i]) - arr[i];
            res += cal;
        }
        return res;
    }
};
