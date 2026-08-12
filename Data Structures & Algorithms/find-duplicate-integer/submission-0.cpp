class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0 ; i< n ; i++)
        {
            int index = (arr[i]>0)? arr[i] : -1 * arr[i];
            if(arr[index]<0)
            {
                return index;
            }
            else
            arr[index] = -1*arr[index];
        }
        return -1;
    }
};
