class Solution {
public:
    bool can_eat(vector<int>arr , int h , int mid , int n)
    {
        int cal = 0;
        for(int i = 0 ; i< n ; i++)
        {
            cal += ceil((double)arr[i]/mid);
            if(cal>h)
            return false;
        }
        return true;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = piles[0];
        for(int &x: piles)
        {
            if(x>maxi)
            maxi = x;
        }
        if(n == h)
        {
            return maxi;
        }
        else
        {
            int low = 1;
            int high = maxi;
            int res = high ;
            while(low<=high)
            {
                int mid = (low + high)/2;
                bool check = can_eat(piles , h , mid , n);
                if(check)
                {
                    res = min(res , mid);
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return res;
        }
    }
};
