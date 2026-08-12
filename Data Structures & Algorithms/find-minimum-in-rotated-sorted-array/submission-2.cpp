class Solution {
public:
    int findMin(vector<int> &arr) {
        int n = arr.size();
        int low = 0;
        int high = n -1;
        int res = INT_MAX;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(arr[mid]>=arr[low])
            {
                res = min(res , arr[low]);
                low = mid +1;
            }
            else
            {
                high = mid -1;
                res = min(res , arr[mid]);
            }
        }
        return res;
    }
};
