class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int arr[26] = {0};
        int n = s1.length();
        int m = s2.length();
        
        for(int i = 0 ; i< n; i++)
        arr[s1[i] - 'a']++;
        for(int i= 0 ; i<= m - n ;i++)
        {
            int brr[26] = {0};
            bool flag = true;
             for(int j = i ; j< n+i ; j++)
             {
                brr[s2[j] - 'a']++;
             }
             for(int k = 0 ; k< 26 ; k++)
             {
                if(arr[k]!=brr[k])
                {
                    flag = false;
                    break;
                }
                else
                continue;
             }
             if(flag)
             return true;
        }
        return false;
    }
};
