class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int n = arr.size();//row 
        int m = arr[0].size();//coloum
        int lm  = 0;
        int ln = 0;
        int hm = m - 1;
        int hn = n - 1;
        int store = 0;
        bool check = false;
        while(ln <= hn)
        {
            int mid = (ln + hn)/2;
            if(arr[mid][0]<=target && arr[mid][m - 1]>= target)
            {
                check = true;
                store = mid;
                break;
            }
            else if(arr[mid][0]>target)
            {
                hn = mid - 1;
            }
            else 
            ln = mid + 1;
        }
        if(check)
        {
            while(lm<= hm)
            {
                int  mid = (lm + hm)/2;
                if(arr[store][mid]== target) return true;
                else if(arr[store][mid]>target) hm = mid - 1;
                else
                lm = mid + 1;
            }
        }
        return false;
    }
};
