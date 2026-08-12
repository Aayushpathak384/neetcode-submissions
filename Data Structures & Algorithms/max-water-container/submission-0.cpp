class Solution {
public:
    int maxArea(vector<int>& arr) {
        int start = 0 ; 
        int end = arr.size() - 1;
        int res = 0;
        while(start<end)
        {
            int cal = min(arr[start] , arr[end]) * (end - start);
            res = max(res , cal );
            if(arr[start]<arr[end])
            start++;
            else
            end--;
        }
        return res;
    }
};
