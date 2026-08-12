class Solution {
public:
    int bsearch(vector<int>arr , int l , int h , int target)
    {
        while(l<=h)
            {
                        int m = (l + h)/2;
                        if(arr[m]== target) return m;
                        else if(arr[m]>target)
                        h = m - 1;
                        else
                        l = m + 1;
            }
            return -1;
    }
    int search(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0;
        int high = n -1;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(arr[mid]== target) return mid;
            else if(arr[mid]>=arr[low])
            {
                if(target == arr[low]) return low;
                else if(target>arr[low] && target<arr[mid])
                {
                    return bsearch(arr , low , mid , target); 
                }
                else
                low = mid + 1;
            }
            else
            {
                if(target == arr[high]) return high;
                else if(target<arr[high] && target>arr[mid])
                {
                    return bsearch(arr , mid , high , target);    
                }
                else
                high = mid -1;
            }
        }
        return -1;
    }
};
